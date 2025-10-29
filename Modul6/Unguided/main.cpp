#include "Doublylist.h"

int main() {
    List L;
    createList(L);


    for (int i = 0; i < 3; i++) {
        kendaraan k;
        cout << "Masukkan nomor polisi: ";
        getline(cin, k.nopol);
        cout << "Masukkan warna kendaraan: ";
        getline(cin, k.warna);
        cout << "Masukkan tahun kendaraan: ";
        cin >> k.thnBuat;
        cin.ignore();

        cout << endl;

        insertLast(L, alokasi(k));
    }

    cout << "\n=== DAFTAR KENDARAAN ===" << endl;
    printInfo(L);

    string cari;
    cout << "\nMasukkan Nomor Polisi yang dicari: ";
    getline(cin, cari);
    cout << endl;

    address hasil = findElm(L, cari);
    if (hasil != NULL) {
        cout << "Nomor Polisi : " << hasil->info.nopol << endl;
        cout << "Warna        : " << hasil->info.warna << endl;
        cout << "Tahun        : " << hasil->info.thnBuat << endl;
    } else {
        cout << "\nData dengan nomor polisi " << cari << " tidak ditemukan." << endl;
    }

    string hapus;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus: ";
    getline(cin, hapus);

    address target = findElm(L, hapus);
    address P;

    if (target != NULL) {
        if (target == L.first) {
            deleteFirst(L, P);
        } else if (target == L.last) {
            deleteLast(L, P);
        } else {
            deleteAfter(target->prev, P);
        }

        dealokasi(P);
        cout << "Data dengan nomor polisi " << hapus << " berhasil dihapus." << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    cout << "\n=== DAFTAR KENDARAAN ===" << endl;
    printInfo(L);
    return 0;
}
