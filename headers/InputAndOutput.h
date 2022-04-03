#pragma once

#include "data.h"
#include "validation.h"

void ivedimas(studentas& data, bool generavimas);
int ivestiPazymi();

void bufer_read(deque<studentas>& studentai, string file_name);
void bufer_write(deque<studentas>& studentai);
void ssToFile(string file_name, std::stringstream& data);
void ssToFile(string file_name, std::stringstream& data);
