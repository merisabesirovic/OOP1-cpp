#include <iostream>
using namespace std;
using std::string;
class Clan{
    int broj;
    string ime;
    float stanje;
    bool pocasni;
    public:
    Clan(){
        broj = 123;
        ime= "Merisa";
        stanje = 0.0;
        pocasni = false;
    }
    Clan(int broj, string name){
    this->broj = broj;
    ime = name;
    }
    void set(float novoStanje, bool pocasni){
        stanje = novoStanje;
        this->pocasni = pocasni;
    }
    string getIme(){
        return ime;
    }
    Clan(const Clan &objekat){
     this->broj = objekat.broj;
     this->ime = objekat.ime;
     this->stanje = objekat.stanje;
     this->pocasni = objekat.pocasni;
    }
    void ispis(){
        cout<<broj<<" "<<ime<<" "<<stanje<<" "<<pocasni<<endl;
    }
};
int main(){
    Clan c1;
    c1.ispis();
    


}