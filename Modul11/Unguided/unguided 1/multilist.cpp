#include <iostream>
#include <cstdlib>
#include "multilist.h"

using namespace std;

boolean ListEmpty(listinduk L) {
    return (L.first == Nil && L.last == Nil);
}

boolean ListEmptyAnak(listanak L) {
    return (L.first == Nil && L.last == Nil);
}

void CreateList(listinduk &L) {
    L.first = Nil;
    L.last = Nil;
}

void CreateListAnak(listanak &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotypeinduk P) {
    address newElm = new elemen_list_induk;
    if (newElm != Nil) {
        newElm->info = P;
        CreateListAnak(newElm->lanak);
        newElm->next = Nil;
        newElm->prev = Nil;
    }
    return newElm;
}

address_anak alokasiAnak(infotypeanak P) {
    address_anak newElm = new elemen_list_anak;
    if (newElm != Nil) {
        newElm->info = P;
        newElm->next = Nil;
        newElm->prev = Nil;
    }
    return newElm;
}

void dealokasi(address P) {
    delete P;
}

void dealokasiAnak(address_anak P) {
    delete P;
}

address findElm(listinduk L, infotypeinduk X) {
    address P = L.first;
    while (P != Nil && P->info != X) {
        P = P->next;
    }
    return P;
}

address_anak findElm(listanak L, infotypeanak X) {
    address_anak P = L.first;
    while (P != Nil && P->info != X) {
        P = P->next;
    }
    return P;
}

