#include <iostream>
#include <string>
using namespace std;

struct great
{
    string a[15];
};

class landmarks
{
public:
    landmarks *land[10];
    string source;
    string location;
    landmarks *next;
    landmarks *temp1[10];
    int i = 0;

    // Function to add a new node
    void addnode()
    {
        cout << "enter the source: ";
        cin >> source;

        landmarks *Node = new landmarks;
        Node->source = source;
        land[i] = Node;
        i++;
    }

    // Function to create a path from source to destination
    void createpath()
    {
        cout << "enter the source you wanna find: ";
        cin >> source;
        cout << "enter the destination: ";
        cin >> location;

        landmarks *node = new landmarks;
        for (int j = 0; j < i; j++)
        {
            if (land[j]->source == source)
            {
                // Issue: This line creates a local pointer temp1[j] without initializing it.
                // You should use the existing temp1[j] array to store the new node.
                node->next = temp1[j];
                node->location = location;
                temp1[j] = node;
            }
        }
    }

    // Function to display paths from a given source
    void display()
    {
        cout << "enter the source you wanna search: ";
        cin >> source;

        for (int j = 0; j < i; j++)
        {  if(land[j]->source==source)
        {
            landmarks *temp = temp1[j];
            while (temp != NULL)
            {
                cout << "Source: " << source << " has a path to Location: " << temp->location << endl;
                temp = temp->next;
            }
        }
        }
    }
    void BFS()
    {
        for(int j=0;j<i;j++)
        {   landmarks *temp = temp1[j];
            while (temp != NULL)
            {
               
            }
            
        }
    }
};

int main()
{
    landmarks obj;
    int operators;
    int k = 0;

    while (k < 4)
    {
        cout << "enter the operator: ";
        cin >> operators;

        switch (operators)
        {
        case 1:
            obj.addnode();
            break;
        case 2:
            obj.createpath();
            break;
        }
        k++;
    }

    obj.display();

    return 0;
}
