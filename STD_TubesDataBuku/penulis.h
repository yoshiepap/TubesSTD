#ifndef PENULIS_H_INCLUDED
#define PENULIS_H_INCLUDED

#include <iostream>
#define first(L) L.first
#define firstR(P) P->firstR
#define next(P) P->next
#define info(P) P->info
#define nextR(P) P->nextR
#define infoR(P) P->infoR
#define Nil NULL

using namespace std;


struct penulis {
    string nama;
    string jKel;
    int umur;
};

typedef struct elemenPenulis *adrP;
typedef struct relasi *adrR;

typedef penulis infoP;

struct elemenPenulis{
    infoP info;
    adrP next;
    adrR firstR;
};

struct ListPenulis{
    adrP first;
};

struct relasi{
    adrR nextR;
    string infoR;
};

void createList(ListPenulis &L);
adrP createNewPenulis(infoP x);
adrR createNewRelasi(string judul);
void addPenulis(ListPenulis &L, adrP P);
void addRelasi(adrP P, adrR R);
void deletePenulis(ListPenulis &L, adrP P);
void deleteFirstPenulis(ListPenulis &L, adrP &P);
void deleteLastPenulis(ListPenulis &L);
void deleteAfterPenulis(ListPenulis &L, adrP prec);
void deleteRelasi(ListPenulis &L, adrR P);
void deleteFirstRelasi(ListPenulis &L, adrR &P, adrP Q);
void deleteLastRelasi(ListPenulis &L, adrP Q);
void deleteAfterRelasi(adrR prec, adrP Q);
adrR findRelasi(adrP P, string judul);
adrP findPenulis(ListPenulis L, string nama);
void relasikan(adrP P, adrR R);
void showPenulis(ListPenulis L);
#endif // PENULIS_H_INCLUDED
