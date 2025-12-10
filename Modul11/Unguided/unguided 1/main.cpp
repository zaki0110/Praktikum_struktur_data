#include <iostream>
#include "multilist.h"
#include "multilist.cpp"

using namespace std;

int main() {
    listinduk L;
    CreateList(L);
    
    cout << "1. Membuat 3 elemen induk (10, 20, 30)...\n";
    address P1 = alokasi(10);
    address P2 = alokasi(20);
    address P3 = alokasi(30);
    
    insertLast(L, P1);
    insertLast(L, P2);
    insertLast(L, P3);
    
    cout << "2. Menambahkan anak ke induk 10...\n";
    address_anak A1 = alokasiAnak(11);
    address_anak A2 = alokasiAnak(12);
    address_anak A3 = alokasiAnak(13);
    
    insertLastAnak(P1->lanak, A1);
    insertLastAnak(P1->lanak, A2);
    insertLastAnak(P1->lanak, A3);
    
    cout << "3. Menambahkan anak ke induk 20...\n";
    address_anak A4 = alokasiAnak(21);
    address_anak A5 = alokasiAnak(22);
    
    insertLastAnak(P2->lanak, A4);
    insertLastAnak(P2->lanak, A5);
    
    cout << "\n=== MENAMPILKAN DATA ===\n";
    printInfo(L);
    
    cout << "\n=== INFORMASI ===\n";
    cout << "Jumlah induk: " << nbList(L) << endl;
    cout << "Jumlah anak induk 10: " << nbListAnak(P1->lanak) << endl;
    cout << "Jumlah anak induk 20: " << nbListAnak(P2->lanak) << endl;
    
    return 0;
}