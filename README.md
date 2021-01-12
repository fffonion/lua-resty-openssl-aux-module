Name
====
lua-resty-openssl-aux-module - C module to interact with SSL operations in OpenResty


Table of Contents
=================

* [Name](#name)
* [Description](#description)
* [Install](#install)
* [License](#license)

Description
===========

This is an auxiliary module to [lua-resty-openssl](https://github.com/fffonion/lua-resty-openssl) to interact
with SSL operations inside OpenResty.

User is not supposed to use this module directly. Instead, lua-resty-openssl will be able to automatically
detect existence of this module after installing.


Install
=======
This module can be installed just like any ordinary Nginx C module, using the
`--add-module` configuration option:

```shell
./configure --prefix=/usr/local/openresty \
            --add-module=/path/to/lua-resty-openssl-aux-module \
            --add-module=/path/to/lua-resty-openssl-aux-module/stream \
            ...

```

By default this module assumes itself in same parent directory of lua-nginx-module and
stream-lua-nginx-module. If the directory layout is different, user can pass `NGX_LUA_LOC` and
`NGX_STREAM_LUA_LOC` environment variable to specify paths of the two modules.

After the module is compiled, also install the lua helper file.

```
make install
```


License
=====================

This module is licensed under the BSD license.

Copyright (C) 2021, by fffonion <fffonion@gmail.com>.

All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

[Back to TOC](#table-of-contents)
