#include<iostream>
using namespace std;

class topologicalsort {
public:
    topologicalsort* a[15];
    string source;
    topologicalsort* next;
    topologicalsort* temp;
    topologicalsort* head;
    string destination;
    int j = 0;

    void addsource() {
        cout << "enter the source: ";
        topologicalsort* temp = new topologicalsort;
        cin >> temp->source;
        temp->next = NULL;
        a[j] = temp;
        head = a[j];
        j++;
    }

    void createpath() {
        cout << "enter the source you want to search: ";
        cin >> source;
        topologicalsort* Node = new topologicalsort;
        for (int i = 0; i < j; i++) {
            if ((a[i]->head)->source == source) {
                cout << "enter the destination: ";
                cin >> destination;
                temp = a[i]->head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = Node;
                Node->destination = destination;
                Node->next = NULL;
            }
        }
    }

    void display() {
        cout << "enter the source you want to display: ";
        cin >> source;
        for (int k = 0; k < j; k++) {
            if (a[k]->source == source) {
                temp = a[k]->head;
                while (temp != NULL) {
                    cout << source << " -----> " << temp->destination << endl;
                    temp = temp->next;
                }
            }
        }
    }
};

int main() {
    topologicalsort obj;
    int operators;
    int l = 0;
    while (l < 5) {
        cout << "enter the operator: ";
        cin >> operators;
        switch (operators) {
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
    return 0;
}
