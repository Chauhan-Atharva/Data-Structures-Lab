#include <iostream>
using namespace std; 
int* arr = new int[100];
int k =0;
class Node{
    public:
    string type; 
    string company; 
    int y; 
    Node* left; 
    Node* right; 
    Node(string ty, string cm, int yr){
        type = ty; 
        company = cm; 
        y = yr; 
        left = right = NULL;
    }
};
class BinarySearchTree{
    public:
    Node* root; 
    BinarySearchTree(){
        root = NULL;
    }
    Node* insert(Node* root, int n, string ty, string cm){
        if(root == NULL){
            return new Node(ty,cm,n);
        }
        if(root->y > n){
            root->left =  insert(root->left,n, ty, cm);
        }
        else{
            root->right = insert(root->right, n,ty, cm);
        }
        return root; 
    }
    int inOrderSuccessor(Node* Root ){
        int i =0;
        for(; i< 100; i++){
            if(arr[i] == Root->y ){
                break;
            }
        }
        return arr[i-1];
    }
    Node* Delete(Node* root, int n){
        if(root == NULL){
            return root; 
        }
        if(root->y == n){
            if(root->left == NULL && root->right == NULL){
                delete root; 
                return NULL;
            }
            else if(root->left != NULL && root->right != NULL){
                int value = inOrderSuccessor(root);
                if(value == root->left->y){
                    root = root->left;
                }
                else {
                    root = root->right;
                }
                return root;
            }
            else{
                if(root->left != NULL){
                    root = root->left;
                    return root;
                }else{
                    root = root->right;
                    return root;
                }
            }
        }
        if(root->y > n){
            root->left = Delete(root->left,n);
        }
        else{
            root->right = Delete(root->right , n);
        }
        return root; 
    }
    void inOrder(Node* root){
        Node* temp = root;
        if(temp == NULL){
            return ; 
        }
        inOrder(temp->left);
        cout<<temp->y<<" "<<temp->company<<" "<<temp->type<<endl; arr[k] = temp->y;  k++;
        inOrder(temp->right);
    } 
    void preOrder(Node* root){
        if(root == NULL){
            return; 
        }
        cout<<root->y<<" "<<root->company<<" "<<root->type<<endl;
        preOrder(root->left);
        preOrder(root->right);
    }
    void postOrder(Node* root){
        if(root == NULL){
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->y<<" "<<root->company<<" "<<root->type<<endl;
    }  
};
int main(){
    BinarySearchTree B; 
    B.root = B.insert(B.root,2010,"car","maruti");
    B.root = B.insert(B.root,2012,"car","mahindra");
    B.root = B.insert(B.root,2015,"car","hyundai");
    B.root = B.insert(B.root,2018,"car","kia");
    cout<<"Inorder before deletion: "<<endl;
    B.inOrder(B.root);
    B.root = B.Delete(B.root,2012);
    cout<<"After deletion: "<<endl; 
    cout<<"Inorder : "<<endl; 
    B.inOrder(B.root);
    cout<<"Preorder: "<<endl; 
    B.preOrder(B.root);
    cout<<"Postorder: "<<endl; 
    B.postOrder(B.root);
    return 0; 
}