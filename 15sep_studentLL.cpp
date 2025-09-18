#include <iostream>
using namespace std; 
class Node{
    public:
    string name; 
    int roll_no; 
    float per; 
    Node* next; 
    public:
    Node(string n, int r, float p){
        name = n; 
        roll_no = r; 
        per = p ; 
        next = NULL; 
    }
};
class LinkedList{
    Node* start; 
    public: 
    LinkedList(){
        start = NULL;
    }
    void push(string n, int r, float p){
        Node* newNode = new Node(n, r, p);
        if(start == NULL){
            start = newNode; 
        }
        else{
            Node* temp = start;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void insert(int n, string name, int r, float p){
        Node* newNode = new Node(name,r,p);
        bool found = false; 
        if(n == 1){
            found = true; 
            Node* temp = start; 
            start = newNode;
            start->next = temp; 
        }
        else{
            Node*prev = start;
            Node * temp = start->next; 
            int i =2; 
            while(temp->next != NULL){
                if(n==i){
                    prev->next = newNode;
                    newNode->next = temp;
                    found = true; 
                    break;
                }
                i++;
                temp = temp->next;
                prev= prev->next;
            }  
        }
        if(found==true) cout<<"Inserted Node"<<endl; 
        else cout<<"Position not found"<<endl;
    }
    void Delete(int r){
        bool found = false; 
        if(start->roll_no == r){
            Node* temp = start; 
            start = start->next; 
            temp->next = NULL;
            delete temp; 
        }
        else{
            Node* prev = start; 
            Node* temp = start->next; 
            while(temp->next != NULL){
                if(temp->roll_no == r){
                    found = true; 
                    prev->next = temp->next;
                    temp->next = NULL; 
                    break; 
                }
                temp = temp->next;
                prev = prev->next;
            }
            if(found == true) cout<<r<<" roll no deleted"<<endl;
            else cout<<r<<" roll no not found"<<endl; 
        }
    }
    void reverse(){
        Node * temp = start; 
        Node* prev = NULL;
        Node* next = NULL; 
        while(temp != NULL ){
            next = temp->next;
            temp->next = prev; 
            prev = temp;
            temp = next; 
        }
        start = prev; 
    }
    void display(){
        Node * temp = start; 
        while(temp!= NULL){
            cout<<"Name: "<<temp->name<<" Roll no: "<<temp->roll_no<<" Percentage: "<<temp->per<<endl; 
            temp = temp->next;
        }
    }
};
int main(){
    LinkedList l1; 
    l1.push("Atharva", 81, 96);
    l1.push("Dev", 63, 96.6);
    l1.push("Nishant", 78, 92.4);
    l1.push("Harshit", 44, 90.6);
    l1.insert(3, "Rishabh", 68, 97.5);
    cout<<"After inserting: "<<endl; 
    l1.display();
    l1.Delete(78);
    cout<<"After deleting: "<<endl; 
    l1.display();
    cout<<"Reversing the linked list: "<<endl; 
    l1.reverse();
    l1.display();
    return 0; 
}
