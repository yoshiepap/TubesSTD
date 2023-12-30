#include "penulis.h"
#include "buku.h"

void createList(ListPenulis &L){
    first(L) = Nil;
}

adrP createNewPenulis(infoP x){
    adrP P = new elemenPenulis;
    info(P) = x;
    next(P) = Nil;
    firstR(P) = Nil;
    return P;
}

adrR createNewRelasi(string judul){
    adrR P = new relasi;
    infoR(P) = judul;
    nextR(P) = Nil;
    return P;
}

void addPenulis(ListPenulis &L, adrP P){
    adrP f = findPenulis(L, info(P).nama);
    if (f != Nil) {
        cout << "Penulis telah didaftarkan." << endl;
    } else {
        if (first(L) != Nil) {
            adrP Q = first(L);
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

void addRelasi(adrP P, adrR R){
    if (P != Nil) {
        adrR Q = firstR(P);
        if (Q != Nil) {
            while (nextR(Q) != Nil) {
                Q = nextR(Q);
            }
            nextR(Q) = R;
            nextR(R) = Nil;
        } else {
            firstR(P) = R;
            nextR(R) = Nil;
        }
    } else {
        firstR(P) = R;
        nextR(R) = Nil;
    }
}

void deletePenulis(ListPenulis &L, adrP P){
    adrP prec;
    if (P != Nil) {
        if (P == first(L)) {
            deleteFirstPenulis(L, P);
        } else if (next(P)== Nil) {
            deleteLastPenulis(L);
        } else {
            prec = first(L);
            while(next(prec) != P) {
                prec = next(prec);
            }
            deleteAfterPenulis(L, prec);
        }
    } else {
        cout << "List Kosong." << endl;
    }
}

void deleteFirstPenulis(ListPenulis &L, adrP &P){
    first(L) = next(P);
    next(P) = Nil;
}

void deleteLastPenulis(ListPenulis &L){
    adrP P = first(L);
    while (next(next(P)) != Nil) {
        P = next(P);
    }
    adrP Q = next(P);
    next(Q) = Nil;
    next(P) = Nil;
}

void deleteAfterPenulis(ListPenulis &L, adrP prec){
    adrP P = first(L);
    while (next(P) != Nil && info(P).nama != info(prec).nama) {
        P= next(P);
    }
    adrP Q = next(P);
    next(P) = next(Q);
    next(Q) = Nil;
}

void deleteRelasi(ListPenulis &L, adrR P){
    adrP Q;
    adrR R, prec;
    if (P != NULL) {
        Q = first(L);
        while (Q != NULL) {
            R = firstR(Q);
            while (R != NULL) {
                if (infoR(R) == infoR(P)) {
                    if (R == firstR(Q)) {
                        deleteFirstRelasi(L, R, Q);
                    } else if (nextR(R) == NULL) {
                        deleteLastRelasi(L, Q);
                    } else {
                        prec = firstR(Q);
                        while (infoR(nextR(prec)) != infoR(P)) {
                            prec = nextR(prec);
                        }
                        deleteAfterRelasi(prec, Q);
                    }
                }
                R = nextR(R);
            }
            Q = next(Q);
        }
    } else {
        cout<<"List kosong."<<endl;
    }
}

void deleteFirstRelasi(ListPenulis &L, adrR &P, adrP Q){
    firstR(Q) = nextR(P);
    nextR(P) = Nil;
}

void deleteLastRelasi(ListPenulis &L, adrP Q){
    adrR P = firstR(Q);
    while (nextR(nextR(P)) != Nil) {
        P = nextR(P);
    }
    adrR R = nextR(P);
    nextR(R) = Nil;
    nextR(P) = Nil;
}

void deleteAfterRelasi(adrR prec, adrP Q){
    adrR P = firstR(Q);
    while (nextR(P) != Nil && infoR(P) != infoR(prec)) {
        P = nextR(P);
    }
    adrR R = nextR(P);
    nextR(P) = nextR(R);
    nextR(R) = Nil;
}

adrR findRelasi(adrP P, string judul){
    if (firstR(P) != Nil) {
        adrR Q = firstR(P);
        do {
            if (infoR(Q) != judul) {
                Q = nextR(Q);
            } else {
                return Q;
            }
        } while (Q != Nil);
    } else {
        return Nil;
    }
}

adrP findPenulis(ListPenulis L, string nama){
    if(first(L) != Nil) {
        adrP P = first(L);
        do {
            if(info(P).nama != nama) {
                P = next(P);
            } else {
                return P;
            }
        } while (P != Nil);
    } else {
        return Nil;
    }
}

void relasikan(adrP P, adrR R) {
    if (P != Nil && R != Nil) {
        addRelasi(P, R);
    } else {
        cout << "Penulis tidak ditemukan." << endl;
    }
}

void showPenulis(ListPenulis L) {
    adrP P = first(L);
    int i = 0;
    cout << endl << "Penulis terdaftar: " << endl;
    if (first(L) != Nil) {
        while (P != Nil) {
            i++;
            cout << i << ". " <<"Nama : "<< info(P).nama << endl;
            cout << "   JK : " << info(P).jKel << endl;
            cout << "   Umur : " << info(P).umur << endl;
            cout << endl;
            P = next(P);
        }
    } else {
        cout << "Tidak ada penulis terdaftar." << endl;
    }
    cout << endl;
}
