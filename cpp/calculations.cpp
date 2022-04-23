#include "../headers/calculations.h"

void galutiniai(list<studentas> &studentai)
{
    for (auto &data : studentai)
    {

        std::sort(data.pazymiai.begin(), data.pazymiai.end());
        if (data.pazymiai.size() % 2 != 0)
            data.rezultatasMed = 0.4 * (double)data.pazymiai[data.pazymiai.size() / 2] + 0.6 * data.egzaminas;
        else
            data.rezultatasMed = 0.4 * ((double)(data.pazymiai[(data.pazymiai.size() - 1) / 2] + data.pazymiai[data.pazymiai.size() / 2]) / 2.0) + 0.6 * data.egzaminas;

        for (int x = 0; x < data.pazymiai.size(); x++)
            data.rezultatasVid += data.pazymiai[x] * 1.0;
        data.rezultatasVid = (0.4 * (data.rezultatasVid / data.pazymiai.size())) + 0.6 * data.egzaminas;
    }
}

void sortStudents(list<studentas> &kietiakai, list<studentas> &vargsai, list<studentas> &studentai)
{
    for (auto &stud : studentai)
    {
        if (stud.rezultatasVid < 5)
        {
            vargsai.push_back(stud);
        }
        else
        {
            kietiakai.push_back(stud);
        }
    }
    studentai.clear();
}

bool isVargsas(studentas a)
{
    if (a.rezultatasMed < 5 || a.rezultatasVid < 5)
        return true;
    return false;
}

void sortStudents2(list<studentas> &kietiakai, list<studentas> &vargsai)
{
    copy_if(kietiakai.begin(), kietiakai.end(), back_inserter(vargsai), isVargsas);
    kietiakai.erase(remove_if(kietiakai.begin(), kietiakai.end(), isVargsas), kietiakai.end());
}