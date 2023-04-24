#include <iostream>
#include <string>
using namespace std;

class Stack {
    char* s;
    int max_size;
    int top;

public:
    Stack(int size) {
        s = new char[size];
        max_size = size;
        top = -1;
    }

    Stack(int size, const char string[]) {
        s = new char[size];
        max_size = size;
        for (int i = 0; i < size; i++) {
            s[i] = string[i];
        }
        top = size - 1;
    }

    void reset() {
        top = -1;
    }

    void push(char c) {
        s[++top] = c;
    }

    char pop() {
        return s[top--];
    }

    char topOf() {
        return s[top];
    }

    bool isFull() {
        if (top == max_size - 1)
            return true;
        else
            return false;
    }

    bool isEmpty() {
        if (top == -1)
            return true;
        else
            return false;
    }
};

int main() {
    Stack s1(3);
    char x;
    s1.reset();
    cout << "Unesite niz karaktera za ubacivanje u stek: ";
    while (!s1.isFull()) {
        cin >> x;
        if (x == EOF) {
            break;
        }
        else {
            s1.push(x);
        }
    }
    while (!s1.isEmpty()) {
        cout << s1.pop() << " ";
    }
    cout << endl;
    Stack s2(4, "ABCD");
    while (!s2.isEmpty()) {
        cout << s2.pop() << " ";
    }
    cout << endl;

    return 0;
}
