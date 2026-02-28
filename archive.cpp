#include <iostream>
#include <fstream>
#include <cstdlib>//for getenv
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
class Lists{    //class
    public:     //access identifier
        string l1,l2,l3,l4;
};//class

vector<Lists> TableData;
void load();void entry();void save();

string path=getenv("USERPROFILE"); 
string directory=path + "\\Desktop\\CL.csv";
fstream Database(directory);//create and read Database

int main(){   
    cout<<path;
    cout<<"\n\n!Tribune!\n\n";//Sounds nice. "trYYYBeeeeUUUUUUNNNe"
    while(true){
        fstream Database(directory);//create and read Database
        //select choice
        int choice;
        cout<<left<<setw(10)<<"[1] New Entry"<<setw(10)<<"[2] Save"<<endl;
        cout<<"Choice[Save before you close]: ";
        cin>>choice;
        if(!cin.fail()){
            /*cin.clear();
            cin.ignore();*solved wrong input. However no input works*/
            switch(choice){
                case 1:
                    entry();
                    break;
                case 2:
                    save();
                    break;
                default:
                    cout<<"Wrong choice!";
                    break;
            }//issue with switch where non integer causes breakdown. 
        }else{cin.clear();cin.ignore();}
        
        //cin.ignore();
        //Loads Database. If it is'nt Present, it creates new one
        if(!Database.is_open()){
            ofstream Database(directory);//Create Database
            cout<<"\nNo Database present. Creating new Database!\n";
        }
        cin.ignore();
    }
    
    return 0;
}

/*void load(){
        TableData.push_back(Dataread);
}*/
void entry(){
    Lists entry;//creating object
    cout<<"l1: ";cin >> entry.l1;
    cout<<"l2: ";cin >> entry.l2;
    cout<<"l3: ";cin >> entry.l3;
    cout<<"l4: ";cin >> entry.l4;
    TableData.push_back(entry);
    int ID=TableData.size()-1;
    cout<<entry.l1<<"\t\t"<<entry.l2<<"\t\t"<<entry.l3<<"\t\t"<<entry.l4<<endl;
    cout<<"ID: "<<ID<<endl;
}
void save(){
    for(const auto &row : TableData){
        Database<<left<<","<<row.l1<<","<<row.l2<<","<<row.l3<<","<<row.l4<<endl;
    }
    Database.close();
}