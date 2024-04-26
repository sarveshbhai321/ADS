
#include<iostream>
using namespace std;

class Dictionary {
public:
    int key;
    string value;
    Dictionary* hashtable[10];
    Dictionary* head = nullptr;
    Dictionary* node = nullptr;
    int flag = 0;
    int hk;
    Dictionary* next = nullptr;

    void constants() {
        for (int i = 0; i < 10; i++) {
            hashtable[i] = nullptr; // Initialize hashtable elements to nullptr
            flag = 0; // Reset flag
        }
    }

    void getdata(int key, string value) {
        hk = key % 10;

        if (hashtable[hk] == nullptr) {
            hashtable[hk] = new Dictionary();
            hashtable[hk]->value = value;
            hashtable[hk]->key = key;
        } else {
            head = hashtable[hk];
            node = head;
            Dictionary* Node = new Dictionary();
            Node->value = value;
            Node->key = key;

            while (node->next != nullptr) {
                node = node->next;
            }

            node->next = Node;
        }
    }

    void printdata() {
        for (int i = 0; i < 10; i++) {
            if (hashtable[i] != nullptr) {
                cout << "Hash Key: " << i << endl;
                node = hashtable[i];

                while (node != nullptr) {
                    cout << "Key: " << node->key << ", Value: " << node->value << endl;
                    node = node->next;
                }
            }
        }
    }
};

int main() {
    Dictionary obj;
    obj.constants();
    int cases;
    
    int key;
    string value;
    while(true){
        cout<<"enter the case 1:to insert,2: to print ,3: to search";
    cin>>cases;
        switch(cases){
        case 1:
        cout<<"enter the key";
        cin>>key;
        cout<<"enter the value";
        cin>>value;
        obj.getdata(key,value);
        case 2:
        obj.printdata();
        
    }

    }
    
    return 0;
}
