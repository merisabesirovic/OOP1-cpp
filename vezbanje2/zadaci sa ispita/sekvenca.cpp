/*1) (укупно 100 поена) Написати на језику C++ следећи систем класа. Класе опремити оним
конструкторима, деструктором и операторима доделе који су потребни за безбедно и ефикасно
коришћење класа. Грешке пријављивати изузецима типа једноставних класа које су опремљене
писањем текста поруке. За генеричке збирке није дозвољено коришћење класа из стандардне
библиотеке шаблона (STL).
• (30 поена) Секвенца садржи произвољан број података неког типа. Елементи се могу додавати
на крај секвенце. Може се узети елемент са почетка секвенце. Може се дохватити елемент са
произвољне позиције у секвенци, као и дужина секвенце. Грешка је уколико се покуша
додавање новог елемента након узимања првог елемента из секвенце.
• (10 поена) Разломак се ствара задавањем целобројног имениоца и бројиоца. Подразумевана
вредност имениоца је 1. Два разломка је могуће сабрати (r1 + r2) и упоредити (r1 > r2).
Разломак је могуће уписати у излазни ток (it << razlomak) у облику бројилац/именилац.
• (10 поена) Музички знак се ствара задавањем трајања у виду разломка. Трајање је могуће
дохватити. Сабирањем два музичка знака (znak1 + znak2) добија се збир њихових трајања.
Музички знак је могуће имплицитно конвертовати у разломак који представља његову дужину.
Могуће је саставити текстуални опис музичког знака. Знак се у излазни ток уписује
(it<<znak) у облику текстуални_опис(трајање).
• (10 поена) Нота је музички знак који се ствара задавањем октаве (цео број у опсегу 1-5), висине
(DO, RE, MI, FA, SOL, LA, SI) и трајања. Ноту је могуће померити за произвољан број октава
наниже (nota<<=pomeraj) или навише (nota>>=pomeraj), што се извршава смањивањем
целобројне вредности октаве приликом померања наниже, односно увећавањем исте приликом
померања навише. Текстуални опис ноте је облика висина. Пауза је музички знак који се ствара
задавањем трајања. Текстуални опис паузе је _.
• (20 поена) Такт се састоји од секвенце музичких знакова. Ствара се празан са задатим
разломком који одређује максимално трајање свих музичких знакова који се налазе у њему.
Могуће је дохватити максимално трајање такта. Могуће је додати музички знак у такт. Грешка
је уколико се додавањем музичког знака прелази максимално трајање такта. Могуће је завршити
такт након чега се у њега више не могу додавати музички знакови. Такт је непотпун уколико је
збир трајања музичких знакова у њему мањи од максималног трајања такта. Може се проверити
да ли је такт завршен, као и да ли је непотпун. Приликом уписа у излазни ток (it<<takt)
уписују се сви музички знакови одвојени знаком размака, а затим знак |. Такт није могуће
копирати ни на који начин.
• (20 поена) Композиција се састоји од секвенце тактова. Ствара се празна након чега се тактови
додају један по један. Грешка је уколико такт који се додају у композицију није завршен. Сви
тактови у оквиру композиције морају бити једнаког максималног трајања. Непотпун такт се
може појавити само на почетку и крају композиције. Композиција се у излазни ток уписује
(it<<kompozicija) тако што се сваки такт упише у по једном реду. Композицију није могуће
копирати ни на који начин.
(0 поена) Приложена је главна функција која направи једну композицију са неколико тактова и
испише је на главни излаз.*/
// #include <iostream>
// using namespace std;
// using std::string;
// template <typename S>
// class Sekvenca{
// S *sekvenca;
// int tr;
// int n;
// int uzeto=0;
// public:
// Sekvenca(int n){
//     sekvenca = new S[n];
//     tr=-1;
//     this->n = n;
// }
// Sekvenca(){
//     sekvenca = new S[10];
//     tr=-1;
// }
// void dodaj(S el){
// if(tr<n && uzeto==0){
//     if(tr==-1) tr=0;
//     sekvenca[tr]=el;
//     tr++;
// }
// else cout<<"ERROR"<<endl;
// }
// void ispis(){
//     for(int i=0;i<tr;i++){
//         cout<<sekvenca[i]<<" ";
//     }
//     cout<<endl;
// }
// S getPrvi(){
//     uzeto = 1;
//     cout<<sekvenca[0]<<endl;
//     return sekvenca[0];

