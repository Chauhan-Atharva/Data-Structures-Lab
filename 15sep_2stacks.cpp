#include <iostream>
using namespace std; 
class TwoStacks{
    int *arr; 
    int top1 ; 
    int top2; 
    int s1, s2;
    public: 
    TwoStacks(int a,int b){
        s1 = a;
        s2 = b; 
        arr = new int[a+b];
        top1 = -1; 
        top2 = a+b; 
    }
    void push1(int val){
        // cout<<"s1-1 "<<s1-1<<endl; 
        // cout<<"top1 = "<<top1<<endl; 
        if(top1 < (s1-1) ){
            arr[++top1] = val; 
            cout<<val<<" inserted in stack 1"<<endl; 
            // top1 ++;
            // cout<<"top1 = "<<top1<<endl; 
        }
        else{
            cout<<"Stack 1 overflow"<<endl; 
        }
    }
    void push2(int val){
        if(top2 >= (s1+1)){
            arr[--top2] = val; 
            cout<<val<<" inserted in stack 2"<<endl; 
        }
        else{
            cout<<"Stack 2 overflow "<<endl; 
        }
    }
    void pop1(){
        if(top1 > -1){
            cout<<arr[top1]<<endl;
            top1--;
        }
        else{
            cout<<"Stack 1 underflow"<<endl; 
        }
    }
    void pop2(){
        if(top2 <= s1+s2-1){
            cout<<arr[top2]<<endl; 
            top2++;
        }
        else{
            cout<<"Stack 2 underflow "<<endl; 
        }
    }
};
int main(){
    TwoStacks s(3,4);
    cout<<"Pushing in stack 1: "<<endl ;
    s.push1(1);
    s.push1(2);
    s.push1(3);
    s.push1(4);
    cout<<"Pushing in stack 2: "<<endl; 
    s.push2(1);
    s.push2(2);
    s.push2(3);
    s.push2(4);
    s.push2(5);
    cout<<"Pop from stack 1: "<<endl; 
    s.pop1();
    s.pop1();
    s.pop1();
    s.pop1();
    cout<<"Pop from stack 2: "<<endl; 
    s.pop2();
    s.pop2();
    s.pop2();
    s.pop2();
    s.pop2();
    
    
}