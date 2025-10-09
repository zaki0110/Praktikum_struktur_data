#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Masukkan jumlah elemen (N): ";
    cin >> N;

    int *arr = new int[N]; 

    cout << "\nMasukkan " << N << " bilangan bulat:\n";
    for (int i = 0; i < N; i++) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> *(arr + i); 
    }

    int jumlah = 0;
    int maks = *arr;
    int min = *arr;

    for (int i = 0; i < N; i++) {
        int nilai = *(arr + i);
        jumlah += nilai;

        if (nilai > maks) maks = nilai;
        if (nilai < min) min = nilai;
    }

    cout << "\n=== Hasil Perhitungan ===" << endl;
    cout << "Jumlah seluruh bilangan = " << jumlah << endl;
    cout << "Nilai maksimum          = " << maks << endl;
    cout << "Nilai minimum           = " << min << endl;

    return 0;
}
