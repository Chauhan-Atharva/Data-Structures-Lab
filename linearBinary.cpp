#include <iostream>
using namespace std; 
int linearSearch(int arr[], int n, int key){
    for(int i = 0; i<n; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1; 
}
int binarySearch(int arr[], int n, int key){
    int st = 0; int end = n-1; int mid;
    while(st<=end){
        mid = st + (end-st)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            end = mid-1; 
        }
        else{
            st = mid+1; 
        }
    }
    return -1; 
}
int main(){
    cout<<"Enter no. of elements in the array: "<<endl; 
    int n; cin>>n; 
    int arr[n];
    cout<<"Enter elements in the array: "<<endl; 
    for(int i = 0  ; i<n ; i++){
        cout<<"arr["<<i<<"] = "; cin>>arr[i]; 
    }cout<<endl; 
    cout<<"Enter key to search: "<<endl; 
    int key; cin>>key; 
    cout<<"Using linear search, position = ";
    int ans = linearSearch(arr,n,key);
    (ans != -1)? cout<<ans : cout<<"Not found";
    cout<<endl;
    cout<<"Using binary search, position = ";
    ans = binarySearch(arr,n,key);
    (ans != -1)? cout<<ans : cout<<"Not found";
    cout<<endl; 
}
