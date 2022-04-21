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


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::list;


struct studentas {
    string vardas = "";
    string pavarde = "";
    vector<int> pazymiai;
    int pazymiuKiekis = 0;
    int egzaminas;
    double rezultatasVid = 0;
    double rezultatasMed = 0;
};
