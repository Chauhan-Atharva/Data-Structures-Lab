#include<iostream>
using namespace std; 
int main(){
    cout<<"enter no of elements in array"<<endl; 
    int n ; cin>>n; 
    int arr[n];
    // cout<<"Enter values into array"<<endl; 
    // for(int i =0; i<n; i++){
    //     cin>>arr[i];
    // }
    int size=0;
    int cc;
    do{
    cout<<"Choose 1: Push into array at end"<<endl; 
    cout<<"Choose 2: Insert into array at any position"<<endl; 
    cout<<"Choose 3: Delete any element from array"<<endl; 
    cout<<"choose 4: To print the array"<<endl; 
    int c; cin>>c;
    switch (c)
    {
    case 1:
        cout<<"Enter value to enter"<<endl; 
        int val; 
        cin>>val;
        arr[size] = val;
        size++;
        break;
    case 2:
        cout<<"Enter value to enter"<<endl; 
        int val1;
        cin>>val1;
        cout<<"Enter position"<<endl; 
        int pos; cin>>pos; 
        for(int i = pos; i<n; i++){
            arr[i+1] = arr[i];
        }
        arr[pos]= val1;
        size++;
        break;

    case 3:
        cout<<"Enter position to delete"<<endl; 
        int pos1;cin>>pos1; 
        for(int i = pos1; i<n-1; i++){
            arr[i] = arr[i+1];
        }
        size--;
        break;
    case 4:
        for(int i =0; i<size;i++){
            cout<<arr[i]<<" ";
        }
    default:
       cout<<"Wrong value entered"<<endl;
        break;
    }
    cout<<" 0 - not continue and 1 - yes continue"<<endl;
       cin>>cc; 
}while(cc==1);
}