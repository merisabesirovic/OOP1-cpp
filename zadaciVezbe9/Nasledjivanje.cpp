// #include <iostream>
#include <iostream>
using std::string;
using namespace std;
 class Proizvod{
    protected:
    int barkod;
    float cena;
    float kolicina;
    public:
    Proizvod(){
cout<<"Pozvao se konsturkotr bez argumenata";
barkod = 123;
cena = 130;
kolicina = 2000;}

Proizvod(float c, float k, int bk){
cout<<"Pozvao se konsturkotr bez argumenata";
barkod = bk;
cena = c;
kolicina = k; }
void ispis(){
    cout<<barkod<<" "<<cena<<" "<<kolicina<<endl;
}
};
class Radnik{
    protected:
    string ime;
    string prezime;
    public:
    Radnik(){
        cout<<"Pozvao se konsturkotr bez argumenata"<<endl;
        ime = "Petar";
        prezime = "Petrovic";
    }
     Radnik(string i, string p){
        cout<<"Pozvao se konsturkotr sa argumenata"<<endl;
        ime = i;
        prezime = p;
    }
    void ispis(){
        cout<<"Podaci o radniku"<<endl;
        cout<<ime<<endl;
        cout<<prezime<<endl;
    }
};
class Prodavnica:Proizvod, Radnik{
private:
float br;
float cenaPoSatu;
public:
Prodavnica(){
    cout<<"Pozvao se konsturkor bez argumenata"<<endl;
    br = 160;
    cenaPoSatu = 8.5;
}
Prodavnica(float brs, float cps);Proizvod(bk, c, k), Radnik(i,p){
    cout<<"Pozvao se konsturkor sa argumenata"<<endl;
    br = brs;
    cenaPoSatu = cps;
}
void ispis(){
    cout<<"Podaci o prodavnici su "<<endl;
    cout<<br<<endl;
    cout<<cenaPoSatu<<endl;
    Proizvod::ispis();
    Radnik::ispis();
}
float Plata(){
    return br*cenaPoSatu;
}
void Prodaj(float kol){
    if(kol <= kolicina){
    cout<<"Artikal je prodat u kolicini"<<endl;
    float racun = kol*cena;
    cout<<racun<<endl;
    kolicina -=kol;}
    else 
    cout<<"Nemamo zeljenju kolicinu"<<endl;
}
};
int main(){
    Prodavnica p1;
    Prodavnica p2(120,10,111,1600,50, "Dzejlana", "Radoncic");
    p1.ispis();
    p2.ispis();
    cout<<"Radnik u prvoj prodavnici ima platu"<<p1.Plata()<<endl;
    cout<<"Radnik u drugoj prodavnici ima platu"<<p2.Plata()<<endl;
    p1.Prodaj(5);
    p2.Prodaj(30);

}

