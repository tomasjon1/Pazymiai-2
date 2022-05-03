#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::list;
using std::ofstream;
using std::string;
using std::vector;

struct studentas
{
    string vardas = "";
    string pavarde = "";
    vector<int> pazymiai;
    int pazymiuKiekis = 0;
    int egzaminas;
    double rezultatasVid = 0;
    double rezultatasMed = 0;
};

class Studentas
{
private:
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    int pazymiuKiekis = 0;
    int egzaminas;
    double rezultatasVid = 0;
    double rezultatasMed = 0;

public:
    Studentas();

    void setFirstName(string firstName);
    void setFirstName(std::istream &name);
    void setlastName(string lastName);
    void setlastName(std::istream &name);
    void sethomeWork(int homeWork);
    void sethomeWorkAmount(int homeWorkAmount);
    void setExam(int exam);
    void setVid(double vid);
    void setmed(double med);

    string getFirstName();
    string getlastName();
    int getHomeWorkAmount();
    vector<int> getHomeWork();
    double getExam();
    double getVid();
    double getMed();

    void calculateMedian();
    void calculateAvarage();
    void calculateRez();
};