// // Potrebno je kreirati aplikaciju za deljenje znanja putemrazmene članaka među korisnicima. Izdvojene su sledeće funkcionalnosti.
// //  Na osnovu datih klasa implementirati opisanefunkcionalnosti sistema. Po potrebi dopuniti klase novimatributima i/ili metodama.
// // Kreirati klasu Vreme koja ima atribute sati, minuti isekunde i metode: konstruktor bez argumenata, konstruktor sa 3 argumenta 
// (sati, minuti i sekunde), konstruktor sa 2 argumenta (sati i minuti), Info saargumentom tipa bool koji određuje 
// da li će vreme bitiispisano u punom format (hh:mm:ss) ili u skraćenomformatu (hh:mm), Add koja kao rezultat vraća noviobjekat 
// tipa vreme koji predstavlja sumu vremenaposleđenog kao parametar i instance this, Add koja kaorezultat vraća novi objekat tipa vreme 
// koji predstavljasumu parametra izraženog u minutama i vremenainstance this, 
// CompareTo koja vraća vrednost tipa int u zavisnosti od toga da li je vreme instance this pre, jednako
//  ili posle vremena proslijeđenog kao parameter (-1 - vreme instance
//  this nastupa pre vremena v2, 0 - vreme instance this je jednako vremenu v2, 1 - vremeinstance this nastupa nakon vremena v2). (10 poena)
//  Klasa Datum ima dan, mesec i godinu. Potrebnekonstruktore za ispravan rad, destruktore i metodu za ispis. (5 poena)
// 3. Klasa Korisnik ima puno ime koje mora imati najviše 30 karaktera, korisnicko ime može imati najviše 20 karaktera, 
// lozinku (promenljive dužine) i tip korisnika(administrator ili gost). Potrebne konstruktore za ispravan rad, destruktore i metodu za ispis.
//  Metodu za promenu lozinke gde se šalju kao parametri stara i nova lozinka. Samo ako je stara
//   lozinka ispravno poslata možese promeniti na novu lozinku u suprotnom ispisatiporuku o grešci. (10 poena)
// Klasa Komentar ima tekst promenljive dužine, datum, vreme, popularnost (ceo broj koji označava koliko je komentar popularan), 
// korisnik koji je autor komentara. Potrebne konstruktore za ispravan rad, destruktore imetodu za ispis.
//  Metodu za povećanje popularnostikomentara za +1. (5 poena)
// 5. Klasa Clanak ima naslov od najviše 50 karaktera, sadržajpromenljive dužine,
//  datum, vreme, broj pregleda, tagovi(niz stringova), oblast niz od 100 karaktera, 
//  korisnik koji je autor clanka, niz komentara koje je clanak dobio koji je promenljive dužine. 
//  Potrebne konstruktore za ispravanrad, destruktore i metodu za ispis. Metoda za dodavanjenovog taga.
//  Članke mogu dodavati svi registrovanikorisnici nebitno 
// li su oni administratori ili gosti. Korisnici aplikacije koji su gosti takođe mogu ostavitikomentar na određeni članak.
//  Administratori ne moguostavljati komentar. Kreirati metodu za promenu sadržajai vremena promene članka. 
//  Kao verifikaciju dozvolepotrebno je proslediti korisničko ime autora članka. 
// Samo kreator članka ima permisije da menja njegovsadržaj. (20 poena)
#include <iostream>
using namespace std;
using std::string;
#include <cstring>
enum TIP {ADMIN, GOST};
class Vreme{
    int sati;
    int minute;
    int sekunde;
public:
    Vreme(){
        sati = 0;
        minute = 0;
        sekunde = 0;
    }
    Vreme(int sat, int m, int sek){
        sati = sat;
        minute = m;
        sekunde = sek;
    }
    Vreme(int s, int m){
        sati = s;
        minute = m;
        sekunde = 0;
    }
    int getSek(){
        return sekunde;
    }
    void info(bool showSeconds){
        if(showSeconds){
            if(sati<10)
                cout<<"0"<<sati<<":";
            else cout<<sati<<":";
            if(minute<10)
                cout<<"0"<<minute<<":";
            else cout<<minute<<":";
            if(sekunde<10)
                cout<<"0"<<sekunde<<":";
            else cout<<sekunde<<":";
        }
        else{
            if(sati<10)
                cout<<"0"<<sati<<":";
            else cout<<sati<<":";
            if(minute<10)
                cout<<"0"<<minute<<":";
            else cout<<minute<<":"; 
        }
    }
    Vreme operator +(Vreme v){
        Vreme r;
        r.sekunde = (sekunde + v.sekunde) % 60;
        r.minute = (sekunde + v.sekunde) / 60 + (minute + v.minute) % 60;
        r.sati = (minute + v.minute) / 60 + sati + v.sati;
        return r;
    }
    int compareTo(Vreme v){
        if(v.sati <= this->sati && v.minute <= this->minute && v.sekunde < this->sekunde)
            return -1;
        else if(v.sati <= this->sati && v.minute < this->minute && v.sekunde <= this->sekunde)
        return -1;
        else if(v.sati == this->sati && v.minute == this->minute && v.sekunde == this->sekunde)
        return 0;
        else return 1;
    }
   friend void operator<<(ostream &COUT, Vreme v);
};
    void operator<<(ostream &COUT, Vreme v){
        COUT<<"sekunde"<<v.sekunde<<" "<<v.minute<<" "<<v.sati<<endl;

    }
