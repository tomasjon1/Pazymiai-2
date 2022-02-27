#include "../headers/InputAndOutput.h"


void ivedimas(studentas& data, bool generavimas) {
    cout << endl;
    cout << "Iveskite studento pavarde: "; cin >> data.pavarde;
    cout << "Iveskite studento varda: "; cin >> data.vardas;

    cout << "Iveskite studento namu darbu kieki: "; data.pazymiuKiekis = ivestoSkaiciausPatikrinimas();
    cout << endl;
    if (generavimas) {
        for (int x = 0; x < data.pazymiuKiekis; x++) {
            data.pazymiai.push_back(rand() % 10 + 1);
            cout << "Ivestas " << x + 1 << " pazymyss bus: " << data.pazymiai[x] << endl;
        }
        data.egzaminas = rand() % 10 + 1;
        cout << "Ivestas studento egzamino pazymys bus: " << data.egzaminas << endl;
    }
    else {
        for (int x = 0; x < data.pazymiuKiekis; x++) {
            cout << "Iveskite " << x + 1 << " -a(-i) pazymi: "; data.pazymiai.push_back(ivestiPazymi());
        }
        cout << "iveskite studento egzamino pazymi: "; data.egzaminas = ivestiPazymi();
    }
    cout << endl;
}

int ivestiPazymi()
{
    while (true)
    {
        int paz = ivestoSkaiciausPatikrinimas();
        if (pazymioPatikrinimas(paz)) return paz;
    }
}

void skaitymasIsFailo(ifstream& fin, vector<string>& length, vector<studentas>& studentai)
{
    string t;
    while ((fin.peek() != '\n') && (fin >> t))
        length.push_back(t);
    length.resize(length.size() - 3);

    while (!fin.eof())
    {
        int p;
        studentas t;
        fin >> t.vardas >> t.pavarde;
        for (auto& el : length)
        {
            fin >> p;
            t.pazymiai.push_back(p);
        }
        fin >> t.egzaminas;
        t.pazymiuKiekis = t.pazymiai.size();
        studentai.push_back(t);
    }
}

void isvedimas(studentas& data, ofstream& fout) {
    fout << std::setw(20) << data.vardas << std::setw(20) << data.pavarde;

    std::sort(data.pazymiai.begin(), data.pazymiai.end());
    if (data.pazymiuKiekis % 2 != 0) data.rezultatasMed = 0.4 * (double)data.pazymiai[data.pazymiuKiekis / 2] + 0.6 * data.egzaminas;
    else data.rezultatasMed = 0.4 * ((double)(data.pazymiai[(data.pazymiuKiekis - 1) / 2] + data.pazymiai[data.pazymiuKiekis / 2]) / 2.0) + 0.6 * data.egzaminas;

    for (int x = 0; x < data.pazymiuKiekis; x++) data.rezultatasVid += data.pazymiai[x] * 1.0;
    data.rezultatasVid = (0.4 * (data.rezultatasVid / data.pazymiuKiekis)) + 0.6 * data.egzaminas;

    fout << std::setw(20) << data.rezultatasMed << std::setw(20) << data.rezultatasVid << endl;
}



