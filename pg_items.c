#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include "pg_items.h"

void clear_and_exit_connection(PGconn *connection, PGresult *result) {
  fprintf(stderr, "%s\n", PQerrorMessage(connection));

  PQclear(result);
  PQfinish(connection);

  exit(1);
}

void exit_connection(PGconn *connection) {
  PQfinish(connection);
  exit(1);
}

void get_postgres_db_server_version() {
  PGconn *connection = PQconnectdb("user=<username> password=<password> dbname=<database name>");

  if(PQstatus(connection) == CONNECTION_BAD) {
    fprintf(stderr, "Connection to the database has failed:  %s\n", PQerrorMessage(connection));
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

void query_execution() {
  PGconn *connection = PQconnectdb("user=<username> password=<password> dbname=<database name>");
  
  if(PQstatus(connection) == CONNECTION_BAD) {
    fprintf(stderr, "Connection to the database has failed:  %s\n", PQerrorMessage(connection));
    exit_connection(connection);
  }

  PGresult *result = PQexec(connection, "SELECT * FROM <table name>;");

  if(PQresultStatus(result) != PGRES_TUPLES_OK) {
    printf("Unable to retrieve data\n");
    PQclear(result);
    exit_connection(connection);
  }

  printf("%s %s %s %s %s %s\n", PQgetvalue(result, 0, 0), PQgetvalue(result, 0, 1), PQgetvalue(result, 0, 2), PQgetvalue(result, 0, 3), PQgetvalue(result, 0, 4), PQgetvalue(result, 0, 5));

  PQclear(result);
  PQfinish(connection);
}
