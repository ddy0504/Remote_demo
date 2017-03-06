#include "Type.h"
#include "Template_type.h"
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

extern void test1();

namespace my_type{

    void test(){
       cout << "this is test" << endl;
    }
    void changeRef(int &alias){
    alias = 8999;
    }
    //默认构造函数
    Base::Base():memberA(0),memberB(100),pMemberC(new int[size]){
      cout<< "In default constructor"<<endl;
    }
    //普通构造函数
    Base::Base(int a):
          memberA{a},memberB{100},pMemberC(new int[size]){
      cout<<"In normal constructor"<<endl;
    }
    //拷贝构造函数
    Base::Base(const Base& other):
         memberA{other.memberA},memberB{other.memberB},
         pMemberC{nullptr}{
         cout<<"In copy constructor"<<endl;
         if(other.pMemberC != nullptr){
            pMemberC = new int[Base::size];
            memcpy(pMemberC,other.pMemberC,size);
         }        
      }
    //拷贝赋值函数,重载赋值操作符
    Base& Base::operator =(const Base& other){
        this->memberA = other.memberA;
        (*this).memberB = other.memberB;
        if(pMemberC != nullptr){
           delete[] pMemberC;
           pMemberC = nullptr;
        }
        if(other.pMemberC != nullptr){
           pMemberC = new int[Base::size];
           memcpy(pMemberC,other.pMemberC,size);
        }
        return *this;
    } 
    //移动构造函数,Base&&表示Base的右值引用类型
    Base::Base(Base&& other):
        memberA(other.memberA),memberB(other.memberB),
       pMemberC(other.pMemberC){
          other.pMemberC = nullptr;
      }
    //移动赋值函数
    Base& Base::operator =(Base&& other){
       memberA = other.memberA;
       memberB = other.memberB;
       if(pMemberC != nullptr){
           delete[] pMemberC;
           pMemberC = nullptr;
       }
       pMemberC = other.pMemberC;
       other.pMemberC = nullptr;
       return *this;
    }
    Base::~Base(){
      if(pMemberC != nullptr){
           delete[] pMemberC;
           pMemberC = nullptr;
      }
     cout<<"in destructor"<<endl;
    }
}
void changeNoRef(int &x){
   x = 9999;
}

int main()
{
   my_type::test();
   int a = 100;
   changeNoRef(a);
   cout << "a = " << a << endl;
   a = 100;
   my_type::changeRef(a);
   cout << "a = " << a << endl;
   test1();
   return 0;
}
