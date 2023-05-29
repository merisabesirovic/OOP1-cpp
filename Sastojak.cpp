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
#include <string>
using namespace std;

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
    Sastojak(string i, float c, Vrsta vr) {
        ime = i;
        cenaKg = c;
        v = vr;
    }
    Sastojak(){
        ime = "";
        cenaKg = 0.0;
    }

    string getIme() const {
        return ime;
    }

    float getCenaKg() const {
        return cenaKg;
    }

    float ukupnaCena(int gram) const {
        return cenaKg * (gram / 1000.0);
    }

    friend ostream& operator<<(ostream& os, const Sastojak& s) {
        os << s.ime << "-" << s.cenaKg << "/kg";
        return os;
    }

    string nadjiVrstu() const {
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
    int kolicina;
    int trenutnaKolicina;
    int promenaCene;
    int satCene;
    PG pg;

public:
    Jelo(int k, string n) {
        kolicina = k;
        ime = n;
        lista = new Sastojak[k];
        trenutnaKolicina = 0;
    }

    virtual ~Jelo() {
        delete[] lista;
    }

    string nadjiPG() const {
        if (pg == P)
            return "P";
        else if (pg == G)
            return "G";
        else
            return "D";
    }

    virtual void dodaj(const Sastojak& s) {
        if (trenutnaKolicina < kolicina) {
            lista[trenutnaKolicina] = s;
            trenutnaKolicina++;
        }
        else {
            cout << "ERROR" << endl;
        }
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
            konacna += lista[i].ukupnaCena(kolicina);
        }
        return konacna;
    }

    friend ostream& operator<<(ostream& os, const Jelo& j) {
        os << j.ime << ":" << j.konacnaCena() << endl;
        for (int i = 0; i < j.trenutnaKolicina; i++) {
            os << j.lista[i].getIme() << ":" << j.kolicina << endl;
        }
        return os;
    }
};

class Predjelo : public Jelo {
public:
    Predjelo(int k, string n) : Jelo(k, n) {
        pg = P;
    }

    void dodaj(const Sastojak& s) override {
        if (s.nadjiVrstu() == "SLAN") {
            Jelo::dodaj(s);
        }
        else {
            cout << "ERROR" << endl;
        }
    }
};

class GlavnoJelo : public Jelo {
public:
    GlavnoJelo(int k, string n) : Jelo(k, n) {
        pg = G;
    }

    void dodaj(const Sastojak& s) override {
        if (s.nadjiVrstu() == "SLAN") {
            Jelo::dodaj(s);
        }
        else {
            cout << "ERROR" << endl;
        }
    }
};

class Dezert : public Jelo {
public:
    Dezert(int k, string n) : Jelo(k, n) {
        pg = D;
    }

    void dodaj(const Sastojak& s) override {
        if (s.nadjiVrstu() == "SLADiNEUT") {
            Jelo::dodaj(s);
        }
        else {
            cout << "ERROR" << endl;
        }
    }
};

int main() {
    Sastojak s1("Slani sastojak", 10, Sastojak::SLAN);
    Sastojak s2("Sladak i neutralan sastojak", 15, Sastojak::SLADiNEUT);

    Predjelo p(10, "Predjelo");
    p.dodaj(s1);
    p.dodaj(s2);
    cout << "Predjelo: " << p << endl;

    GlavnoJelo g(20, "Glavno jelo");
    g.dodaj(s1);
    g.dodaj(s2);
    cout << "Glavno jelo: " << g << endl;

    Dezert d(5, "Dezert");
    d.dodaj(s2);
    cout << "Dezert: " << d << endl;

    return 0;
}

