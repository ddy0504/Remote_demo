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

int Operate(char *sql){

   //char *sql;
   const char* data = "Callback function called";
   char *zErrMsg = 0;

   /* Execute SQL statement */
   //第四个参数若无须传入，可传入0
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

int main(int argc, char* argv[])
{
   int ret;
   char *sql;

   ret = Open();

   sql = "SELECT * from COMPANY";
   ret = Operate(sql);

   //更新记录
   //sql = "UPDATE COMPANY set SALARY = 25000.00 where ID=1; " \
         "SELECT * from COMPANY";
   //ret = Operate(sql);

   //删除记录
   //sql = "DELETE from COMPANY where ID=2; " \
         "SELECT * from COMPANY";
   //ret = Operate(sql);

   //插入记录
   //sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (5, 'ddy', 25, 'China', 15.00 ); "\
         "SELECT * from COMPANY";
   //ret = Operate(sql);

   //创建表
   //sql = "CREATE TABLE DEPARTMENT( "\
         "ID INT PRIMARY KEY      NOT NULL, "\
         " DEPT           CHAR(50) NOT NULL, "\
         "EMP_ID         INT      NOT NULL "\
         ")";
   //Operate(sql);

   sqlite3_close(db);

   return 0;
}
