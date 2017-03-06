#include <iostream>
using namespace std;

template<typename T,unsigned int N>
class TObj{
public:
   void accessObj(){
      cout<<"TObj<typename T,unsigned int N> N="<<N<<endl;
   }
   template<typename T1>
   bool compare(const T1& a,const T& b){
      cout<<"调用类模板的比较函数"<<endl;
      return a < b;
   }
public:
   T obj[N];
};

//全特化
template<>
class TObj<int*,5>{
public:
   void accessObj(){
      cout<<"Full specialization TObj<int*,5>"<<endl;
   }
   template<typename T1>
   bool compare(const T1& a,const int* & b){
      cout<<"调用全特化的比较函数"<<endl;
      return a < (*b);
   }
public:
   int* obj[5];
   void Call();
};

//偏特化
template<unsigned int N>
class TObj<int*,N>{
public:
   void accessObj(){
      cout<<"Partial specialization TObj<int*,N> N="<<N<<endl;
   }
   template<typename T1>
   bool compare(const T1& a,const int* & b){
      cout<<"调用偏特化的比较函数"<<endl;
      return a < (*b);
   }
public:
   int* obj[N];
   void Cal();
   template<typename T2>
   bool compare2(const T2& a,const int* &b);
};

