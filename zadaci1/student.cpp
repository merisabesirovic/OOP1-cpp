// /*
// 	Realizovati klasu Student koja ima privatne atribute ime,prezime i broj indeksa.
// 	Metode: inicijalizacija(char* i,char* p,int b) postavlja vrednosti atribute na vrednosti koje dolazi kao argumenti i ispis koja ispisuje vrednosti atributa.
// */
#include <iostream>
using namespace std;
using std::string;
class Student {
    string name;
    string prezime;
    int brojIndeksa;
public:
void inicijalizacija(string i, string p, int b){
    name = i;
    prezime = p;
    brojIndeksa = b;
}
void ispis(){
    cout<<"Ime i prezime studenta:"<<name<<" "<<prezime<<" broj indeksa:"<<brojIndeksa<<endl;
}

};
int main (){
    Student student1; 
    student1.inicijalizacija("Merisa", "Besirovic", 36012);
    student1.ispis();
    student1.inicijalizacija("Merisa2", "Besirovic", 364984);
    student1.ispis(); 

}