#include "Playlist.h"

int main() {
    Playlist playlist;
    int pilihan;
    string judul, penyanyi;
    float durasi;

    do {
        cout << "\n=== MENU PLAYLIST LAGU ===" << endl;
        cout << "1. Tambah lagu di awal playlist" << endl;
        cout << "2. Tambah lagu di akhir playlist" << endl;
        cout << "3. Tambah lagu setelah playlist ke-3" << endl;
        cout << "4. Hapus lagu berdasarkan judul" << endl;
        cout << "5. Tampilkan seluruh lagu" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
        case 1:
            cout << "Masukkan judul lagu: ";
            getline(cin, judul);
            cout << "Masukkan nama penyanyi: ";
            getline(cin, penyanyi);
            cout << "Masukkan durasi (menit): ";
            cin >> durasi;
            playlist.tambahDepan(judul, penyanyi, durasi);
            break;

        case 2:
            cout << "Masukkan judul lagu: ";
            getline(cin, judul);
            cout << "Masukkan nama penyanyi: ";
            getline(cin, penyanyi);
            cout << "Masukkan durasi (menit): ";
            cin >> durasi;
            playlist.tambahBelakang(judul, penyanyi, durasi);
            break;

        case 3:
            cout << "Masukkan judul lagu: ";
            getline(cin, judul);
            cout << "Masukkan nama penyanyi: ";
            getline(cin, penyanyi);
            cout << "Masukkan durasi (menit): ";
            cin >> durasi;
            playlist.tambahSetelahKe3(judul, penyanyi, durasi);
            break;

        case 4:
            cout << "Masukkan judul lagu yang ingin dihapus: ";
            getline(cin, judul);
            playlist.hapusLagu(judul);
            break;

        case 5:
            playlist.tampilkan();
            break;

        case 0:
            cout << "Keluar dari program." << endl;
            break;

        default:
            cout << "Pilihan tidak valid." << endl;
        }

    } while (pilihan != 0);

    return 0;
}
