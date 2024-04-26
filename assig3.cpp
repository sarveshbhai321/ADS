#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class AOVNetwork
{
	private:
    int n;
    vector<int> inDegree;
    vector<vector<int>> adjList;
    vector<int> order;

	public:
    AOVNetwork(int numDuties) : n(numDuties), inDegree(numDuties, 0), adjList(numDuties) {}

    void addDependency(int dependent, int dependency)
    {
        adjList[dependency].push_back(dependent);
        inDegree[dependent]++;
    }

    bool canSolveDuties() 
    {
        queue<int> q;
        for (int i = 0; i < n; ++i) 
        {
            if (inDegree[i] == 0) 
            {
                q.push(i);
            }
        }

        while (!q.empty()) 
        {
            int current = q.front();
            q.pop();
            order.push_back(current);

            for (int neighbor : adjList[current]) 
            {
                if (--inDegree[neighbor] == 0) 
                {
                    q.push(neighbor);
                }
            }
        }
        return order.size() == n;
    }

    void printOrder() 
    {
        if (canSolveDuties()) 
        {
            cout << "Sandy can solve all his duties. The correct order is:\n";
            for (int duty : order) 
            {
                cout << duty + 1 << " ";
            }
            cout << endl;
        } else 
        {
            cout << "Sandy cannot solve all his duties due to dependencies.\n";
        }
    }
};

int main() 
{
    int numDuties;
    cout << "Enter the number of duties: ";
    cin >> numDuties;

    AOVNetwork aov(numDuties);

    int choice, dependent, dependency;
    do 
    {
        cout << "Menu:\n";
        cout << "1. Add dependency\n";
        cout << "2. Check if Sandy can solve all duties and print order\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter dependent duty: ";
                cin >> dependent;
                cout << "Enter dependency duty: ";
                cin >> dependency;
                aov.addDependency(dependent - 1, dependency - 1);
                break;

            case 2:
                aov.printOrder();
                break;

            case 3:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } 
    while (choice != 3);
    return 0;
}

