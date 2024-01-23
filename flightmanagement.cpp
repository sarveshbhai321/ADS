/*Flight management: There are flight paths between cities. If there is a
flight between city A and city B then there is an edge between the cities.
The cost of the edge can be the time that flight takes to reach city B from
A, or the amount of fuel used for the journey.
Write a menu driven C++ program to represent this as a graph using
adjacency matrix and adjacency list. The node can be represented by the
airport name or name of the city. Check whether cities are connected
through flight or not. Compare the storage representation.*/


#include<iostream>
using namespace std;
class node
{
    private:
    string source;
    string destination;
     node* head=NULL;
     node *next;
     string city[10];
     node *temp=NULL;
    string sources[10];
    int i=0;
    int l=0;
    string destination1[50];
    string src;
    string dst;
    string new1[50][50];
    public:

    void addnode()
    {
       node*Node=new node;
       cout<<"enter the source";
       cin>>source;
       cout<<"enter the destination";
       cin>>destination;
        if(head==NULL)
        {
            temp=Node;
            head=temp;
            temp->source=source;
            temp->destination=destination;
            temp->next=NULL;
           
        
            
        }
        else {
            temp->next=Node;
            temp=Node;
            temp->source=source;
            temp->destination=destination;
           

        }
        destination1[l]=destination;
        l++;
        
        
    }
    void check()
    {
    cout<<"enter the source";
    cin>>src;
    cout<<"enter the destination";
    cin>>dst;
    temp=head;
    while(temp!=NULL)
    {
    if(temp->source==src&&temp->destination==dst)
    {
		cout<<"there exists flight between"<<src<<dst<<endl;
		return;
		}
		
		temp=temp->next;
		}
	cout<<"there ios no flight";
		}
   /*void display()
    {
        node *temp =head;
        while(temp!=NULL)
        {
        cout<<"source is";
        cout<<temp->source<<endl;
        cout<<"destination is";
        cout<<temp->destination<<endl;
        temp=temp->next;
        }
        cout<<"flights to nashik are"<<endl;
        for(int j=0;j<=i;j++)
        {
            cout<<nashikdest[j];
        }
    }*/
        void adjacency()
        {  head=temp;
            while(temp!=NULL)
            {int i=0;
                for (int j=0;j<=l-1;j++)
                {
                    if(temp->destination==destination1[j])
                    {
                        new1[i][j]="1";
                    }
                    else{
                        new1[i][j]="0";
                    }

                }
                temp=temp->next;
                i++;
            }
       


    }
    void displayadj()
    {
        for(int i=0;i<=l;i++)
        {
            for(int j=0;j<=l;j++)
            {
                cout<<new1[i][j];
            }
            cout<<endl;
        }
    }
};
int main()
{
    int operators;
    node obj;
    while(true)
    {
    cout<<"enter the operators"<<endl;
    cin>>operators;
    switch(operators)
    {
        case 1:
        obj.addnode();
        break;
       /* case 2:
        obj.display();
        break;*/
        case 3:
        obj.check();
        break;
        case 4:
        obj.adjacency();
        break;
        case 5:
        obj.displayadj();
        break;

    }
    }
}
