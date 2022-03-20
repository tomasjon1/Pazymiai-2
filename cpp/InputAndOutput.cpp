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

void bufer_read(vector<studentas>& studentai) {

    std::string line;
    std::stringstream buffer;

    std::ifstream open_f("studentai.txt");


    buffer << open_f.rdbuf();
    open_f.close();
    std::getline(buffer, line);



    while (buffer) {
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

void bufer_write(vector<studentas>& studentai) {

    std::stringstream outputas;
    outputas << std::left << std::setw(20) << "Vardas";
    outputas << std::left << std::setw(20) << "Pavarde";
    outputas << std::left << std::setw(20) << "Galutinis (Vid.)";
    outputas << std::left << std::setw(20) << "Galutinis (Med.)";
    outputas << endl;

    for (auto& studentas : studentai) {
        outputas << std::left << std::setw(20) << studentas.vardas;
        outputas << std::left << std::setw(20) << studentas.pavarde;
        outputas << std::left << std::setw(20) << studentas.rezultatasVid;
        outputas << std::left << std::setw(20) << studentas.rezultatasMed;
        outputas << endl;
    }

    ssToFile("rez.txt", outputas);
}

void galutiniai(studentas& data)
{
    std::sort(data.pazymiai.begin(), data.pazymiai.end());
    if (data.pazymiuKiekis % 2 != 0) data.rezultatasMed = 0.4 * (double)data.pazymiai[data.pazymiuKiekis / 2] + 0.6 * data.egzaminas;
    else data.rezultatasMed = 0.4 * ((double)(data.pazymiai[(data.pazymiuKiekis - 1) / 2] + data.pazymiai[data.pazymiuKiekis / 2]) / 2.0) + 0.6 * data.egzaminas;

    for (int x = 0; x < data.pazymiuKiekis; x++) data.rezultatasVid += data.pazymiai[x] * 1.0;
    data.rezultatasVid = (0.4 * (data.rezultatasVid / data.pazymiuKiekis)) + 0.6 * data.egzaminas;

}


void ssToFile(string file_name, std::stringstream& data)
{
    std::ofstream out_f(file_name);
    out_f << data.rdbuf();
    out_f.close();
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

