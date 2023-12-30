#include"Penulis.h"
#include"Buku.h"
#include"menu.h"

int main(){
    cout<<"---------------------------------------"<<endl;
    cout<<"-    This Program is engineered by    -"<<endl;
    cout<<"-        Dito Adistya Wirawan         -"<<endl;
    cout<<"-                and                  -"<<endl;
    cout<<"-         Yoshie Pranendya A          -"<<endl;
    cout<<"-      We're from class DS-46-03      -"<<endl;
    cout<<"---------------------------------------"<<endl;

    ListBuku LB;
    ListPenulis LP;

    createList(LP);
    createList(LB);

    menu(LP, LB);
}
