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
    int pazymiuKieks;
    int egzaminas;
    double rezultatas;
};

void ivedimas(studentas& data);

int main()
{
    cout << "Hello World!\n";
}

void ivedimas(studentas& data) {
    cout << "Įveskite studento vardą: "; cin >> data.vardas;
    cout << "Įveskite studento pavardę: "; cin >> data.pavarde;
    cout << "Įveskite studento namų darbų kiekį: "; cin >> data.pazymiuKieks;
    data.pazymiai = new int[100000];
    for (int x = 1; x <= data.pazymiuKieks; x++) {
        cout << "Įveskite " << x << " -ą(-į) pažymį"; cin >> data.pazymiai[x];
    }
    cout << "Įveskite studento egzamino pažymį: "; cin >> data.egzaminas;
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
