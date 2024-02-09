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
    landmarks *temp = NULL;
    landmarks *temp1[10];
    int i = 0;
    void addnode()
    {
        cout << "enter the source";
        cin >> source;
        landmarks *Node = new landmarks;
        Node->source = source;
        land[i] = Node;
        i++;
    }
    void createpath()
    {
        cout << "enter the source you wanna find";
        cin >> source;
        cout << "enter the destination";
        cin >> location;
        landmarks *node = new landmarks;
        for (int j = 0; j < i; j++)
        {
            if (land[j]->source == source)
            {
                landmarks *temp1[j];

                temp1[j]->next = node;
                node->location = location;
                temp1[j] = node;
            }
        }
    }
    void display()
    {
        cout << "enter the source you wanna search";
        cin >> source;
        for (int j = 0; j < i; j++)
        {
            cout << "the source is" << source << "it has path with" << temp1[j]->location;
        }
    }
};
int main()
{
    landmarks obj;
    int operators;
    int k = 0;
    while (k < 8)
    {
        cout << "enter the operator";
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
}
