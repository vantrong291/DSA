#include<iostream>
using namespace std;

int arrMax(int start, int end, int arr[]) {
    int max_index = arr[start]>=arr[end]?start:end;
    if(start == 0) {
         return arr[max_index];
    }
    else {
        int max_index = arr[start]>=arr[end]?start:end;
        return arrMax(start-1, max_index, arr);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int a = sizeof(arr)/4;
    cout << arrMax(n - 1, n - 1, arr);
}
