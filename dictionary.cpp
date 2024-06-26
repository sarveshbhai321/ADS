#include<iostream>
#include<stack>
using namespace std;

class bst
{
public:
    bst* root = NULL;
    bst* head;
    string data;
    string value;
    bst* left;
    bst* right;
    int x;

public:
    void creatroot(string data,string value)
    {
        this->data = data;
        bst* node = new bst;
        node->data = data;
        node->value=value;
        node->left = NULL;
        node->right = NULL;
        root = node;
        head = root;
    }

    void insertnode(string data,string value)
    {
        this->data = data;
        if (data < root->data && root->left != NULL)
        {
            root = root->left;
            insertnode(data,value);
        }
        else if (data > root->data && root->right != NULL)
        {
            root = root->right;
            insertnode(data,value);
        }
        else if (data < root->data)
        {
            bst* Node = new bst;
            Node->data = data;
            Node->value = value;

            root->left = Node;
            root = Node;
            root = head;
            cout << "Node successfully inserted"<<endl;
        }
        else if (data > root->data)
        {
            bst* Node = new bst;
            Node->data = data;
            Node->value = value;
            root->right = Node;
            root = Node;
            root = head;
            cout << "Node successfully inserted"<<endl;
        }
    }

    void printInOrder()
    {
        cout<<"enter the data";
        cin>>data;
        stack<bst*> s;
        bst* current = head;

        while (current != nullptr || !s.empty())
        {
            while (current != nullptr)
            {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            if(current->data==data)
            {
            cout << current->data << " "<<"meaning  is"<<current->value;
            }
            current = current->right;
        }
    }
    void Tables()
    {

        stack<bst*> s1;
        bst* current = head;
        cout<<"data"<<"      "<<"meaning"<<endl;
        cout<<"-------------"<<endl;
        while (current != nullptr || !s1.empty())
        {
            while (current != nullptr)
            {
                s1.push(current);
                current = current->left;
            }
            current = s1.top();
            s1.pop();
            cout<<"|";
            cout << current->data << "      "<<current->value;
            cout<<endl;
            cout<<"|"<<"----------------------"<<"|"<<endl;
            current = current->right;
        }
    }
};

int main()
{
    bst obj;
    string data,value;
    int choice;
    cout << "Enter the data of the first root: ";
    cin >> data;
    cout << "Enter the value of the first root: ";
    cin >> value;
    obj.creatroot(data,value);

    while (true)
    {
        cout << "Enter the choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter the data: ";
                cin >> data;
                cout << "Enter the value: ";
                cin >> value;
                obj.insertnode(data,value);
                break;
            case 2:
            // for finding word
                obj.printInOrder();
                break;
            case 3:
            // for printing table 
                obj.Tables();
        }
    }

    return 0;
}
