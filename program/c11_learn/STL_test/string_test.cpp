#include <string>
#include <iostream>
using namespace std;

void string_test(){
   string s1("this is s1");
   string s2 = "this is s2";
   string s3 = s1 + ", " + s2;
   cout<<"s1="<<s1<<endl;
   cout<<"s2="<<s2<<endl;
   cout<<"s3="<<s3<<endl;
   //返回字符串所占的字节个数，不是字符的个数，对于多字节字符，
   //一个字符可能不止占据一个字节
   string::size_type size = s3.size();
   cout<<"s3.size()= "<<size<<endl;
   //判断字符串是否为空
   bool isEmpty = s1.empty();
   cout<<"isEmpty="<<isEmpty<<endl;
   
   char b = s2[3];
   for(auto item:s2){
      cout<<item<<endl;
   }
   s2.clear();
   s2 = "a new s2";
   string::size_type pos = s2.find("new");
   if(pos != string::npos){
      cout<<"find new pos ="<<pos<<endl;
   }
   //c_str()获取string中的字符串，可用于printf中
   const char* c_string = s3.c_str();
   cout<<c_string<<endl;
}

int main(){
   string_test();
   return 0;
}
