#include <iostream>
using namespace std; 
class Node{
    public:
    int value; 
    Node* next; 
    public:
    Node(int val){
        value = val; 
        next = NULL;
    }
};
class Stack{
    Node* top ; 
    public:
    Stack(){
        top = NULL;
    }
    void push(int val){
        Node* newNode = new Node(val);
        newNode->next = top; 
        top = newNode;
        cout<<val<<" inserted into stack"<<endl;  
    }
    void pop(){
        if(top == NULL){
            cout<<"Stack underflow"<<endl; 
        }
        else{
        Node*temp = top; 
        cout<<top->value<<endl; 
        top = top->next;
        delete temp; 
        }
    }
    void peek(){
        if(top == NULL){
            cout<<"Stack is empty "<<endl; 
        }
        else{
            cout<<"top of stack: "<<top->value<<endl; 
        }
    }
    void traverse(){
        if(top == NULL){
            cout<<"Stack is empty"<<endl; 
        }
        Node* temp = top; 
        while(temp != NULL){
            cout<<temp->value<<endl; 
            temp = temp->next;
        } 
    }
};
int main(){
    Stack s;
    cout<<"s.push(1)"<<endl; s.push(1);
    cout<<"s.push(2)"<<endl; s.push(2);
    cout<<"s.push(3)"<<endl; s.push(3);
    cout<<"s.push(4)"<<endl; s.push(4);
    cout<<"s.pop()"<<endl; s.pop();
    cout<<"s.pop()"<<endl; s.pop();
    cout<<"s.pop()"<<endl; s.pop();
    cout<<"s.pop()"<<endl; s.pop();
    cout<<"s.pop()"<<endl; s.pop();
    cout<<"s.peek()"<<endl; s.peek();
    cout<<"s.push(15)"<<endl; s.push(15);
    cout<<"s.push(16)"<<endl; s.push(16);
    cout<<"s.push(17)"<<endl; s.push(17);
    cout<<"s.traverse()"<<endl; 
    s.traverse();
    return 0;   
}