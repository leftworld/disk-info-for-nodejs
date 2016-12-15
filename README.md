# disk-info-for-nodejs
desc:

Get disk info  

binding.gyp

		{
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
find "v8.h" and "node.h" directory and add to "include_dirs" config

node-gyp configure

node-gyp build

test:
node test.js

{ '/': { Size: 29, UsedPercent: 75, Used: 20, unit: 4096 } }

"/" is disk

"Size" :29G

"usedPercent": 75% 

"Used" : 20G

"unit": block size
