#include<iostream>
#include<string>
using namespace std;
struct great
{
    string a[15];
};
class landmarks
{
    public:
 landmarks * land[10];
    string source;
    string location;
    landmarks* next;
    landmarks *temp=NULL;
    int i=0;
    void addnode()
    {
        cout<<"enter the source";
        cin>>source;
        land[i]->source=source;
        i++;
    }
    void createpath()
    {
        cout<<"enter the source you wanna find";
        cin>>source; 
        cout<<"enter the destination";
        cin>>location; 
        landmarks*node=new landmarks;
        for(int j=0;j<i;j++)
        {
            if(land[i]->source==source)
            {  
                land[i]->next=node;
                node->location=location;
            }
        }
    }
}
