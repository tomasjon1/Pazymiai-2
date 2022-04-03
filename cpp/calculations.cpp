#include "../headers/calculations.h"


void galutiniai(list<studentas>& studentai)
{
    for (auto& data : studentai) {

        std::sort(data.pazymiai.begin(), data.pazymiai.end());
        if (data.pazymiai.size() % 2 != 0) data.rezultatasMed = 0.4 * (double)data.pazymiai[data.pazymiai.size() / 2] + 0.6 * data.egzaminas;
        else data.rezultatasMed = 0.4 * ((double)(data.pazymiai[(data.pazymiai.size() - 1) / 2] + data.pazymiai[data.pazymiai.size() / 2]) / 2.0) + 0.6 * data.egzaminas;

        for (int x = 0; x < data.pazymiai.size(); x++) data.rezultatasVid += data.pazymiai[x] * 1.0;
        data.rezultatasVid = (0.4 * (data.rezultatasVid / data.pazymiai.size())) + 0.6 * data.egzaminas;
    }
}

void sortStudents(std::stringstream& kietiakai, std::stringstream& vargsai, list<studentas>& studentai)
{
    for (auto& stud : studentai)
    {
        if (stud.rezultatasVid < 5)
        {
            vargsai << std::left << std::setw(20) << stud.vardas;
            vargsai << std::left << std::setw(20) << stud.pavarde;
            vargsai << std::left << std::setw(20) << stud.rezultatasVid;
            vargsai << std::left << std::setw(20) << stud.rezultatasMed;
            vargsai << endl;
        }
        else
        {
            kietiakai << std::left << std::setw(20) << stud.vardas;
            kietiakai << std::left << std::setw(20) << stud.pavarde;
            kietiakai << std::left << std::setw(20) << stud.rezultatasVid;
            kietiakai << std::left << std::setw(20) << stud.rezultatasMed;
            kietiakai << endl;
        }
    }
    studentai.clear();
}