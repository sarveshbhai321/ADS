#include<iostream>
using namespace std;
class topologicalsort
{
    public:
topologicalsort* a[15];
string source;
topologicalsort* next;
    topologicalsort* temp;
    topologicalsort* head;
    string destination;
int j=0;
void addsource()
{
    cout<<"enter the source";
        topologicalsort* temp= new topologicalsort;
        topologicalsort* head= new topologicalsort;
        
    cin>>temp->source;
      a[j]=temp;
      temp->next=NULL;
      head=temp;
      head=a[j];
      j++;

}
void createpath()
{
    cout<<"enter the source you want to search";
    cin>>source;
    topologicalsort* Node=new topologicalsort;
    for(int i=0;i<j;i++)
    {
        if((a[i]->head)->source==source)
        {
            cout<<"enter the destination ";
            temp=head;
            while((temp->next)!=NULL)
            {   temp=head;
                temp->next=Node;
                temp =Node;
                temp->destination=destination;

            }
            


        }
    }
}
void display()
{
    cout<<"enter the source you want to diaplay";
    cin>>source;
    for(int k=0;k<j;k++)
    {
        if(a[k]->source == source)
        {
            while(temp!=NULL)
            {
                cout<<source<<"----->"<<temp->destination;
            }

        }
    }
}
};
int main()
{
    topologicalsort obj;
    int operators;
    int l=0;
    while(l<5)
    {
        cout<<"enter the operator";
        cin>>operators;
        switch(operators)
        {
            case 1:
            obj.addsource();
            break;
            case 2:
            obj.createpath();
            break;
            case 3:
            obj.display();
            break;
        }
        l++;
    }
}
