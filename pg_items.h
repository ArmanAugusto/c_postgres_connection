#ifndef PG_ITEMS_H
#define PG_ITEMDS_H

#include <libpq-fe.h>

void clear_and_exit_connection(PGconn *connection, PGresult *result);
void exit_connection(PGconn *connection);
void get_postgres_db_server_version();
void get_libpq_version();
void query_execution();

#endif /* PG_ITEMS_H */
