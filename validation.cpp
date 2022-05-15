#include "validation.h"

Validator::Validator()
{
}

Validator::~Validator()
{
}

int Validator::ivestoSkaiciausPatikrinimas()
{
    int n;
    while (true)
    {
        cin >> n;
        if (cin.good())
            return n;
        else
        {
            cout << "Ne numeris" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }
}

string Validator::atsakymoIvedinimoPatikrinimas()
{
    string ats;
    do
    {
        cin >> ats;
        if (ats != "taip" && ats != "ne")
        {
            cout << ats;
            cout << "Atsakymas turi buti (taip arba ne)" << endl;
        }
    } while (ats != "taip" && ats != "ne");
    return ats;
}

bool Validator::pazymioPatikrinimas(int paz)
{
    if (paz > 0 && paz <= 10)
        return true;
    else
    {
        cout << "Blogas pazymys" << endl;
        return false;
    }
}
