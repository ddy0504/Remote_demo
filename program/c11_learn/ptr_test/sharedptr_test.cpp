#include <iostream>
#include <memory>

using namespace std;

class SPItem{
public:
    SPItem(int x):mx{x}{
        cout<<"in SPItem mx="<<mx<<endl;
    }
    ~SPItem(){
        cout<<"in ~SPItem mx="<<mx<<endl;
    }
    int mx;
};

int main(){

    shared_ptr<SPItem> item0 = make_shared<SPItem>(1);    cout<<"item0->mx="<<item0->mx<<endl;
    
    shared_ptr<SPItem> item1 = item0;
    if(item0.get() == item1.get()){
        cout<<"item0 and item1 same"<<endl;
    }
    cout<<"use count = "<<item1.use_count()<<endl;

    item1.reset(new SPItem(2));
    cout<<"(*item1).mx="<<(*item1).mx<<endl;
    cout<<"use count = "<<item1.use_count()<<endl;

    unique_ptr<SPItem> unique0(new SPItem(3));
    cout<<"(*unique0).mx"<<(*unique0).mx<<endl;
    SPItem* pUnique0 = unique0.release();
    delete pUnique0;

    unique_ptr<SPItem> unique1(new SPItem(4));
    unique_ptr<SPItem> unique2;
    unique2 = std::move(unique1);
    if(unique1 == false){
        cout<<"after move,the pointer is "<<
                  unique1.get()<<endl;
    }

    unique2.reset(nullptr);

   

     
    return 0;
}
