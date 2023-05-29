/*Realizovati sledeće klase (klase opremiti onim konstruktorima, destruktorima i operatorima dodele (preklopljenim operatorima) 
koji su potrebni za bezbedno i efikasno korišćenje.
Nalepnica ima naziv i jednoznačni automatski generisan identifikator kojem može da se pristupi.Naziv se zadaje sa standardnog 
ulaza prilikom stvaranje objekta. Prilikom kopiranja voditi računa da se kopira naziv a da se identifikator sam kreira. Omogućiti 
metodu za ispis. 
Flaša pića ima sledeće podatke: nalepnicu, cenu bez kaucije (u koju nije uračunata cena flaše), zapreminu (podrazumevano 0,33 litara) 
i vrstu pića. Vrsta pića može biti BEZALKOHOLNO (podrazumevano) i ALKOHOLNO. Svi podaci se unose prilikom stvaranja objekta i mogu se 
odštampati, a samo se cena može promeniti. Kreirati metodu koja može da izračuna cenu flaše pića sa kaucojom(ima razlike za staklenu 
i plastičnu flašu). Metodu PROVERA koja proverava da li su dve flaše jednake (flaše su jednake ukoliko imaju isti naziv nalepnice,
 cenu flaše sa kaucijom i vrstu pića. Omogućiti metodu za ispis.
Staklena flaša pića je flaša pića kod koje se cena sa kaucijom računa tako što se na cenu bez kaucije doda 5% ukoliko je zapremina
 manja od 0,5 litara ili 10% ukoliko je zapremina veća ili jednaka od 0,5 litara. Preklopiti metodu ispis da ispisuje podatke o 
 flaši i poruku da je flaša staklena.
Plastična flaša pića je flaša pića kod koje je cena sa kaucijom jednaka ceni bez kaucije. Preklopiti metodu za ispis da ispisuje
 podatke o flaši i poruku da je flaša plastnična.
Formirati funkciju UKUPNO, van klasa koja formira dinamički niz staklenih i plastičnih flaša čije podatke unosi korisnik sa tastature
 i zatim računa i vraća ukupan zbir svih flaša sa kaucijom.
U main funkciji napraviti po jedan objekat svake klase i testirati sve metode, kao i funkciju UKUPNO.
*/
#include <iostream>
using namespace std;
using std::string;
class Nalepnica {
    int posId;
    string naziv;
public:
    static int id;
    
    Nalepnica() {
        cout << "Unesite ime nalepnice" << endl;
        cin >> naziv;
        posId=++id;
    }
    
Nalepnica(Nalepnica const &n) {
        naziv = n.naziv;
        posId=++id;
    }
    
    ~Nalepnica() {};
    
    void ispis() {
        cout << naziv << " ima id " << posId<< endl;
    }
    
    string getNaziv() {
        return naziv;
    }
};

int Nalepnica::id = 0;
class Flasa{
public:
enum Vrsta {
    ALKOHOLNO, BEZALKOHOLNO
};
protected:
Nalepnica nalepnica;
float cenaBezKaucije;
float zapremina;
Vrsta vrsta;
public:
Flasa(Nalepnica const &n, float c, float z=0.33, Vrsta v=BEZALKOHOLNO){
nalepnica = n;
cenaBezKaucije = c;
zapremina = z;
vrsta = v;
}
string nadjiVrstu(){
    string result;
    switch(vrsta){
        case BEZALKOHOLNO: result = "Bezalkohlno";
        break;
        case ALKOHOLNO: result = "Alkoholno";
        return result;
    }
}
void print(){
    nalepnica.ispis();
    cout<<" kosta "<<cenaBezKaucije<<" ima zapreminu "<<zapremina<<"a pice je "<<nadjiVrstu()<<endl;
    
}
void setCena(float c){
    cenaBezKaucije = c;
}
virtual float cenaSaKaucijom()const{
   return cenaBezKaucije; 
}
bool operator==(Flasa &f2){
    return (cenaSaKaucijom()==f2.cenaSaKaucijom() && nalepnica.getNaziv()==f2.nalepnica.getNaziv() && nadjiVrstu()==f2.nadjiVrstu());
}
};
class StaklenaFlasa : public Flasa{
    public:
    StaklenaFlasa(Nalepnica const &n, float c, float z=0.33, Vrsta v=BEZALKOHOLNO):Flasa(n,c,z,v){};
    float cenaSaKaucijom(){
        if(zapremina<0.5)
        return cenaBezKaucije + cenaBezKaucije * 0.05;
        else return cenaBezKaucije + cenaBezKaucije *0.1;
    }
void print(){
    nalepnica.ispis();
    cout<<"je staklena flasa i kosta "<<cenaSaKaucijom()<<" ima zapreminu "<<zapremina<<"a pice je "<<nadjiVrstu()<<endl;
}
};
class Plasticna : public Flasa{
    public:
    Plasticna(Nalepnica const &n, float c, float z=0.33, Vrsta v=BEZALKOHOLNO):Flasa(n,c,z,v){};
    void print(){
    nalepnica.ispis();
    cout<<"je plasticna flasa i kosta "<<cenaSaKaucijom()<<" ima zapreminu "<<zapremina<<"a pice je "<<nadjiVrstu()<<endl;
}
};
float UKUPNO(const Flasa** flase, int brojFlasa) {
    float ukupno = 0.0;
    for (int i = 0; i < brojFlasa; i++) {
        ukupno += flase[i]->cenaSaKaucijom();
    }
    return ukupno;
};
int main() {
    Nalepnica nalepnica1;
    nalepnica1.ispis();
    Nalepnica nalepnica2;
    
    
    nalepnica2.ispis();
    
    Flasa flasa1(nalepnica1, 10.0);
    Flasa flasa2(nalepnica2, 15.0, 0.5, Flasa::ALKOHOLNO);
    
    flasa1.print();
    flasa2.print();
   
    
    
    flasa1.setCena(12.0);
    flasa2.setCena(18.0);
    
    flasa1.print();
    flasa2.print();
    
    StaklenaFlasa staklenaFlasa(nalepnica1, 20.0, 0.4, Flasa::BEZALKOHOLNO);
    Plasticna plasticnaFlasa(nalepnica2, 25.0, 0.6, Flasa::ALKOHOLNO);
    
    staklenaFlasa.print();
    plasticnaFlasa.print();
    
    float ukupno = UKUPNO(new const Flasa*[4]{&flasa1, &flasa2, &staklenaFlasa, &plasticnaFlasa}, 4);
    cout << "Ukupna cena svih flaša sa kaucijom: " << ukupno << endl;
    
    return 0;
}
