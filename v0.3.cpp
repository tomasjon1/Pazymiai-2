#include "data.h"
#include "validation.h"
#include "InputAndOutput.h"

using namespace std;


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

    std::sort(studentai.begin(), studentai.end(), [](studentas& a, studentas& b){ return a.vardas < b.vardas; });
     
    fout << std::setw(20) << "VARDAS" << std::setw(20) << "PAVARDE" << std::setw(20) << "GALUTINS (Vid.)" << std::setw(20) << "GALUTINS (Med.)" << endl;

    for (studentas studentas : studentai) 
        isvedimas(studentas, fout);

    
}
