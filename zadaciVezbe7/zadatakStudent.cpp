#include <iostream>
using namespace std;
using std::string;
enum FINANSIRANJE {SAMOFINANSIRANJE, BUDZET};
class Student{
    string ime;
    int index;
    FINANSIRANJE finansiranje;
    string nadjiFinansiranje(){
        if(finansiranje==0)
        return "SAMOFINANSIRANJE";
        else return "BUDZET";
    }
    float prosek;
    public:
    Student(string n, FINANSIRANJE f){
        ime = n;
        finansiranje = f;
        prosek = 0;
    }
    Student(){
        ime = "Merisa";
        finansiranje = BUDZET;
        prosek = 0;
    }
    string getName(){
        return ime;
    }
    float getProsek(){
        return prosek;
    }
    int getIndex(){
        return index;
    }
    void setIndex(int i){
        index = i;
    }
    void noviIspit(int ocena){
        if(ocena<=10 && ocena>5){
            if(prosek==0)prosek = ocena;
            else prosek = (ocena + prosek)/2.0;}
        else cout << "Ocena nine validna";

    }
    void ispis(){
        cout << "Broj indeksa"<<index<<"Ime studenta"<<ime << "Finansiranje"<<nadjiFinansiranje()<<endl;
    }
    FINANSIRANJE getFinansiranje(){
        return finansiranje;
    }


};
class StudijskiProgram{
    string naziv;
    int max;
    Student *studenti;
    int br;
    float prosekSP(){
            float s=0;
            for(int i=0;i<br;i++){
                s+=studenti[i].getProsek();
            }
            return s/br;
        }
    public:
    StudijskiProgram(string n, int m){
        naziv = n;
        max = m;
        br = 0;
        studenti = new Student[max];
    };
    void dodajStudenta(Student *s) {
    if (br < max) {
        int brIndexa;
        if (br > 0)
            brIndexa = studenti[br - 1].getIndex() + 1;
        else
            brIndexa = 1;
        s->setIndex(brIndexa);
        studenti[br] = *s;
        br++;
    } else {
        cout << "Nema slobodnog mesta za dodavanje studenta" << endl;
    }
}

    void brisiStudenta(){
        if(br>0)
        br--;
    }
    friend bool BoljiSp(StudijskiProgram &s1, StudijskiProgram &s2){
        if(s1.prosekSP()>s2.prosekSP())
        return true;
    else return false;
    }
    void Ispis(){
        for(int i=0;i<br;i++){
            cout <<studenti[i].getName()<<endl;
        }
        cout<<"Na studijskom programu "<<naziv<<" ima "<<br<<" studentata i prosek studijskog programa je "<<prosekSP()<<endl;
    }

    };

int main(){
Student s1("merisa", BUDZET), s2("merisa2", BUDZET), s3("merisa3", SAMOFINANSIRANJE);
StudijskiProgram sp1("softversko inzenjerstvo", 60), sp2("racunarska tehnika", 100);
s1.noviIspit(10);
s1.noviIspit(9);
s1.noviIspit(10);
s1.noviIspit(8);
s2.noviIspit(7);
s3.noviIspit(10);
sp1.dodajStudenta(&s1);
sp1.dodajStudenta(&s2);
sp2.dodajStudenta(&s3);
if(BoljiSp(sp1,sp2)==true)
    cout<<"Prvi studijski program je bolji"<<endl;
else cout<<"Drugi studijski program je bolji"<<endl;
sp1.Ispis();
sp2.Ispis();

}