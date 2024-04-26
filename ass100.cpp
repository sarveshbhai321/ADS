#include<iostream>
using namespace std;
class dictionary{
    public:
    int key;
    dictionary* hashtable[10];
    dictionary* head= NULL;
    dictionary* node;
    int flag=0;
    string value;
    int hk;
    dictionary* next;
    void constants()
    {
          for(int i=0;i<10;i++)
        {
            hashtable[i]->flag=0;
        }
    }
    void getdata(int key,string value)
    {
        hk=key%10;
      
        for(int i=0;i<10;i++)
        {
            if(i==hk && hashtable[i]->flag==0)
            {
                hashtable[i]->value=value;
            }
            else{
                hashtable[i]->flag=1;
                head=hashtable[i];
                node=head;
                dictionary* Node= new dictionary();
                Node->value=value;
                Node->key=key;
                
                while(node->next!=NULL)
                {
                     node=node->next;
                }
                node->next=Node;
                node=Node;
               node=head;
            }
        }

    }
    void printdata(){
        for(int i=0;i<10;i++)
        {
            if(flag==0)
            {
                cout<<hashtable[i]->value;

            }
            else{
                while(node->next!=NULL)
                {
                    cout<<node->value;
                    cout<<node->key;
                }
            }
            
        }
    }

};
int main()
{
    dictionary obj;
    obj.constants();
    obj.getdata(2,"jaihind");
    obj.getdata(2,"hi hello");
    obj.getdata(0,"great hello");
    return 0;
    
}