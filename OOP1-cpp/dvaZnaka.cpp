 /**
//  * unutar metode adresa objekta koji je pozvao  je dostupna preko  kljucne reci this
//  * this- adresa ojekta koji je pozvao metodu
//  * *this-sam objekat
//  **/

// /*
// 	Reazlivati klasu DvaZnaka koja ima dva javna atributa koji su tipa karakteri
// 	Metode: inicijalizacija(z1,z2),uvecaj() koja uvecava znakove tj dobijamo sledece karaktere u ASCII tabeli;
// 	ispis() metoda koja ispisuje koji su trenutni znaci
// 	adresaoObjekta() ispisuje adresu objekta koji je pozvao
// */
#include <iostream>
using namespace std;
using std::string;
class DvaZnaka{
public:
char Z1;
char Z2;
void inicijalizacija(char z1, char z2){
    this->Z1 = z1;
    this->Z2 = z2;
};
void uvecaj(){
    this->Z1++;
    this->Z2++;
};
void ispis(){
    cout<<"Trenutni znaci"<<Z1<<Z2<<endl;
};
void adresaObjekta(){
    cout <<"Adresa objekta koji je pozvao metodu"<<this<<endl;
};
};
int main() {
    DvaZnaka znak1;
    znak1.inicijalizacija('c','2');
    znak1.ispis();
    znak1.uvecaj();
    znak1.ispis();
    znak1.adresaObjekta();
    DvaZnaka znak2;
     znak2.inicijalizacija('A','4');
    znak2.ispis();
    znak2.adresaObjekta();

}