// // Realizovati klasu Odeljenje koja treba da sadrži atribute:br_ucenika - celobrojna promenljiva,uspeh 
// - dinamicki niz realnih brojeva koji predstavljaju prosečnu ocenu učenika. 
// Metode:konstruktor sa i bez argumenata koji učitava uspeh učenika sa standardnog ulaza.Konstruktor kopiranja,
//  Destruktor,prosek() - metoda koja vraća vrednost prosečne ocene svih učenika, 
//  br_odlican5() - metoda koja vraća broj učenika koji imaju sve petice tj uspeh im je 5,00. ispis() - metoda koja ispisuje broj nedovoljnih,
//   dovoljnih, dobrih i odličnih učenika kao i prosečnu ocenu pozivajući poslednju metodu za prosek.uspehucenika(int i,double u) - 
//    i-tom učeniku uspeh, dodaj_ucenika(double u) - dodaje novog ucenika u odeljenje (ubacuje njegov uspeh u niz uspeha i povecava ukupan 
//    broj ucenika)
// // Napisati main funkciju, formirati objekat i isprobati sve metode.
#include <iostream>
using namespace std;
class Odeljenje{
    int brUcenika;
    float *uspeh;
    public:
    Odeljenje(){
        cout<<"Unesite broj ucenika";
        cin>>brUcenika;
        uspeh = new float[brUcenika];
        cout<<"Unesite uspeh"<<endl;
        for(int i = 0; i<brUcenika; i++){
            cin>>uspeh[i];
        }
    }
    Odeljenje(int n){
        brUcenika = n;
        uspeh = new float[brUcenika];
        cout<<"Unesite uspeh"<<endl;
        for(int i = 0; i<brUcenika; i++){
            cin>>uspeh[i];
    }}
    Odeljenje(Odeljenje const &odeljenje1){
        this->brUcenika = odeljenje1.brUcenika;
        uspeh = new float[brUcenika];
        for(int i = 0; i<brUcenika; i++){
            uspeh[i]= odeljenje1.uspeh[i];
        }
    }
    ~Odeljenje(){
        delete [] uspeh;
    }
    float prosek(){
        float s=0;
        for(int i = 0; i<brUcenika; i++){
            s += uspeh[i];
        }
        return s/brUcenika;
    }
    int brOdlicnih(){
        int counter = 0;
        for(int i=0; i<brUcenika; i++){
            if(uspeh[i] == 5.00)
            counter++;
        }
        return counter;
    }
    void ispis(){
        int nedovoljni=0, dovoljni=0, dobri=0, vrDobri=0 ,odlicni = 0;
        for(int i = 0; i<brUcenika; i++){
            if(uspeh[i]<=5.00 && uspeh[i]>=4.50)
            odlicni++;
            else if(uspeh[i]<4.50 && uspeh[i]>=3.50)
            vrDobri++;
            else if(uspeh[i]<3.50 && uspeh[i]>=2.50)
            dobri++;
            else if(uspeh[i]<2.50 && uspeh[i]>=1)
            dovoljni++;
            else nedovoljni++;
        }
    cout << "Broj ucenika: " << brUcenika << endl;
    cout << "Broj nedovoljnih: " << nedovoljni << endl;
    cout << "Broj dovoljnih: " << dovoljni << endl;
    cout << "Broj dobrih: " << dobri << endl;
    cout << "Broj odlicnih: " << odlicni << endl;
    cout << "Prosecan uspeh: " << prosek() << endl;
    }
    void uspehItog(int ucenik){
        cout<<"Uspeh "<<ucenik<<". ucenika:"<<uspeh[ucenik-1];
    }
    void postavi(int ucenik, float u){
        if(ucenik<=0 || ucenik>brUcenika)
        cout<<"Nemoguce";
        else uspeh[ucenik-1]=u;
    }
    void dodaj(int u){
        float *pom = new float[brUcenika];
        for(int i=0; i<brUcenika;i++){
            pom[i]=uspeh[i];
        }
        delete [] uspeh;
        brUcenika++;
        uspeh = new float[brUcenika];
        for(int i=0; i<brUcenika-1; i++){
            uspeh[i]=pom[i];
        }
        uspeh[brUcenika-1]=u;
    
    }
};
int main(){

Odeljenje o2(4);
Odeljenje o3(o2);
cout<<o3.prosek()<<endl;
o3.dodaj(5.00);
cout<<o3.prosek()<<endl;
o2.ispis();
o3.ispis();


}