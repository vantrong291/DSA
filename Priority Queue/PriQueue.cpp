#include<iostream>
#include<fstream>
using namespace std;

void mySwap(int &a, int &b) {
    int  tmp;
    tmp = a;
    a = b;
    b = tmp;
}
void upheap(int a[], int index){
    if(index<2) return;
    else {
        if(index%2==0) {
            if(a[index] < a[(index)/2]){
                mySwap(a[index], a[index/2]);
            }
            upheap(a, index/2);
        }
        else {
            if(a[index] < a[(index-1)/2]){
                mySwap(a[index], a[(index-1)/2]);
            }
            upheap(a, (index-1)/2);
        }
    }
}
void downheap(int a[], int index, int n) {
    if(index > n/2) return;
    else {
        int k = 2*index;
        if(n%2==0) {
            if(a[n] < a[n/2]) {
                mySwap(a[n], a[n/2]);
            }
        }
        if(n>2) {
            int i = 2*index, j =2*index+1;
            if(a[i] <= a[j] && a[index] > a[i]) {
                mySwap(a[index], a[i]);
            }
            if(a[i] > a[j] && a[index] > a[j]) {
                mySwap(a[index], a[j]);
                k = k+1;
            }
        }
        downheap(a, k, n);
    }
}

void swapThree(int &a, int &b, int &c) {
    if(b <= c && a > b) {
        mySwap(a, b);
    }
    if(c < b && a > c) mySwap(a, c);
}
void Insert(int arr[], int& n, int v);
void InsertQ(int a[], int &n, int v) {
    a[n+1] = v; n++;
    upheap(a, n);
}
void print(int arr[], int n) {
    for(int i =1; i<= n; i++) {
        cout << arr[i] <<" ";
    }
    cout << "\n";
}
int removeMin(int arr[], int &n);
void priQueue(char* filename) {
    ifstream in;
    int tmp, n = 0; int *arr = new int[0];
    int i = 0;// int arr[n];
    in.open(filename);
    while(in >> tmp) {
        InsertQ(arr, n, tmp);
    }

    if(n!=0) {
        print(arr, n);
    }
    else cout << "File trong!!";

    InsertQ(arr,n,6);
    print(arr, n);
    removeMin(arr, n);
    print(arr, n);

}


int removeMin(int arr[], int &n) {
    if(n>=1) {
        int min = arr[1];
        arr[1] = arr[n];
        n--;
        downheap(arr, 1, n);
        return min;
    }
    else {
        cout << " Error!!" << "\n";
        return 0;
    }

}
int main() {
    priQueue("Pri.txt");
    //4 2 1 10 5 7 3 8
}
