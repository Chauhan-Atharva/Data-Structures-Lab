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
    bool found = false; 
    int st, end; 
    for(int i =0; i<n ;i++){
        int sum = 0;
        for(int j =i; j<n; j++){
            sum+= arr[j];
            if(sum ==0 ){
                found = true; 
                st = i; 
                end = j;
                break; 
            }
            if(found == true ){
            break;
            }
        }
    }
    if(found == true){
        cout<<"Subarray with sum 0 : "<<endl; 
        for(int i = st; i<end; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl; 
    }
    else{
        cout<<"Not found"<<endl;
    }
}