boolean fFindElm(listinduk L, address P) {
    address temp = L.first;
    while (temp != Nil) {
        if (temp == P) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

boolean fFindElmanak(listanak L, address_anak P) {
    address_anak temp = L.first;
    while (temp != Nil) {
        if (temp == P) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

address findBefore(listinduk L, address P) {
    if (L.first == P) {
        return Nil;
    }
    return P->prev;
}

address_anak findBeforeAnak(listanak L, infotypeinduk X, address_anak P) {
    if (L.first == P) {
        return Nil;
    }
    return P->prev;
}

void insertFirst(listinduk &L, address P) {
    if (ListEmpty(L)) {
        L.first = P;
        L.last = P;
        P->next = Nil;
        P->prev = Nil;
    } else {
        P->next = L.first;
        P->prev = Nil;
        L.first->prev = P;
        L.first = P;
    }
}

void insertAfter(listinduk &L, address P, address Prec) {
    if (Prec != Nil) {
        P->next = Prec->next;
        P->prev = Prec;
        
        if (Prec->next != Nil) {
            Prec->next->prev = P;
        } else {
            L.last = P;
        }
        Prec->next = P;
    }
}

void insertLast(listinduk &L, address P) {
    if (ListEmpty(L)) {
        L.first = P;
        L.last = P;
        P->next = Nil;
        P->prev = Nil;
    } else {
        P->prev = L.last;
        P->next = Nil;
        L.last->next = P;
        L.last = P;
    }
}

void insertFirstAnak(listanak &L, address_anak P) {
    if (ListEmptyAnak(L)) {
        L.first = P;
        L.last = P;
        P->next = Nil;
        P->prev = Nil;
    } else {
        P->next = L.first;
        P->prev = Nil;
        L.first->prev = P;
        L.first = P;
    }
}

void insertAfterAnak(listanak &L, address_anak P, address_anak Prec) {
    if (Prec != Nil) {
        P->next = Prec->next;
        P->prev = Prec;
        
        if (Prec->next != Nil) {
            Prec->next->prev = P;
        } else {
            L.last = P;
        }
        Prec->next = P;
    }
}

void insertLastAnak(listanak &L, address_anak P) {
    if (ListEmptyAnak(L)) {
        L.first = P;
        L.last = P;
        P->next = Nil;
        P->prev = Nil;
    } else {
        P->prev = L.last;
        P->next = Nil;
        L.last->next = P;
        L.last = P;
    }
}

void delFirst(listinduk &L, address &P) {
    if (!ListEmpty(L)) {
        P = L.first;
        if (L.first == L.last) {
            L.first = Nil;
            L.last = Nil;
        } else {
            L.first = L.first->next;
            L.first->prev = Nil;
            P->next = Nil;
        }
    }
}

void delLast(listinduk &L, address &P) {
    if (!ListEmpty(L)) {
        P = L.last;
        if (L.first == L.last) {
            L.first = Nil;
            L.last = Nil;
        } else {
            L.last = L.last->prev;
            L.last->next = Nil;
            P->prev = Nil;
        }
    }
}

void delAfter(listinduk &L, address &P, address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        
        if (P->next != Nil) {
            P->next->prev = Prec;
        } else {
            L.last = Prec;
        }
        
        P->next = Nil;
        P->prev = Nil;
    }
}

void delP(listinduk &L, infotypeinduk X) {
    address P = findElm(L, X);
    if (P != Nil) {
        if (P == L.first) {
            address temp;
            delFirst(L, temp);
            dealokasi(temp);
        } else if (P == L.last) {
            address temp;
            delLast(L, temp);
            dealokasi(temp);
        } else {
            address Prec = P->prev;
            address temp;
            delAfter(L, temp, Prec);
            dealokasi(temp);
        }
    }
}

void delFirstAnak(listanak &L, address_anak &P) {
    if (!ListEmptyAnak(L)) {
        P = L.first;
        if (L.first == L.last) {
            L.first = Nil;
            L.last = Nil;
        } else {
            L.first = L.first->next;
            L.first->prev = Nil;
            P->next = Nil;
        }
    }
}

void delLastAnak(listanak &L, address_anak &P) {
    if (!ListEmptyAnak(L)) {
        P = L.last;
        if (L.first == L.last) {
            L.first = Nil;
            L.last = Nil;
        } else {
            L.last = L.last->prev;
            L.last->next = Nil;
            P->prev = Nil;
        }
    }
}

void delAfterAnak(listanak &L, address_anak &P, address_anak Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        
        if (P->next != Nil) {
            P->next->prev = Prec;
        } else {
            L.last = Prec;
        }
        
        P->next = Nil;
        P->prev = Nil;
    }
}

void delPAnak(listanak &L, infotypeanak X) {
    address_anak P = findElm(L, X);
    if (P != Nil) {
        if (P == L.first) {
            address_anak temp;
            delFirstAnak(L, temp);
            dealokasiAnak(temp);
        } else if (P == L.last) {
            address_anak temp;
            delLastAnak(L, temp);
            dealokasiAnak(temp);
        } else {
            address_anak Prec = P->prev;
            address_anak temp;
            delAfterAnak(L, temp, Prec);
            dealokasiAnak(temp);
        }
    }
}

void printInfo(listinduk L) {
    if (ListEmpty(L)) {
        cout << "List Induk Kosong" << endl;
    } else {
        address P = L.first;
        int no = 1;
        while (P != Nil) {
            cout << "Induk " << no << ": " << P->info << endl;
            if (!ListEmptyAnak(P->lanak)) {
                cout << "  Anak: ";
                printInfoAnak(P->lanak);
            } else {
                cout << "  Anak: (kosong)" << endl;
            }
            P = P->next;
            no++;
        }
    }
}

void printInfoAnak(listanak L) {
    if (!ListEmptyAnak(L)) {
        address_anak P = L.first;
        while (P != Nil) {
            cout << P->info;
            if (P->next != Nil) {
                cout << " <-> ";
            }
            P = P->next;
        }
        cout << endl;
    }
}

int nbList(listinduk L) {
    int count = 0;
    address P = L.first;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

int nbListAnak(listanak L) {
    int count = 0;
    address_anak P = L.first;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

void delAll(listinduk &L) {
    address P;
    while (!ListEmpty(L)) {
        address_anak PAnak;
        while (!ListEmptyAnak(L.first->lanak)) {
            delFirstAnak(L.first->lanak, PAnak);
            dealokasiAnak(PAnak);
        }
        delFirst(L, P);
        dealokasi(P);
    }
}