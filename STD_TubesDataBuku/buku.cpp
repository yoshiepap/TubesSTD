#include "buku.h"

void createList(ListBuku &L) {
    first(L) = Nil;
}

adrB createNewBuku(infoB x) {
    adrB P = new elemenBuku;
    info(P) = x;
    next(P) = Nil;
    return P;
}

void addBuku(ListBuku &L, adrB P) {
    adrB f = findBuku(L, info(P).judul);
    if (f != Nil) {
        cout << "Buku telah ditammbahkan." << endl;
    } else {
        if (first(L) != Nil) {
            adrB Q = first(L);
            while(next(Q) != Nil) {
                Q = next(Q);
            }
            next(Q) = P;
            next(P) = Nil;
        } else {
            first(L) = P;
            next(P) = Nil;
        }
    }
}

void deleteBuku(ListBuku &L, adrB P){
    adrB prec;
    if (P != Nil) {
        if (P == first(L)) {
            deleteFirstBuku(L, P);
       } else if (next(P) == Nil) {
           deleteLastBuku(L);
       } else {
           prec = first(L);
           while (next(prec) != P) {
                prec = next(prec);
           }
           deleteAfterBuku(L, prec);
       }
    } else {
        cout << "List kosong." << endl;
    }
}

void deleteFirstBuku(ListBuku &L, adrB &P){
    first(L) = next(P);
    next(P) = Nil;
}

void deleteLastBuku(ListBuku &L){
    adrB P = first(L);
    while (next(next(P)) != Nil) {
        P = next(P);
    }
    adrB Q = next(P);
    next(Q) = Nil;
    next(P) = Nil;
}

void deleteAfterBuku(ListBuku &L, adrB prec){
    adrB P = first(L);
    while (next(P) != Nil && info(P).judul != info(prec).judul) {
        P = next(P);
    }
    adrB Q = next(P);
    next(P) = next(Q);
    next(Q) = Nil;
}

adrB findBuku(ListBuku L, string judul){
    if (first(L) != Nil) {
        adrB P = first(L);
        do {
            if (info(P).judul != judul) {
                P = next(P);
            } else {
                return P;
            }
        } while (P != Nil);
    } else {
        return Nil;
    }
}

void showBuku(ListBuku L){
    int i = 0;
    adrB P = first(L);
    cout << endl << "Buku Terdaftar:" << endl;
    if (first(L) != Nil) {
        while (P != Nil) {
            i++;
            cout << i << ". " <<"Judul  : "<< info(P).judul << endl;
            cout << "   Penerbit  : " << info(P).penerbit << endl;
            cout << "   Jumlah Halaman : " << info(P).jmlHalaman << endl;
            cout << endl;
            P = next(P);
        }
    } else {
        cout << "Tidak ada buku terdaftar." << endl;
    }
    cout << endl;
}
