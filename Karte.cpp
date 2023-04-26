//  Написати на језику C++ следеће класе (класе опремити оним конструкторима,
// деструктором и операторима доделе који су потребни за безбедно и ефикасно коришћење класа):
//  (15 поена) Карта се задаје знаком (PIK, TREF, KARO, HERC) и бројем (К1=1, К2, К3, К4, К5,
// К6, К7, К8, К9, К10=10, ZANDAR=12, DAMA=13, KRALJ=14). Може да се одреди вредност
// карте према следећем критеријуму: жандар, дама, краљ, 1 и 10 = 1 поен, 2 треф = 1 поен, 10
// каро = 2 поена, док све остале карте вреде 0 поена. Могуће је упоредити број на две карте
// (karta1>karta2), као и вредност коју носе две карте (karta1>>karta2). Карту је могуће
// уписати у излазни ток (it<<karta) у облику karta(број, знак).
//  (40 поена) Шпил се састоји од произвољног броја карата. Ствара се празан после чега се карте
// додају једна по једна на крај шпила (spil+=karta). Могуће је узети карту са краја шпила
// (spil--), при чему било каква грешка приликом узимања карте доводи до прекида програма.
// Може да се одреди укупан број карата у шпилу, укупна вредност свих карата у шпилу (spil())
// и да се дохвати карта са највећим бројем. Два шпила је могуће упоредити на основу укупне
// вредности свих карата у њима (spil1>spil2) или на основу карте са највећим бројем
// (spil1>>spil2) – први шпил је већи од другог ако је највећа карта у првом шпилу већа од
// највеће карте у другом шпилу. Шпил се у излазни ток исписује (it<<spil) тако што се у првој
// линији испише spil(број_карата), а затим се у засебним линијама исписују појединачне
// карте из шпила.
//  (5 поена) Тест се састоји од два шпила који се задају приликом стварања. Могуће је узети карту
// (test--) из првог шпила, док се у случају да је први шпил празан, карта узима из другог
// шпила. Тест је завршен када оба шпила постану празна. Може се проверити да ли је тест
// завршен. 
#include <iostream>
#include <string>
using namespace std;
using std ::string;
enum ZNAK {PIK, TREF, KARO, HERC};
enum BROJ {KARTA1=1, KARTA2, KARTA3, KARTA4, KARTA5, KARTA6, KARTA7, KARTA8, KARTA9, KARTA10, ZANDAR=12, DAMA=13, KRALJ=14};
class Karta{
ZNAK znak;
BROJ broj;
public:
 Karta(){
    znak=PIK;
    broj = DAMA;
 }
 Karta(ZNAK znak, BROJ broj){
    this->znak = znak;
    this->broj = broj;
 }
 int vrednost(){
    if(broj==10 && znak==KARO) return 2;
    else if(broj == ZANDAR || broj == DAMA || broj == KRALJ || broj == 1 || broj ==10 || (broj==2 && znak==KARO))
        return 1;
    else return 0;
};
bool operator>(Karta &k){
    return broj>k.broj;
};
bool operator>>(Karta &k){
    return this->vrednost()>k.vrednost();
}
friend ostream& operator<<(ostream& out, const Karta& karta) {
        string znak_str;
        switch (karta.znak) {
            case PIK:
                znak_str = "PIK";
                break;
            case TREF:
                znak_str = "TREF";
                break;
            case KARO:
                znak_str = "KARO";
                break;
            case HERC:
                znak_str = "HERC";
                break;
        }
        out << "karta(" << karta.broj << ", " << znak_str << ")";
        return out;
    }

};
class Spil{
    int maxbrKarata;
    int trBr;
    Karta *karte;
    public:
    Spil(){
        maxbrKarata = 0;
        karte = nullptr;
        trBr = -1;
    }
    Spil(int br){
        karte = new Karta[br];
        trBr = -1;
    }
    void operator +=(Karta &k){
        if(maxbrKarata>trBr)
        karte[++trBr] = k;
        else cout<<"NEMA MESTA U SPILU"<<endl;
    };
    void operator --(int){
        if(trBr!=-1)
        karte[trBr--];
        else cout<<"Spil je prazan"<<endl;
    }
    int ukupanBr(){
        return trBr+1;
    }
    int ukupnaVrednost(){
        int s = 0;
        for(int i = 0; i <trBr; i++){
            s+=karte[i].vrednost();
        }
        return s;
    };
    Karta najveca(){
        int max = karte[0].vrednost();
        Karta pom;
        for(int i =1; i <trBr; i++){
            if(max<karte[i].vrednost()){
            max = karte[i].vrednost();
            pom = karte[i];};
        }
        return pom;
        
    }
    bool operator >(Spil &k){
       return ukupnaVrednost()> k.ukupnaVrednost();
    }
    bool operator >>(Spil &k){
        return this->najveca().vrednost()> k.najveca().vrednost();
    }
 friend ostream& operator<<(ostream& it, const Spil& s){
        it<<s.trBr<<"je broj karata u spilu"<<endl;
        for(int i = 0; i < s.trBr; i++){
            it<<s.karte[i];
        }
    }
    bool isEmpty(){
    if(trBr!=-1) return true;
    else return false;
}};
class Test {
    Spil t1;
    Spil t2;
    public:
    void operator--(int){
        if(t1.isEmpty())
        t1--;
        else{
            if(t2.isEmpty())
            t2--;
            else cout<<"Spilovi su prazni";
        }
        
    }
};
int main(){
    Karta card1;
    Karta card2;
    Karta card3;
    Karta card4(KARO, KARTA10);
    Karta card5(PIK, KARTA10);
    Karta card6(KARO, KARTA1);




    // compare two cards
    if (card1 > card2) {
        cout << "card1 is greater than card2" << std::endl;
    } else {
        cout << "card2 is greater than card1" << std::endl;
    }

   
    cout << "The value of card4 is: " << card4.vrednost() << std::endl;


    Spil deck(8);
    deck += card1;
    deck += card2;
    deck += card3;
    deck += card4;
    deck += card5;
    deck += card6;

    cout << "The deck has " << deck.ukupanBr() << " cards." << endl;
    deck--;
    cout << "The deck has " << deck.ukupanBr() << " cards." << endl;
    cout<<"Najveca"<<deck.najveca();
}
