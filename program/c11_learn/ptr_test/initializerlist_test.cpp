#include <iostream>

using namespace std;

class Test{

public:
   //定义一个参数为lnitializer_list的构造函数
   Test(initializer_list<int> a_list){
      for(auto item:a_list){
          cout<<"item="<<item<<endl;
      }
   }
   
   int x;
};

int main(){

    Test a = {1,2,3,4};

    initializer_list<string> strlist = {"1","2","3"};
    using ILiter = initializer_list<string>::iterator;

    for(ILiter iter = strlist.begin();iter!=strlist.end();
            ++iter){

        cout<<"item="<<*iter<<endl;
    }
    return 0;
}
