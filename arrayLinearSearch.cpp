#include <iostream>
using namespace std;
int main(){
    int n; 
    cout<<"Input size of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter elements in the array"<<endl; 
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter the element to search: "<<endl; 
    int key; cin>>key;
    bool found = false; 
    int i =0;
    for(; i<n; i++){
        if(arr[i] == key){
            found = true; 
            break;
        }
    }
    if(found == false){
        cout<<"Not found"<<endl; 
    }else
    {
        cout<<"Found at: "<<(i+1)<<endl;
    }
    
    return 0; 
}