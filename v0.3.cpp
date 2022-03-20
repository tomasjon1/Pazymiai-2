#include "headers/data.h"
#include "headers/validation.h"
#include "headers/InputAndOutput.h"

using namespace std;


int main()
{
 
    srand(time(NULL));

    int studentuKiekis = 0;
    string atsGeneravimas;
    string atsStudentuSkaicius;
    string atsFailoSkaitymas;
    string atsFailoGeneravimas;
    bool generavimas = false;
    bool studentuSkaicius = false;
    bool failoSkaitymas = false;
    bool failoGeneravimas = false;

    string genFile_name;

    vector<studentas> studentai;

    std::ofstream fout("rez.txt");


    cout << "Ar notire studentus nuskaityti is failo (taip/ne): "; atsFailoSkaitymas = atsakymoIvedinimoPatikrinimas();
        
    if (atsFailoSkaitymas == "taip") {

        cout << "Ar notire studentus nuskaityti is failo (taip/ne): "; atsFailoGeneravimas = atsakymoIvedinimoPatikrinimas();
        if (atsFailoGeneravimas == "taip") {

            cin.ignore();
            cout << "Koks turetu buti failo pavadinimas?(studentai.txt by default): ";
            getline(cin, genFile_name);
            genFile_name.empty() ? genFile_name = "studentai1.txt" : genFile_name += ".txt";
            cout << "Kiek generuoti studentu?" << endl;
            int studCount;
            studCount = ivestoSkaiciausPatikrinimas();
            studentai.reserve(studCount);
            cout << "Kiek generuoti namu darbu?" << endl;
            int ndCount;
            ndCount = ivestoSkaiciausPatikrinimas();
            cout << "-------------------------" << endl;
            cout << studCount << " irasu testavimas" << endl;
            genFile(studCount, genFile_name, ndCount);

            bufer_read(studentai, genFile_name);
        }
        else {
            vector<string> antrastineEilute;

            try
            {
                bufer_read(studentai, "studentai.txt");
            }
            catch (std::exception& e)
            {
                cout << "Failas nerastas" << endl;
            }
        }
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
        else cout << "Studentu skaicius yra nezinomas" << endl;

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
                studentas temp;
                ivedimas(temp, generavimas);
                studentai.push_back(temp);
                cout << "Ar notire ivesti dar studenta (taip/ne): "; ats = atsakymoIvedinimoPatikrinimas();
                if (ats == "ne")
                    break;
            }
        }
    }

    galutiniai(studentai);

    std::sort(studentai.begin(), studentai.end(), [](studentas& a, studentas& b){ return a.vardas < b.vardas; });
     
    bufer_write(studentai);
}
