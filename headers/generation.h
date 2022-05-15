#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <random>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::left;
using std::mt19937;
using std::setw;
using std::string;
using std::to_string;

class Generator
{
private:
public:
    Generator();
    ~Generator();

    void genFile(int size, string file_name, int ndCount);
    std::stringstream genStudentString(int ndCount);

    int randomInt(int from, int to);
    string randFirstName();
    string randLastName();
};