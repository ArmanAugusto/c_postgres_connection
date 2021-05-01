#include <stdio.h>
#include "pg_items.h"

int main(void) {
  get_libpq_version();
  get_postgres_db_server_version();

  return 0;
}
