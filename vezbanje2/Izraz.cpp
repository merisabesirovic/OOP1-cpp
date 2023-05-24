/*Napraviti program koji ce realizovati klase izraz1 i izraz2.
Izraz1 se sastoji od sledecih obelezja:
char op1  - promenljiva znakovnog tipa koja obelezava operaciju (+,-,*,/)
operand1 - celobrojna promenljiva prvi operand
operand2 - celobrojna promenljiva drugi operand
Metode konstruktor bez argumenata postavlja operaciju na + a operande na 2 i 5;
Konstruktor sa argumentima (operand1, operancd2, operacija1)
set i get metode;
polimorfna metoda double izracunaj() - racuna rezultat na osnovu operacije (sabiranje, mnozenje, deljenje ili oduzimanje)
metoda ispis() - ispisuje operand1 operand2 i operaciju.
Klasa izraz2 nasledjuje klasu izraz1 i dodaje jos op2 - operacija 2
i operand3 - celobrojna promenljiva koja predstavlja treci operand.
Metode:Konstruktor bez argumenata (postavlja operande na 2, 5 i 3 a operacija na + i *)
Konstruktor sa argumentima.set i get metode.
polimorfnu metodu double izracunaj() koja racuna rezultat ali sada vodi racuna o prioritetu koja operacija se prva izvodi (* i /) pa tek onda (+ i -);
void ispis() ispisuje obelezja();
Testirate sve metode u glavom programu.
*/