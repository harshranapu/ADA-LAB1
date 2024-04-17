#include<iostream>
#include<fstream>
#include<cstdlib>
#include<chrono>
#include "stack.cpp"
using namespace std;
using namespace std::chrono;

//const int size = 100000;

void random_generator(int a[],int n){
 for(int i=0;i<n;i++){
    a[i]= random()%100;
 } 
}

void print(int a[],int n){
    cout<<"Generated Array"<<endl;
    for(int i=0;i<n;i++){
            cout<<a[i]<<"\t";
        }
        cout<<endl;
    }

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
   
    // Place pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);


    // Sort left and right parts of the pivot element
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void q_sort(int a[], int p, int q){
    stack s1;
    while(1){
    while(p<q){
    int j = partition(a,p,q);
    if((j-p)<(q-j)){
        s1.push(j+1);
        s1.push(q);
        q = j-1;
    }
    else{
        s1.push(p);
        s1.push(j);
        p = j+1;
    }
    }
    if(s1.is_empty()){
        return;
    }
    q = s1.pop();
    p = s1.pop();
    }
}

int main(){
 fstream file;
 file.open("merging.txt",ios::out);
 for(int i=10; i<=10;){
    int a[i];
    random_generator(a,i);
    print(a,i);
    int avg_time =0;
    int total_time = 0;
    for (int m=0;m<10;m++){
    auto start = high_resolution_clock::now();
    q_sort(a,0,i-1);
    auto stop = high_resolution_clock::now();
    cout<<"Corrected Sequence";
    auto duration = duration_cast<microseconds>(stop - start);
    total_time +=duration.count();
    }
    print(a,i);
    avg_time = total_time/10;
    cout<<"avg time taken for size of array = "<<i<<" is "<<avg_time<<" microseconds"<<endl;
     file<<i<<","<<avg_time<<endl;
       if(i<1000)
     i *=10;
     else if(i>=1000 && i<5000)
     i=5000;
     else
     i +=5000;
 }
}