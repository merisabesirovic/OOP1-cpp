// Realizovati klasu Polinom koja treba ima dinamicki alocirani niz *koeficijenti i stepen polinoma n.
// Konstruktore sa i bez argumenata, copy konstruktor, ispis I metoda izracunaj(x) koja racuna vrednost polinoma za x.
// U main funkciji napraviti objekat klase i testirati sve metode
#include <iostream>
#include <cmath>
using namespace std;
class Polinom{
float *koeficijenti;
int n;
    public:
    Polinom(){
        cout<<"Unesite stepen polinoma"<<endl;
        cin>>n;
        koeficijenti = new float[n+1];
        cout<<"Unesite koeficijente polinom"<<endl;
        for(int i=0; i<n+1; i++){
            cin>>koeficijenti[i];
        };
    }
    Polinom(int n1){
        n=n1;
        koeficijenti = new float[n+1];
        cout<<"Unesite koeficijente polinom"<<endl;
        for(int i=0; i<n+1; i++){
            cin>>koeficijenti[i];
        };
    }
    Polinom (Polinom const &polinom){
        this->n=polinom.n;
        koeficijenti = new float[n+1];
        for(int i=0; i<n+1; i++){
            this->koeficijenti[i] = polinom.koeficijenti[i];
        }
    }
    void ispis(){
        cout<<koeficijenti[0]<<"x"<<"+";
        for(int i=1; i<n+1; i++){
            cout<<koeficijenti[i]<<"x"<<"^"<<i;
            cout<<"+";
        }
        cout<<endl;
    }
    float izracunajPolinom(float x){
        float s=koeficijenti[0];
        for(int i=1; i<n+1; i++){
            s+=(koeficijenti[i])*pow(x,i);
        }
    return s;
    }
};
int main() {
    Polinom p1;
    Polinom p2(3);
    p2.ispis();
    Polinom p3(p2);
    p3.ispis();
    cout<<p3.izracunajPolinom(2);
    

}