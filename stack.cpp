#include<iostream>
using namespace std ;
const int size = 20;
class stack {
    int data[1000];
    int top ;
    public :
    stack(){
        top =-1;
    }
    void push(int number){
        if(top >=1000){
            cout<<"stack overflow "<<endl;
            return ;
        }
        else{
            top++;
            data[top]=number ;
        }
}

int pop(){
    if(top<0){
        cout<<"stack is empty"<<endl;
        exit(0);
    }
    else{
        int value = data[top];
        top--;
        return value;
    }
}

void peek(){
    if(top<0){
        cout<<"stack is empty"<<endl;
        
    }
    else{
        cout<<data[top]<<endl;
    }
}

bool is_empty(){
    if(top<0)
    return true;
    else
    return false;
}
int stacksize(){
    return top+1;
}
};

void delete_mid(stack&s1){
    cout<<"size of stack is "<<s1.stacksize()<<endl;
     cout<<"done"<<endl;
    stack n;
    int end = s1.stacksize();
    int mid = (end+1)/2;
    for(int i=1;i<mid;i++){
         cout<<"done"<<endl;
        int temp;
        temp = s1.pop();
        n.push(temp);
    }
    s1.pop();
    int t = n.stacksize();
    cout<<"value of t "<<t<<endl;
    while(t!=0){
         cout<<"done"<<endl;
        int temp = n.pop();
        s1.push(temp);
        t--;
    }



}