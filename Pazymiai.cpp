#include <string>
#include <iomanip>
#include <iostream>

using std::cout;
using std::cin;
using std::string;

struct studentas {
    string vardas = "";
    string pavarde = "";
    int *pazymiai;
    int egzaminas;
    double rezultatas;
};

int main()
{
    cout << "Hello World!\n";
}


// 1. 

// susikurti struktura mokiniui
// funkcija sukasi tiek kiek yra mokiniu
// funckija nuskaityti duomenis
//      funkcija nuskaito varda pavarde
//      funkcija nuskaito mokinio nd skaiciu
//      funkcija nuskaito mokinio n pazymius
//      funkcija nuskaito mokinio egzamino rezultata
//      funkcija apskaiciuoja metini rezultata
// funkcija atspausdinimui

// 2.

//Papildyti pirmaja funckija su parametru (bool) arReikiaMedianos
//Papildyti mokinio struktura su medianos fieldu
//Pakeisti funckija
//      Dadedti if kuris tikrina ar reikia medianos
//      Atlikti skaiciavima su mediana
//Pakeisti spausdinimo funkcija
//      Patikrinti ar reikia spausdinti medianos stulpeli

// 3. 
