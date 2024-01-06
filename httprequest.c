#include "httprequest.h"
#include <string.h>
#include <stdlib.h>

int get_method(char *method)
{
  if (strcmp(method, "GET") == 0)
  {
    return GET;
  }
  if (strcmp(method, "POST") == 0)
  {
    return POST;
  }
  if (strcmp(method, "PUT") == 0)
  {
    return PUT;
  }
  if (strcmp(method, "HEAD") == 0)
  {
    return HEAD;
  }
  if (strcmp(method, "PATCH") == 0)
  {
    return PATCH;
  }
  if (strcmp(method, "DELETE") == 0)
  {
    return DELETE;
  }
  if (strcmp(method, "CONNECT") == 0)
  {
    return CONNECT;
  }
  if (strcmp(method, "TRACE") == 0)
  {
    return TRACE;
  }
  if (strcmp(method, "OPTIONS") == 0)
  {
    return OPTIONS;
  }
  return GET;
}

struct HTTPRequest create_http_request(char *req)
{
  char requested[strlen(req)];
  strcpy(requested, req);
  // look for \n\n
  for (int i = 0; i < (int)strlen(requested) - 1; i++)
  {
    if (requested[i] == '\n' && requested[i + 1] == '\n')
    {
      requested[i + 1] = '|';
    }
  }
  char *request_line = strtok(requested, "\n");
  char *headers = strtok(NULL, "|");
  char *body = strtok(NULL, "|");

  char *method = strtok(requested, " ");
  char *uri = strtok(NULL, " ");
  char *http_version = strtok(NULL, " ");
  http_version = strtok(http_version, "/");
  http_version = strtok(NULL, "/");

  struct HTTPRequest request = {
      get_method(method),
      uri,
      (float)atof(http_version),
  };

  return request;
}