#include <iostream>
using namespace std;

enum ZANR { POP, REP, ROK };

class Izvodjac {
    string ime;
    ZANR zanr;
    string nadjiZanr() {
        switch (zanr) {
            case POP: return "POP";
            case REP: return "REP";
            case ROK: return "ROK";
        }
        return "Greska";
    }
public:
    Izvodjac(string i, ZANR z) {
        ime = i;
        zanr = z;
    }
    Izvodjac() {
        ime = "Micko";
        zanr = ROK;
    }
    void ispis() {
        cout << ime << "(" << nadjiZanr() << ")" << endl;
    }
    ZANR getZanr() {
        return zanr;
    }
};

class Pesma {
    string naziv;
    int min;
    int sec;
    int max;
    Izvodjac* izvodjaci;
    int br;
public:
    Pesma(string n, int m, int s, int maxBrIzvodjaca) {
        naziv = n;
        min = m;
        sec = s;
        max = maxBrIzvodjaca;
        izvodjaci = new Izvodjac[max];
        br = 0;
    }
    int getMin() const {
        return min;
    }
    int getSec() const {
        return sec;
    }
    friend bool Duza(const Pesma& p1, const Pesma& p2);
    void Dodavanje(Izvodjac* i) {
        if (br < max) {
            izvodjaci[br] = *i;
            br++;
        }
        else {
            cout << "Niz izvodjaca je pun, nije moguce dodati novog izvodjaca" << endl;
        }
    }
    void ispis() {
        cout << "P(" << naziv << "-" << min << ":" << sec << ")" << endl;
        for (int i = 0; i < br; i++) {
            izvodjaci[i].ispis();
        }
    }
};

bool Duza(const Pesma& p1, const Pesma& p2) {
    if (p1.min > p2.min || (p1.min == p2.min && p1.sec > p2.sec))
        return true;
    return false;
}

int main() {
    ZANR z = POP;
    cout << "Hello world " << z << endl;
    Izvodjac i1, i2("Licko", REP), i3("Lepa", POP);
    i1.ispis();
    i2.ispis();
    i3.ispis();
    Pesma p1("naziv1", 3, 20, 5) , p2("naziv2",1, 50,2);
    p2.Dodavanje(&i1);
    p2.Dodavanje(&i2);
    p2.Dodavanje(&i3);
    p1.Dodavanje(&i1);
    p1.Dodavanje(&i2);
    p1.Dodavanje(&i3);
    if(Duza(p1, p2)==true){
        cout <<"Prva pesma je duza od druge"<<endl;
    }else {
        cout <<"Prva pesma je kraca od druge"<<endl;
    }
    p1.ispis();
    p2.ispis();}