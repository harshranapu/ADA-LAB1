#include<bits/stdc++.h>
#include<chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;
int * generate_input(int arr[], int k) {
    for (int j = 0; j < k; j++) {
        arr[j] = rand() % 100;
    }
    return arr;
}

int* selection_sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int j = i;
        for (int k = i + 1; k < n; k++) {
            if (arr[k] < arr[j]) {
                j = k;
            }
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    return arr;
}

int * merge_arr(int a[], int b[], int c[], int low_a, int low_b, int high_a, int high_b) {
    int i = 0;
    while (low_a <= high_a && low_b <= high_b) {
        if (a[low_a] < b[low_b]) {
            c[i] = a[low_a];
            low_a++;
        } else {
            c[i] = b[low_b];
            low_b++;
        }
        i++;
    }

    while (low_a <= high_a) {
        c[i] = a[low_a];
        low_a++;
        i++;
    }

    while (low_b <= high_b) {
        c[i] = b[low_b];
        low_b++;
        i++;
    }

    return c;
}

int main() {
    int *arr1 = new int[100000];
    int *arr2 = new int[100000];
    int *arr3 = new int[200000];
    arr1 = generate_input(arr1, 10);
    arr1 = selection_sort(arr1, 10);
    for (int i = 0; i < 10; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    arr2 = generate_input(arr2, 10);
    arr2 = selection_sort(arr2, 10);
    for (int i = 0; i < 10; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
 for(int i=1000;i<=10000 ;i=i+1000)
    {
    auto start = high_resolution_clock::now();
    for(int m =1;m<=10;m++)
    {
         arr3 = merge_arr(arr1, arr2, arr3, 0, 0, i, i);
    }
    auto stop = high_resolution_clock::now();
    auto duration = (duration_cast<nanoseconds>(stop-start))/10;
    cout << "inputs \t" << i    << "\t Time taken: " << duration.count() << "nanoseconds" << endl ;
    }

   /* for (int i = 0; i < 20; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;
*/
    return 0;
}
