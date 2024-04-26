/*Graph traversal: The area around the college and the prominent
landmarks of it are represented using graphs.
Write a menu driven C++ program to represent this as a graph using
adjacency matrix /list and perform DFS and BFS.*/
#include<iostream>
using namespace std;
struct great{
    string poly,eng,pharma,grd;
};
class node
{
    private:
    string landmark;
    string destination;
    great  dest[50];
    node* next;
    node* head;
    node* temp=NULL;
    void getdata()
    {
        node* Node=new node;
        cout<<"enter the landmark";
         cin>>landmark;
         cout<<"enter the destination";
         cin>>destination;
         if(head=NULL)
         {
            head=Node;
            temp=head;
            temp->landmark=landmark;
            temp->destination=destination;
            temp->next=NULL;
         }
         else{
            temp->next=Node;
            temp=Node;
            temp->landmark=landmark;
            temp->destination=destination;
            temp->next=NULL;
         }
         if(temp->landmark="poly")
         {
            dest[i].poly=destination;
         }
         else if(Node->landmark="eng")
         {
            dest[i].eng=destination;
         }
    }



}