#include<iostream>
#include<stack>
using namespace std;

class bst
{
public:
    bst* root = NULL;
    bst* head;
    string data;
    bst* left;
    bst* right;
    int x;

public:
    void creatroot(string data)
    {
        this->data = data;
        bst* node = new bst;
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        root = node;
        head = root;
    }

    void insertnode(string data)
    {
        this->data = data;
        if (data < root->data && root->left != NULL)
        {
            root = root->left;
            insertnode(data);
        }
        else if (data > root->data && root->right != NULL)
        {
            root = root->right;
            insertnode(data);
        }
        else if (data < root->data)
        {
            bst* Node = new bst;
            Node->data = data;
            root->left = Node;
            root = Node;
            root = head;
            cout << "Node successfully inserted";
        }
        else if (data > root->data)
        {
            bst* Node = new bst;
            Node->data = data;
            root->right = Node;
            root = Node;
            root = head;
            cout << "Node successfully inserted";
        }
    }

    void printInOrder()
    {
        stack<bst*> s;
        bst* current = this;

        while (current != nullptr || !s.empty())
        {
            while (current != nullptr)
            {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }
};

int main()
{
    bst obj;
    string data;
    int choice;
    cout << "Enter the data of the first root: ";
    cin >> data;
    obj.creatroot(data);

    while (true)
    {
        cout << "Enter the choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter the data: ";
                cin >> data;
                obj.insertnode(data);
                break;
            case 2:
                obj.printInOrder();
                break;
        }
    }

    return 0;
}
