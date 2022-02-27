#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <vector>
#include <algorithm>
#include <functional>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;


struct studentas {
    string vardas = "";
    string pavarde = "";
    vector<int> pazymiai;
    int pazymiuKiekis = 0;
    int egzaminas;
    double rezultatasVid = 0;
    double rezultatasMed = 0;
};

void ivedimas(studentas& data, bool generavimas);
void isvedimas(studentas& data, ofstream& fout);
int ivestoSkaiciausPatikrinimas();
string atsakymoIvedinimoPatikrinimas();
bool pazymioPatikrinimas(int n);
int ivestiPazymi();
void skaitymasIsFailo(ifstream& fin, vector<string>& length, vector<studentas>& studentai);

int main()
{
 
    srand(time(NULL));

    int studentuKiekis = 0;
    string atsGeneravimas;
    string atsStudentuSkaicius;
    string atsFailoSkaitymas;
    bool generavimas = false;
    bool studentuSkaicius = false;
    bool failoSkaitymas = false;
   
    vector<studentas> studentai;
    std::ofstream fout("rez.txt");


    cout << "Ar notire studentus nuskaityti is failo (taip/ne): "; atsFailoSkaitymas = atsakymoIvedinimoPatikrinimas();
        
    if (atsFailoSkaitymas == "taip") {

        vector<string> antrastineEilute;
        std::ifstream fin("studentai.txt");
        skaitymasIsFailo(fin, antrastineEilute, studentai);

    }
    else
    {
        cout << "Ar studentu skaicius yra zinomas (taip/ne): "; atsStudentuSkaicius = atsakymoIvedinimoPatikrinimas();
        cout << "Ar notire namu darbu pazymius generuoti automatiskai (taip/ne): "; atsGeneravimas = atsakymoIvedinimoPatikrinimas();
        cout << endl;

        if (atsStudentuSkaicius == "taip") {
            cout << "Studentu skaicius yra zinomas" << endl;
            studentuSkaicius = true;
        }
        else cout << "Namu darbu skaiciai yra nezinomi" << endl;

        if (atsGeneravimas == "taip") {
            cout << "Namu darbu pazymiai bus genereruojami" << endl;
            generavimas = true;
        }
        else cout << "Namudarbu pazymiai nebus genereruojami" << endl;


        if (studentuSkaicius)
        {
            cout << "Iveskite studentu kieki: "; studentuKiekis = ivestoSkaiciausPatikrinimas();
            for (int x = 0; x < studentuKiekis; x++)
            {
                studentas temp;
                ivedimas(temp, generavimas);
                studentai.push_back(temp);
            }
        }
        else
        {
            string ats;
            while (true) {
                cout << "Ar notire ivesti dar studenta (taip/ne): "; ats = atsakymoIvedinimoPatikrinimas();
                if (ats == "ne")
                    break;
                studentas temp;
                ivedimas(temp, generavimas);
                studentai.push_back(temp);
            }
        }
    }

    std::sort(studentai.begin(), studentai.end(), [](studentas& a, studentas& b){ return a.vardas < b.vardas; });
     
    fout << std::setw(20) << "VARDAS" << std::setw(20) << "PAVARDE" << std::setw(20) << "GALUTINS (Vid.)" << std::setw(20) << "GALUTINS (Med.)" << endl;

    for (studentas studentas : studentai) isvedimas(studentas, fout);

    
}

void ivedimas(studentas& data, bool generavimas) {
    cout << endl;
    cout << "Iveskite studento pavarde: "; cin >> data.pavarde;
    cout << "Iveskite studento varda: "; cin >> data.vardas;

        cout << "Iveskite studento namu darbu kieki: "; data.pazymiuKiekis = ivestoSkaiciausPatikrinimas();
        cout << endl;
        if (generavimas) {
            for (int x = 0; x < data.pazymiuKiekis; x++) {
                data.pazymiai.push_back(rand() % 10 + 1);
                cout << "Ivestas " << x + 1 << " pazymyss bus: " << data.pazymiai[x] << endl;
            }
            data.egzaminas = rand() % 10 + 1;
            cout << "Ivestas studento egzamino pazymys bus: " << data.egzaminas << endl;
        }
        else {
            for (int x = 0; x < data.pazymiuKiekis; x++) {
                cout << "Iveskite " << x + 1 << " -a(-i) pazymi: "; data.pazymiai.push_back(ivestiPazymi());
            }
            cout << "iveskite studento egzamino pazymi: "; data.egzaminas = ivestiPazymi();
        }
    cout << endl;
}
//
void isvedimas(studentas& data, ofstream& fout) {
    fout << std::setw(20) << data.vardas << std::setw(20) << data.pavarde;

    std::sort(data.pazymiai.begin(), data.pazymiai.end());
    if (data.pazymiuKiekis % 2 !=  0) data.rezultatasMed = 0.4 * (double)data.pazymiai[data.pazymiuKiekis / 2] + 0.6 * data.egzaminas;
    else data.rezultatasMed = 0.4 * ((double)(data.pazymiai[(data.pazymiuKiekis - 1) / 2] + data.pazymiai[data.pazymiuKiekis / 2]) / 2.0) + 0.6 * data.egzaminas;
   
    for (int x = 0; x < data.pazymiuKiekis; x++) data.rezultatasVid += data.pazymiai[x] * 1.0;
    data.rezultatasVid = (0.4 * (data.rezultatasVid / data.pazymiuKiekis)) + 0.6 * data.egzaminas;
    
    fout << std::setw(20) << data.rezultatasMed << std::setw(20) << data.rezultatasVid << endl;
}

int ivestoSkaiciausPatikrinimas()
{
    int n;
    while (true)
    {
        cin >> n;
        if (cin.good())
            return n;
        else
        {
            cout << "Ne numeris" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }
}

string atsakymoIvedinimoPatikrinimas() {
    string ats;
    do {
        cin >> ats;
        if (ats != "taip" && ats != "ne")
        {
            cout << ats;
            cout << "Atsakymas turi buti (taip arba ne)" << endl;
        }
    } while (ats != "taip" && ats != "ne");
    return ats;
}

bool pazymioPatikrinimas(int paz)
{
    if (paz > 0 && paz <= 10)
        return true;
    else
    {
        cout << "Blogas pazymys" << endl;
        return false;
    }
}

int ivestiPazymi() 
{
    while (true)
    {
        int paz = ivestoSkaiciausPatikrinimas();
        if (pazymioPatikrinimas(paz)) return paz;
    }
}

void skaitymasIsFailo(ifstream& fin, vector<string>& length, vector<studentas>& studentai)
{
    string t;
    while ((fin.peek() != '\n') && (fin >> t))
        length.push_back(t);
    length.resize(length.size() - 3);

    while (!fin.eof())
    {
        int p;
        studentas t;
        fin >> t.vardas >> t.pavarde;
        for (auto& el : length)
        {
            fin >> p;
            t.pazymiai.push_back(p);
        }
        fin >> t.egzaminas;
        t.pazymiuKiekis = t.pazymiai.size();
        studentai.push_back(t);
    }
}
