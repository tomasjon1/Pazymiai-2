#include "../headers/InputAndOutput.h"

void ivedimas(studentas &data, bool generavimas)
{
    cout << endl;
    cout << "Iveskite studento pavarde: ";
    cin >> data.pavarde;
    cout << "Iveskite studento varda: ";
    cin >> data.vardas;

    cout << "Iveskite studento namu darbu kieki: ";
    data.pazymiuKiekis = ivestoSkaiciausPatikrinimas();
    cout << endl;
    if (generavimas)
    {
        for (int x = 0; x < data.pazymiuKiekis; x++)
        {
            data.pazymiai.push_back(rand() % 10 + 1);
            cout << "Ivestas " << x + 1 << " pazymyss bus: " << data.pazymiai[x] << endl;
        }
        data.egzaminas = rand() % 10 + 1;
        cout << "Ivestas studento egzamino pazymys bus: " << data.egzaminas << endl;
    }
    else
    {
        for (int x = 0; x < data.pazymiuKiekis; x++)
        {
            cout << "Iveskite " << x + 1 << " -a(-i) pazymi: ";
            data.pazymiai.push_back(ivestiPazymi());
        }
        cout << "iveskite studento egzamino pazymi: ";
        data.egzaminas = ivestiPazymi();
    }
    cout << endl;
}

int ivestiPazymi()
{
    while (true)
    {
        int paz = ivestoSkaiciausPatikrinimas();
        if (pazymioPatikrinimas(paz))
            return paz;
    }
}

void bufer_read(list<studentas> &studentai, string file_name)
{

    std::string line;
    std::stringstream buffer;

    std::ifstream open_f(file_name);

    buffer << open_f.rdbuf();
    open_f.close();
    std::getline(buffer, line);

    while (buffer)
    {
        std::getline(buffer, line);
        if (line.length() == 0)
            break;
        studentas t;
        std::istringstream lineStream(line);
        lineStream >> t.vardas >> t.pavarde;
        int mark;
        while (lineStream >> mark)
        {

            t.pazymiai.push_back(mark);
        }
        t.egzaminas = t.pazymiai.back();
        t.pazymiai.pop_back();
        studentai.push_back(t);
    }
}

void bufer_write(list<studentas> &studentai)
{

    std::stringstream outputas;
    outputas << std::left << std::setw(20) << "Vardas";
    outputas << std::left << std::setw(20) << "Pavarde";
    outputas << std::left << std::setw(20) << "Galutinis (Vid.)";
    outputas << std::left << std::setw(20) << "Galutinis (Med.)";
    outputas << endl;

    for (auto &stud : studentai)
    {

        outputas << std::left << std::setw(20) << stud.vardas;
        outputas << std::left << std::setw(20) << stud.pavarde;
        outputas << std::left << std::setw(20) << stud.rezultatasVid;
        outputas << std::left << std::setw(20) << stud.rezultatasMed;
        outputas << endl;
    }

    studentai.clear();
    std::ofstream out_f("rez.txt");
    out_f << outputas.rdbuf();
    out_f.close();
}

void listToFile(string file_name, list<studentas> &data)
{
    std::stringstream outputas;
    outputas << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Vid." << std::left << std::setw(20) << "Med." << endl;
    for (auto &stud : data)
    {
        outputas << std::left << std::setw(20) << stud.vardas;
        outputas << std::left << std::setw(20) << stud.pavarde;
        outputas << std::left << std::setw(20) << stud.rezultatasVid;
        outputas << std::left << std::setw(20) << stud.rezultatasMed;
        outputas << endl;
    }
    std::ofstream out_f(file_name);
    out_f << outputas.rdbuf();
    out_f.close();
}