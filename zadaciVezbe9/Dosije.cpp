#include <iostream>
using namespace std;
using std::string;
class Dosije{
protected:
string ime;
string prezime;
int indeks;
public:
    Dosije(){
        ime = "Merisa";
        prezime = "Besirovic";
        indeks = 0;
    }
    Dosije(string i, string prezime, int in){
        ime = i;
        this->prezime = prezime;
        indeks = in;
    }
    void predstaviSe(){
        cout<<"Ime"<<ime<<endl;
        cout<<"Prezime"<<prezime<<endl;
        cout<<"Index"<<indeks<<endl;
    };

};
class Predmet{
    protected:
    string imeProf;
    string prezimeProf;
    string naziv;
    public:
    Predmet(){
        imeProf = "Nesto";
        imeProf = "Nesto";
        naziv = "Naziv";
    }
    Predmet(string i, string p, string n){
        imeProf = i;
        prezimeProf = p;
        naziv = n;
    }
    void opisPredmeta(){
        cout<<"Profesor: "<<imeProf<<" "<<prezimeProf<<endl;
        cout<<"Naziv: "<<naziv<<endl;
    }};
    class Ispit:protected Dosije,protected Predmet{
        private: 
        int ocena;
        string datum;
        public:
        Ispit(){
            ocena = 5;
            datum = "1.12023";
        }
       Ispit(int ocena, string datum, string im, string p, int ind, string imp, string pp, string n) :
    Dosije(im, p, ind),
    Predmet(imp, pp, n){
    this->ocena = ocena;
    this->datum = datum;
}

        void ispis(){
            predstaviSe();
            opisPredmeta();
            cout<<"Student je "<<datum<<" "<<"dobio ocenu "<<ocena<<" "<<endl;
        }
        bool polozio(){
            return (ocena>5 && ocena<=10);
        }
    };
    int main(){
        Ispit i1;
        Ispit i2(8,"24.03.2023", "Haris", "Vesnic", 222, "Bratislav", "Miric", "Programiranje");
        i1.ispis();
        i2.ispis();
    }
