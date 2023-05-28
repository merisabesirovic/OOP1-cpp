/*Primer u kom ćemo realizovati funkciju za unos elemenata niza,
 ispis elemenata i računjanje srednje vrednosti elemenata niza. 
 Tip elemenata nam nije poznat prema tome imali bismo 3 preklopljenje
  funkcije za unos, 3 za ispis i 3 za srednju vrednost tj ukupno 9 funkcija. 
  Umesto toga uptoerbnom šablona imaćemo samo 3 funkcije za bilo koji tip podataka.
*/
#include <iostream>
using namespace std;
template <typename T1>
void unos(T1*niz, int n){
    cout<<"Unesite elemente niza"<<endl;
    for(int i = 0; i < n; i++){
        cin>>niz[i];
    }

};
template <typename T1>
void ispis(T1*niz, int n){
for(int i = 0; i < n; i++){
    cout<<niz[i]<<" ";
}
cout<<endl;
};
template <typename T1>
float as(T1 *niz, int n){
    float s=0;
    for(int i = 0; i < n; i++){
        s+=niz[i];
    }
    return s/n;
}
int main(){
    int *niz=new int[5];
    int n=5;

    unos(niz, n);
    ispis(niz, n);
}

