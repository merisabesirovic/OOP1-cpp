// Написати на језику C++ следеће класе (класе опремити оним конструкторима
// и деструктором који су потребни за безбедно и ефикасно коришћење класа у општем случају):
//  (20 поена) Артикал има назив, реалну цену и целобројни износ попуста (подразумевано 0).
// Подаци артикла се задају при стварању (није потребна провера). Може да се дохвати назив,
// цена са попустом и износ попуста. На главном излазу се исписује у облику
// назив(цена_са_попустом).
//  (20 поена) Ставка рачуна се креира за задати артикал и задату целобројну количину. Ставки
// рачуна се додељује редни број на рачуну приликом додавања ставке на рачун. Може да се
// израчуна износ ставке рачуна као производ количине и цене артикла. Може да се дохвати
// артикал ставке. На главном излазу се исписује у облику S
// редни_број_на_рачуну(артикал):количина|износ.
//  (30 поена) Рачун садржи произвољан број ставки и целобројни износ додатног попуста.
// Ствара се празан, након чега се ставке додају појединачно. Може да се постави износ
// додатног попуста. Може да се израчуна износ рачуна као сума износа свих појединачних
// ставки на рачуну. Уколико постоји додатни попуст, он се обрачунава само за артикле који
// већ нису на попусту. На главном излазу се исписује у облику Racun: износ_рачуна, а затим
// се у сваком реду исписује по једна ставка у облику ставка [износ_са_додатним_попустом].
//  (0 поена) Приложена је главна функција која ствара један рачун и у њега дода неколико ставки
// са по једним артиклом. Након тога створи нови рачун као копију претходног, одобри се додатан
// попуст на нови рачун, а затим испише оригинални и нови рачун на главном излазу. Називе
// класа и метода прилагодити главној функцији, тако да се програм може превести и извршити. 
#include <iostream>
using namespace std;
using std::string;
class Artikal{
string naziv;
float cena;
int popust;
public:
    Artikal(){
        naziv ="";
           cena = 0.0;
           popust = 0; 
        }
    Artikal(string n, int p, float c){
        naziv = n;
        popust = p;
        cena = c;  
    }
    string getNaziv() const {
        return naziv;
    }
    float cenaSaPopustom() const{
        return cena-(cena*(popust*0.01));
    }
    int getPopust(){
        return popust;
    }
    void ispis(){
        cout<<"("<<naziv<<")"<<cenaSaPopustom()<<endl;
    }
};
class Stavka{
    Artikal artikal;
    int kolicina;
    public:
    static int redniBr;
    Stavka(int kolicina, Artikal a){
        artikal = a;
        this->kolicina = kolicina;
        redniBr++;
    }
    Stavka(){
        kolicina = 0;
        redniBr++;
    }
    float iznosStavke() const{
        return kolicina * artikal.cenaSaPopustom();
    }
    Artikal getArtikal(){
        return artikal;
    }
  friend ostream& operator<<(ostream& S, const Stavka& s) {
        S << s.redniBr << ". " << s.artikal.getNaziv() << " : " << s.kolicina << " | " << s.iznosStavke() << endl;
        return S;
    }
};
class Racun{
Stavka *stavka;
int dodatniPopust;
public:
static int trBr;
    Racun(){
        stavka = new Stavka[++trBr];
        dodatniPopust = 0;
    }
Racun(int dodatniPopust, Stavka s){
    if(trBr==0){
        stavka = new Stavka[1];
        stavka[0] = s;
        trBr++;
    }
    else{
    Stavka *pom = new Stavka[trBr];
    for(int i = 0; i < trBr; i++){
        pom[i] = stavka[i];
    };
    delete []stavka;
    stavka = new Stavka[trBr+1];
    for(int i = 0; i < trBr; i++){
        stavka[i] = pom[i];
    }
    stavka[trBr++]=s;}
}
    void setDdodatniPopust(int d){
        dodatniPopust = d;
    }
    float iznosRacuna(){
        float s = 0.0;
        for(int i = 0; i < trBr; i++){
            if(stavka[i].getArtikal().getPopust())
            s+=stavka[i].iznosStavke();
            else s+=stavka[i].iznosStavke()-(stavka[i].iznosStavke()*(dodatniPopust*0.01));
        }
        return s;
    }
    void ispis(){
        cout<<"Iznos racuna :"<<iznosRacuna()<<endl;
        for(int i = 0; i < trBr; i++){
            cout<<stavka[i]<<endl;
        };
    }
};
int Stavka::redniBr = 0;
int Racun::trBr = 0;
int main(){
    Artikal a("mleko", 20, 1000);
    a.ispis();
    Stavka s(4, a);
    Artikal b("hleb", 0, 200);
    cout<<s<<endl;
    Stavka s2(2,a);
    Stavka p(2,b);
    cout<<s2<<endl;
    Racun r(20,s);
    r.ispis();
    Racun r2(10,p);
    r2.ispis();
}
