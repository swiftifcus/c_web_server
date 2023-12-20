#include "server.h"
#include <stdio.h>
#include <stdlib.h>

struct Server create_server(int domain, int service, int protocol, u_long interface, int port, int backlog, void (*launch)(struct Server *server))
{
  struct Server server;
  server.domain = domain;
  server.service = service;
  server.protocol = protocol;
  server.interface = interface;
  server.port = port;
  server.backlog = backlog;
  server.launch = launch;

  server.addr.sin_family = domain;
  server.addr.sin_port = htons(port);
  server.addr.sin_addr.s_addr = htonl(interface);

  server.socket = socket(domain, service, protocol);

  if (server.socket == 0)
  {
    perror("Failed to connect to socket...\n");
    exit(1);
  }

  if ((bind(server.socket, (struct sockaddr *)&server.addr, sizeof(server.addr))) < 0)
  {
    perror("Failed to bind the socket...\n");
    exit(1);
  }

  if ((listen(server.socket, server.backlog)) < 0)
  {
    perror("Failed to start listening...\n");
    exit(1);
  }

  return server;
}