#include <iostream>
using namespace std;

template <class T>
float srednjaV(T* a, int n) {
    float s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
    }
    return s / n;
}

template <class T>
void unos(T* niz, int n) {
    cout << "Unesite vrednosti niza" << endl;
    for (int i = 0; i < n; i++) {
        cin >> niz[i];
    }
}

template <class T>
void ispis(T* niz, int n) {
    cout << "Elementi niza su:" << endl;
    for (int i = 0; i < n; i++) {
        cout << niz[i] << " ";
    }
}

int main() {
    int* niz = new int[6];
    unos(niz, 6);
    ispis(niz, 6);
    cout << "Srednja vrednost niza je " << srednjaV(niz, 6);
    delete[] niz;
    return 0;
}
