#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include "pg_items.h"

void exit_connection(PGconn *connection) {
  PQfinish(connection);
  exit(1);
}

void get_postgres_db_server_version() {
  PGconn *connection = PQconnectdb("user=armanaugusto password=TekkonKinkreet14! dbname=stubpaytrackerdb");

  if(PQstatus(connection) == CONNECTION_BAD) {
    fprintf(stderr, "Connection to database failed:  %s\n", PQerrorMessage(connection));
    exit_connection(connection);
  }

  int version = PQserverVersion(connection);
  printf("Postgres Database Server Version:  %d\n", version);

  PQfinish(connection);
}

void get_libpq_version() {
  int libpq_version = PQlibVersion();
  printf("Version of libpq:  %d\n", libpq_version);
}
