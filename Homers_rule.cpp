#include<iostream>
#include<fstream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;

//link for graph - https://www.desmos.com/calculator/ofvz3nfodz

const int size = 100000;
void random_generator(int a[],int n){
 for(int i=0;i<n;i++){
    a[i]= rand();
    cout<<a[i]<<endl;
 } 
}

int horner_rule(int a[],int n , int k,int x){
    if(k==n-1){
        return a[k] ;
    }
    else{
       return a[k] + (x*(horner_rule(a,n,k+1,x)));
       }
}

int main(){
 //cout<<"done1"<<endl;
 int a[10000];
 fstream file;
 int avg_time =0;
 int total_time = 0;

 file.open("horner_rule_result.txt",ios::out);
 for(int i=10;i<=10000;){
    avg_time =0;
    total_time = 0;
    int k = 0;
    int x =1;
    cout<<endl;
    random_generator(a,i);
    
    for (int m=0;m<10;m++){
    auto start = high_resolution_clock::now();
    int h = horner_rule(a,i,k,x);
    cout<<h<<endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    total_time +=duration.count();
    }
    avg_time = total_time/10;
    cout<<"avg time taken for size of array = "<<i<<" is "<<avg_time<<" microseconds"<<endl;
     file<<"("<<i<<","<<avg_time<<")"<<endl;
       if(i<1000)
     i *=10;
     else if(i>=1000 && i<5000)
     i=5000;
     else
     i +=5000;
 }
 return 0;
}