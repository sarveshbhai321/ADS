#include<iostream>
using namespace std;
class landmark
{
    private:
    string source;
    landmark* next;
    string arrdest1[10];
    string arrdest2[10];
    string arrdest3[10];
    string arrdest4[10];
    landmark* head=NULL;
    landmark* temp=NULL;
    public:
    void createnode()
    {
        int i=0;
        int b=1;
        landmark* Node =new landmark;
         cout<<"enter the source";
         cin>>source;
         if(head=NULL)
         {
            head=Node;
            temp=Node;
            temp->source=source;
            temp->next=NULL;
         }
         else{
            temp->next=Node;
            temp=Node;
            temp->source=source;
            temp->next=NULL;

         }
         
         }

         

   }
    };
    int main()
    {
        landmark obj;
        obj.createnode();
    }
