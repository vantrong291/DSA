#include<iostream>

using namespace std;


int maxx(int a[], int n) {
    int maxx = a[0];
    for(int i = 0; i < n; i ++) {
        if(maxx < a[i]) maxx=a[i];
    }
    return maxx;
}
int maxIndex(int a[], int c[], int n, int maxx){
    int index = 0, k;

    for(int i = 0; i < n; i++) {
        if(a[i] == maxx) {
            k = i;
        }
    }
    for(int i = 0; i < n; i++) {
        if((a[index]<a[i] && a[i] < maxx && i < k) || ( a[index] == a[i] && c[index] > c[i] && a[i] < maxx && i < k)) {
            index = i;
        }
    }
    return index;
}
void  printArr(int a[], int n) {
    for(int i = 0; i < n; i ++) {
        cout << a[i] << " ";
    }
    cout << endl;
}


int main() {
    int n;
    cin >> n;
    int n2 = n;
    int arr[n];
    int arr1[n], c[n];
    arr1[n] = 1;
    int arr_max = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++) {
        arr_max = 0;
        for(int j = 0; j < i; j++) {
            if(arr[j] <= arr[i]){
                if(arr_max < arr1[j]) {
                    arr_max = arr1[j];
                }
            }
            //arr1[i] = arr_max + 1;
        }
        arr1[i] = arr_max + 1;
    }
    printArr(arr1, n);
    int max_i, max = maxx(arr1, n);
    int k = max - 1, h = k;
    //cout << "max " << max;
    max_i = maxIndex(arr1, arr, n, max+1);
    c[k] =  arr[max_i]; k = k-1;



    while(k >= 0){
        max_i = maxIndex(arr1, arr, n, max);
        c[k] = arr[max_i];
        max = arr1[max_i];
        k --;

    }
    printArr(c, h+1);
}
