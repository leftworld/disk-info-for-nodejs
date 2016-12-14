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
