#pragma once

#include "data.h"
#include "validation.h"

void ivedimas(studentas& data, bool generavimas);
int ivestiPazymi();
void skaitymasIsFailo(ifstream& fin, vector<string>& length, vector<studentas>& studentai);
void isvedimas(studentas& data, ofstream& fout);
void bufer_read(vector<studentas>& studentai);
void bufer_write(vector<studentas>& studentai);
void ssToFile(string file_name, std::stringstream& data);

