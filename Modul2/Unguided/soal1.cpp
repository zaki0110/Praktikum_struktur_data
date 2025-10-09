#include <iostream>
#include <string>
using namespace std;

int main() {
    string nama[5];
    float nilai[5][3];
    float rata[5];
    int tertinggi = 0;

    for (int i = 0; i < 5; i++) {
        cout << "\nMasukkan nama mahasiswa ke-" << i + 1 << ": ";
        cin >> ws;
        getline(cin, nama[i]);

        float total = 0;
        for (int j = 0; j < 3; j++) {
            cout << "Nilai mata kuliah ke-" << j + 1 << ": ";
            cin >> nilai[i][j];
            total += nilai[i][j];
        }
        rata[i] = total / 3;

        if (rata[i] > rata[tertinggi]) {
            tertinggi = i;
        }
    }

    cout << "\n=== Daftar Nilai Mahasiswa ===\n";
    for (int i = 0; i < 5; i++) {
        cout << nama[i] << ": ";
        for (int j = 0; j < 3; j++) {
            cout << nilai[i][j] << " ";
        }
        cout << " | Rata-rata = " << rata[i] << endl;
    }

    cout << "\nMahasiswa terbaik adalah: " << nama[tertinggi] << " dengan rata-rata " << rata[tertinggi] << endl;

    return 0;
}
