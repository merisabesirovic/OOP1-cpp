//  (укупно 70 поена) Написати на језику C++ следеће класе (класе опремити оним конструкторима
// и деструктором који су потребни за безбедно и ефикасно коришћење класа):
//  (20 поена) Датум има целобројне дан, месец и годину. Компоненте датума се задају при
// стварању (није потребна провера) и могу да се дохвате појединачно. Може да се провери да
// ли је датум већи од задатог датума. Датум може да се испише на главном излазу у облику
// дан.месец.година.
//  (20 поена) Лек има једнозначни аутоматски генерисани идентификатор, комерцијално име,
// генерички назив, рок трајања (датум до којег се може користити) и цену. Сви подаци се
// задају приликом стварања и могу да се дохвате, а само цена може да се промени. Приликом
// копирања лека идентификатор се не копира. На главном излазу се исписује у облику
// идентификатор-комерцијано име (генерички назив):рок-цена.
//  (20 поена) Апотека има име и садржи произвољан број лекова. Ствара се празна, после чега
// се лекови додају појединачно. Не може да се направи копија апотеке, а при уништавању се не
// уништавају садржани лекови. Може да се дохвати лек по задатом идентификатору. На
// главном излазу се исписује тако што се у првом реду испише име апотеке, а потом се у
// засебним редовима испишу садржани лекови.
// (10 поена) Написати на језику C++ програм који створи једну апотеку и у њу дода неколико
// лекова, испише је на главном излазу, а затим дохвати лек са идентификатором 3 и провери да
// ли је у року трајања на дан 04.11.2016. Користити фиксне параметре – није потребно ништа
// учитати с главног улаза.

#include <iostream>
using namespace std;
using std::string;
class Datum{
    int dan;
    int mesec;
    int godina;
    public:
    Datum(){
        dan = 1;
        mesec = 1;
        godina = 2023;
    }
    Datum(int d, int m, int g){
        dan = d;
        mesec = m;
        godina = g;
    }
    int getDan(){
        return dan;
    }
    int getMesec(){
        return mesec;
    }
    int getGodina(){
        return godina;
    }
    bool operator>(Datum &d){
        if(godina>d.godina)
        return true;
        else if(godina>=d.godina && mesec>d.mesec)
        return true;
        else if(godina>=d.godina && mesec>=d.mesec && dan>d.dan)
        return true;
        else return false;
    }
friend ostream& operator<<(ostream& out, const Datum& d) {
    out << d.dan << "." << d.mesec << "." << d.godina<<endl;
    return out;
}
};
class Lek{
public:
int static Id;
private:
string komercijalnoIme;
string generickiNaziv;
Datum rok;
int cena;
public:
 Lek(){
 komercijalnoIme = "";
 generickiNaziv = "";
    }
 Lek(string ki, string gn, Datum r, int c){
    komercijalnoIme = ki;
    generickiNaziv = gn;
    rok = r;
    cena = c;
    Id++;
 }
 string getKime(){
    return komercijalnoIme;
 }
 string getGeni(){
    return generickiNaziv;
 }
 Datum getDatum(){
    return rok;
 }
 int getCena(){
    return cena;
 }
 void setCena(int c){
    cena = c;
 }
 Lek(Lek const &l){
    komercijalnoIme = l.komercijalnoIme;
    generickiNaziv = l.generickiNaziv;
    rok = l.rok;
    cena = l.cena;
 }
 friend ostream& operator<<(ostream& stream, Lek const &L){
    stream<<L.Id<<" "<<L.komercijalnoIme<<" "<<L.generickiNaziv<<" : "<<L.rok<<" "<<L.cena<<endl;
    return stream;
 }
};
class Apoteka{
    Lek *lekovi;
    string ime;
    public:
    int static trBr;
    Apoteka(Lek const l, string ime){
            lekovi = new Lek[1];
            lekovi[0]=l;
            trBr++;
        this->ime = ime;
        };
    void dodaj(Lek const l){
        if(trBr ==0){
            lekovi = new Lek[1];
            lekovi[0]=l;
            trBr++;}
        else{
            Lek *pom ;
            pom = new Lek[trBr];
            for(int i=0; i<trBr; i++){
                pom[i]=lekovi[i];
            }
        delete [] lekovi;
        trBr++;
        lekovi = new Lek[trBr];
        for(int i=0; i<trBr-1; i++){
            lekovi[i]=pom[i];
        }
        lekovi[trBr-1]=l;
    }
    }
~Apoteka(){
}
 Lek getLek(int l){
    for(int i=0; i<trBr; i++){
        if(lekovi[i].Id == l){
            return lekovi[i];
            break;
    }
 }
};
friend ostream& operator<<(ostream& pisi, Apoteka& a){
    pisi<<a.ime<<endl;
    for(int i=0; i<trBr; i++){
        pisi<<a.lekovi[i]<<endl;
    }
    return pisi;
}};

int Lek::Id =0;
int Apoteka:: trBr =0;
int main(){
    Datum d1(24,3,1997);
    Datum d2(31,5,1997);
    if(d1>d2){
        cout<<"Prvi datum"<<endl;
    }
    else cout<<"Drugi datum"<<endl;
    cout<<d1;
    Lek l1("Probiotik", "Probiotik nesto", d1, 600);
    // cout<<l1;
    Lek l2("Bromazepam", "Brjsbfj", d2, 900);
    Lek l3("Kapi", "za nos", d2, 900);

    // cout<<l2;
    Apoteka a1(l1, "Hygia");
    a1.dodaj(l2);
    a1.dodaj(l3);
    a1.dodaj(l1);
    cout<<a1;
    cout<<"Ovo je to"<<a1.getLek(3);
}