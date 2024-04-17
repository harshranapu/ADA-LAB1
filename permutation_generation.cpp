#include<iostream>
#include<fstream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;


const int size = 10;
void char_generator(char a[],int n){
    for(int i=65;i<65+n;i++){
        a[i-65]=char(i);
    }
}

void swap(char &a ,char &b){
    char temp = a;
    a= b;
    b= temp;
}
void PG(char a[],int n , int k=0){
    if(k==n-1){
        for(int i=0;i<n;i++){
            cout<<a[i];
        }
        cout<<endl;
        return ;
    }
    else{
       for(int i=k;i<n;i++){
        swap(a[k],a[i]);
        PG(a,n,k+1);
        swap(a[k],a[i]);
       }
    }
}

int main(){
 //cout<<"done1"<<endl;
 char a[1000];
 fstream file;
 int avg_time =0;
 int total_time = 0;
 file.open("permutation_generation_result.txt",ios::out);
 for(int i=1;i<1000;i++){
    avg_time =0;
    total_time = 0;
    cout<<endl;
    char_generator(a,i);
    for (int m=0;m<10;m++){
    auto start = high_resolution_clock::now();
    PG(a,i);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    total_time +=duration.count();
    }
    avg_time = total_time/10;
    cout<<"avg time taken for size of array = "<<i<<" is "<<avg_time<<" microseconds"<<endl;
     file<<"("<<i<<","<<avg_time<<")"<<endl;
 }
 return 0;
}