#include "../headers/data.h"

void Studentas::setFirstName(string firstName) { vardas = firstName; }
void Studentas::setlastName(string lastName) { pavarde = lastName; }
void Studentas::sethomeWork(int homeWork) { pazymiai.push_back(homeWork); }
void Studentas::sethomeWorkAmount(int homeWorkAmount) { pazymiuKiekis = homeWorkAmount; }
void Studentas::setexam(int exam) { egzaminas = exam; }
void Studentas::setVid(double vid) { rezultatasVid = vid; }
void Studentas::setmed(double med) { rezultatasMed = med; }

string Studentas::getFirstName() { return vardas; }
string Studentas::getlastName() { return pavarde; }
vector<int> Studentas::getHomeWork() { return pazymiai; }
int Studentas::getHomeWorkAmount() { return pazymiuKiekis; }
double Studentas::getExam() { return egzaminas; }
double Studentas::getVid() { return rezultatasVid; }
double Studentas::getMed() { return rezultatasMed; }

void Studentas::calculateAvarage()
{
    double sum = 0;
    for (auto &el : pazymiai)
        sum += el;

    if (pazymiai.size() != 0)
        rezultatasVid = sum / (pazymiai.size() * 1.0) * 0.4 + rezultatasVid * 0.6;
    else
        rezultatasVid = rezultatasVid * 0.6;
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