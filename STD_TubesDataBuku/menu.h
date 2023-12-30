#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <conio.h>

void AddAuthor(ListPenulis &LP, adrP P, ListBuku LB);
void AddBook(ListBuku &LB, adrB B, ListPenulis LP);
void Connect(ListPenulis &LP, ListBuku &LB);
void DeleteAuthor(ListPenulis &LP, ListBuku LB, adrP &P);
void DeleteBook(ListPenulis &LP, ListBuku &LB, adrR &R, adrB &B);
void ShowBookAuthor(ListBuku LB, ListPenulis LP);
void ShowBookAuthors(ListBuku LB, ListPenulis LP);
void menu(ListPenulis &LP, ListBuku &LB);
void showAuthorBook(ListPenulis LP, ListBuku LB);
void ShowBookAndAuthor(ListBuku LB, ListPenulis LP);
void ShowActiveAndInactiveWriters(ListPenulis LP, ListBuku LB);

#endif // MENU_H_INCLUDED
