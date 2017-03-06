#include <iostream>
using namespace std; 

//函数模板一般定义在头文件中
template<typename T>
T add(const T& a,const T& b){
  cout << "sizeof(T)= " << sizeof(T) << endl;
  return a+b;
}

template<typename T1,typename T2,typename T3 = long>
T3 add123(T1 a1,T2 a2){
   cout << "sizeof(T1,T2,T3)=(" << sizeof(T1) << ","
       << sizeof(T2)<< "," << sizeof(T3) <<")"<< endl;
   return (T3)(a1+a2);
}

template<>//特例化
long add123(int* a1,int* a2);
