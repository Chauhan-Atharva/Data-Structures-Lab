#include <iostream>
using namespace std;
int s1, s2, top1, top2, n;
int * arr; 
void push1(int a){
        if(top1 < s1 ){
            arr[top1] = a;
            top1--;
        }
        else{
            cout<<"Stack overflow"<<endl; 
        }
    }
    void push2(int b){
        if(top2 >= s1 ){
            arr[top2] = b;
            top2--;
        }
        else{
            cout<<"Stack overflow"<<endl; 
        }
    }
    void pop1(){
        if(top1 == 0){
            cout<<"Stack underflow"<<endl; 
        }
        else{
            cout<<arr[top1--]<<endl; 
        }
    }
    void pop2(){
        if(top2 == n-1){
            cout<<"Stack underflow"<<endl; 
        }
        else{
            cout<<arr[top2--]<<endl; 
        }
    }
int main(){
    cout<<"size of 1st stack"<<endl;
    cin >>s1;
    cout<<"size of 2nd stack"<<endl; 
    cin>>s2;
    n = s1+s2;
    int * arr = new int[n];
    top1 = 0;
    top2 = n-1;
    
    
    cout<<"Stack 1: s1"<<endl; 
    cout<<"s1.push(2)"<<endl;push1(2);
    cout<<"s1.push(3)"<<endl;push1(3);
    cout<<"s1.push(4)"<<endl;push1(4);
    cout<<"s1.push(5)"<<endl;push1(5);
    cout<<"s1.push(6)"<<endl;
     push1(6);
    cout<<"s1.pop()"<<endl;
    pop1();
    cout<<"s1.pop()"<<endl; pop1();
    cout<<"s1.pop()"<<endl; pop1();
    cout<<"s1.pop()"<<endl; pop1();
    cout<<"s1.pop()"<<endl; pop1();
     cout<<"Stack 1: s2"<<endl; 
    cout<<"s2.push(2)"<<endl;push2(2);
    cout<<"s2.push(3)"<<endl;push2(3);
    cout<<"s2.push(4)"<<endl;push2(4);
    cout<<"s2.push(5)"<<endl;push2(5);
    cout<<"s2.push(6)"<<endl; push2(6);
    cout<<"s2.push(7)"<<endl; push2(7);
    cout<<"s2.pop()"<<endl; pop2();
    cout<<"s2.pop()"<<endl; pop2();
    cout<<"s2.pop()"<<endl; pop2();
    cout<<"s2.pop()"<<endl; pop2();
    cout<<"s2.pop()"<<endl; pop2();
    cout<<"s2.pop()"<<endl; pop2();

    return -1; 

}