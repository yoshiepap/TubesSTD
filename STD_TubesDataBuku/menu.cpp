#include "buku.h"
#include "penulis.h"
#include "menu.h"

void AddAuthor(ListPenulis &LP, adrP P, ListBuku LB) {
   bool f = false;
   infoP elem1;
   cout << "-------------------------------------" << endl;
   cout << "         Menambahkan Penulis" << endl;
   cout << "-------------------------------------" << endl;
   while (!f) {
       cout << "Masukkan nama penulis: ";
       cin >> elem1.nama;
       if (elem1.nama == "stop") {
           f = true;
       } else {
           cout << "Masukkan jenis kelamin penulis: ";
            cin >> elem1.jKel;
            cout << "Masukkan umur penulis: ";
            cin >> elem1.umur;
            P = createNewPenulis(elem1);
           addPenulis(LP, P);
       }
   }
   showPenulis(LP);
   cout << "_____________________________________" << endl;
   menu(LP, LB);
}

void AddBook(ListBuku &LB, adrB B, ListPenulis LP){
    bool f = false;
    infoB elem1;
    cout << "-------------------------------------" << endl;
    cout << "          Menambahkan Buku" << endl;
    cout << "-------------------------------------" << endl;
    while (!f) {
        cout << "Masukkan judul buku: ";
        cin >> elem1.judul;
        if (elem1.judul == "stop") {
            f = true;
        } else {
            cout << "Masukkan penerbit buku: ";
            cin >> elem1.penerbit;
            cout << "Masukkan jumlah halaman: ";
            cin >> elem1.jmlHalaman;
            B = createNewBuku(elem1);
            addBuku(LB, B);
       }
   }
   showBuku(LB);
   cout << "_____________________________________" << endl;
   menu(LP, LB);
}

void Connect(ListPenulis &LP, ListBuku &LB){
    bool f = false;
    string nama, judul;
    cout<<"--------------------------------------"<<endl;
    cout<<"              Relasikan"<<endl;
    cout<<"--------------------------------------"<<endl;
    showPenulis(LP);
    showBuku(LB);
    cout << "Tulis nama penulis dan judul bukunya:" << endl;
    while (!f) {
        cout << "Nama penulis: ";
        cin >> nama;
        if (nama=="stop") {
            break;
        }
        adrP P = findPenulis(LP, nama);

        cout << "Judul buku: ";
        cin >> judul;
        adrB B = findBuku(LB, judul);

        if (P != NULL && B != NULL) {
            adrR f = findRelasi(P, info(B).judul);
            if (f != NULL) {
                cout<<"Gagal, penulis dan buku sudah berelasi."<<endl;
            } else {
                adrR R = createNewRelasi(judul);
                relasikan(P, R);
                cout<<"Berhasil merelasikan."<<endl;
            }
        } else if (P == NULL && B != NULL) {
            cout<<"Gagal, penulis tidak ada."<<endl;
        } else if (P != NULL && B == NULL) {
            cout<<"Gagal, buku tidak ada."<<endl;
        } else {
            cout<<"Gagal, data tidak valid."<<endl;
        }
        cout<<endl;
    }
    cout << endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LB);
}
void DeleteAuthor(ListPenulis &LP, ListBuku LB, adrP &P){
    string nama;
    cout<<"--------------------------------------"<<endl;
    cout<<"          Menghapus Penulis"<<endl;
    cout<<"--------------------------------------"<<endl;
    showPenulis(LP);
    if (first(LP) != NULL) {
        cout<<"Masukkan nama penulis: ";
        cin>>nama;
        if (nama != "stop") {
            P = findPenulis(LP, nama);
            if (P != NULL) {
                deletePenulis(LP, P);
                cout<<endl<<"Penulis yang bernama "<<nama<<" telah dihapus."<<endl;
                showPenulis(LP);
            } else {
                cout<<"Penulis tidak ditemukan."<<endl;
            }
        } else {
            cout<<endl;
            menu(LP, LB);
        }
    } else {
        cout<<"Tidak ada yang bisa dihapus."<<endl;
        cout<<endl;
        menu(LP, LB);
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LB);
}

