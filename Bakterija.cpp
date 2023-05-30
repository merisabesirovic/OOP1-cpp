/*укупно 70 поена) Написати на језику C++ следеће класе (класе опремити оним конструкторима,
деструктором и операторима доделе, који су потребни за безбедно и ефикасно коришћење
класа):
• (20 поена) Супстанца има назив (string) који се задаје приликом стварања и може да се
дохвати. Може да упише свој назив у излазни ток (it<<supstanca).
• Једноћелијски организам има стање ZIV или MRTAV (подразумевано ZIV). Може да направи
свој клон, да реагује са задатом супстанцом и да у излазни ток упише назив свог стања
(it<<organizam). Не може да се копира ни премешта, ни иницијализацијом ни доделом.
• (20 поена) Бактерија је једноћелијски организам који има задате назив (string), назив
супстанце која јој шкоди (string) и вероватноћу успешног клонирања (подразумевано 50%).
Бактерија памти број успешних клонирања. Након реакције са супстанцом која јој шкоди,
бактерија прелази у стање MRTAV, и тада се сваки покушај клонирања завршава неуспехом.
Може да се упише у излазни ток (it<<bakterija) у облику
назив/бр.усп.клонирања(организам). Напомена: функција rand() генерише случајaн цео
број у опсегу од 0 до RAND_MAX.
• (20 поена) Колонија једноћелијских организама има јединствен, аутоматски генерисан,
целобројан идентификатор. Садржи произвољан број организама. Ствара се задавањем једног
организма који постаје члан колоније. Колонија може да се размножи, при чему се од сваког
организма прави клон и додаје у колонију. Може да реагује са задатом супстанцом, при чему
супстанца реагује са сваким организмом у колонији. Колонија не може да се копира ни
премешта, ни иницијализацијом ни доделом. Може да се упише у излазни ток
(it<<kolonija) у облику (ид.број){oрганизам | oрганизам | ... | oрганизам}.
(10 поена) Написати на језику C++ програм који направи једну колонију бактерија осетљивих на
цефалоспорин, затим неколико пута изврши размножавање колоније и испише је на главном
излазу. Потом изврши реакцију колоније са цефалоспорином и поново испише колонију на
главном излазу.*/
#include <iostream>
using namespace std;
using std::string;
class Supstanca{
    string naziv;
    public:
    Supstanca(string naziv){
        this->naziv = naziv;
    }
    Supstanca(){
        naziv = "";
    }
    string getNaziv()const{
        return naziv;
    }
    void ispis(){
        cout<<"Supstanca koje je u pitanju je"<<naziv<<endl;
    }
};
class JednocelijskiOrganizam{
    public:
    enum Stanje{ZIV, MRTAV};
    protected:
    Stanje stanje;
    public:
    JednocelijskiOrganizam(){
        stanje = ZIV;
    }
    virtual JednocelijskiOrganizam *kopija()=0;
    string nadjiStanje()const{
        switch (stanje)
        {
        case ZIV: return "ZIV";
            break;
    case MRTAV: return "MRTAV";
            break;
        }
    }
    void setStanje(Stanje stanje){
        this->stanje = stanje;
    }
    virtual void reakcija(Supstanca &s)=0;
   friend ostream& operator<<(ostream& stream, const JednocelijskiOrganizam& o) {
    stream << o.nadjiStanje();
    return stream;
}
};
class Bakterija:public JednocelijskiOrganizam{
    string naziv;
    string stetnaSupstanca;
    int verovatnoca;
    int uspesnaKloniranja;
    public:
    Bakterija(string naziv, string stetnas, int v=50):JednocelijskiOrganizam(){
        this->naziv=naziv;
        stetnaSupstanca=stetnas;
        verovatnoca=v;
        uspesnaKloniranja=0;
    }
    Bakterija *kopija()override {
        if(stanje==MRTAV){
            cout<<"Neuspesno kloniranje"<<endl;
            return nullptr;
        }
        else {
            uspesnaKloniranja++;
            return new Bakterija(naziv,stetnaSupstanca,verovatnoca);
        }
    };
    void reakcija(Supstanca &s){
        if(s.getNaziv()==stetnaSupstanca){
            setStanje(MRTAV);
        }
        else return;
    }
    friend ostream& operator<<(ostream& stream, const Bakterija& b) {
    stream << b.naziv << "/" << b.uspesnaKloniranja << "(" << static_cast<const JednocelijskiOrganizam&>(b) << ")";
    return stream;
}
};
class Kolonija{
public:
static int posId;
private:
int id;
JednocelijskiOrganizam **organizmi;
int max;
int tr;
public:
Kolonija(int max, JednocelijskiOrganizam *org){
    id=++posId;
    this->max=max;
    organizmi= new JednocelijskiOrganizam *[max];
    tr=0;
    organizmi[tr]=org;
    tr++;
}
void dodaj(JednocelijskiOrganizam *p){
    if(max>tr){
        organizmi[tr]=p;
        tr++;
    }
    else {
        cout<<"Nema mesta"<<endl;
    }
}
void Razmnozi(){
    JednocelijskiOrganizam *org;
    Bakterija *b;
    for(int i=0; i<tr; i++){
        org=organizmi[i];
        dodaj(org->kopija());
    }
}
void reaguj(Supstanca &s){
for(int i=0; i<tr; i++){
    organizmi[i]->reakcija(s);
}
}
friend ostream& operator<<(ostream& os, const Kolonija& k) {
    os << "(" << k.id << "){";
    for (int i = 0; i < k.tr; i++) {
        os << *k.organizmi[i];
        if (i != k.tr - 1) {
            os << " | ";
        }
    }
    os << "}";
    return os;
}


};
int Kolonija::posId=0;
int main() {
    Supstanca s1("Supstanca1");
    Supstanca s2("Supstanca2");
    
    Bakterija b1("Bakterija1", "Supstanca1");
    Bakterija b2("Bakterija2", "Supstanca2");
    
    Kolonija kolonija(5, &b1);
    kolonija.dodaj(&b2);
    cout<<kolonija<<endl;
    
    kolonija.Razmnozi();
    cout<<kolonija<<endl;
    
    kolonija.reaguj(s1);
    kolonija.reaguj(s2);
    
    cout << kolonija;
    
    return 0;
}
