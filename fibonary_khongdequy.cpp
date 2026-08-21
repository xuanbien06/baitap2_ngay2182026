#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int f0 = 0, f1 = 1, fn = 0;

    cout << f0 << " " << f1 << " "; 
    for (int i = 2; i < n; i++) {
        fn = f0 + f1;        
        cout << fn << " ";   
        f0 = f1;             
        f1 = fn;             
    }
    return 0;
}