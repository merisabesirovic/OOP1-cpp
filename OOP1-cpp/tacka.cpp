/*
	Realizovati klasu Tacka sa privatnim atributima x i y.
	Metode: inicijalizacija(a,b) koja postavlja vrednosti atributa na vrednosti koje dolazi kao argumenti, translacija(int dx,int dy) koja translira tacku za vrednosti dx po x, odnosno dy po y osi;
	pozicija() ispisuje trenutnu poziciju tacke u koordinatnom sistemu (njene x i y koordinate) 
*/
#include <iostream>
using namespace std;
class Tacka {
int x, y;
public :
void inicijalizacija(int a, int b);
void translacija(int dx, int dy);
void ispisPozicije();
}tacka1;
void Tacka::inicijalizacija(int a, int b){
    x=a; y=b;
}
void Tacka::translacija(int dx, int dy){
    x+=dx; y+=dy;
}
void Tacka:: ispisPozicije(){
    cout << "Pozicija tacke na x osi x: "<<x<<" i pozicija tacke na y osi y: "<<y<<endl;

}
int main(){
    Tacka tacka1;
    tacka1.inicijalizacija(2,3);
    tacka1.ispisPozicije();
    tacka1.translacija(6,2);
    tacka1.ispisPozicije();
    return 0;
}