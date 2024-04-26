#include <iostream>
using namespace std;


class Graph_Traversal{

    public:
        string landmarks[100];
        string college[100][3];
        int adjacency_matrix[100][100];
        //Node *adjacency_list[100];
        int n, f;
        string src, des;
        int tt;
        bool validsrc=false;
        bool validdes=false;


        void add_landmarks(){
            cout<<"Enter Number of landmarks to be added: "<<endl;
            cin>>n;
            for(int i=0; i<n; i++){
            cout<<"Enter landmarks "<<(i+1)<<":"<<endl;
                cin>>landmarks[i];
                //adjacency_list[i] = NULL;
            }
            cout<<endl;
            cout<<"landmarks:"<<endl;
            for(int i=0; i<n; i++){
                cout<<landmarks[i]<<" ";
            }
            cout<<endl;
        }

        void add_college_routes(){
            cout<<"Enter Number of routes to be added: "<<endl;
            cin>>f;

            //for matrix
            for(int i=0; i<f; i++){
            bool valid=false;
                while(!valid){
                    cout<<"Enter Details for Routes "<<(i+1)<<": "<<endl;
                    cout<<"Enter Source :"<<endl;
                    cin>>college[i][0];
                    cout<<"Enter Destination :"<<endl;
                    cin>>college[i][1];
                    cout<<"Enter Distance:"<<endl;
                    cin>>college[i][2];

                    for(int k=0; k<n; k++){

                       if(college[i][0]==landmarks[k]){
                        validsrc=true;
                       }
                       if(college[i][1]==landmarks[k]){
                        validdes=true;
                       }

                    }
                    if(!validsrc || !validdes){
                        cout<<"Enter valid source and destination!"<<endl;
                        valid=false;
                    }
                    else{
                        valid=true;
                    }
                }
           }
            cout<<endl;
           
            cout<<"Source\tDestination\tDistance"<<endl;
            for(int i=0; i<f; i++){
                cout<<college[i][0]<<"\t\t"<<college[i][1]<<"\t\t"<<college[i][2]<<endl;    
            }
            cout<<endl;

           

        }

       

};

int main(){

    Graph_Traversal f1;
    int ch;
    do{
    cout<<"Menu..."<<endl;
    cout<<"1. Add Landmarks"<<endl;
    cout<<"2. Add Routes"<<endl;
    cout<<"Enter Your Choice: "<<endl;
    cin>>ch;
    switch(ch){
        case 1:
            f1.add_landmarks();
            cout<<endl<<endl;
            break;
        case 2:
            f1.add_college_routes();
            break;
        case 3:
           
            cout<<endl<<endl;
            break;
        case 4:
           
            cout<<endl<<endl;
            break;
        case 5:
           
            cout<<endl<<endl;
            break;
        default:
            cout<<"Invalid Choice!"<<endl;
    }
    }while(ch<=5);

return 0;
}