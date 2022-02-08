#include <string>
#include <iomanip>
#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;


struct studentas {
    string vardas = "";
    string pavarde = "";
    int *pazymiai;
    int pazymiuKiekis;
    int egzaminas;
    double rezultatas = 0;
};

void ivedimas(studentas& data, bool mediana);
void isvedimas(studentas& data, bool mediana);

int main()
{
    int studentuKiekis = 0;
    string atsMediana;
    bool mediana = false;

    cout << "Iveskite studentu kieki: "; cin >> studentuKiekis;
    studentas* studentai = new studentas[studentuKiekis];
    cout << "Ar notire naudoti mediana vietoje vidurkio (taip/ne): "; cin >> atsMediana;
    
    if (atsMediana == "taip") 
        mediana = true;
    else 
        cout << "Atsakymas bus su vidurkiu." << endl;


    for (studentas* studentas = studentai; studentas < studentai + studentuKiekis; studentas++) 
        ivedimas(*studentas, mediana);

    if(mediana)
        cout << endl << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Med.)" << endl;
    else
        cout << endl << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << endl;
    for (studentas* studentas = studentai; studentas < studentai + studentuKiekis; studentas++) 
        isvedimas(*studentas, mediana);
    
}

void ivedimas(studentas& data, bool mediana) {
    cout << "Iveskite studento pavarde: "; cin >> data.pavarde;
    cout << "Iveskite studento varda: "; cin >> data.vardas;
    cout << "Iveskite studento namu darbu kieki: "; cin >> data.pazymiuKiekis;
    data.pazymiai = new int[data.pazymiuKiekis];
    for (int x = 0; x < data.pazymiuKiekis; x++) {
        cout << "Iveskite " << x + 1 << " -a(-i) pazymi: "; cin >> data.pazymiai[x];
    }
    cout << "iveskite studento egzamino pazymi: "; cin >> data.egzaminas;
}

void isvedimas(studentas& data, bool mediana) {
    cout << std::setw(20) << data.vardas << std::setw(20) << data.pavarde;
    if (mediana) {
        for (int x = 0; x < data.pazymiuKiekis; x++)
            for (int y = 0; y < data.pazymiuKiekis; y++)
                if (data.pazymiai[x] > data.pazymiai[y])
                    std::swap(data.pazymiai[x], data.pazymiai[y]);
        if (data.pazymiuKiekis % 2 !=  0)
            data.rezultatas = (double)data.pazymiai[data.pazymiuKiekis / 2];
        else
            data.rezultatas = (double)(data.pazymiai[(data.pazymiuKiekis - 1) / 2] + data.pazymiai[data.pazymiuKiekis / 2]) / 2.0;
    }
    else {
        for (int x = 0; x < data.pazymiuKiekis; x++) data.rezultatas += data.pazymiai[x] * 1.0;
        data.rezultatas = data.rezultatas / data.pazymiuKiekis;
    }
    cout << std::setw(20) << data.rezultatas << endl;
}

