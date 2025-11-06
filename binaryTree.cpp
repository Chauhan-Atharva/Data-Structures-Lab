#include <iostream>
using namespace std; 
class Node{
    public:
    int val; 
    Node* left; 
    Node* right; 
    Node(int data){
        val = data; 
        left = right = NULL;
    }
};
class BinaryTree{
    public:
    Node* root;
    void inOrder(Node* root){
        Node* temp = root;
        if(temp == NULL){
            return ; 
        }
         
        inOrder(temp->left);
        cout<<temp->val<<" ";
        inOrder(temp->right);
    } 
    void preOrder(Node* root){
        if(root == NULL){
            return; 
        }
        cout<<root->val<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
    void postOrder(Node* root){
        if(root == NULL){
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->val<<" ";
    }
};
int main(){
    BinaryTree b; 
    b.root = new Node(1);
    b.root->left = new Node(2);
    b.root->right = new Node(3);
    b.root->left->left = new Node(4);
    b.root->left->right = new Node(5);
    b.root->right->left = new Node(6);
    b.root->right->right = new Node(7);
    cout<<"Inorder traversal: "<<endl; 
    b.inOrder(b.root);cout<<endl; 
    cout<<"Preorder traversal: "<<endl;
    b.preOrder(b.root);cout<<endl; 
    cout<<"Postorder traversal: "<<endl;
    b.postOrder(b.root);
    cout<<endl; 
    return 0;  
}