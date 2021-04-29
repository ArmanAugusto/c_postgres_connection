#include <stdio.h>
#include <libpq-fe.h>
#include "libpq_version.h"

void get_libpq_version() {
  int libpq_version = PQlibVersion();
  printf("Version of libpq:  %d\n", libpq_version);
}
