#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
};

Node *crnode(char data)
{
    Node *newnode = new Node{data, nullptr, nullptr};
    return newnode;
}

bool isop(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

Node *constructtree(string &prefix)
{
    stack<Node *> st;
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        Node *newnode = crnode(prefix[i]);
        if (isop(prefix[i]))
        {
            newnode->left = st.top();
            st.pop();
            newnode->right = st.top();
            st.pop();
        }

        st.push(newnode);
    }
    return st.top();
}

void postOrderTraversal(Node *root)
{
    if (!root)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void deleteTree(Node *root)
{
    if (!root)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    cout<<"Deleted Node :  "<<root->data<<endl;
    delete root;
}


int main()
{

    string prefixExpression;
    cout<<"Enter the Prefix Expression : ";
    cin>>prefixExpression;
    cout<<endl;
    Node *root = constructtree(prefixExpression);

    int choice;
    do
    {
        cout << "\n1. Traverse in post order\n2. Delete the tree\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Post Order Traversal: ";
            postOrderTraversal(root);
            cout << endl;
            break;

        case 2:
            deleteTree(root);
            cout << "\nOverall Tree deleted.\n";
            break;

        case 3:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 3);

    return 0;
}

