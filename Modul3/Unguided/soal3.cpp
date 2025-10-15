#include <iostream>
using namespace std;

void tampil(int a[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void tukarArray(int (*x)[3], int (*y)[3], int i, int j) {
    int temp = x[i][j];
    x[i][j] = y[i][j];
    y[i][j] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int B[3][3] = {{9,8,7},{6,5,4},{3,2,1}};
    int (*pA)[3] = A, (*pB)[3] = B;

    cout << "Array A sebelum:\n"; tampil(A);
    cout << "Array B sebelum:\n"; tampil(B);

    tukarArray(pA, pB, 1, 2);

    cout << "\nSetelah tukar elemen [1][2]:\n";
    cout << "Array A:\n"; tampil(A);
    cout << "Array B:\n"; tampil(B);

    int x = 10, y = 20;
    int *px = &x, *py = &y;
    tukarPointer(px, py);

    cout << "\nSetelah tukar pointer:\n";
    cout << "x = " << x << ", y = " << y << endl;
}
