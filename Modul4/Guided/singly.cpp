#include "singly.h"

void CreateList(List &L){
    L.First = Nil;
}

address alokasi(infotype x){
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address&P){
    delete P;
}

void insertFirst(List &L, address P){
    P->next = L.First;
    L.First = P;
}

void insertLast(List &L, address P){
    if (L.First == Nil)
    {
        insertFirst(L,P);
    } else {
        address Last = L.First;
        while (Last->next != Nil){
            Last = Last->next;
        }
        Last->next = P;
    }
}

void printInfo(List L){
    address P = L.First;
    if (P == Nil)
    {
        std::cout << "List Kosong!" << std::endl;
    } else{
        while (P != Nil){
            std::cout << P->info << " ";
            P = P->next;
        }
        std::cout << std::endl;
    }
}