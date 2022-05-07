#include "../headers/data.h"

Studentas::Studentas() {}

void Studentas::setFirstName(string firstName) { vardas = firstName; }
void Studentas::setFirstName(std::istream &name) { name >> vardas; }
void Studentas::setlastName(string lastName) { pavarde = lastName; }
void Studentas::setlastName(std::istream &name) { name >> vardas; }
void Studentas::sethomeWork(int homeWork) { pazymiai.push_back(homeWork); }
void Studentas::sethomeWorkAmount(int homeWorkAmount) { pazymiuKiekis = homeWorkAmount; }
void Studentas::setExam(int exam) { egzaminas = exam; }
void Studentas::setVid(double vid) { rezultatasVid = vid; }
void Studentas::setmed(double med) { rezultatasMed = med; }

string Studentas::getFirstName() { return vardas; }
string Studentas::getlastName() { return pavarde; }
vector<int> Studentas::getHomeWork() { return pazymiai; }
int Studentas::getHomeWorkAmount() { return pazymiuKiekis; }
double Studentas::getExam() { return egzaminas; }
double Studentas::getVid() { return rezultatasVid; }
double Studentas::getMed() { return rezultatasMed; }

int Studentas::getAndPopLastMark()
{
    int t = pazymiai.back();
    pazymiai.pop_back();
    return t;
}

void Studentas::calculateAvarage()
{
    rezultatasVid = 0;
    for (auto &el : pazymiai)
    {
        rezultatasVid += el;
    }

    rezultatasVid = (0.4 * (rezultatasVid / pazymiai.size())) + 0.6 * egzaminas;
}

void Studentas::calculateMedian()
{
    std::sort(pazymiai.begin(), pazymiai.end());
    if (pazymiai.size() % 2 == 0 && pazymiai.size() != 0)
    {
        rezultatasMed = (pazymiai[pazymiai.size() / 2] + pazymiai[pazymiai.size() / 2 - 1]) * 1.0 / 2;
    }
    else if (pazymiai.size() % 2 != 0 && pazymiai.size() != 0)
    {
        rezultatasMed = pazymiai[pazymiai.size() / 2] * 0.4 + egzaminas * 0.6;
    }
    else if (pazymiai.size() == 0)
    {
        cout << "no marks" << endl;
        rezultatasMed = egzaminas * 0.6;
    }
}

void Studentas::calculateRez()
{
    calculateAvarage();
    calculateMedian();
}

bool compare(Studentas &a, Studentas &b)
{
    return a.getFirstName() < b.getFirstName();
}

bool isVargsas(Studentas &a)
{
    if (a.getMed() < 5 || a.getVid() < 5)
        return true;
    return false;
}