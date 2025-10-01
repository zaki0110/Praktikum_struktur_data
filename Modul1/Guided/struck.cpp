#include <iostream>
using namespace std;

struct Mahasiswa
{
    string nama;
    string NIM;

};

int main()
{
    Mahasiswa mhs;
    mhs.nama = "zaki maula dhia";
    mhs.NIM = "103112400127";
    
    cout << "Nama: " << mhs.nama << endl
         << "NIM : " << mhs.NIM;
}