/*A Dictionary using AVL: A Dictionary stores key and value pairs
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be
comparable, Keys must be unique.
Standard Operations: Insert(key, value), Find(key), Delete(key)
Write a menu driven C++ program to provide above standard operations
on dictionaries and provide a facility to display whole data sorted in
ascending/ Descending order. Also find how many maximum
comparisons may require for finding any keyword.
Use Height balanced tree(AVL) and find the complexity for finding a
keyword*/
#include <iostream>
using namespace std;

struct Node {
    int key;
    string value;
    Node* left;
    Node* right;
    int height;
};

class AVLTree {
private:
    Node* root;

    int height(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int getBalance(Node* node) {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    Node* insert(Node* node, int key, string value) {
        if (node == nullptr) {
            Node* newNode = new Node;
            newNode->key = key;
            newNode->value = value;
            newNode->left = nullptr;
            newNode->right = nullptr;
            newNode->height = 1;
            return newNode;
        }

        if (key < node->key)
            node->left = insert(node->left, key, value);
        else if (key > node->key)
            node->right = insert(node->right, key, value);
        else // Duplicate keys not allowed in dictionary
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && key < node->left->key)
            return rotateRight(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key)
            return rotateLeft(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* deleteNode(Node* root, int key) {
        if (root == nullptr)
            return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == nullptr || root->right == nullptr) {
                Node* temp = root->left ? root->left : root->right;

                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;

                delete temp;
            } else {
                Node* temp = minValueNode(root->right);
                root->key = temp->key;
                root->value = temp->value;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        if (root == nullptr)
            return root;

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root);

        // Left Left Case
        if (balance > 1 && getBalance(root->left) >= 0)
            return rotateRight(root);

        // Left Right Case
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        // Right Right Case
        if (balance < -1 && getBalance(root->right) <= 0)
            return rotateLeft(root);

        // Right Left Case
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    Node* search(Node* root, int key, int& comparisons) {
        if (root == nullptr || root->key == key) {
            comparisons++;
            return root;
        }

        comparisons++;
        if (root->key < key)
            return search(root->right, key, comparisons);
        else
            return search(root->left, key, comparisons);
    }

    void inorder(Node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->key << ": " << root->value << endl;
            inorder(root->right);
        }
    }

    void reverseInorder(Node* root) {
        if (root != nullptr) {
            reverseInorder(root->right);
            cout << root->key << ": " << root->value << endl;
            reverseInorder(root->left);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int key, string value) {
        root = insert(root, key, value);
    }

    void remove(int key) {
        root = deleteNode(root, key);
    }

    void find(int key) {
        int comparisons = 0;
        Node* result = search(root, key, comparisons);
        if (result != nullptr)
            cout << "Key: " << result->key << ", Value: " << result->value << endl;
        else
            cout << "Key not found." << endl;
        cout << "Number of comparisons: " << comparisons << endl;
    }

    void displayAscending() {
        inorder(root);
    }

    void displayDescending() {
        reverseInorder(root);
    }
};

int main() {
    AVLTree dictionary;
    int choice, key;
    string value;

    do {
        cout << "Menu:\n1. Insert\n2. Find\n3. Delete\n4. Display Ascending\n5. Display Descending\n6. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                dictionary.insert(key, value);
                break;
            case 2:
                cout << "Enter key to find: ";
                cin >> key;
                dictionary.find(key);
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                dictionary.remove(key);
                break;
            case 4:
                cout << "Dictionary in ascending order:\n";
                dictionary.displayAscending();
                break;
            case 5:
                cout << "Dictionary in descending order:\n";
                dictionary.displayDescending();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}