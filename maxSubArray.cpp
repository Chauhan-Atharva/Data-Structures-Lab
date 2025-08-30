#include <iostream>
#include<climits>
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
    int maxSum = arr[0];
    int currSum =arr[0];
    int st =0, end = 0, tempStart = 0;
    for(int i =1; i<n; i++){
        if(currSum + arr[i] < arr[i]){
            currSum = arr[i];
            tempStart = i;
        }else{
            currSum += arr[i];
        }
        if(currSum>maxSum){
            maxSum = currSum;
            st = tempStart;
            end = i;
        }
    }
    cout<<"the maximum subarray sum = "<<maxSum<<endl;
    cout<<"the subarray is : "<<endl;
    for(int i =st; i <= end;i++){
        cout<<arr[i]<<endl; 
    }
}