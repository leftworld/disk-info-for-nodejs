#include <v8.h>
#include <node.h>
#include <mntent.h>
#include <sys/vfs.h>
#include <string.h>

using namespace node;
using namespace v8;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void Method(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  Local<Object> obj = Object::New(isolate);
  FILE* mount_table = NULL;
  struct mntent *mount_entry;
  struct statfs s;
  mount_table = setmntent("/etc/mtab", "r");
  if (mount_table)
  {
    while (1) {
      const char *device;
      const char *mount_point;
      if (mount_table) {
        mount_entry = getmntent(mount_table);
        if (!mount_entry) {
          endmntent(mount_table);
          break;
        }
      }else
      {
        continue;
      }
      device = mount_entry->mnt_fsname;
      mount_point = mount_entry->mnt_dir;
      if (statfs(mount_point, &s) != 0)
      {
        continue;
      }
      if (strcmp(device, "rootfs") == 0)
      {
        continue;
      }
      if (strcmp(device, "tmpfs") == 0)
      {
        continue;
      }
      if (strcmp(device, "udev") == 0 )
      {
        continue;
      }
      if ((s.f_blocks > 0) || !mount_table )
      {
        unsigned long blocks_used = s.f_blocks - s.f_bfree;
        unsigned long blocks_percent_used = 0;
        if (blocks_used + s.f_bavail)
        {
          blocks_percent_used = (blocks_used * 100ULL + (blocks_used + s.f_bavail) / 2 ) / (blocks_used + s.f_bavail) + 1;
          obj->Set(String::NewFromUtf8(isolate, mount_point), Number::New(isolate, blocks_percent_used));
        }
      }
    }
  }
  args.GetReturnValue().Set(obj);
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "getDiskUsed", Method);
}

NODE_MODULE(diskinfo, init);
