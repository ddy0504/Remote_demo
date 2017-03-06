#include <iostream>
using namespace std;

int main(){

    auto f1 = []{
      cout <<"this is f1,no return"<<endl;
    };
    auto f2 = []{
      cout <<"this is f2,return int"<<endl;
      return 0;//编译器会推导出返回值的类型
    };
    f1();
    f2();

    int x = 0;
    bool a = false;
    auto f3 = [](int x,bool &a) -> bool{
        cout << "this is f3"<<endl;
        return false;
    };
    f3(1,a);
    
    string info = "hello world";
    string info2 = "ddy";
    auto f4 = [x,&info,&info2](){
      cout<<"x="<<x
          <<" info2="<<info2
          <<" info="<<info<<endl;
          info = "hello world in f4";
    };
    cout<<info<<endl;
    f4();
    cout<<info<<endl;
} 
