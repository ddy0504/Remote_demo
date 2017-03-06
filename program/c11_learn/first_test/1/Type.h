#ifndef _TYPE_H_
#define _TYPE_H_

namespace my_type{
   void test();
   class Base{
    public:
        Base();
        Base(int a);
        Base(const Base& other);//拷贝构造函数
        Base& operator =(const Base& other);//拷贝赋值函数
   
        Base(Base&& other);//移动构造函数
        Base& operator =(Base&& other);//移动赋值函数
        ~Base();
    protected:
        int getMemberB(){
           return memberB;
        }
        int deleteC(int a,int b = 100,
                 bool test=true);
    private:
        int memberA;
        int memberB;
        static const int size = 512;
        int* pMemberC;
    };
};
#endif

