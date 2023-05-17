#include <iostream>
using namespace std;
template <class T, int k=10>
class Vektor{
public:
int n;
T *niz;
public:
Vektor(){
    n= k;
    niz = new T[n];
}
T& operator[](int i){
    return niz[i];
}
class A{
    public:
    int p;
    A(){
        p = 5;
    }
}
// preklopiti operator indeksiranja
};
int main(){
    Vektor<int,5> obj1;
    Vektor<float,3> obj2;
    for(int i=0; i<5; i++){
        obj1.niz[i] = i+1;
        cout<<"3. element prvog niza je "<<obj1[2]<<endl;
    }
    // Vektor<A,5> obj3;
return 0;
};