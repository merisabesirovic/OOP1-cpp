#include <iostream>
using namespace std;
using std::string;
class Odgovor{
string tekst;
bool tacan;
double procenat;
public:
Odgovor(string tekst="", bool tacan=false, double p=0){
    this->tekst = tekst;
    this->tacan = tacan;
    procenat = p;
}
Odgovor(const Odgovor& o){
    tekst = o.tekst;
    tacan = o.tacan;
    procenat = o.procenat;
}
string getTekst(){
    return tekst;
}
bool getTecan(){
    return tacan;
}
double getProcenat(){
    return procenat;
}
void setTacan(bool value){
    tacan = value;
}
void setProcenat(double value){
    if(value >= -100 && value <= 100)
    procenat = value;
}
friend ostream& operator<<(ostream &os, Odgovor& o){
    os<<o.tekst<<" "<<o.procenat<<"%"<<endl;
    return os;
}
Odgovor& operator=(const Odgovor& o){
    if(this == &o) return *this;
    tekst = o.tekst;
    tacan = o.tacan;
    procenat = o.procenat;
    return *this;
} 
};
class Pitanje{
public:
string tekst;
double poeni;
int brOdg;
Odgovor *ponudjeni;
int trenutnoOdgovora;
public:
    Pitanje(int brOdg=5, string tekst = "", double poeni=0){
        this->brOdg = brOdg;
        ponudjeni = new Odgovor[brOdg];
        trenutnoOdgovora = 0;
        this->tekst = tekst;
        this->poeni = poeni;
    }
    Pitanje (const Pitanje &p){
        brOdg = p.brOdg;
        ponudjeni = new Odgovor[brOdg];
        trenutnoOdgovora = p.trenutnoOdgovora;
        tekst = p.tekst;
        poeni = p.poeni;
        for(int i = 0; i < trenutnoOdgovora; i++){
            ponudjeni[i] = p.ponudjeni[i];
        }
    }
     Pitanje operator+=(const Odgovor &o){
        if(trenutnoOdgovora<brOdg){
            ponudjeni[trenutnoOdgovora] = o;
            trenutnoOdgovora++;
            double proc = 100;
            int brTacnih=0;
            for(int i = 0; i<trenutnoOdgovora; i++){
                if(ponudjeni[i].getTecan())
                brTacnih++;
            }
            proc = brTacnih>0 ?  double(100)/brTacnih : 100;
            for(int i = 0; i<trenutnoOdgovora; i++){
                if(ponudjeni[i].getTecan())
                ponudjeni[i].setProcenat(proc);
                else ponudjeni[i].setProcenat(-100);
            }
        }
     }
     double Odgovori(int niz[], int n){
        int p=0;
        for(int i = 0; i < n; i++){
            if(ponudjeni[niz[i-1]].getTecan()==false)
            return 0;
            p++;
        }
        double proc = 0;
        for(int i = 0; i < n; i++){
            if(ponudjeni[i].getTecan() == true)
            proc = ponudjeni[i].getProcenat();
            break;
        }
        return (p*proc/100)*poeni;
     }
     friend ostream& operator<<(ostream& s, Pitanje &p){
        s<<p.tekst<<": "<<p.poeni<<endl;
        for(int i = 0; i <p.trenutnoOdgovora; i++){
            s<<p.ponudjeni[i];
            return s;
        }
     }

};


