#include "../headers/generation.h"

int randomInt(int from, int to)
{
    std::uniform_int_distribution<int> dist(from, to);
    return dist(mt);
}
string randFirstName()
{
    return firstNames[randomInt(0, firstNames.size() - 1)];
}
string randLastName()
{
    return lastNames[randomInt(0, lastNames.size() - 1)];
}

void genFile(int size, string file_name, int ndCount)
{
    std::stringstream outputas;
    outputas << std::left << std::setw(20) << "Vardas";
    outputas << std::left << std::setw(20) << "Pavarde";
    for (int i = 1; i <= ndCount; i++)
    {
        outputas << std::left << "ND" << std::setw(5) << i;
    }

    outputas << std::left << std::setw(7) << "Egz" << endl;

    for (int i = 0; i < size; i++)
    {
        outputas << genStudentString(ndCount).str();
    }
    std::ofstream out_f(file_name);
    out_f << outputas.rdbuf();
    out_f.close();
}

std::stringstream genStudentString(int ndCount)
{
    std::stringstream stud;

    stud << std::left << std::setw(20) << randFirstName();
    stud << std::left << std::setw(20) << randLastName();
    for (int i = 0; i < ndCount; i++)
        stud << std::left << std::setw(7) << randomInt(1, 10);
    stud << std::left << std::setw(7) << randomInt(1, 10) << endl;
    return stud;
}

