// Realizovati klasu Ocena koja ima tri privatna atributa: 
// ime_predmeta, ocenu i datum. 
// Metode: Konstruktor sa i bez argumenata, metodu jeLiPolozio() koja vraca true ako je student polozio ispit i false ako nije. 
// Ispis() koja ispisuje podatke o oceni, set i get metode. 
// Klasa Student ima privatne atribute: imeIprezime, brIndeksa, ocena1, ocena2 i ocena3 ( objekti klase ocena). set i get metode.
//  int ukupnoPolozenih() - vraca broj polozenih ispita. float prosek() - vraca prosek studenta. ispis() - 
//  ispuje podatke o studentu i njegovim ocenama.
#include <iostream>
using namespace std;
using std::string;
class Ocena{
    string imePredmeta;
    int ocena;
    string datum;
    public:
    Ocena(){
        cout<<"Unesite ime predmeta"<<endl;
        cin>>imePredmeta;
        cout<<"Unesite ocenu"<<endl;
        cin>>ocena;
        cout<<"Unesite datum"<<endl;
        cin>>datum;
    }
    Ocena(string ime, int ocena, string datum){
        imePredmeta = ime;
        this->ocena = ocena;
        this->datum = datum;
    }
    bool jeLiPolozio(){
        if(ocena>5) return true;
        else return false;
    }
    void ispis(){
        cout<<"Ime predmeta: "<<imePredmeta<<" ocena: "<<ocena<<" datum: "<<datum;
    }
    void setOcena(int ocena){ this->ocena = ocena;}
    void setDatum(string datum){ this->datum = datum;}
    void setImePredmeta(string ime){ imePredmeta = ime;}
    int getOc(){
        return ocena;
    }
};
class Student{
    private:
    string imePrezime;
    int brojIndeksa;
    Ocena ocena1, ocena2, ocena3;
    public:
    void setIme(string ime){
        imePrezime = ime;
    }
    void setIndeks(int br){
        brojIndeksa = br;
    }
    void setOcena1(int o, string d, string naziv){
        ocena1.setOcena(o);
        ocena1.setDatum(d);
        ocena1.setImePredmeta(naziv);
    }
    void setOcena2(int o,string d,string naziv){
        ocena2.setOcena(o);
        ocena2.setDatum(d);
        ocena2.setImePredmeta(naziv);
    }
    void setOcena3(int o, string d, string naziv){
        ocena3.setOcena(o);
        ocena3.setDatum(d);
        ocena3.setImePredmeta(naziv);
    }
int ukupnoPolozenih(){
    int counter = 0;
        if (ocena1.jeLiPolozio()) counter++;
        if (ocena2.jeLiPolozio()) counter++;
        if (ocena3.jeLiPolozio()) counter++;
        return counter;
}
float prosek(){
    return (ocena1.getOc()+ocena2.getOc()+ocena3.getOc())/3.0;
}
};
int main(){
    Student s;
    s.setIme("Marko Markovic");
    s.setIndeks(12345);
    s.setOcena1(6, "2021-02-01", "Programiranje 1");
    s.setOcena2(7, "2021-03-15", "Matematika 1");
    s.setOcena3(8, "2021-04-25", "Osnove elektrotehnike");
    Ocena o;
    o.ispis();
    cout << "Ukupno polozenih ispita: " << s.ukupnoPolozenih() << endl;
    cout << "Prosek: " << s.prosek() << endl;

    return 0;
}
