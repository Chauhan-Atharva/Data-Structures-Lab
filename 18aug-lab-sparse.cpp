#include <iostream>
using namespace std;
int main(){
    int n =0 ;
    cout<<"Enter the no of rows in array "<<endl;
    int r; cin>>r; 
    cout<<"Enter the no of columns in array"<<endl;
    int c; cin>>c; 
    int sparse[1000][3];
    int input; 
    cout<<"enter elements rowwise in array"<<endl; 
    for(int i =0; i<r; i++){
        for(int j = 0 ; j<c; j++){
        cin>>input;
        if(input != 0){
            sparse[n][0] = input;
            sparse[n][1] = i;
            sparse[n][2] = j; 
            n++;
        }
      }
   }
   for(int i =0; i<n; i++){
    for(int j =0; j<3; j++){
        cout<<sparse[i][j]<<" ";
    }cout<<endl; 
   }
   cout<<"final Array: "<<endl; 
   for(int i = 0; i<r; i++){
    for(int j =0; j<c; j++){
        int ans =0;
        for(int a = 0; a<n; a++){
            if(sparse[a][1] == i && sparse[a][2] == j){
                ans = sparse[a][0];
                break; 
            }
        }
        cout<<" "<<ans<<" ";
    }cout<<endl; 
   }
}