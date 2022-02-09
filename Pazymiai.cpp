#include <string>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <algorithm>

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

void ivedimas(studentas& data, bool ndSkaicius, bool generavimas);
void isvedimas(studentas& data, bool mediana);
void nezinomuNdPazIvedimas(studentas& data, int paz);

int main()
{
    int studentuKiekis = 0;
    string atsMediana;
    string atsNdSkaicius;
    string atsGeneravimas;
    bool mediana = false;
    bool ndSkaicius = false;
    bool generavimas = false;

    cout << "Iveskite studentu kieki: "; cin >> studentuKiekis;
    studentas* studentai = new studentas[studentuKiekis];
    cout << "Ar notire naudoti mediana vietoje vidurkio (taip/ne): "; cin >> atsMediana;
    cout << "Ar namu darbu skaiciai yra zinomi (taip/ne): "; cin >> atsNdSkaicius;
    cout << "Ar notire namu darbu pazymius generuoti automatiskai (taip/ne): "; cin >> atsGeneravimas;
    
    if (atsMediana == "taip") {
        cout << "Atsakymas bus su mediana." << endl;
        mediana = true;
    }
    else 
        cout << "Atsakymas bus su vidurkiu." << endl;

    if (atsNdSkaicius == "taip") {
        cout << "Namu darbu skaiciai yra zinomi" << endl;
        ndSkaicius = true;
    }
    else
        cout << "Namu darbu skaiciai yra nezinomi" << endl;

    if (atsGeneravimas == "taip") {
        cout << "Namu darbu pazymiai bus genereruojami" << endl;
        generavimas = true;
    }
    else
        cout << "Namudarbu pazymiai ne bus genereruojami" << endl;


    for (studentas* studentas = studentai; studentas < studentai + studentuKiekis; studentas++) 
        ivedimas(*studentas, ndSkaicius, generavimas);

    if(mediana)
        cout << endl << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Med.)" << endl;
    else
        cout << endl << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << endl;
    for (studentas* studentas = studentai; studentas < studentai + studentuKiekis; studentas++) 
        isvedimas(*studentas, mediana);
}

void ivedimas(studentas& data, bool ndSkaicius, bool generavimas) {
    cout << endl;
    cout << "Iveskite studento pavarde: "; cin >> data.pavarde;
    cout << "Iveskite studento varda: "; cin >> data.vardas;

    if(ndSkaicius){
        cout << "Iveskite studento namu darbu kieki: "; cin >> data.pazymiuKiekis;
        cout << endl;
        data.pazymiai = new int[data.pazymiuKiekis];
        if (generavimas) {
            for (int x = 0; x < data.pazymiuKiekis; x++) {
                data.pazymiai[x] = rand() % 10 + 1;
                cout << "Ivestas " << x + 1 << " pazimys bus: " << data.pazymiai[x] << endl;
            }
            data.egzaminas = rand() % 10 + 1;
            cout << "Ivestas studento egzamino pazymis bus: " << data.egzaminas << endl;
        }
        else {
            for (int x = 0; x < data.pazymiuKiekis; x++) {
                cout << "Iveskite " << x + 1 << " -a(-i) pazymi: "; cin >> data.pazymiai[x];
            }
            cout << "iveskite studento egzamino pazymi: "; cin >> data.egzaminas;
        }
    }
    else {
        if (generavimas) {
            int paz;
            string atsStop;
            while (true) {
                cout << "Spauskite enter sugeneruoti " << data.pazymiuKiekis + 1 << " -a(-i) pazymi arba bet koki kita klavisa ir enter, kad sustoti: " << endl;
                if (cin.get() != '\n') 
                    break;
                paz = rand() % 10 + 1;
                cout << "Sugeneruotas pazymis yra: " << paz << endl;
                nezinomuNdPazIvedimas(data, paz);
            }
            data.egzaminas = rand() % 10 + 1;
            cout << "Ivestas studento egzamino pazymis bus: " << data.egzaminas << endl;
        }
        else {
            int paz;
            string atsStop;
            while (true) {
                cout << "Iveskite " << data.pazymiuKiekis + 1 << " -a(-i) pazymi arba 0, kad sustoti: "; cin >> paz;
                if (paz == 0) 
                    break;
                nezinomuNdPazIvedimas(data, paz);
            }
            cout << "iveskite studento egzamino pazymi: "; cin >> data.egzaminas;
        }
    }
    cout << endl;

}

void isvedimas(studentas& data, bool mediana) {
    cout << std::setw(20) << data.vardas << std::setw(20) << data.pavarde;

    if (mediana) {
        std::sort(data.pazymiai, data.pazymiai + data.pazymiuKiekis);
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

void nezinomuNdPazIvedimas(studentas& data, int paz) {
    int* temp = new int[data.pazymiuKiekis];
    for (int x = 0; x < data.pazymiuKiekis; x++) temp[x] = data.pazymiai[x];
    delete[] data.pazymiai;
    data.pazymiuKiekis++;
    data.pazymiai = new int[data.pazymiuKiekis];
    for (int x = 0; x < data.pazymiuKiekis - 1; x++) data.pazymiai[x] = temp[x];
    data.pazymiai[data.pazymiuKiekis - 1] = paz;
}

//PATVARKYTI FINAL REZ SKAICIAVIMA
//SUTVARKYT KODA IR PADARYTI GRAZIUS OUTPUTUS