#pragma once

#include "Human.h"

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

class Studentas : public Human
{
public:
    vector<int> pazymiai;
    int pazymiuKiekis = 0;
    int egzaminas;
    double rezultatasVid = 0;
    double rezultatasMed = 0;

    void f(){};

public:
    Studentas();
    Studentas(string a, string b, double vid, double med);
    ~Studentas();
    Studentas &operator=(const Studentas &s);
    bool operator<(const Studentas &s);
    bool operator>(const Studentas &s);

    Studentas(const Studentas &s);

    void sethomeWork(int homeWork);
    void sethomeWorkAmount(int homeWorkAmount);
    void setExam(int exam);
    void setVid(double vid);
    void setmed(double med);

    int getHomeWorkAmount();
    vector<int> getHomeWork();
    double getExam();
    double getVid();
    double getMed();

    int getAndPopLastMark();

    void calculateMedian();
    void calculateAvarage();
    void calculateRez();
};

bool compare(Studentas &a, Studentas &b);
bool isVargsas(Studentas &a);
