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
    for(int i =0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    int sum =0;
    cout<<"The 5 largest elements in the array are: "<<endl;
    for(int i = n-1; i>n-6 ; i--){
        sum += arr[i];
        cout<<arr[i]<<" ";
    }
    cout<<endl; 
    cout<<"Sum = "<<sum<<endl; 
    return 0; 
}