void DeleteBook(ListPenulis &LP, ListBuku &LB, adrR &R, adrB &B){
    string judul;
    cout<<"--------------------------------------"<<endl;
    cout<<"            Menghapus Buku"<<endl;
    cout<<"--------------------------------------"<<endl;
    showBuku(LB);
    if (first(LB) != NULL) {
        cout<<"Masukkan judul buku: ";
        cin>>judul;
        if (judul != "stop") {
            adrB B = findBuku(LB, judul);
            if (B != NULL) {
                if(R == NULL) {
                    deleteBuku(LB, B);
                    cout<<"Buku yang berjudul "<<judul<<" telah dihapus."<<endl;
                } else {
                    string penulis;
                    cout << "Masukkan nama penulis: ";
                    cin >> penulis;
                    adrP P = findPenulis(LP, penulis);
                    adrR R = findRelasi(P,judul);
                    deleteRelasi(LP, R);
                    deleteBuku(LB, B);
                    cout<<"Buku yang berjudul "<<judul<<" telah dihapus."<<endl;
                }
                showBuku(LB);
            } else {
                cout<<"Buku tidak ditemukan."<<endl;
            }
        } else {
            cout<<endl;
            menu(LP, LB);
        }
    } else {
        cout<<"Tidak dapat menghapus buku."<<endl;
        cout<<endl;
        menu(LP, LB);
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LB);
}
void ShowBookAuthor(ListBuku LB, ListPenulis LP) {
    cout<<"--------------------------------------"<<endl;
    cout<<"    Data buku beserta penulisnya"<<endl;
    cout<<"--------------------------------------"<<endl;
    if (first(LP)==NULL && first(LB)==NULL) {
        cout<<"List kosong."<<endl;
    } else {
        adrB B = first(LB);
        if(B!=NULL) {
            while (B!=NULL) {
                bool f = false;
                cout<<"Buku berjudul "<<info(B).judul<<" ditulis oleh: "<<endl;
                adrP P = first(LP);
                if (P!=NULL) {
                    while (P!=NULL) {
                        adrR R = firstR(P);
                        while (R!=NULL) {
                            if (info(B).judul == infoR(R)) {
                                f = true;
                                cout<<"- "<< info(P).nama <<endl;
                            }
                            R=nextR(R);
                        }
                        P=next(P);
                    }
                    if (f = false) {
                        cout<<"Tidak diketahui."<<endl;
                    }
                    B=next(B);
                } else {
                    cout<<"Penulis tidak ditemukan."<<endl;
                }
            }
        } else {
            cout<<"Buku tidak ditemukan."<<endl;
        }
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LB);
}
void ShowBookAuthors(ListBuku LB, ListPenulis LP);

void ShowActiveAndInactiveWriters(ListPenulis LP, ListBuku LB) {
   cout<<"--------------------------------------"<<endl;
   cout<<" Penulis paling aktif dan tidak aktif"<<endl;
   cout<<"--------------------------------------"<<endl;
   if (first(LP)==NULL && first(LB)==NULL) {
       cout<<"List kosong."<<endl;
   } else {
       adrP P = first(LP);
       if (P!=NULL) {
           int Max = 0;
           int Min = INT_MAX;
           adrP activeWriter = NULL;
           adrP inactiveWriter = NULL;
           cout<<"Penulis yang paling aktif menulis adalah: "<<endl;
           while (P!=NULL) {
               int i = 0;
               adrR R = firstR(P);
               while (R!=NULL) {
                  i++;
                  R=nextR(R);
               }
               if (Max<i){
                  Max = i;
                  activeWriter = P;
               }
               if (Min > i){
                  Min = i;
                  inactiveWriter = P;
               }
               P=next(P);
           }
           cout << "Penulis Teraktif adalah " << info(activeWriter).nama << " dengan buku yang ditulis sebanyak " << Max << endl;
           cout << "Penulis Tidak Aktif adalah " << info(inactiveWriter).nama << " dengan buku yang ditulis sebanyak " << Min << endl;
       } else {
           cout<<"Tidak dapat menemukan penulis."<<endl;
       }
   }
   cout<<endl;
   cout<<"______________________________________"<<endl;
   menu(LP, LB);
}

