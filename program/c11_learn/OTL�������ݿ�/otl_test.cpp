#include <iostream>
using namespace std;
#include <stdio.h>
#define OTL_ORA11G_R2 // 指定连接的数据库类型
#include "otlv4.h" // include the OTL 4 header file
otl_connect db; // 定义数据库实例

/*void insert()
// 添加记录
{
 otl_stream o(50, // buffer size
              "insert into test_tab values(:f1<float>,:f2<char[31]>)",
                 // SQL statement
              db // connect object
             );
 char tmp[32];
 for(int i=1;i<=100;++i){
#if defined(_MSC_VER)
#if (_MSC_VER >= 1400) // VC++ 8.0 or higher
  sprintf_s(tmp,sizeof(tmp),"Name%d",i);
#else
  sprintf(tmp,"Name%d",i);
#endif
#else
  sprintf(tmp,"Name%d",i);
#endif
  o<<static_cast<float>(i)<<tmp;
 }
}

//查询记录
void select()
{
 otl_stream i(50, // buffer size
              "begin "
              "  open :cur1 for "
              "   select * from test_tab "
              "   where f1>=:f<int> and f1<=:f*2; "
              "end;", // SELECT statement via referenced cursor
              db, // connect object
              ":cur1" // referenced cursor placeholder name
             );
   // create select stream
 
 otl_column_desc* desc;
 int desc_len;
 i<<4; // Before the child SELECT statement can be described,
       // the PL/SQL master block needs to be executed.
       // Forcing the execution of the blcok by entering its input
       // patameter.
 desc=i.describe_select(desc_len);
{
 for(int n=0;n<desc_len;++n){
  cout<<"========== COLUMN #"<<n+1<<" ==========="<<endl;
  cout<<"name="<<desc[n].name<<endl;
  cout<<"dbtype="<<desc[n].dbtype<<endl;
  cout<<"otl_var_dbtype="<<desc[n].otl_var_dbtype<<endl;
  cout<<"dbsize="<<desc[n].dbsize<<endl;
  cout<<"scale="<<desc[n].scale<<endl;
  cout<<"prec="<<desc[n].prec<<endl;
  cout<<"nullok="<<desc[n].nullok<<endl;
 }
}
}*/

void select2(){
    otl_stream tt_emp(
            20,
            "select empno,ename from emp",
            db
          );
    char ename[20];
    double empno;
    while(!tt_emp.eof())
    {
        tt_emp >> empno;
        tt_emp >> ename;
        cout<<"empno: "<<empno <<" name: "<<ename<<endl;
    }
}

int main()
{
    otl_connect::otl_initialize(); // 初始化Oracle环境
    try{
        db.rlogon("scott/tiger"); // 连接Oracle
        /*otl_cursor::direct_exec
        (
          db,
          "drop table test_tab",
          OTL_ORA11G_R2otl_exception::disabled // disable OTL exceptions
         ); // drop table
         otl_cursor::direct_exec
         (
           db,
           "create table test_tab(f1 number, f2 varchar2(30))"
          );  // create table
          insert(); 
          select();*/
          select2();
         
    }
    catch(otl_exception& p){ // intercept OTL exceptions
        cerr<<p.msg<<endl; // print out error message
        cerr<<p.stm_text<<endl; // print out SQL that caused the error
        cerr<<p.var_info<<endl; // print out the variable that caused the error
     }
     db.logoff(); //断开数据库连接
     return 0;
}
