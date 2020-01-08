
#include <iostream>
#include "Complex.h"
using namespace std;


int main() {
    Complex<double> c1(3.2, 4);
    Complex<double> c2(2.5, 1);

    cout << c1 << endl;
    cout << c2 << endl;

    cout << c1 + 2.0 << endl;
    cout << 3.0 + c2 << endl;

    cout << c1 + c2 << endl;
    cout << c1 - c2 << endl;

    cout << c1 << " " << conj(c1) << endl;
    cout << c2 << " " << conj(c2) << endl;
    return 0;
}