#include "circularlist.h"

void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = P->prev = Nil;
    return P;
}

void dealokasi(address P) {
    delete P;
}

address createData(string nama, string nim, char jenis_kelamin, float ipk) {
    infotype x;
    x.nama = nama;
    x.nim = nim;
    x.jenis_kelamin = jenis_kelamin;
    x.ipk = ipk;
    return alokasi(x);
}

void insertFirst(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        P->next = P;
        P->prev = P;
    } else {
        address last = L.first->prev;
        P->next = L.first;
        P->prev = last;
        last->next = P;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        insertFirst(L, P);
    } else {
        address last = L.first->prev;
        P->next = L.first;
        P->prev = last;
        last->next = P;
        L.first->prev = P;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (Prec != Nil) {
        address Q = Prec->next;
        Prec->next = P;
        P->prev = Prec;
        P->next = Q;
        Q->prev = P;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
        return;
    }

    P = L.first;

    if (P->next == P) {
        L.first = Nil;
    } else {
        address last = L.first->prev;
        L.first = P->next;
        L.first->prev = last;
        last->next = L.first;
    }

    P->next = P->prev = Nil;
}

void deleteLast(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
        return;
    }

    address last = L.first->prev;

    if (last == L.first) {
        deleteFirst(L, P);
    } else {
        P = last;
        address before_last = last->prev;

        before_last->next = L.first;
        L.first->prev = before_last;

        P->next = P->prev = Nil;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec->next == L.first) {
        deleteFirst(L, P);
    } else {
        P = Prec->next;
        address Q = P->next;

        Prec->next = Q;
        Q->prev = Prec;

        P->next = P->prev = Nil;
    }
}

address findElm(List L, infotype x) {
    if (L.first == Nil) return Nil;

    address P = L.first;

    do {
        if (P->info.nim == x.nim) return P;
        P = P->next;
    } while (P != L.first);

    return Nil;
}

void printInfo(List L) {
    if (L.first == Nil) return;

    address P = L.first;

    do {
        cout << "Nama : " << P->info.nama << endl;
        cout << "NIM  : " << P->info.nim << endl;
        cout << "JK   : " << P->info.jenis_kelamin << endl;
        cout << "IPK  : " << P->info.ipk << endl << endl;
        P = P->next;
    } while (P != L.first);
}
