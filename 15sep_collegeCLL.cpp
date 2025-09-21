#include <iostream>
using namespace std; 
class Node{
    public:
    string name;
    string loc; 
    int year; 
    Node* next; 
    public: 
    Node(string n, string l, int y){
        name = n; 
        loc =l; 
        year =y; 
        next = NULL; 
    }
};
class CollegeList{
    Node * last; 
    public: 
    CollegeList(){
        last = NULL;
    }
    void insertAtFront(string n, string l, int y){
        Node* newNode = new Node(n,l,y);
        if(last == NULL){
            last = newNode;
            last->next = last; 
        }
        else{
            newNode->next = last->next; 
            last->next = newNode; 
        }
    }
    void deleteAtEnd(){
        if(last == NULL){
            cout<<"Empty list can't delete"<<endl; 
        }
        else{
            if(last == last->next){
                delete last; 
                last = NULL; 
            }
            else{
            Node*temp = last->next;
            Node*prev = NULL;
            while(temp->next != last->next){
                prev = temp; 
                temp = temp->next;
            }
            prev->next = last->next; 
            temp->next = NULL; 
            delete temp; 
            last = prev; 
        }
        }
    }
    void Display(){
    Node* temp = last->next;
    // cout<<"Name: "<<temp->name<<" Location: "<<temp->loc<<" Year established: "<<temp->year<<endl; 
    do{
        cout<<"Name: "<<temp->name<<" Location: "<<temp->loc<<" Year established: "<<temp->year<<endl; 
        temp = temp->next;
     }while(temp != last->next);
    //  cout<<"Name: "<<temp->name<<" Location: "<<temp->loc<<" Year established: "<<temp->year<<endl; 
        
   }
};
int main(){
    CollegeList l1; 
    l1.insertAtFront("USICT", "Dwarka, Delhi", 1999);
    l1.insertAtFront("MAIT", "Rohini, New Delhi", 1999);
    cout<<"list: "<<endl; 
    l1.Display();
    cout<<"After inserting at front: "<<endl; 
    l1.insertAtFront("MSIT", "Rajouri Garden, Delhi", 2000);
    l1.Display();
    cout<<"After deleting at last: "<<endl; 
    l1.deleteAtEnd();
    l1.Display();
    return 0;
}
