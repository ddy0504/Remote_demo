#include <iostream>

using namespace std;

enum Color{red,yellow,green};

enum class ColorWithScope{red,yellow,green};

int main(){

    int a_red = red;
    
    auto ColorWithScope_green = ColorWithScope::green;

    static_assert(sizeof(void*)==4,"can only be");

    return 0;
}
