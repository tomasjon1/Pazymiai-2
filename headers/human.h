#pragma once

#include <iostream>
#include <string>
#include <fstream>

using std::string;

class Human
{
protected:
    string vardas;
    string pavarde;

public:
    virtual void f() = 0;

public:
    Human();
    ~Human();
    Human(const Human &h);

    void setFirstName(string &name);
    void setFirstName(std::istream &name);
    void setlastName(string &name);
    void setlastName(std::istream &name);

    string getFirstName();
    string getlastName();
};