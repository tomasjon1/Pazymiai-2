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
    int pazymiuKiekis;
    int egzaminas;
    double rezultatas = 0;
};

void ivedimas(studentas& data);
void isvedimas(studentas& data);

int main()
{
    setlocale(LC_ALL, "Lithuanian");
    int studentųKiekis;
    cout << "Įveskite studentų kiekį: "; cin >> studentųKiekis;
    studentas* studentai = new studentas[studentųKiekis];

    for (studentas* studentas = studentai; studentas < studentai + studentųKiekis; studentas++) ivedimas(*studentas);
    for (studentas* studentas = studentai; studentas < studentai + studentųKiekis; studentas++) isvedimas(*studentas);
    
}

void ivedimas(studentas& data) {
    cout << "Įveskite studento vardą: "; cin >> data.vardas;
    cout << "Įveskite studento pavardę: "; cin >> data.pavarde;
    cout << "Įveskite studento namų darbų kiekį: "; cin >> data.pazymiuKiekis;
    data.pazymiai = new int[data.pazymiuKiekis];
    for (int x = 0; x < data.pazymiuKiekis; x++) {
        cout << "Įveskite " << x + 1 << " -ą(-į) pažymį"; cin >> data.pazymiai[x];
    }
    cout << "Įveskite studento egzamino pažymį: "; cin >> data.egzaminas;
}

void isvedimas(studentas& data) {
    cout << std::setw(20) << data.vardas << std::setw(20) << data.pavarde;
    for (int x = 0; x < data.pazymiuKiekis; x++) data.rezultatas += data.pazymiai[x];
    data.rezultatas = data.rezultatas / data.pazymiuKiekis;
    cout << std::setw(20) << data.rezultatas;
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
