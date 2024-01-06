#ifndef httprequest_h
#define httprequest_h

#define FOREACH_HTTP_METHOD(HTTP_METHOD) \
  HTTP_METHOD(GET) \
  HTTP_METHOD(POST) \
  HTTP_METHOD(PUT) \
  HTTP_METHOD(PATCH) \
  HTTP_METHOD(HEAD) \
  HTTP_METHOD(DELETE) \
  HTTP_METHOD(CONNECT) \
  HTTP_METHOD(TRACE) \
  HTTP_METHOD(OPTIONS) \

#define GENERATE_ENUM(ENUM) ENUM,
#define GENERATE_STRING(STRING) #STRING,

enum HTTPMethods {
  FOREACH_HTTP_METHOD(GENERATE_ENUM)
};

static const char *HTTP_METHOD_STRING[] = {
  FOREACH_HTTP_METHOD(GENERATE_STRING)
};

// enum HTTPMethods
// {
//   GET,
//   POST,
//   PUT,
//   PATCH,
//   HEAD,
//   DELETE,
//   CONNECT,
//   TRACE,
//   OPTIONS,
// }


struct HTTPRequest
{
  int method;
  char *uri;
  float http_version;
};

struct HTTPRequest create_http_request(char *req);

#endif