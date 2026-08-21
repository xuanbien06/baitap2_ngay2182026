#include <iostream>
using namespace std;

void hoanVi(int a[], int n, int step) {
    if (step == n) { 
        for (int i = 0; i < n; i++) cout << a[i];
        cout << endl;
        return;
    }
    for (int i = step; i < n; i++) {
        swap(a[step], a[i]);       
        hoanVi(a, n, step + 1);   
        swap(a[step], a[i]);       
    }
}

int main() {
    int a[] = {1, 2, 3};
    hoanVi(a, 3, 0); 
    return 0;
}