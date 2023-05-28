//Realizovati klase radnik i sef koje imaju ime, prezime i platu, metode brz argumenata i ispis()
//Klasa firma je genericka klasa koja ima niz (Radnika, sefova) i broj radnika/sefova koji je podrazumevano 10
//metodu plate koja ispisuje podatke o radnicima/sefovima
//Kreirati 2firme, jednu firmu sefova 10, i firmu radnika koja ima 3 radnika
#include <iostream>
using namespace std;
using std::string;
class Radnik{
protected:
string ime;
string prezime;
float plata;
public:
Radnik(){
    ime="Petar";
    prezime="Pertovic";
    plata=500;
}
Radnik(string iime, string prezime, float plata){
    ime=iime;
    this->prezime=prezime;
    this->plata=plata;
}
void ispis(){
    cout<<"Ime radnika "<<ime<<" "<<prezime<<" "<<plata<<endl;
}
};
class Sef:public Radnik{
    public:
void ispis(){
    cout<<"Ime sefa "<<ime<<" "<<prezime<<" "<<plata<<endl;
}
};
template <class T=Radnik, int k=10>
class Firma{
private:
T zaposleni[k];
public:
void plate(){
    for(int i=0; i<k; i++){
        zaposleni[i].ispis();    }
}
};
int main(){
    // Radnik r("Merisa", "Besirovic", 5000);
    // r.ispis();
    // Sef s;
    // s.ispis();
     Firma<Sef> firSef;
    firSef.plate();
    Firma<Radnik,3> firRad;
    firRad.plate();
 return 0;   

}