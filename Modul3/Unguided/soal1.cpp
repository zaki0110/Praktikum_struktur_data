#include <iostream>
#include <iomanip>
using namespace std;

struct Mahasiswa {
  string nama;
  string nim;
  float uts;
  float uas;
  float tugas;
  float nilaiakhir;
};

float hitung_nilai_akhir(float uts, float uas, float tugas){
  return (0.3*uts)+(0.4*uas)+(0.3*tugas);
}

int main(){
  Mahasiswa mhs[10];
  int n;

  cout << "Masukan jumlah Mahasiswa(maksimal 10): ";
  cin >> n;
  if (n>10) {
    cout << "Jumlah melebihi batas" << endl;
    return 0;
  }

  for (int i = 0; i < n; i++) {
    cout << "\nData Mahasiswa ke-" << i+1 << endl;
    cin.ignore();
    cout << "Nama : ";
    getline(cin, mhs[i].nama);
    cout << "NIM : ";
    getline(cin, mhs[i].nim);
    cout << "UTS : ";
    cin >> mhs[i].uts;
    cout << "UAS : ";
    cin >> mhs[i].uas;
    cout << "Tugas : ";
    cin >> mhs[i].tugas;

    mhs[i].nilaiakhir = hitung_nilai_akhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
  }

  for (int j = 0; j < n; j++) {
    cout << endl;
    cout << "Nama Mahasiswa : " << mhs[j].nama << endl;
    cout << "NIM : " << mhs[j].nim << endl;
    cout << "Nilai UTS : " << mhs[j].uts << endl;
    cout << "Nilai UAS : " << mhs[j].uas << endl;
    cout << "Nilai Tugas : " << mhs[j].tugas << endl;
    cout << "Nilai Akhir : " << mhs[j].nilaiakhir << endl;
  }

  return 0;
}
