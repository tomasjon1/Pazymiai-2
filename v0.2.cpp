#include <string>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <functional>
#include <iostream>
#include <fstream>

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
    double rezultatas = 0;
};

void ivedimas(studentas& data, bool generavimas);
void isvedimas(studentas& data, bool mediana);
int ivestoSkaiciausPatikrinimas();
string atsakymoIvedinimoPatikrinimas();
bool pazymioPatikrinimas(int n);
int ivestiPazymi();
void skatiymasIsFailo(ifstream& fin, vector<string>& length, vector<studentas>& studentai);

int main()
{
 
    srand(time(NULL));

    int studentuKiekis = 0;
    string atsMediana;
    string atsGeneravimas;
    string atsStudentuSkaicius;
    string atsFailoSkaitymas;
    bool mediana = false;
    bool generavimas = false;
    bool studentuSkaicius = false;
    bool failoSkaitymas = false;
   
    vector<studentas> studentai;
    std::ofstream fout("rez.txt");


    cout << "Ar notire naudoti mediana vietoje vidurkio (taip/ne): "; atsMediana = atsakymoIvedinimoPatikrinimas();
    cout << "Ar notire studentus nuskaityti is failo (taip/ne): "; atsFailoSkaitymas = atsakymoIvedinimoPatikrinimas();
        
    if (atsFailoSkaitymas == "taip") {

        vector<string> antrastineEilute;

        std::ifstream fin("studentai.txt");

        skatiymasIsFailo(fin, antrastineEilute, studentai);

        cout << "FAILO skaitymas" << endl;
    }
    else
    {
        /*cout << "Ar studentu skaicius yra zinomas (taip/ne): "; atsStudentuSkaicius = atsakymoIvedinimoPatikrinimas();
        cout << "Ar notire namu darbu pazymius generuoti automatiskai (taip/ne): "; atsGeneravimas = atsakymoIvedinimoPatikrinimas();
        cout << endl;

        if (atsMediana == "taip") {
            cout << "Atsakymas bus su mediana." << endl;
            mediana = true;
        }
        else  cout << "Atsakymas bus su vidurkiu." << endl;

        if (atsStudentuSkaicius == "taip") {
            cout << "Studentu skaicius yra zinomas" << endl;
            studentuSkaicius = true;
        }
        else cout << "Namu darbu skaiciai yra nezinomi" << endl;

        if (atsGeneravimas == "taip") {
            cout << "Namu darbu pazymiai bus genereruojami" << endl;
            generavimas = true;
        }
        else cout << "Namudarbu pazymiai ne bus genereruojami" << endl;


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
        }*/
    }

    cout << " BAIGIAU " << endl;
     
    if(mediana) cout << std::setw(20) << "VARDAS" << std::setw(20) << "PAVARDE" << std::setw(20) << "GALUTINS (Med.)" << endl;
    else        cout << std::setw(20) << "VARDAS" << std::setw(20) << "PAVARDE" << std::setw(20) << "GALUTINS (Vid.)" << endl;

    for (studentas studentas : studentai) isvedimas(studentas, mediana);

    
}

//void ivedimas(studentas& data, bool generavimas) {
//    cout << endl;
//    cout << "Iveskite studento pavarde: "; cin >> data.pavarde;
//    cout << "Iveskite studento varda: "; cin >> data.vardas;
//
//        cout << "Iveskite studento namu darbu kieki: "; data.pazymiuKiekis = ivestoSkaiciausPatikrinimas();
//        cout << endl;
//        //data.pazymiai = new int[data.pazymiuKiekis];
//        if (generavimas) {
//            for (int x = 0; x < data.pazymiuKiekis; x++) {
//                data.pazymiai.push_back(rand() % 10 + 1);
//                cout << "Ivestas " << x + 1 << " pazimys bus: " << data.pazymiai[x] << endl;
//            }
//            data.egzaminas = rand() % 10 + 1;
//            cout << "Ivestas studento egzamino pazymis bus: " << data.egzaminas << endl;
//        }
//        else {
//            for (int x = 0; x < data.pazymiuKiekis; x++) {
//                cout << "Iveskite " << x + 1 << " -a(-i) pazymi: "; data.pazymiai.push_back(ivestiPazymi());
//            }
//            cout << "iveskite studento egzamino pazymi: "; data.egzaminas = ivestiPazymi();
//        }
//    cout << endl;
//}
//
void isvedimas(studentas& data, bool mediana) {
    cout << std::setw(20) << data.vardas << std::setw(20) << data.pavarde;

    if (mediana) {
        std::sort(data.pazymiai.begin(), data.pazymiai.end());
        if (data.pazymiuKiekis % 2 !=  0)
            data.rezultatas = 0.4 * (double)data.pazymiai[data.pazymiuKiekis / 2] + 0.6 * data.egzaminas;
        else
            data.rezultatas = 0.4 * ((double)(data.pazymiai[(data.pazymiuKiekis - 1) / 2] + data.pazymiai[data.pazymiuKiekis / 2]) / 2.0) + 0.6 * data.egzaminas;
    }
    else {
        for (int x = 0; x < data.pazymiuKiekis; x++) data.rezultatas += data.pazymiai[x] * 1.0;
        data.rezultatas = (0.4 * (data.rezultatas / data.pazymiuKiekis)) + 0.6 * data.egzaminas;
    }
    cout << std::setw(20) << data.rezultatas << endl;
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
            cout << "Ataskymas turi buti (taip arba ne)" << endl;
        }
    } while (ats != "taip" && ats != "ne");
    return ats;
}

//bool pazymioPatikrinimas(int paz)
//{
//    if (paz > 0 && paz <= 10)
//        return true;
//    else
//    {
//        cout << "Blogas pazymys" << endl;
//        return false;
//    }
//}
//
//int ivestiPazymi() 
//{
//    while (true)
//    {
//        int paz = ivestoSkaiciausPatikrinimas();
//        if (pazymioPatikrinimas(paz)) return paz;
//    }
//}

void skatiymasIsFailo(ifstream& fin, vector<string>& length, vector<studentas>& studentai)
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
