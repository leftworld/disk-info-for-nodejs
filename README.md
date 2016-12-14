# diskused-for-nodejs
#desc:
Get disk used ratio  

binding.gyp

```{
  'targets':[
  {
    'include_dirs': [
      '/usr/include/nodejs/src',
      '/usr/include/nodejs/deps/v8/include'
    ],
    'target_name':'diskinfo',
    'sources':['diskinfo.cc'],
    'conditions':[
      ['OS == "mac"',
        {
          'libraries':['-lnode.lib'],
        }
      ]
    ]
  }
 ]
}
```
find "v8.h" and "node.h" directory and add to "include_dirs" config

#node-gyp configure

#node-gyp build

#test:
node test
