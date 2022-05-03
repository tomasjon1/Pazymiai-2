#pragma once

#include "data.h"
#include "validation.h"

#include <vector>

using std::vector;

class Application : public Validator
{
private:
    int studentuKiekis = 0;
    string atsStudentuSkaicius;
    string atsGeneravimas;
    bool generavimas = false;
    bool studentuSkaicius = false;

    vector<Studentas> studentai;

public:
    Application();
    ~Application();
    void run();

private:
    void ivedimas(Studentas &temp, bool generavimas);
    int ivestiPazymi();
};