#include <stdio.h>

extern int func1();
extern int func2();

int main()
{
    int i;
    i = func1();
    printf("func1 return = %d\n",i);
    i = func2();
    printf("func2 return = %d\n",i);
    return 0;
}
    
