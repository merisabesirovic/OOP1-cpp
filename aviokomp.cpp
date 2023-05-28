/*
Avio kompanija omogućava rezervaciju karata za letove sa šaltera do većeg broja destinacija. 
Kompanija podržava dva tipa letova, redovne linije i čarter letovi. Imformacioni sistem podržava rad kompanije. 
Redovni letovi moraju da imaju informacije o polaznoj i dolaznoj destinaciji (char*), datumu i vremenu poletanja
 (char* oblika yyyy-MM-dd HH:mm:ss), broju mesta u avionu (int) i broju rezervisanih mesta u avionu (int).
  Potrebno je obezbediti rezervaciju jednog mesta na letu ako nisu sva mesta rezervisana. Omogućiti štampanje svih podataka o letu.
Čarter letovi čuvaju informacije o polaznoj i dolaznoj destinaciji (char*), datumu i vremenu poletanja (char*),
 broju mesta u redovnom avionu (int), broju mesta u vanrednom avionu (int) i broju rezervisanih mesta u avionu (int). 
 Potrebno je obezbediti rezervaciju jednog mesta na letu ako nisu sva mesta u vanrednom avionu rezervisana. 
 Omogućiti štampanje svih podataka o letu.
Sistem za podršku rada avio kompanije pamti sve letove u okviru jedinstvenog niza čiji se maksimalni broj 
letova postavlja na početku pri konfiguraciji sistema, a broj letova koji se trenutno nalazi u sistemu ažurira pri 
dodavanju ili brisanju nekog leta. Pri gašenju sistema obezbediti da se svi letovi uneti u njega obrišu. Sistem treba da ima mogućnost da:
•	doda zadati let u listu letova
•	obriše zadati let iz liste letova na osnovu zadatih destinacija i vremena poletanja
•	rezerviše kartu za let između zadatih destinacija u zadato vreme
•	uredi letove po vremenu poletanja (za realizaciju ove mogućnosti napraviti operator poređenja)
•	štampa podatke o svim letovima u sistemu.
Korišćenjem prethodno definisanog:
•	Kreirati sistem koji može da prihvati maksimalno 100 letova
•	Kreirati nekoliko redovnih i čarter letova i dodati ih u sistem
•	Obrisati barem dva uneta leta
•	Rezervisati nekoliko karata na nekom od letova
•	Urediti letove po vremenu
•	Štampati podatke o letovima koji se nalaze u sistemu.
*/
#include <iostream>
using namespace std;
using std::string;
class Let{
protected:
string polazna;
string dolazna;
string datumVreme;
int brMesta;
int rezMesta;
public:
Let(string polazna, string dolazna, int brMesta, int rezMesta, string dv){
    this->polazna = polazna;
    this->dolazna = dolazna;
    this->brMesta = brMesta;
    this->rezMesta = rezMesta;
    datumVreme = dv;
}
virtual void rezervacija(){
if(brMesta > rezMesta)
rezMesta++;
else cout<<"Nema mesta"<<endl;
}
virtual void ispis(){
    cout<<"Avion polazi ka "<<polazna<<" a dolazi u "<<dolazna<<"u "<<datumVreme<<endl;
    cout<<"Broj mesta u avionu je "<<brMesta<<" a trenutno je rezervisano "<<rezMesta<<endl;
}
string getPolazna(){
    return polazna;
}
int getMesta(){
    return brMesta;
}
string getDolazna(){return dolazna;};
string getDv(){return datumVreme;};
~Let(){
};
};
class RedovniLet:public Let{
    public:
RedovniLet(string polazak, string dolazak, int brMesta, int rezMesta, string dv) : Let(polazak, dolazak, brMesta,rezMesta, dv){

}
};
class CarterLet:public Let{
int brVanMesta;
public:
CarterLet(string polazak, string dolazak, int brMesta, int rezMesta, string dv, int brVanMesta) : Let(polazak, dolazak, brMesta,rezMesta, dv){
this->brVanMesta = brVanMesta;
}
void rezervacija(){
    if(brVanMesta > rezMesta)
    rezMesta++;
    else cout<<"Nena mesta"<<endl;
}
void ispis(){
    cout<<"Avion polazi ka "<<polazna<<" a dolazi u "<<dolazna<<"u "<<datumVreme<<endl;
    cout<<"Broj mesta u redovnom avionu je "<<brMesta<<" a trenutno je rezervisano "<<rezMesta<<endl;
    cout<<"Broj mesta u vanrednom avionu je "<<brVanMesta<<endl;
}
};
class Sistem{
int max;
int tr;
Let **sviLetovi;
public:
Sistem(int m){
    tr=0;
    max=m;
    sviLetovi = new Let*[m];
}
void operator+=(Let *l){
    if(tr<max)
    sviLetovi[tr]=l;
    tr++;
}
void brisi(string dest, string pol, string dv){
    int index;
    for(int i=0; i<tr; i++){
        Let *l=sviLetovi[i];
        if(l->getPolazna() == pol && l->getDolazna()== dest && l->getDv() == dv){
            delete l;
            if(i==tr-1){
                tr--;
                break;
            }
            else {
                for(int j=0; j<tr-1; j++){
                    sviLetovi[i] = sviLetovi[i+1];
                }
                tr--;
            }

        }
    }
}
void rezervisi(string pol, string dv, string dest){
    for(int i=0; i<tr; i++){
        Let *l=sviLetovi[i];
        if(l->getPolazna() == pol && l->getDolazna()== dest && l->getDv() == dv){
        l->rezervacija();
        break;}
        else cout <<"Mesto nije rezervisano"<<endl;
    } 
}
// void operator>(Let *l1, Let *l2){
//     int pom;
//     if(l1->getMesta()>l2->getMesta()){
//         l1=l2;


//     }
// }
// void sortiraj(){

// }
void stampa(){
    for(int i=0; i<tr; i++){
        sviLetovi[i]->ispis();
    }
    cout<<endl;
}
};
int main() {
    Sistem sistem(100); 

   
    Let* let1 = new RedovniLet("Beograd", "New York", 200, 50, "2023-06-15 10:00:00");
    Let* let2 = new RedovniLet("Beograd", "London", 150, 100, "2023-06-20 14:30:00");
    sistem += let1;
    sistem += let2;

   
    Let* let3 = new CarterLet("Beograd", "Barselona", 180, 50, "2023-06-25 08:45:00", 120);
    Let* let4 = new CarterLet("Beograd", "Rim", 150, 80, "2023-07-01 16:15:00", 70);
    sistem += let3;
    sistem += let4;

    cout << "All flights in the system:" << endl;
    sistem.stampa();
    
  
    sistem.brisi("New York", "Beograd", "2023-06-15 10:00:00");


    cout << "Flights after deletion:" << endl;
    sistem.stampa();

    sistem.rezervisi("Beograd", "2023-06-20 14:30:00", "London");

    cout << "Flights after reservation:" << endl;
    sistem.stampa();

    // Clean up memory
    delete let1;
    delete let2;
    delete let3;
    delete let4;

    return 0;
}
