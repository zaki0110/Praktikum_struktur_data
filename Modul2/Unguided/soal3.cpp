#include <iostream>
using namespace std;

float rata2(int nilai[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++)
        total += nilai[i];
    return (float)total / n;
}

void minMax(int nilai[], int n, int &min, int &max) {
    min = max = nilai[0];
    for (int i = 1; i < n; i++) {
        if (nilai[i] < min) min = nilai[i];
        if (nilai[i] > max) max = nilai[i];
    }
}

int main() {
    int n;
    cout << "Jumlah siswa: ";
    cin >> n;

    int nilai[n];
    for (int i = 0; i < n; i++) {
        cout << "Nilai ke-" << i + 1 << ": ";
        cin >> nilai[i];
    }

    int min, max;
    cout << "\nRata-rata: " << rata2(nilai, n);
    minMax(nilai, n, min, max);
    cout << "\nTertinggi: " << max;
    cout << "\nTerendah : " << min;

    return 0;
}