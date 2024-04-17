#include<iostream>
#include<fstream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;

const int size = 10000;

void random_generator(int a[],int n){
 for(int i=0;i<n;i++){
    a[i]= rand();
 } 
}

void selection_sort(int a[], int i){
   for (int j=0; j<i; j++){
    int t = j;
    int k;
    for (k=j+1; k<i;k++){
        if(a[t]>a[k]){
            t=k;
        }
    }
    int temp;
    temp=a[t];
    a[t]=a[j];
    a[j]= temp;
   }
}



int main(){
 int a[1000];
 fstream file;
 file.open("unsorted.txt",ios::out);
 for(int i=0; i<=1000; i +=500){
    int avg_time =0;
    int total_time = 0;
    random_generator(a,i);
    /*for(int j=0;j<i;j++){
        cout<<a[j]<<"\t";
    }
    cout<<endl;*/
    for (int m=0;m<10;m++){
    auto start = high_resolution_clock::now();
    selection_sort(a,i);
    auto stop = high_resolution_clock::now();
    /* for(int l=0;l<i;l++){
        cout<<a[l]<<"\t";
    }
    cout<<endl;*/
    auto duration = duration_cast<microseconds>(stop - start);
    total_time +=duration.count();
    //cout<<"time taken for size of array =  "<<i<<" in trail "<<m<<" is "<<duration.count()<<endl;
    }
    avg_time = total_time/10;
    cout<<"avg time taken for size of array = "<<i<<" is "<<avg_time<<" microseconds"<<endl;
     file<<"("<<i<<","<<avg_time<<")"<<endl;
 }
}