/*Napisati na jeziku C++ sledeći sistem klasa. Klase opremiti onim konstruktorima,destruktoromi operatorima
 dodelekoji su potrebni za bezbedno i efikasno korišćenje klasa. Greške prijavljivati  izuzecima  tipa 
  jednostavnih  klasa  koje  su  opremljene  pisanjem  teksta  poruke. Za generičke zbirke nije dozvoljeno
   korišćenje klasa iz standardne biblioteke šablona (STL).
1.	Klasa Sastojak sadrži zadato ime i cenu po kilogramu.Pomoću metoda može da se dohvati vrsta sastojka i 
da se izračuna cena za zadatu količinu sastojka u gramima(količina dolazi kao argument metode). Upisuje se u 
izlazni tok (cout<<s)  u obliku ime-cena/kg.
Vrste slanog, slatkog i neutralnog sastojka su SLAN, SLADiNEUT, respektivno. (Odraditi pomoću enumeracije)
2.	Klasa Jelo ima ime i sadrži listu sastojaka, kao i celobrojnu vrednost koja predstavlja količinu sastojka 
za pripremu jela izraženu u gramima. Cena jela je određena zbirom cene sastojaka, uz eventualno procentualno 
povećanje ili smanjenje osnovne cene, koje zavisi od sata formiranja cene jela. Može da se postavi podatak o 
procentualnoj promeni cene jela i podatak o satu formiranja cene. Može da se doda sastojak određene količine u jelo,
 pri čemu se pre dodavanja proverava da li je sastojak adekvatan(greška je ako nije), da se dohvati jednoslovna vrsta 
 jela i da se izračuna njegova cena. Upisuje se u izlazni tok(cout<<j) tako što se u prvom redu upiše ime:cena, a u narednim 
 redovima se upisuje jedan sastojak poredu u obliku sastojak:količina. Pri uništavanju jela, uništavaju se i svi sadržani sastojci.
3.	Predjelo i glavno jelo su jela koja mogu da sadrže samo slane i neutralne sastojke i njihove vrste su P i G, respektivno. 
Predjelo se nalazi na akciji u periodu 9-12 časova (kada se cena umanjuje za određeni procenat). Cena glavnog jela se uvećava
 za određeni procenat u periodu 20-23 časa. Dezert je jelo koje može da sadrži samo slatke i neutralne sastojke i njegova vrsta je D.
Napisati na jeziku C++programkojinapravi nekoliko jela, postavi im određeni procenatpromene cene, doda im sastojke,
 a zatim napravljena jela doda u jelovnik. Potom napravi generator koji generiše  dnevni  meni za  određeni  sat i 
  ispiše ga na  standardnom  izlazu. Koristiti  fiksne parametre –nije potrebno ništa učitati sglavnog ulaza.
*/
#include <iostream>
using namespace std;
using std::string;

class Sastojak {
public:
    enum Vrsta {
        SLAN, SLADiNEUT
    };

private:
    string ime;
    float cenaKg;
    Vrsta v;

public:
    Sastojak(string i, float c) {
        ime = i;
        cenaKg = c;
    }

    Sastojak() {
        ime = "";
        cenaKg = 0;
    }

    string getIme() {
        return ime;
    }

    float cenaPoKg() {
        return cenaKg;
    }

    float ukupnaCena(int kg) {
        return cenaKg * kg;
    }

    friend ostream& operator<<(ostream& os, Sastojak const& s) {
        os << s.ime << s.cenaKg << endl;
        return os;
    }

    string nadjiVrstu() {
        switch (v) {
        case SLAN:
            return "SLAN";
        case SLADiNEUT:
            return "SLADiNEUT";
        }
        return "";
    }
};

class Jelo {
public:
    enum PG {
        P, G, D
    };

protected:
    string ime;
    Sastojak* lista;
    int gram;
    int kolicina;
    int trenutnaKolicina;
    int promenaCene;
    int satCene;
    PG pg;

public:
    Jelo(int k, int gram, string n) {
        kolicina = k;
        ime = n;
        lista = new Sastojak[k];
        this->gram = gram;
        trenutnaKolicina = 0;
    }

    string nadjiPG() {
        if (pg == P)
            return "P";
        else if (pg == G)
            return "G";
        else
            return "D";
    }

    virtual void dodaj(Sastojak const& s) {
        if (kolicina > trenutnaKolicina) {
            lista[trenutnaKolicina] = s;
            trenutnaKolicina++;
        }
        else
            cout << "ERROR";
    }

    void setPovecanje(int p) {
        promenaCene = p;
    }

    void setSat(int s) {
        satCene = s;
    }

    virtual float konacnaCena() const {
        float konacna = 0.0;
        for (int i = 0; i < trenutnaKolicina; i++) {
            konacna += lista[i].ukupnaCena(gram / 1000);
        }
        return konacna;
    }

    friend ostream& operator<<(ostream& os, Jelo const& j) {
        os << j.ime << ":" << j.konacnaCena() << endl;
        for (int i = 0; i < j.trenutnaKolicina; i++) {
            os << j.lista[i].getIme() << " " << j.gram << endl;
        }
        return os;
    }

    ~Jelo() {
        delete[] lista;
    }
};

class Predjelo : public Jelo {
public:
    Predjelo(int k, int gram, string n) : Jelo(k, gram, n) {}

    void dodaj(Sastojak& s) {
        if (s.nadjiVrstu() == "SLAN") {
            Jelo::dodaj(s);
        }
        else {
            cout << "ERROR" << endl;
        }
    }

    float konacnaCena() {
        if (satCene >= 9 && satCene <= 12 && nadjiPG() == "P") {
            setPovecanje(0.2);
            return Jelo::konacnaCena() - Jelo::konacnaCena() * 0.2;
        }
        else {
            return Jelo::konacnaCena();
        }
    }
};

class GlavnoJelo : public Predjelo {
public:
    GlavnoJelo(int k, int gram, string n) : Predjelo(k, gram, n) {}

    float konacnaCena() {
        if (satCene >= 20 && satCene <= 23 && nadjiPG() == "G") {
            return Jelo::konacnaCena() + Jelo::konacnaCena() * 0.2;
        }
        else {
            return Jelo::konacnaCena();
        }
    }
};

class Dezert : public Jelo {
public:
    Dezert(int k, int gram, string n) : Jelo(k, gram, n) {};

    void dodaj(Sastojak& s) {
        if (s.nadjiVrstu() == "SLADiNEUT") {
            Jelo::dodaj(s);
        }
        else {
            cout << "ERROR" << endl;
        }
    }
};

int main() {
    Sastojak slanSastojak("Slani sastojak", 10.0);
    Sastojak sladineutSastojak("Sladak i neutralan sastojak", 15.0);
    cout << sladineutSastojak << endl;
    cout << slanSastojak << endl;

    Predjelo predjelo(3, 200, "Predjelo");
    GlavnoJelo glavnoJelo(2, 400, "Glavno jelo");
    Dezert dezert(4, 100, "Dezert");

    predjelo.dodaj(slanSastojak);
    glavnoJelo.dodaj(slanSastojak);
    dezert.dodaj(sladineutSastojak);

    cout << glavnoJelo << endl;
    cout << predjelo << endl;

    predjelo.setSat(10);
    glavnoJelo.setSat(21);
    dezert.setSat(15);

    cout << predjelo << endl;
    cout << glavnoJelo << endl;
    cout << dezert << endl;

    return 0;
}
