#include<iostream>
#include<fstream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;

const int size = 50000;




void sorted_generator(int a[],int n){
 for(int i=0;i<n;i++){
    a[i]= i;
 } 
}

int sum(int arr[],int n){
    if(n==1)
    return arr[0];
    else
    return arr[n-1] + sum(arr,n-1);
}

int main(){
 //cout<<"done1"<<endl;
 int a[1000];
 fstream file;
 int avg_time =0;
 int total_time = 0;
 file.open("sum_of_array_result.txt",ios::out);
 //cout<<"done2"<<endl;
 for(int i=10; i<=1000;){
    sorted_generator(a,i);
    //cout<<"done4"<<endl;
    avg_time =0;
    total_time = 0;
    cout<<endl;
    for (int m=0;m<10;m++){
      //  cout<<"done5"<<endl;
    auto start = high_resolution_clock::now();
    int total = sum(a,i);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    //cout<<"sum is : "<<total<<endl;
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
}