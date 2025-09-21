#include <iostream>
using namespace std; 
class Node{
    public:
    string name; 
    int empid; 
    int salary; 
    Node * next; 
    Node * prev; 
    public: 
    Node(int id, int sal, string n){
        name = n; 
        empid = id; 
        salary = sal; 
        next = NULL; 
        prev = NULL;
    }
};
class EmployeeList{
    Node * start; 
    public:
    EmployeeList(){
        start = NULL; 
    }
    void push(string n, int id, int sal){
        Node *newNode = new Node(id, sal, n);
        if(start == NULL){
            start = newNode; 
        }
        else{
            Node* temp = start; 
            while(temp->next != NULL){
                temp = temp->next; 
            }
            temp->next = newNode;
            newNode->next = NULL;
            newNode->prev = temp; 
        }
    }
    void insertAtFront(string n, int id, int sal){
        Node* newNode = new Node(id,sal,n);
        start->prev = newNode; 
        newNode->next = start; 
        start = newNode; 
    }
    void DeleteAtEnd(){
        Node * temp = start; 
        while(temp->next != NULL){
            temp = temp->next; 
        }
        Node* prev = temp->prev; 
        temp->prev = NULL;
        prev->next = NULL;
    }
    void display(){
        Node* temp = start; 
        while(temp!=NULL){
            cout<<"Name: "<<temp->name<<" Id: "<<temp->empid<<" Salary: "<<temp->salary<<endl; 
            temp= temp->next; 
        }
    }
};
int main(){
    EmployeeList l1; 
    l1.push("Vishesh", 101,12000);
    l1.push("Arjun", 102, 15000);
    l1.push("Vijay", 103, 18000);
    cout<<"List: "<<endl; 
    l1.display();
    l1.insertAtFront("Sanjay", 100, 10000);
    cout<<"After inserting at front: "<<endl;
    l1.display();
    l1.DeleteAtEnd();
    cout<<"After deleting at end: "<<endl;  
    l1.display();
}