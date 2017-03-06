#include <iostream>

using namespace std;

class Item{
public:
    Item(int x):mx{x}{
        cout<<"in Item(x="<<mx<<")"<<endl;
    }
    ~Item(){
        cout<<"in ~Item()"<<endl;
    }
private:
    int mx = 0;
};
void allocator_test(){
    allocator<Item> itemAllocator;
    Item* pItems = itemAllocator.allocate(5);
    cout<<"construct Items"<<endl;
    for(int i = 0;i<5;i++){
        itemAllocator.construct(pItems+i,i*i);
    }
    for(int i = 0;i<5;i++){
        itemAllocator.destroy(pItems+i);
    }
    cout<<"destroy memory"<<endl;
    itemAllocator.deallocate(pItems,5);
}

int main(){
   allocator_test();
   return 0;
}
