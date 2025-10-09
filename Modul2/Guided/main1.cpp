#include <iostream>
using namespace std;

int main(){
    int x, y;
    int *lx;
    x = 87;
    lx = &x;
    y = *lx;

    cout << "Alamat x   = " << &x << endl;
    cout << "Isi px     = " << lx << endl;
    cout << "Isi x      = " << x << endl;
    cout << "Nilai *px  = " << *lx << endl;
    cout << "Nilai y    = " << y << endl;

    return 0;
}