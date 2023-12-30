#ifndef BUKU_H_INCLUDED
#define BUKU_H_INCLUDED

#include <iostream>

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define nextR(P) P->nextR
#define Nil NULL

using namespace std;

typedef struct elemenBuku *adrB;

struct buku {
    string judul;
    string penerbit;
    int jmlHalaman;
};

typedef struct buku infoB;

struct elemenBuku {
    infoB info;
    adrB next;
};

struct ListBuku {
    adrB first;
};

void createList(ListBuku &L);
adrB createNewBuku(infoB x);
void addBuku(ListBuku &L, adrB P);
void deleteBuku(ListBuku &L, adrB P);
void deleteFirstBuku(ListBuku &L, adrB &P);
void deleteLastBuku(ListBuku &L);
void deleteAfterBuku(ListBuku &L, adrB prec);
adrB findBuku(ListBuku L, string judul);
void showBuku(ListBuku L);

#endif // BUKU_H_INCLUDED
