// Klasa poklon ima cena, jedinstven automatski generisani celobrojni identifikator. Svi atributi su zaštićeni od pristupa 
// (ne može im se pristupiti – znači da trebaju da budu private i da nemaju set i get metode). 
// Metode: konstruktor sa argumentima, kopi konstruktor, ispis() koja ispisuje id poklona i cenu u formatu “id(cena)”.
#include <iostream>
using namespace std;
class Poklon{
public:
static int posId;
private:
float cena;
int id;
public:
 Poklon(float c){
    cena = c;
    id=++posId;
 }
 Poklon(Poklon const &p){
    cena = p.cena;
    id = ++posId;
 }
 void ispis(){
    cout<<id<<"("<<cena<<")"<<endl;
 }
};
int Poklon::posId = 0; 
int main()
{
Poklon p1(500),p2(1500);
p1.ispis();
p2.ispis();
Poklon p3 = p1;
p3.ispis();
cout<<"Trenutno je stvoreno "<<Poklon::posId<<" objekata klase Poklon"<<endl;
return 0;
}
