/*(укупно 70 поена) Написати на језику C++ следеће класе (класе опремити оним конструкторима,
деструктором и операторима доделе који су потребни за безбедно и ефикасно коришћење
класа):
 (10 поена) Датум се задаје помоћу редног броја дана, месеца и године (подразумевано
27.11.2015, исправност не треба проверавати). Може да се одреди да ли је датум после другог
датума (datum1>datum2) и да се испише на главном излазу у облику дан.месец.годиnа..
 (30 поена) Апстрактна полиса осигурања има јединствен, аутоматски генерисан целобројан
идентификатор (број полисе), датум почетка важења, датум истека, податак да ли је активна
и тип. Тип полисе може бити STANDARD, KOMFORT и EKSKLUZIV (подразумевано
STANDARD). При стварању, полиса је активна. Може да се утврди да ли је активна и дохвати
датум истека, као и да се полиса означи неактивном. Важење полисе је могуће продужити
задавањем новог датума истека (неактивна полиса постаје активна, а продужење се игнорише
ако је нови датум истека пре текућег). Може да се дохвати максимална премија при
реализацији полисе и да се полиса упише у излазни ток (it<<polisa) у облику ид -
тип[премијаeur][почетак-крај].
 Максимална премија при реализацији полисе путног осигурања је 5000 еур, 7000 еур и
10000 еур, за типове STANDARD, KOMFORT и EKSKLUZIV, респективно. Полиса путног
осигурања може да се упише у излазни ток у облику Putno_osiguranje: полиса.
 (20 поена) Осигураник има име и јединствен, аутоматски генерисан, целобројан
идентификатор осигураника. Садржи произвољан број полиса чији је власник. Ствара се
задавањем имена, без полиса осигурања, након чега се полисе додају појединачно
(osiguranik+=polisa). Могуће је означити неактивним све полисе осигураника чији је
датум истека пре задатог датума, и продужити важење до задатог датума свих активних
полиса осигураника. Осигураник не може да се копира ни премешта, ни иницијализацијом ни
доделом. Може да се упише у излазни ток (it<<osiguranik) у облику име(ид), након
чега се у пару витичастих заграда ({ }) уписују полисе осигураника, свака у засебном реду.
(10 поена) Написати на језику C++ програм који направи осигураника, дода му неколико
полиса путног осигурања и испише га на главном излазу. Након тога означи неактивним полисе
осигураника истекле пре 27.11.2015., продужи важење полиса осигураника до краја године и
испише осигуранике. */
#include <iostream>
#include <string>
using namespace std;
using std::string;

class Datum {
    int dan;
    int mesec;
    int godina;

public:
    Datum(int d, int m, int g) {
        dan = d;
        mesec = m;
        godina = g;
    }

    Datum() {
        dan = 27;
        mesec = 11;
        godina = 2015;
    }

    bool operator>(const Datum& d) {
        if (godina > d.godina)
            return true;
        else if (godina >= d.godina && mesec < d.mesec)
            return true;
        else if (godina >= d.godina && mesec <= d.mesec && dan < d.dan)
            return true;
        else
            return false;
    }

    void ispis() {
        cout << dan << "." << mesec << "." << godina << ".";
    }
};

class Polisa {
public:
    enum Tip { STANDARD, KOMFORT, EKSKLUZIV };

protected:
    static int id;
    int brojPolise;
    Datum pocetak;
    Datum kraj;
    Tip tip;
    bool aktivan;

public:
    Polisa(Polisa& polisa) {
        brojPolise = polisa.brojPolise;
        aktivan = polisa.aktivan;
        pocetak = polisa.pocetak;
        kraj = polisa.kraj;
    }

    Polisa() {
        brojPolise = ++id;
        aktivan = true;
        pocetak = Datum();
        kraj = Datum();
        tip = STANDARD;
    }

    Polisa(Datum p, Datum k, Tip t = STANDARD) {
        brojPolise = ++id;
        pocetak = p;
        kraj = k;
        tip = t;
        aktivan = true;
    }

    virtual ~Polisa() {}

    virtual int getPremija() const = 0;

    bool isActive(const Datum& d) {
        return kraj > d;
    }

    void setActive() {
        aktivan = false;
    }

    Datum getKraj() {
        return kraj;
    }

    void produzi(const Datum& d) {
        if (!isActive(d)) {
            kraj = d;
            aktivan = true;
        }
        else {
            cout << "Polisa je trenutno aktivna" << endl;
        }
    }

    void pisi() {
        cout << brojPolise << " - " << nadjiTip() << "[" << getPremija() << "eur][";

        pocetak.ispis();
        cout << "-";
        kraj.ispis();

        cout << "]" << endl;
    }

private:
    string nadjiTip() const {
        switch (tip) {
        case STANDARD:
            return "STANDARD";
        case KOMFORT:
            return "KOMFORT";
        case EKSKLUZIV:
            return "EKSKLUZIV";
        default:
            return "N/A";
        }
    }
};

int Polisa::id = 0;

class Premija : public Polisa {
public:
    Premija(Datum p, Datum k, Tip t = STANDARD) : Polisa(p, k, t) {}

    int getPremija() const override {
        if (tip == STANDARD)
            return 5000;
        else if (tip == KOMFORT)
            return 7000;
        else if (tip == EKSKLUZIV)
            return 9000;
        else
            return 0;
    }
};

class Osiguranik {
    static int id2;
    string ime;
    int idOsiguranika;
    Polisa** polise;
    int tr;
    int max;

public:
    Osiguranik(int m, string ime) {
        this->ime = ime;
        polise = new Polisa*[m];
        tr = 0;
        max = m;
    }

    ~Osiguranik() {
        for (int i = 0; i < tr; i++) {
            delete polise[i];
        }
        delete[] polise;
    }

    void operator+=(Polisa& polisa) {
        if (tr < max) {
            polise[tr] = &polisa;
            tr++;
        }
        else {
            cout << "ERROR: Maximum number of polise reached!" << endl;
        }
    }

    void provera(Datum p) {
        for (int i = 0; i < tr; i++) {
            if (!polise[i]->isActive(p))
                polise[i]->setActive();
            else
                continue;
        }
    }

    void print() {
        cout << ime << "(" << idOsiguranika << ")" << endl;
        for (int i = 0; i < tr; i++) {
            polise[i]->pisi();
        }
        cout << endl;
    }
};

int Osiguranik::id2 = 0;

int main() {
    Osiguranik osiguranik(5, "John Doe");

    Datum pocetak(1, 1, 2023);
    Datum kraj(31, 12, 2023);
    if(pocetak>kraj)cout<<"Prvi je veci"<<endl;
    else cout<<"Drugo je veci"<<endl;

    Premija p1(pocetak, kraj, Polisa::KOMFORT);
    Premija p2(pocetak, kraj, Polisa::STANDARD);
    Premija p3(pocetak, kraj, Polisa::EKSKLUZIV);

    osiguranik += p1;
    osiguranik += p2;
    osiguranik += p3;

    Datum datumProvere(27, 11, 2015);
    osiguranik.provera(datumProvere);

    Datum datumProduzenja(31, 12, 2023);
    

    osiguranik.print();

    return 0;
}


