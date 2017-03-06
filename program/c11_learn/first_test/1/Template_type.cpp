#include "Template_type.h"

template<>
long add123(int* a1,int* a2){
   return (*a1) + (*a2);
}

void test1(){
  int x= add(10,20);
  int y= add123<int,int,int>(1,2);
  y = add123<short,short>(1,2);
  add123<int>(4,5);
  add123(0,0);
  int a1 = 100;
  int b1 = 200;
  long value = add123(&a1,&b1);
  cout <<"value=" << value <<endl;
}
