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
    cout<<"sorting staring "<<endl;
    for(int i =0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout<<"sorting done"<<endl;
    bool found = false; 
    int st = 0; int end = n-1; 
    int mid = (st+end)/2;
    while(st<=end){
        if(arr[mid]== key){
            cout<<"Found at "<<mid+1<<endl; 
            found = true; 
            break;
        }
        else if(arr[mid] > key){
            end = mid-1; 
        }
        else{
            st = mid+1;
        }
        mid = (st+end)/2;
    }
    if(found == false){
        cout<<"Not found"<<endl; 
    }
    return 0; 
}