#include <iostream>
using namespace std;

int main() {
    int a = 15, b = 10;
    while (b != 0) {
        int du = a % b; 
        a = b;          
        b = du;         
    }
    cout << a;
    return 0;
}