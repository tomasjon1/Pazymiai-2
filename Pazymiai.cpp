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
    int *pazymiai = nullptr;
    int pazymiuKiekis = 0;
    int egzaminas;
    double rezultatas = 0;
};

void ivedimas(studentas& data, bool ndSkaicius);
void isvedimas(studentas& data, bool mediana);

int main()
{
    int studentuKiekis = 0;
    string atsMediana;
    string atsNdSkaicius;
    bool mediana = false;
    bool ndSkaicius = false;

    cout << "Iveskite studentu kieki: "; cin >> studentuKiekis;
    studentas* studentai = new studentas[studentuKiekis];
    cout << "Ar notire naudoti mediana vietoje vidurkio (taip/ne): "; cin >> atsMediana;
    cout << "Ar notire namu darbu skaiciai yra zinomi (taip/ne): "; cin >> atsNdSkaicius;
    
    if (atsMediana == "taip") {
        cout << "Atsakymas bus su mediana." << endl;
        mediana = true;
    }
    else 
        cout << "Atsakymas bus su vidurkiu." << endl;

    if (atsNdSkaicius == "taip") {
        cout << "Namu darbu skaiciai yra zinomi" << endl;
        atsNdSkaicius = true;
    }
    else
        cout << "Namu darbu skaiciai yra nezinomi" << endl;


    for (studentas* studentas = studentai; studentas < studentai + studentuKiekis; studentas++) 
        ivedimas(*studentas, ndSkaicius);

    if(mediana)
        cout << endl << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Med.)" << endl;
    else
        cout << endl << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << endl;
    for (studentas* studentas = studentai; studentas < studentai + studentuKiekis; studentas++) 
        isvedimas(*studentas, mediana);
    
}

void ivedimas(studentas& data, bool ndSkaicius) {
    cout << "Iveskite studento pavarde: "; cin >> data.pavarde;
    cout << "Iveskite studento varda: "; cin >> data.vardas;

    if(ndSkaicius){
        cout << "Iveskite studento namu darbu kieki: "; cin >> data.pazymiuKiekis;
        data.pazymiai = new int[data.pazymiuKiekis];
        for (int x = 0; x < data.pazymiuKiekis; x++) {
            cout << "Iveskite " << x + 1 << " -a(-i) pazymi: "; cin >> data.pazymiai[x];
        }
    }
    else {
        int paz;
        string atsStop;
        while (true) {
            cout << "Iveskite " << data.pazymiuKiekis + 1 << " -a(-i) pazymi arba 0, kad sustoti: "; cin >> paz;
            if (paz == 0) break;
            int* temp = new int[data.pazymiuKiekis];
            for (int x = 0; x < data.pazymiuKiekis; x++) temp[x] = data.pazymiai[x];
            delete[] data.pazymiai;
            data.pazymiuKiekis++;
            data.pazymiai = new int[data.pazymiuKiekis];
            for (int x = 0; x < data.pazymiuKiekis - 1; x++) data.pazymiai[x] = temp[x];
            data.pazymiai[data.pazymiuKiekis - 1] = paz;
        }
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

//PATVARKYTI FINAL REZ SKAICIAVIMA

//ar kai yra zinomas namu darbu skaicius, jis viesiems yra vienodas?