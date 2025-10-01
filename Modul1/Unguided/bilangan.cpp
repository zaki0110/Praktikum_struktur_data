#include <iostream>
using namespace std;


int main() {
    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "empat belas", "lima belas", "enam belas", "tuuh belas", "delapan belas", "sembilan belas"};
    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh","lima puluh", "enam puluh", "tujuh puluh","delapan puluh", "sembilan puluh"};

    int angka;
    cout << "Masukan angka : ";
    cin >> angka;

    if (angka<10)
    {
        cout << satuan[angka];
    }
    else if (angka < 20){
        cout << belasan[angka-10];
    }
    else if (angka < 100){
        int p = angka / 10;
        int s = angka % 10;
        cout << puluhan[p];
        if (s != 0) cout << " " << satuan[s];
    }
    
}