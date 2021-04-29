#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

void exit_connection(PGconn *connection) {
  PQfinish(connection);
  exit(1);
}

void get_postgres_db_server_version() {
  PGconn *connection = PQconnectdb("user=<username> password=<password> dbname=<database>");

  if(PQstatus(connection) == CONNECTION_BAD) {
    fprintf(stderr, "Connection to database failed:  %s\n", PQerrorMessage(connection));
    exit_connection(connection);
  }

  int version = PQserverVersion(connection);
  printf("Postgres Database Server Version:  %d\n", version);

  PQfinish(connection);
}
