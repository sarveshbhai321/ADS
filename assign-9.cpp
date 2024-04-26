#include<iostream>
using namespace std;
class telbook{
    public:
    telbook* node;
    int phonenumber;
    int key;
    int size=20;
    int arr[20];
};
class makebook : protected telbook{
    int arr[20];
    void getdata()
    {
        telbook* node=new telbook;
        cout<<"enter the key";
        cin>>key;
        cout<<"enter phonenumber";
        cin>>phonenumber;
        node->key=key;
        node->phonenumber=phonenumber;
        int index=(node->key)%size;
        for(int i=0;i<size;i++)
        {
            if(i==node->key)
            {
                arr[i] = node->phonenumber;
                return;
            }
        }

    }

    }

       
}
