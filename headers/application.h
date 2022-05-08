#pragma once

#include "data.h"
#include "validation.h"
#include "generation.h"

#include <vector>

using std::vector;

class Application : public Validator
{
private:
    int studentuKiekis = 0;
    string atsStudentuSkaicius;
    string atsGeneravimas;
    string atsFailoSkaitymas;
    string atsFailoGeneravimas;
    bool generavimas = false;
    bool studentuSkaicius = false;
    bool failoSkaitymas = false;
    bool failoGeneravimas = false;

    string genFile_name;

    vector<Studentas> studentai;

public:
    Application();
    ~Application();
    void run();

private:
    void ivedimas(Studentas &temp, bool generavimas);
    int ivestiPazymi();

    void bufer_read(vector<Studentas> &studentai, string file_name);
    void bufer_write(vector<Studentas> &studentai);

    void sortStudents(vector<Studentas> &kietiakai, vector<Studentas> &vargsai, vector<Studentas> &students);
    void sortStudents2(vector<Studentas> &kietiakai, vector<Studentas> &vargsai);
    void dataToFile(string file_name, vector<Studentas> &data);
};