class Dan{
    int d;
    int m;
    int g;
    public:
    Dan(){
        d = 1;
        m = 1;
        g = 2023;
    }
    Dan(int d, int m, int g){
        this->d = d;
        this->m = m;
        this->g = g;
    }
    ~Dan(){
        delete this;
    }
    void ispis(){
        cout<<d<<"."<<m<<"."<<g<<"."<<endl;
    }
};
class Korisnik{
    char ime[30];
    char kime[20];
    string lozinka;
    TIP tipKorisnik;
    string adminOrGost(){
        switch(tipKorisnik){
            case ADMIN: return "admin";
            case GOST : return "gost";
        }
    }
    public:
    void promenaLozinke(string stara, string nova){
        if(stara == lozinka){
        lozinka = nova;
        cout<<"Loznika uspesno promenjena"<<endl;}
        else
        cout<<"Stara loznika i uneta se ne poklapaju"<<endl;
    }
    Korisnik(){
        cout<<"Unesite ime - max 30karaktera"<<endl;
        cin>>ime;
        cout<<"Unesite korsnicko ime - max 20 karaktera"<<endl;
        cin>>kime;
        cout<<"Unesite lozinku"<<endl;
        cin>>lozinka;
        tipKorisnik = GOST;
    }
    Korisnik(char i[], char k[], string l, TIP tip){
        strcpy(ime,i);
        strcpy(kime,k);
        lozinka = l;
        tipKorisnik = tip; 
    }
    ~Korisnik(){
    };
    friend class Clanak;

};
class Komentar{
    string tekst;
    Dan datum;
    Vreme vreme;
    int popularnost;
    string autor;
    public:
    Komentar(){
        tekst = "";
        autor = "X";
        popularnost = 0;
    }
    Komentar(string t, Dan d, Vreme v, int p, string a){
        tekst = t;
        datum = d;
        vreme = v;
        popularnost = p;
        autor = a;
    }
    void ispis(){
        cout<<"Komentar "<<tekst<<" popularnost "<<popularnost<<" autor "<<autor<<endl;
        datum.ispis();
        if(vreme.getSek())
        vreme.info(1);
        else vreme.info(0);
    }
};
class Clanak{
    char naslov[50];
    string sadrzaj;
    Dan datum;
    Vreme vreme;
    int brojPregleda;
    string *tagovi;
    char oblast[100];
    string autor;
    Komentar *kom;
    int brT;
    int brK;
    public:
    Clanak(){
        strcpy(naslov, "");
        sadrzaj = "";
        brojPregleda = 0;
        strcpy(oblast, ""); 
        tagovi = new string[1];
        autor = "";
        kom = new Komentar[1];
    }
    Clanak(char n[], string s, Dan d, Vreme v, int brTag, int br, char o[], string a, int brKom, Komentar *kom1){
        strcpy(naslov, n);
        sadrzaj = s;
        datum = d;
        vreme = v;
        brojPregleda = br;
        tagovi = new string[brTag];
        cout<<"Unesite tagove"<<endl;
        for(int i = 0; i< brTag; i++){
            cin>>tagovi[i];
        }
        brT = brTag;
        autor = a;
        kom = new Komentar[brKom];
        for(int i = 0; i< brKom; i++){
            kom[i] = kom1[i]; 
        }
        brK = brKom;
    }


    void dodajTag(string tag, Korisnik kor){
        string *pom = new string[brT];
        for(int i = 0; i<brT; i++){
            pom[i]=tagovi[i];
        }
        delete [] tagovi;
        brT++;
        tagovi = new string[brT];
        for(int i = 0; i<brT-1; i++){
            tagovi[i]=pom[i];
        }
        tagovi[brT-1]=tag;
        delete [] pom;
    }
    void dodajKoment(Komentar kom1, Korisnik kor){
        if(kor.adminOrGost()=="gost"){
        Komentar *pom= new Komentar[brK];
        for(int i = 0; i<brK; i++){
            pom[i]=kom[i];
        }
    delete [] kom;
        brK++;
        kom = new Komentar[brK];
        for(int i = 0; i<brK-1; i++){
            kom[i]=pom[i];
        }
        kom[brK-1]=kom1;
        delete [] pom;}
        else 
        cout<<"Admin ne moze dodavati komentare"<<endl;}
    void promeniSadrzaj(string s, Vreme v, Korisnik k){
        if(autor == k.kime){
        sadrzaj = s;
        vreme = v;}
        else cout<<"NEDOZVOLJENO!"<<endl;

    }
};

int main(){
    Vreme v1(5,2,36);
    Vreme v2(1, 5, 35);
    Vreme v3 = v1 + v2;
    v3.info(1);
    cout<<v3;
}