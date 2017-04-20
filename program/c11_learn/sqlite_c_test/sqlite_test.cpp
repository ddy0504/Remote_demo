#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
using namespace std;

sqlite3 *db;

static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int Open(){
   //sqlite3 *db;
   int rc;
   
   /* Open database */
   rc = sqlite3_open("testDB.db", &db);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }else{
      fprintf(stderr, "Opened database successfully\n");
   }

   return 0;
}

int Select(){

   char *sql;
   const char* data = "Callback function called";
   char *zErrMsg = 0;
   /* Create SQL statement */
   sql = "SELECT * from COMPANY";

   /* Execute SQL statement */
   int rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return 0;
   }else{
      fprintf(stdout, "Operation done successfully\n");
   }
   return 1;
}

int Insert(){
   char *sql;
   char *zErrMsg = 0;
   /* Create SQL statement */
   sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

   /* Execute SQL statement */
   int rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return 0;
   }else{
      fprintf(stdout, "Records created successfully\n");
   }
   return 1;
}

int main(int argc, char* argv[])
{
   int ret;

   ret = Open();

   ret = Select();

   ret = Insert();

   Select();

   sqlite3_close(db);

   return 0;
}