// }
// S getRandom(int poz){
//     return sekvenca[poz-1];
// }
// int getDuzina(){
//     return tr;
// }
// ~Sekvenca(){
//     delete [] sekvenca;
// }
// };
// class Razlomak{
// int imenilac;
// int brojilac;
// public:
// Razlomak(int imenilac=1,int brojilac=1){
//     this->imenilac = imenilac;
//     this->brojilac = brojilac;
// };
// friend Razlomak operator+(Razlomak &r1, Razlomak &r2){
//     if(r1.imenilac!=r2.imenilac){
//         int pom2 = r1.imenilac;
//         r1.imenilac=r2.imenilac*r1.imenilac;
//         r1.brojilac=r1.brojilac*r2.imenilac;
//         r2.brojilac = r2.brojilac*pom2;
//         return Razlomak(r1.imenilac,r1.brojilac+r2.brojilac);
//     }
//     else{
//         return Razlomak(r1.brojilac + r2.brojilac, r1.imenilac);
//     }
// }
// friend bool operator>(Razlomak &r1, Razlomak &r2){
//     float pom1=(float)r1.brojilac/r1.imenilac;
//     float pom2=(float)r2.brojilac/r2.imenilac;
//     return (pom1>pom2);

// }
// friend ostream &operator<<(ostream &os,const Razlomak &r){
//     os<<r.brojilac<<"/"<<r.imenilac<<endl;
//     return os;
// }
// int getImenilac(){
//     return imenilac;
// }
// int getBrojilac(){
//     return brojilac;
// }
// };
// class Znak{
// Razlomak t;
// public:
// Znak(int i,int b){
//    t= Razlomak(i, b);
// }
// Razlomak getZnak(){
//     return t;}
// friend Razlomak operator+(Znak &a,Znak &b){
//     return a.t+b.t;
// }
// friend ostream &operator<<(ostream &os,const Znak &z){
//     os<<z.t<<endl;
//     return os;
// }
// };
// class Nota:public Znak{
//     public: enum Visina{DO, RE, MI, FA, SOL, LA, SI};  
//     private: Visina v;
//     int oktava;
//     public: Nota(int oktava, Visina v, Razlomak trajanje) : Znak(trajanje.getBrojilac(), trajanje.getImenilac()){
//         if(oktava>1 && oktava<6)
//         this->oktava=oktava;
//         this->v=v;
//     }
// };
// class Pauza:public Znak{
//     public:
// Pauza(Razlomak trajane) : Znak(trajane.getBrojilac(), trajane.getImenilac()){};
// string opis(){
//     return "-";
// }};
// class Takt{
//     Sekvenca <Znak> sekvenca;   
//     Razlomak max, trajanje;
//     public:
//     Takt(Razlomak max){
//         sekvenca=Sekvenca<Znak>();
//         this->max = max;
//     }
//     Razlomak getMax(){
//         Razlomak max = sekvenca.getRandom(0).getZnak();
//         for(int i=0; i<sekvenca.getDuzina(); i++){
//             if(sekvenca.getRandom(i).getZnak()>max)
//             max=sekvenca.getRandom(i).getZnak();
//         }
//         return max;
//     }
//     void dodajZnak(Znak z){
//         if(z.getZnak()>max)
//         cout<<"error"<<endl;
//         else{
//             sekvenca.dodaj(z);
//         }
//     }
// };







// int main(){
//     Sekvenca <int> s(8);
//     s.dodaj(6);
//     s.dodaj(7);
//     s.dodaj(8);
//     s.dodaj(9);
//     s.ispis();
//     s.getPrvi();
//     s.dodaj(3);
//     s.ispis();
//    cout<<s.getDuzina()<<endl;
//    Razlomak r1(6,8);
//    cout<<r1;
//    Razlomak r2(3,4);
//    cout<<r2;
//    cout<<(r1+r2);
//    if(r1>r2) cout<<"prvi veci"<<endl;
//    else cout<<"drugi veci"<<endl;
//     Znak z(4,4);
//     cout<<z;
//     Takt z1(r1);
//     z1.dodajZnak(z);
    
    

 
// }
#include <iostream>
#include <string>
using namespace std;

