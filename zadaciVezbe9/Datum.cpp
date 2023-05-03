// Realizovati klase Datum i Rodjendan.
// Klasa Datum ima javne atribute dan,mesec i godina.
// Metode: konstruktor sa i bez argumenata, ispis koja ispisuje u formatu Danas je d.m.g,Datum uporedi(Datum d) metoda koja upoređuje
//  trenutni datum i datum koji dolazi kao argument (d) i vraća koliko dana, meseci  i godina ima između ova dva datuma.
// Klasa Rodjendan nasledjuje javno klasu Datum i dodaje ime i prezime osobe. 
// Metode: konstruktor sa i bez argumenata,bool daLiJe(Datum d) koja vraća true ako jeste rodjendan datuma d, odnosno false ako nije. 
// void ispisSlavljenika(Datum dat) koja ispisuje poruku ako je danas rodjendan osobi,
//  a ako nije onda ispisuje jos koliko dana i meseci ima do rodjendana
//   (koristeći metodu klase Datum za nalaženje razlike – to je moguće jer je klasa Rodjendan nasledila sve atribute i metode klase Datum),
//    int godine(Datum dat) koja vraća koliko godina ima osoba do datuma dat koji dolazi kao argument.
#include <iostream>
#include <cmath>
using namespace std;
using std::string;
class Datum{
    public:
    int d,m,g;
    Datum(){
        d=1;
        m=1;
        g=2023;
    }
    Datum(int d, int m, int g){
      this->d=d;
      this->m=m;
      this->g=g;
    }
    void ispis(){
        cout<<"Danas je "<<d<<"."<<m<<"."<<g<<endl; 
    }
    Datum Uporedi(Datum dat){
        Datum r;
        if(d>dat.d)
        r.d = d - dat.d;
        else{
            m--;
            switch (m)
          {
          case 1:case 3: case 5:case 7: case 8: case 10 : case 12 : 
          d+=31;
          break;
          case 4:case 6:case 9: case 11:
          r.d = 30+d - dat.d;
          break;
          case 2:
            if((g % 4 == 0 && g % 100 != 0) || (g % 400 == 0))
            r.d = 29+d - dat.d;
            else
            r.d = 28+d - dat.d;                      
                }
                m --;
              }
                if(m == 0)
             {
             m = 12;
                   g --;
                 }
                if(m >= dat.m)

            {
                  r.m = m - dat.m;
                }
                else
                {
                  r.m = 12 + m - dat.m;
                  g --;   
                }
                r.g = g - dat.g;
      return r;
      }
};
class Rodjendan : public Datum
{
    public:
      string ime;
      string prezime;
      public:
      Rodjendan(){
        ime = "Petar";
        prezime = "Petrovic";
      }

};
// odrediti koliko tacno dana izmedju dva dana
