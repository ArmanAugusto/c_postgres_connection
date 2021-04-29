#ifndef DB_SERVER_VERSION_H
#define DB_SERVER_VERSION_H

#include <libpq-fe.h>

void exit_connection(PGconn *connection);
void get_postgres_db_server_version();

#endif /* DB_SERVER_VERSION_H */
