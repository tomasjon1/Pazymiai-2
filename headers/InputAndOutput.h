#pragma once

#include "data.h"
#include "validation.h"

void ivedimas(studentas &data, bool generavimas);
int ivestiPazymi();

void bufer_read(list<studentas> &studentai, string file_name);
void bufer_write(list<studentas> &studentai);
void listToFile(string file_name, list<studentas> &data);
