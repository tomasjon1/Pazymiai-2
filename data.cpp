#include "data.h"

Studentas::Studentas() : rezultatasVid(0), rezultatasMed(0) {}
Studentas::Studentas(string a, string b, double vid, double med)
{
    this->setFirstName(a);
    this->setlastName(b);
    this->setVid(vid);
    this->setmed(med);
}
Studentas::~Studentas() { pazymiai.clear(); }
Studentas::Studentas(const Studentas &s)
{
    this->vardas = s.vardas;
    this->pavarde = s.pavarde;
    this->pazymiai.reserve(s.pazymiai.size());
    this->pazymiai.resize(s.pazymiai.size());
    for (int i = 0; i < s.pazymiai.size(); i++)
        this->pazymiai.at(i) = s.pazymiai[i];

    this->egzaminas = s.egzaminas;
    this->rezultatasVid = s.rezultatasVid;
    this->rezultatasMed = s.rezultatasMed;
}
Studentas &Studentas::operator=(const Studentas &s)
{
    if (&s == this)
        return *this;
    vardas = s.vardas;
    pavarde = s.pavarde;
    pazymiai.reserve(s.pazymiai.size());
    this->pazymiai.resize(s.pazymiai.size());
    for (int i = 0; i < s.pazymiai.size(); i++)
        pazymiai[i] = s.pazymiai[i];
    egzaminas = s.egzaminas;
    rezultatasVid = s.rezultatasVid;
    rezultatasMed = s.rezultatasMed;
    return *this;
}

bool Studentas::operator<(const Studentas &s)
{
    return rezultatasMed < s.rezultatasMed;
}

bool Studentas::operator>(const Studentas &s)
{
    return rezultatasMed > s.rezultatasMed;
}

void Studentas::sethomeWork(int homeWork) { pazymiai.push_back(homeWork); }
void Studentas::sethomeWorkAmount(int homeWorkAmount) { pazymiuKiekis = homeWorkAmount; }
void Studentas::setExam(int exam) { egzaminas = exam; }
void Studentas::setVid(double vid) { rezultatasVid = vid; }
void Studentas::setmed(double med) { rezultatasMed = med; }

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