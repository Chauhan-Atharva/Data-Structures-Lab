#include <iostream>
using namespace std; 
class Node{
    public:
    int data; 
    Node * next; 
    public:
    Node(int val){
        data = val; 
        next = NULL;
    }
};
class linkedList{
    Node* start; 
    public: 
    linkedList(){
        start = NULL;
    }
    void push(int a){
        if(start == NULL){
          start = new Node(a);
        }
        else{
            Node* temp = start; 
            while(temp->next != NULL){
                temp = temp->next;
            }
            Node* New = new Node(a);
            temp->next = New; 
        }
    }
    void insert(int a, int i){
        if(i == 0){
            Node * newNode = new Node(a);
            start = newNode; 
        }
        int index = 1;
        Node* temp = start->next;
        Node * prev = start; 
        while(temp->next != NULL){ 
            if(index == i){
                Node * New = new Node(a);
                prev->next = New;
                New->next = temp;
            }
            temp = temp->next;
            index++;
        }
        if(index == i){
            Node * New = new Node(a);
            temp->next = New; 
        }
    }
    void Delete(int i){
        if(i==0){
            Node * temp = start;
            start = start->next;
            temp->next = NULL; 
        }
        else{
            Node* temp = start->next;
            int index = 1;
            Node *prev = start;
            while(temp->next != NULL){
                if(index == i){
                    prev->next = temp->next;
                    temp->next = NULL; 
                    break; 
                } 
                index++;
                prev = prev->next; 
                temp = temp->next;
            }
        }
    }
    void display(){
        Node * temp = start; 
        while (temp != NULL)
        {
           cout<<temp->data<<endl; 
           temp = temp->next;

        }
        
    }
};
int main(){
    linkedList l1;
    l1.push(1);
    l1.push(2);
    l1.push(3);
    l1.display();
    l1.insert(34,1);
    cout<<"after insertion"<<endl; 
    l1.display();
    l1.Delete(1);
    cout<<"after deletion"<<endl;
    l1.display();
}