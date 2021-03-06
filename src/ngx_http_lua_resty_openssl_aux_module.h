#ifndef _NGX_HTTP_LUA_RESTY_OPENSSL_AUX_MODULE_H_INCLUDED_
#define _NGX_HTTP_LUA_RESTY_OPENSSL_AUX_MODULE_H_INCLUDED_


#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>

#include "ngx_http_lua_socket_tcp.h"

int ngx_http_lua_resty_openssl_aux_get_request_ssl(ngx_http_request_t *r,
    void **ssl_conn);

int ngx_http_lua_resty_openssl_aux_get_request_ssl_ctx(ngx_http_request_t *r,
    void **sess);

int ngx_http_lua_resty_openssl_aux_get_socket_ssl(ngx_http_lua_socket_tcp_upstream_t *u,
    void **ssl_conn);

int ngx_http_lua_resty_openssl_aux_get_socket_ssl_ctx(ngx_http_lua_socket_tcp_upstream_t *u,
    void **sess);

#endif /* _NGX_HTTP_LUA_RESTY_OPENSSL_AUX_MODULE_H_INCLUDED_ */
