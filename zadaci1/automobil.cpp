// **
//  * unutar metode adresa objekta koji je pozvao  je dostupna preko  kljucne reci this
//  * this- adresa ojekta koji je pozvao metodu
//  * *this-sam objekat
//  **/

/*
	Realizovati klasu Automobil sa javnim atributima rezervoar i potrosnja
	Metode: inicijalizacija(gorivo,potrosnja),predji(km) koja pokrece automobil i prelazi km kilometara, pri cemu se smanjuje nivo gorivo u zavinosti od potrosnje i predjenih km
	ispis() ispisuje podatke o Automobilu;adresa() ispisuje adresu objekta koji je pozvao ovu metodu
*/
#include <iostream>
using namespace std;
using std :: string;
class Automobil {
    public :
    int rezervoar;
    int potrosnja;
    void inicijalizacija(int r, int b){
        rezervoar = r;
        potrosnja = b;
    };
    void predji ( int km){
        rezervoar -= km* potrosnja;
    };
    void ispis(){
        cout<<"Trenutno stanje rezervoara "<<rezervoar<<" i potrosnja "<< potrosnja<<endl;
    };
    void adresa (){
        cout<<"Adresa objekta koji je pozvao ovu metodu"<<this;
    };
};
int main (){
    Automobil automobil1;
    automobil1.inicijalizacija(100, 7);
    automobil1.ispis();
    automobil1.predji(3);
    automobil1.ispis();
    automobil1.adresa();


}
