#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Validator
{
public:
    Validator();
    ~Validator();

protected:
    int ivestoSkaiciausPatikrinimas();
    string atsakymoIvedinimoPatikrinimas();
    bool pazymioPatikrinimas(int paz);
};