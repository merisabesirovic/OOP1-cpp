//Realizovati klase radnik i sef koje imaju ime, prezime i platu, metode brz argumenata i ispis()
//Klasa firma je genericka klasa koja ima niz (Radnika, sefova) i broj radnika/sefova koji je podrazumevano 10
//metodu plate koja ispisuje podatke o radnicima/sefovima
//Kreirati 2firme, jednu firmu sefova 10, i firmu radnika koja ima 3 radnika
#include <iostream>
#include <string>
using namespace std;  
using std::string;


class Radnik {
private:
    string ime;
    string prezime;
    float plata;

public:
    Radnik(const string& ime, const string& prezime, float plata)
        : ime(ime), prezime(prezime), plata(plata) {}

    Radnik(){
        ime = "Petar";
        prezime = "Petrovic";
        plata = 50000;
    }

    void ispis() {
     cout << "Ime: " << ime << ", Prezime: " << prezime << ", Plata: " << plata << endl;
    }
};

class Sef {
private:
 string ime;
 string prezime;
    float plata;

public:
    Sef(const string& ime, const string& prezime, float plata)
        : ime(ime), prezime(prezime), plata(plata) {}

    Sef(){
        ime = "Marko";
        prezime = "Markovic";
        plata = 80000;
    }

    void ispis() {
     cout << "Ime: " << ime << ", Prezime: " << prezime << ", Plata: " << plata << endl;
    }
};

template <class T=Radnik, int k=10>
class Firma {
public:
    T* *zaposleni;
    int brojZaposlenih;


public:
    Firma(int brojZaposlenih = 10) : brojZaposlenih(brojZaposlenih) {
        for(int i=0; i<brojZaposlenih; i++){
            zaposleni[i] = new Radnik();
        }
    }

    ~Firma() {
        delete[] zaposleni;
    }

    void plate() {
        for (int i = 0; i < brojZaposlenih; i++) {
            zaposleni[i].ispis();
        }
    }

    void dodajZaposlenog(const T& zaposleniObjekat, int indeks) {
        if (indeks >= 0 && indeks < brojZaposlenih) {
            zaposleni[indeks] = zaposleniObjekat;
        }
    }
};

int main() {
    Firma<Radnik> firma(5);

    Radnik radnik1("Marko", "Markovic", 2500);
    Radnik radnik2("Ana", "Anic", 2800);
    Sef sef1("Petar", "Petrovic", 4000);
    Sef sef2("Jovana", "Jovanovic", 4500);

    firma.dodajZaposlenog(radnik1, 0);
    firma.dodajZaposlenog(radnik2, 1);
    Firma<Radnik> obj;
    // firma.dodajZaposlenog(sef1, 2);
    // firma.dodajZaposlenog(sef2, 3);

    firma.plate();

    return 0;

};