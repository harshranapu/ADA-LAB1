#include<iostream>
#include<fstream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;

const int size = 100000;
void random_generator(int a[],int n){
 for(int i=0;i<n;i++){
    a[i]= rand()%1000;
 } 
}

void power(int base, int exponent){
    float res = 1;
    for(int i=1;i<=exponent;i++){
       res *= base;
    }
    cout<<"result is : "<<res<<endl;
}

int main(){
 fstream file;
 file.open("power_ite.txt",ios::out);
 for(int i=10; i<=1000;){
    int avg_time =0;
    int total_time = 0;
    for (int m=0;m<10;m++){
    auto start = high_resolution_clock::now();
    power(2,i);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    total_time +=duration.count();
    }
    avg_time = total_time/10;
    cout<<"avg time taken for size of array = "<<i<<" is "<<avg_time<<" microseconds"<<endl;
     file<<i<<"   "<<avg_time<<endl;
     if(i<1000)
     i *=10;
     else if(i>=1000 && i<5000)
     i=5000;
     else
     i +=5000;
 }
}