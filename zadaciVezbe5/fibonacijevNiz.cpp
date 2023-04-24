// Realizovati klasu Fibonaci koja ima dva javna atributa
// n - ceo broj koji oznacava koliko elemenata Fibonacijevog
// niza zelimo da izracunamo i *niz - niz elemenata koji predstavljaju elemente Fibonacijevog niza. niz[0] = 1,niz[1] = 1...niz[i]=niz[i-1]+niz[i-2] Metode:
// Konstruktor sa i bez argumenata,Kopi konstruktor
// int suma() - metoda koja vraca sumu elemenata Fibonacijevog
// niza.
// int vrednost(int i) - metoda koja vraca vrednost i-tog elementa
// fibonacijevog niza (ako je moguce) 
// void prosiri(int x) - metoda koja prosiruje niz elemenata Fibonacievog
// niza za x novih elemenata.
// void ispis() - metoda koja ispisuje elemente Fibonacijevog niza
// Destruktor
#include <iostream>
using namespace std;
class Fibonaci{
    public:
    int n;
    int *niz;
    Fibonaci(){
        cout<<"Unesite broj elemenata"<<endl;
        cin>>n;
        niz = new int[n];
        niz[0]=1;
        niz[1]=1;
        for(int i=2; i<n; i++){
            niz[i]=niz[i-1]+niz[i-2];
        }
    }
    Fibonaci(int brojEl){
        n=brojEl;
        niz= new int[n];
        niz[0]=1;
        niz[1]=1;
        for(int i=2; i<n; i++){
            niz[i]=niz[i-1]+niz[i-2];
    }}
    Fibonaci(const Fibonaci &F){
        this->n = F.n;
        niz = new int[this->n];
        for(int i=0; i<this->n; i++){
            this->niz[i]=F.niz[i];
        }
    }
    int Suma(){
        int s=0;
        for(int i=0; i<n; i++)
            s += niz[i];
        return s;
    }
    int i(int itiEl){
        if(itiEl<=n){
            return niz[itiEl-1];
        }
    else return -1;}
    void prosiri(int x){
        int *pomocni;
        pomocni = new int[n];
        for(int i=0; i<n; i++){
            pomocni[i]=niz[i];
        }
        delete [] niz;
        n+=x;
        niz = new int[n];
        for(int i=0; i<n-x; i++){
            niz[i]=pomocni[i];
        }
        for(int i=n-x; i<n; i++){
            niz[i]=niz[i-1]+niz[i-2];
        }
    }
    void ispis(){
        for(int i=0; i<n; i++){
            cout<<" "<<niz[i];
        }
        cout<<endl;
    }
    ~Fibonaci(){
        delete [] niz;
    }
};
int main()
{
    Fibonaci f2(10);
    f2.ispis();
    cout<<f2.Suma()<<endl;
    f2.prosiri(10);
    f2.ispis();
    return 0;
}
