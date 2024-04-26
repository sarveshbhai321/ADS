#include<iostream>
using namespace std;
class binarysearch
{
    binarysearch* root=new binarysearch;
    binarysearch*left;
    binarysearch* right;
    int data;
    void insert()
    {
        cout<<"enter the data";
        cin>>data;
        if(root->data=NULL)
        {
            binarysearch* root=new binarysearch;
            root->data=data;
            cout<<"node inserted";
        }
        else if(root->data>data)
        {
            root->left=insert();
        }
        else if(root->data<data)
        {
            root->right=insert();
        }

    }
}
int main(){
    binarysearch obj;
    obj.insert();
    return 0;
}