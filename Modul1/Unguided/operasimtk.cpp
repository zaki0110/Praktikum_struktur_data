#include <iostream>
using namespace std;
int main()
{

    float bilsatu;
    float bildua; 

    cout << "Masukan bilangan pertama : ";
    cin >> bilsatu;
    cout << "Masukan bilangan kedua : ";
    cin >> bildua;

    cout << "Penjumlahan kedua bilangan = " << bilsatu + bildua << endl;
    cout << "Pengurangan kedua bilangan = " << bilsatu - bildua << endl;
    cout << "Perkalian kedua bilangan = " << bilsatu * bildua << endl;

    if (bildua != 0){
        cout << "Pembagian kedua bilangan = " << bilsatu / bildua << endl;
    }
    else{
        cout << "Pembagian dengan nol tidak terdefinisikan" << endl;
    }

    
}