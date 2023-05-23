// Realizovati klase proizvod,radnik i prodavnica.
// Klasa Proizvod ima barKod,cena,kolicina.
// Metode:Konstruktor sa i bez argumenata,ispis.
// Klasa Radnik ima ime,prezime.
// Metode:Konstruktor sa i bez argumenata,ispis.
// Klasa prodavnica nasledjuje klase radnik i proizvod
// i dodaje brRadnih sati i cenaPoSatu.
// Metode:Konstruktor sa i bez argumenata,ispis,plata,
// prodaj(int kolicina).
// U main funkciji napravite dva objekta klase prodavnica
// i testirati sve metode.
#include <iostream>
using namespace std;
using std::string;
class Proizvod{
protected:
int barKod;
int cena;
int kolicina;
public:
Proizvod(int barKod, int cena, int kolicina){
    this->barKod = barKod;
    this->cena = cena;
    this->kolicina = kolicina;
}
Proizvod(){
    barKod=0;
    cena=0;
    kolicina=0;
}
void ispis(){
    cout<<"Proizvod ima barKod,cena,kolicina"<<barKod<<" "<<cena<<" "<<kolicina<<endl;
}
};
class Radnik{
protected:
string ime;
string prezime;
Radnik(){
    ime = "Petar";
    prezime = "Petrovic";
}
Radnik (string im, string prezime){
    ime = im;
    this->prezime = prezime;
}
void ispis(){
    cout<<"Radnik "<<ime<<" "<<prezime<<endl;
}
};
class Prodavnica : public Proizvod, Radnik{
int brRadSati;
int cenaSata;
Prodavnica():Radnik(), Proizvod(){
    brRadSati = 0;
    cenaSata = 0;
}
Prodavnica(int brRadSati, int cenaSata, string im, string prezime, int barKod, int cena, int kolicina):Radnik(im, prezime ), Proizvod(barKod, cena , kolicina ){
brRadSati = brRadSati;
cenaSata = cenaSata;
ime = im;
}
void ispis(){
    Proizvod ::ispis();
    Radnik :: ispis();
    cout<<"Prodavnica "<<"ima"<<brRadSati<<" "<<"cena"<<cenaSata<<endl;
}
};