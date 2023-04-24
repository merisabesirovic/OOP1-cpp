// Napraviti klasu niz za rad sa nizovima duzine n, atribudi klase ce biti 
// elementi - dinamicki niz u kome ce se cuvati elementi niza
//  i drugi atribut je broj elemenata n u koji cuva broj elemenata niza.napraviti podrazumevani konstruktor, zatim konstruktor broja
//   elemenata koji ucitava direktno sa ulaza elemente i copy konstruktor
#include <iostream>
using namespace std;
class Niz{
  int *niz;
  int n;  
  public:
    Niz(){
        cout<<"Unesite broj elemenata niza"<<endl;
        cin>>n;
        niz = new int[n];
        for(int i=0;i<n;i++){
            niz[i]=0;
        }
    }
    Niz(int n){
        this->n = n;
        niz = new int[n];
        cout<<"Unesite elemente niza"<<endl;
        for(int i=0;i<n;i++){
            cin>>niz[i];
        }
    }
    Niz(Niz const &objekat){
        this->n = objekat.n;
        this->niz = new int[objekat.n];
        for(int i=0;i<this->n;i++){
            this->niz[i]= objekat.niz[i];
        }
    }
    ~Niz(){
        delete [] niz;
    }
    void ispis(){
        for(int i=0;i<n;i++){
            cout<<" "<<niz[i];
        };
        cout<<endl;
    }
};
int main(){
    Niz n1;
    n1.ispis();
    Niz n2(5);
    n2.ispis();
    Niz n3(n2);
    n3.ispis();

}