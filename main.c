#include <stdio.h>
#include "libpq_version.h"
#include "db_server_version.h"

int main(void) {
  get_libpq_version();
  get_postgres_db_server_version();

  return 0;
}
