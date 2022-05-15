#include "../headers/Human.h"

Human::Human() : vardas(""), pavarde("") {}
Human::~Human() {}
Human::Human(const Human &h)
{
    this->vardas = h.vardas;
    this->pavarde = h.pavarde;
}

void Human::setFirstName(string &name) { vardas = name; }
void Human::setFirstName(std::istream &name) { name >> vardas; }
void Human::setlastName(string &name) { pavarde = name; }
void Human::setlastName(std::istream &name) { name >> pavarde; }

string Human::getFirstName() { return vardas; }
string Human::getlastName() { return pavarde; }