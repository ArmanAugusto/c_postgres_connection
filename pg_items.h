#ifndef PG_ITEMS_H
#define PG_ITEMDS_H

#include <libpq-fe.h>

void exit_connection(PGconn *connection);
void get_postgres_db_server_version();
void get_libpq_version();

#endif /* PG_ITEMS_H */
