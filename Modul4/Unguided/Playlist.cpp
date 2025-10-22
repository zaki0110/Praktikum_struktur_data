#include "Playlist.h"

Playlist::Playlist() {
    head = nullptr;
}

Playlist::~Playlist() {
    Lagu* current = head;
    while (current != nullptr) {
        Lagu* temp = current;
        current = current->next;
        delete temp;
    }
}

void Playlist::tambahDepan(string judul, string penyanyi, float durasi) {
    Lagu* laguBaru = new Lagu{judul, penyanyi, durasi, head};
    head = laguBaru;
}

void Playlist::tambahBelakang(string judul, string penyanyi, float durasi) {
    Lagu* laguBaru = new Lagu{judul, penyanyi, durasi, nullptr};
    if (head == nullptr) {
        head = laguBaru;
        return;
    }

    Lagu* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = laguBaru;
}

void Playlist::tambahSetelahKe3(string judul, string penyanyi, float durasi) {
    Lagu* laguBaru = new Lagu{judul, penyanyi, durasi, nullptr};
    Lagu* temp = head;

    int count = 1;
    while (temp != nullptr && count < 3) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Playlist kurang dari 3 lagu. Menambah di akhir." << endl;
        tambahBelakang(judul, penyanyi, durasi);
        delete laguBaru; // karena sudah dibuat baru di tambahBelakang
        return;
    }

    laguBaru->next = temp->next;
    temp->next = laguBaru;
}

void Playlist::hapusLagu(string judul) {
    if (head == nullptr) {
        cout << "Playlist kosong." << endl;
        return;
    }

    if (head->judul == judul) {
        Lagu* hapus = head;
        head = head->next;
        delete hapus;
        cout << "Lagu \"" << judul << "\" berhasil dihapus." << endl;
        return;
    }

    Lagu* temp = head;
    while (temp->next != nullptr && temp->next->judul != judul) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Lagu \"" << judul << "\" tidak ditemukan." << endl;
    } else {
        Lagu* hapus = temp->next;
        temp->next = temp->next->next;
        delete hapus;
        cout << "Lagu \"" << judul << "\" berhasil dihapus." << endl;
    }
}

void Playlist::tampilkan() {
    if (head == nullptr) {
        cout << "Playlist kosong." << endl;
        return;
    }

    Lagu* temp = head;
    int i = 1;
    cout << "\n=== Daftar Lagu dalam Playlist ===" << endl;
    while (temp != nullptr) {
        cout << i++ << ". Judul: " << temp->judul
             << " | Penyanyi: " << temp->penyanyi
             << " | Durasi: " << temp->durasi << " menit" << endl;
        temp = temp->next;
    }
    cout << "===================================" << endl;
}
