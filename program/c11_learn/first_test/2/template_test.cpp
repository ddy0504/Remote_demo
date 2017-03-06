#include "template_test.h"

//通过using关键字定义一个模板类型别名
template<typename T>
using TObj10 = TObj<T,10>;

//在类外定义类模板的成员函数
//全特化得到具体的类，无须加template修饰符
void TObj<int*,5>::Call(){
    cout<<"类外定义全特化成员函数"<<endl;
}
template<unsigned int N>
void TObj<int*,N>::Cal(){
   TObj* p = this;
   p->obj[0] = nullptr;
   cout<<"类外定义偏特化成员函数"<<endl;
}
template<unsigned int N>
template<typename T2>
bool TObj<int*,N>::compare2(const T2& a,const int* &b){
   cout<<"类外定义成员函数模板"<<endl;
   return true;
}

void testTemplateClass(){
   TObj<int,3> intObj_3;
   intObj_3.accessObj();

   TObj10<long> longObj_10;
   longObj_10.accessObj();

   //使用全特化版本
   TObj<int*,5>intpObj_5;
   intpObj_5.accessObj();
   //使用偏特化版本
   TObj<int*,100>intpObj_100;
   intpObj_100.accessObj();
   int x = 100;
   const int *p = &x;
   bool result = intpObj_5.compare(10,p);
   if(result){
       cout<< "10小于100"<<endl;
   }
   result = intpObj_5.compare<long>(1000,p);
   if(result){
       cout<<"1000小于100"<<endl;
   }
   intpObj_5.Call();
   intpObj_100.Cal();
   intpObj_100.compare2(10,p);
}

int main(){
   testTemplateClass();
   return 0;
}
