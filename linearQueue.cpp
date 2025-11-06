#include <iostream> 
using namespace std; 
class Node{
    public:
    int val; 
    Node* next; 
    public:
    Node(int data){
        val = data; 
        next = NULL;
    }  
};
class myQueue{
    public: 
    Node* front; 
    Node* rear; 
    public:
    myQueue(){
        front = NULL;
        rear = NULL;
    }
    void insert(int val){
        Node* newNode = new Node(val);
        if(front==NULL){
            front = newNode; 
            rear = front;
        }
        else{
             rear->next = newNode;
             rear = newNode; 

        }
    }
    void Delete(int data){
        if(front == NULL){
            cout<<"empty queue can't delete"<<endl; 
        }
        Node* temp = front->next; 
        Node* prev = front;
        while(temp != NULL){
            if(temp->val == data ){
                prev->next = temp->next; 
                temp->next = NULL;
                cout<<data<<" deleted "<<endl; 
                break; 
            }
        }
    }
    void display(){
        if(front == NULL){
            cout<<"empty queue"<<endl; 
        }
        Node* temp = front; 
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl; 
    }
};
int main(){
    myQueue m1; 
    m1.insert(12);
    m1.insert(13);
    m1.insert(81);
    m1.insert(79);
    m1.insert(120);
    cout<<"Before Deletion: "<<endl; 
    m1.display();
    m1.Delete(13);
    cout<<"After deletion: "<<endl; 
    m1.display();
    return 0; 
}