void menu(ListPenulis &LP, ListBuku &LB){
    int x;

    adrP P;
    adrB B;
    adrR R;

    cout<<"Fitur Program: "<<endl;
	cout<<"1. Penambahan data penulis"<<"                          "<<"7.  Menampilkan data buku yang ditulis oleh penulis x"<<endl;
	cout<<"2. Penambahan data buku"<<"                             "<<"8.  Menampilkan data penulis dari buku x"<<endl;
	cout<<"3. Penentuan relasi"<<"                                 "<<"9.  Menampilkan penulis yang aktif dan tidak aktif"<<endl;
	cout<<"4. Menghapus data penulis"<<"                           "<<endl;
	cout<<"5. Menghapus data buku"<<"                              "<<endl;
	cout<<"6. Menampilkan data buku beserta penulisnya"<<"        "<<endl;

	cout<<endl;
	cout<<"Choose a feature: ";
	cin>>x;
    system("CLS");

	if (x == 1) {
        AddAuthor(LP, P, LB);
	} else if (x == 2) {
        AddBook(LB, B, LP);
	} else if (x == 3) {
        Connect(LP, LB);
	} else if (x == 4) {
        DeleteAuthor(LP, LB, P);
	} else if (x == 5) {
        DeleteBook(LP, LB, R, B);
	} else if (x == 6) {
        ShowBookAuthor(LB, LP);
	} else if (x == 7) {
        ShowBookAndAuthor(LB, LP);
	} else if (x == 8) {
        showAuthorBook(LP,LB);
	} else if (x == 9) {
        ShowActiveAndInactiveWriters(LP,LB);
	}
}
void showAuthorBook(ListPenulis LP, ListBuku LB){
    cout<<"--------------------------------------"<<endl;
    cout<<"       Menampilkan data penulis"<<endl;
    cout<<"--------------------------------------"<<endl;
    if (first(LP)==NULL && first(LB)==NULL) {
        cout<<"List kosong."<<endl;
    } else {
        string judulBuku;
        cout<<"Masukkan judul buku: ";
        cin>>judulBuku;
        adrB b = findBuku(LB, judulBuku);
         if (b!=NULL) {
             cout<<"Penulis dari buku "<< judulBuku <<" adalah: "<<endl;
             adrP p = first(LP);
             bool found = false;
             while (p != NULL && !found) {
                 adrR r = firstR(p);
                 while (r != NULL) {
                    if (infoR(r) == judulBuku) {
                        cout<<"Nama: "<<info(p).nama<<endl;
                        cout<<"Jenis Kelamin: "<<info(p).jKel<<endl;
                        cout<<"Umur: "<<info(p).umur<<endl;
                        found = true;
                        break;
                    }
                    r = nextR(r);
                 }
                 p = next(p);
             }
             if (!found) {
                 cout<<"Buku tidak dapat ditemukan."<<endl;
             }
         } else {
             cout<<"Buku tidak dapat ditemukan."<<endl;
         }
     }
 cout<<endl;
 cout<<"______________________________________"<<endl;
 menu(LP, LB);
}

void ShowBookAndAuthor(ListBuku LB, ListPenulis LP){
    cout<<"--------------------------------------"<<endl;
    cout<<" Menampilkan Seluruh Buku dan Penulis"<<endl;
    cout<<"--------------------------------------"<<endl;
    if (first(LP)==NULL && first(LB)==NULL) {
        cout<<"List kosong."<<endl;
    } else {
        string penulis;
        cout<<"Masukkan nama penulis: ";
        cin>>penulis;
        adrP p = findPenulis(LP, penulis);
        if (p!=NULL) {
            cout<<"Buku yang ditulis oleh "<<info(p).nama<<" adalah:"<<endl;
            adrR r = firstR(p);
            if (r!=NULL) {
                while (r!=NULL) {
                    cout<<"- "<<infoR(r)<<endl;
                    r=nextR(r);
                }
            } else {
                cout<<"Buku tidak dapat ditemukan."<<endl;
            }
        } else {
            cout<<"Penulis tidak dapat ditemukan."<<endl;
        }
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LB);
}
