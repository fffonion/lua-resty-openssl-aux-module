#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>
#include "ngx_stream_lua_resty_openssl_aux_module.h"

#include "ngx_stream_lua_socket_tcp.h"


static ngx_stream_module_t ngx_stream_lua_resty_openssl_aux_module_ctx = {
    NULL,                                  /* preconfiguration */
    NULL,                                  /* postconfiguration */

    NULL,                                  /* create main configuration */
    NULL,                                  /* init main configuration */

    NULL,                                  /* create server configuration */
    NULL                                   /* merge server configuration */
};


ngx_module_t ngx_stream_lua_resty_openssl_aux_module = {
    NGX_MODULE_V1,
    &ngx_stream_lua_resty_openssl_aux_module_ctx,   /* module context */
    NULL,                                           /* module directives */
    NGX_STREAM_MODULE,                              /* module type */
    NULL,                                           /* init master */
    NULL,                                           /* init module */
    NULL,                                           /* init process */
    NULL,                                           /* init thread */
    NULL,                                           /* exit thread */
    NULL,                                           /* exit process */
    NULL,                                           /* exit master */
    NGX_MODULE_V1_PADDING
};


int
ngx_stream_lua_resty_openssl_aux_get_request_ssl(ngx_stream_lua_request_t *r,
void **ssl_conn)
{
#if (NGX_SSL)
    ngx_connection_t    *c = r->connection;

    if (ssl_conn == NULL) {
        return NGX_ABORT;
    }

    if (c->ssl == NULL) {
        return NGX_ERROR;
    }

    *ssl_conn = c->ssl->connection;

    return NGX_OK;

#else
    return NGX_ABORT;
#endif
}


int
ngx_stream_lua_resty_openssl_aux_get_request_ssl_ctx(ngx_stream_lua_request_t *r,
void **sess)
{
#if (NGX_SSL)
    ngx_connection_t    *c = r->connection;

    if (sess == NULL) {
        return NGX_ABORT;
    }

    if (c->ssl == NULL) {
        return NGX_ERROR;
    }

    *sess = c->ssl->session_ctx;

    return NGX_OK;

#else
    return NGX_ABORT;
#endif
}


int
ngx_stream_lua_resty_openssl_aux_get_socket_ssl(ngx_stream_lua_socket_tcp_upstream_t *u,
void **ssl_conn)
{
#if (NGX_SSL)
    ngx_connection_t    *uc = u->peer.connection;

    if (ssl_conn == NULL) {
        return NGX_ABORT;
    }

    if (uc && (uc->ssl) &&
        (uc->ssl->connection)) {

        *ssl_conn = uc->ssl->connection;
        return NGX_OK;
    }

    return NGX_ERROR;

#else
    return NGX_ABORT;
#endif
}


int
ngx_stream_lua_resty_openssl_aux_get_socket_ssl_ctx(ngx_stream_lua_socket_tcp_upstream_t *u,
void **sess)
{
#if (NGX_SSL)
    ngx_connection_t    *uc = u->peer.connection;

    if (sess == NULL) {
        return NGX_ABORT;
    }

    if (uc && (uc->ssl) &&
        (uc->ssl->connection)) {

        *sess = uc->ssl->session_ctx;
        return NGX_OK;
    }

    return NGX_ERROR;

#else
    return NGX_ABORT;
#endif
}