template <typename S>
class Sekvenca {
    S* sekvenca;
    int tr;
    int n;
    int uzeto;

public:
    Sekvenca(int n) {
        sekvenca = new S[n];
        tr = 0;
        this->n = n;
        uzeto = 0;
    }

    Sekvenca() : Sekvenca(10) {}

    void dodaj(S el) {
        if (tr < n && uzeto == 0) {
            if (tr == -1)
                tr = 0;
            sekvenca[tr] = el;
            tr++;
        } else {
            cout << "ERROR" << endl;
        }
    }

    void ispis() {
        for (int i = 0; i < tr; i++) {
            cout << sekvenca[i] << " ";
        }
        cout << endl;
    }

    S getPrvi() {
        uzeto = 1;
        cout << sekvenca[0] << endl;
        return sekvenca[0];
    }

    S getRandom(int poz) {
        return sekvenca[poz - 1];
    }

    int getDuzina() {
        return tr;
    }

    ~Sekvenca() {
        delete[] sekvenca;
    }
};

class Razlomak {
    int imenilac;
    int brojilac;

public:
    Razlomak(int imenilac = 1, int brojilac = 1) {
        this->imenilac = imenilac;
        this->brojilac = brojilac;
    }

    friend Razlomak operator+(const Razlomak& r1, const Razlomak& r2) {
        if (r1.imenilac != r2.imenilac) {
            return Razlomak(r1.imenilac * r2.imenilac, r1.brojilac + r2.brojilac*r1.imenilac);
        } else {
            return Razlomak(r1.brojilac + r2.brojilac, r1.imenilac);
        }
    }

    friend bool operator>(const Razlomak& r1, const Razlomak& r2) {
        float pom1 = static_cast<float>(r1.brojilac) / r1.imenilac;
        float pom2 = static_cast<float>(r2.brojilac) / r2.imenilac;
        return (pom1 > pom2);
    }

    friend ostream& operator<<(ostream& os, const Razlomak& r) {
        os << r.brojilac << "/" << r.imenilac << endl;
        return os;
    }

    int getImenilac() {
        return imenilac;
    }

    int getBrojilac() {
        return brojilac;
    }
};

class Znak {
    Razlomak t;

public:
    Znak(int i, int b) {
        t = Razlomak(i, b);
    }

    Razlomak getZnak() {
        return t;
    }

    friend Razlomak operator+(const Znak& a, const Znak& b) {
        return a.t + b.t;
    }

    friend ostream& operator<<(ostream& os, const Znak& z) {
        os << z.t << endl;
        return os;
    }
};

class Nota : public Znak {
public:
    enum Visina { DO, RE, MI, FA, SOL, LA, SI };

private:
    Visina v;
    int oktava;

public:
    Nota(int oktava, Visina v, Razlomak trajanje)
        : Znak(trajanje.getBrojilac(), trajanje.getImenilac()) {
        if (oktava > 1 && oktava < 6)
            this->oktava = oktava;
        this->v = v;
    }
};

class Pauza : public Znak {
public:
    Pauza(Razlomak trajane) : Znak(trajane.getBrojilac(), trajane.getImenilac()) {}

    string opis() {
        return "-";
    }
};

class Takt {
    public:
    Sekvenca<Znak> sekvenca;
    Razlomak max;
    Takt(Razlomak max) {
        sekvenca = Sekvenca<Znak>();
        this->max = max;
    }

    Razlomak getMax() {
        Razlomak max = sekvenca.getRandom(0).getZnak();
        for (int i = 0; i < sekvenca.getDuzina(); i++) {
            if (sekvenca.getRandom(i).getZnak() > max)
                max = sekvenca.getRandom(i).getZnak();
        }
        return max;
    }

    void dodajZnak(Znak z) {
        if (z.getZnak() > max) {
            cout << "error" << endl;
        } else {
            sekvenca.dodaj(z);
        }
    }
};

int main() {
    Takt takt(Razlomak(3, 4));
    Znak znak1(1, 4);
    Znak znak2(1, 8);
    Znak znak3(1, 2);
    takt.dodajZnak(znak1);
    takt.dodajZnak(znak2);
    takt.dodajZnak(znak3);
    takt.sekvenca.ispis();

    return 0;
}
