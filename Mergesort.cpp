#include <bits/stdc++.h>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;
 
int* generate_input(int arr[], int k) {
   for (int j = 0; j < k; j++) {
       arr[j] = rand();
   }
   return arr;
}
 
int* merge_arr(int a[], int low, int mid, int high) {
   int *c = new int[100000];
   int i = low;
   int j = mid + 1;
   int k = low;
   while (i <= mid && j <= high) {
       if (a[i] < a[j]) {
           c[k] = a[i];
           i++;
       } else {
           c[k] = a[j];
           j++;
       }
       k++;
   }
   while (i <= mid) {
       c[k] = a[i];
       i++;
       k++;
   }
   while (j <= high) {
       c[k] = a[j];
       j++;
       k++;
   }
   for (int k = low; k <= high; k++) {
       a[k] = c[k];
   }
   delete[] c;
   return a;
}
 
int* ms(int a[], int low, int high) {
   if (low < high) {
       int mid = (low + high) / 2;
       ms(a, low, mid);
       ms(a, mid + 1, high);
       merge_arr(a, low, mid, high);
   }
   return a;
}
 
int main() {
   int* arr = new int[100000];
 
   for (int i = 10; i <= 10; i += 1000) {
       arr = generate_input(arr, i);
       auto start = high_resolution_clock::now();
       for (int m = 1; m < 10; m++) {
           arr = ms(arr, 0, i - 1);
           for (int j = 0; j < i; j++) {
               cout << arr[j] << " ";
           }
       }
       auto stop = high_resolution_clock::now();
       auto duration = duration_cast<nanoseconds>(stop - start) / 10;
       cout << "inputs \t" << i << "\t Time taken: " << duration.count() << "nanoseconds" << endl;
   }
   return 0;
}