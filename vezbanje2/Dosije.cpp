// Realizovati klase Dosije,Predmet i Ispit.
// Klasa dosije ima sledece zasticene atribute:
// ime,prezime,index
// Metode:Konstruktor sa i bez argumenata,predstaviSe()
// Klasa Predmet ima sledece zasticene atribute:
// imeProfesora,prezimeProfesora,nazivPredmeta
// Metode:Konstruktor sa i bez argumenata,opisPredmeta()
// Klasa Ispit nasledjuje zasticeno Dosije i Predmet.
// Dodaje atribute ocena i datum.
// Metode:Konstruktor sa i bez argumenata,ispis(),
// JeLiPolozio() - vraca 1 ako je student polozio,
// 0 u suprotnom.
// U main funkciji napraviti 2 studenta i testirati sve metode.
#include <iostream>
using namespace std;
using std::string;
class Dosije{
protected:
string ime;
string prezime;
int index;
public:
Dosije(){
    ime = "Petar";
    prezime = "Petrovic";
    index = 45;
}
Dosije(string ime, string prezime, int index) {
this->ime = ime;
this->prezime = prezime;
this->index = index;
}
void predstaviSe(){
    cout<<"Ime :"<<ime<<", prezime :"<<prezime<<", index :"<<index<<endl;
}
};
class Predmet{
protected:
string imeProfesora;
string prezimeProfesora;
string nazivPredmeta;
public:
Predmet(){
    imeProfesora = "Bratislav";
    prezimeProfesora = "Miric";
    nazivPredmeta = "OOP";
}
Predmet(string ime, string prezime, string nazivPredmeta){
    imeProfesora = ime;
    prezimeProfesora = prezime;
    this->nazivPredmeta = nazivPredmeta;
}
void opisPredmeta(){
    cout<<"Predmet :"<<nazivPredmeta<<"predaje "<<imeProfesora<<" "<<prezimeProfesora<<endl;
}
};
class Ispit:protected Dosije, Predmet{
int ocena;
string datum;
public:
Ispit():Dosije(),Predmet(){
    ocena = 5;
    datum = "1.1.2023.";
}
Ispit(int ocena, string datum, string imeProf, string prezimeProf, string nazivPred, string ime, string prezime, int index):Dosije(ime, prezime, index), Predmet(imeProf, prezimeProf, nazivPred){
    this->datum = datum;
    this->ocena = ocena;
}
void ispis(){
    Dosije::predstaviSe();
    Predmet::opisPredmeta();
    cout<<"ocena "<<ocena<<" datum "<<datum<<endl;
}
bool jeLiPolozio(){
    if(ocena >5)
    return true;
    else return false;
}
};
int main(){
    Dosije s1;
    Dosije s2("Merisa", "Besirovic", 12);
    Predmet p1;
    Predmet p2("Marko", "Markovic", "Algoritmi i strukture podataka");
    Ispit i1;
    Ispit i2(9,"24.03.","Petko", "Petkovic", "OOP1", "Merisa", "Besirovic", 12);
    i2.ispis();
   cout<<"Polozio je ili ne"<<i2.jeLiPolozio()<<endl;
    i1.ispis();
    if(i1.jeLiPolozio()){
        cout<<"Ovaj student je polozio"<<endl;
    }
    else cout<<"Ovaj student nije polozio"<<endl;
    
}