#include<iostream>
#include "stack.cpp"
using namespace std;

void random_generator(int a[],int n){
 for(int i=0;i<n;i++){
    a[i]= rand()%100;
 } 
}

void print(float a[],int n){
    cout<<"done"<<endl;
    for(int i=0;i<n;i++){
            cout<<a[i]<<"\t";
        }
        cout<<endl;
    }

int partition(float arr[], int start, int end, float profit[], float weight[])
{
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    swap(profit[pivotIndex], profit[start]);
    swap(weight[pivotIndex], weight[start]);
    // Sorting left and right parts of the pivot element
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
            swap(profit[i++], profit[j--]);
            swap(weight[i++], weight[j--]);

        }
    }
    return pivotIndex;
}

void q_sort(float a[], int p, int q, float profit[], float weight[]){
    stack s1;
    while(1){
    while(p<q){
    int j = partition(a,p,q,profit,weight);
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
void knapsack(float p[],float w[], int n ,int maximumW,float x[], float &netP){
    int m = maximumW;
   float PW[n];
   for(int i=0;i<n;i++){
    PW[i] = p[i]/w[i];
   }
   print(PW,n);
   q_sort(PW,0,n-1,p,w);
   print(p,n);
   print(w,n);
   print(PW,n);
   for(int i=0;i<n;i++){
    x[i] = 0.0;
   }
   print(x,n);
   int j =0;
   for(j=n-1;j>=0;j--){
    if(w[j]<= m){
        x[j] = 1;
        m = m - w[j];
        netP += p[j];
    }
    else{
        break;
    }
    print(x,n);
}
if(j>0){
        x[j]= m/w[j];
        netP += p[j]*x[j];
    }
   
}

int main(){
    float profit_list[] = {5600,4560,3290,3400};
    float weight_list[] = {560,300,340,280};
    int n = 4;
    float x[n];
    float netP = 0;
    knapsack(profit_list,weight_list,n,10,x,netP);
    print(profit_list,n);
    print(weight_list,n);
    cout<<"ok"<<endl;
    print(x,n);
    cout<<netP<<endl;
return 0;
}