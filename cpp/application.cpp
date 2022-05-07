#include "../headers/application.h"

Application::Application()
{
}

Application::~Application()
{
}

void Application::run()
{
    cout << "Ar notire studentus nuskaityti is failo (taip/ne): ";
    atsFailoSkaitymas = atsakymoIvedinimoPatikrinimas();

    if (atsFailoSkaitymas == "taip")
    {

        cout << "Ar notire studentu duomenis sugeneruoti (taip/ne): ";
        atsFailoGeneravimas = atsakymoIvedinimoPatikrinimas();

        if (atsFailoGeneravimas == "taip")
        {

            Generator generator;

            cin.ignore();
            cout << "Koks turetu buti failo pavadinimas?(studentai.txt by default): ";
            getline(cin, genFile_name);
            genFile_name.empty() ? genFile_name = "studentai1.txt" : genFile_name += ".txt";
            cout << "Kiek generuoti studentu?" << endl;
            int studCount;
            studCount = ivestoSkaiciausPatikrinimas();
            cout << "Kiek generuoti namu darbu?" << endl;
            int ndCount;
            ndCount = ivestoSkaiciausPatikrinimas();
            generator.genFile(studCount, genFile_name, ndCount);
            bufer_read(studentai, genFile_name);
        }
        else
        {
            try
            {
                cout << "iveskite fialo pavadinima ";
                string pav;
                cin >> pav;
                pav = pav + ".txt";
                bufer_read(studentai, pav);
            }
            catch (std::exception &e)
            {
                cout << "Failas nerastas" << endl;
            }
        }
    }
    else
    {
        cout << "Ar studentu skaicius yra zinomas (taip/ne): ";
        atsStudentuSkaicius = atsakymoIvedinimoPatikrinimas();
        cout << "Ar notire namu darbu pazymius generuoti automatiskai (taip/ne): ";
        atsGeneravimas = atsakymoIvedinimoPatikrinimas();
        cout << endl;

        if (atsStudentuSkaicius == "taip")
        {
            cout << "Studentu skaicius yra zinomas" << endl;
            studentuSkaicius = true;
        }
        else
            cout << "Studentu skaicius yra nezinomas" << endl;

        if (atsGeneravimas == "taip")
        {
            cout << "Namu darbu pazymiai bus genereruojami" << endl;
            generavimas = true;
        }
        else
            cout << "Namudarbu pazymiai nebus genereruojami" << endl;

        if (studentuSkaicius)
        {
            cout << "Iveskite studentu kieki: ";
            studentuKiekis = ivestoSkaiciausPatikrinimas();
            for (int x = 0; x < studentuKiekis; x++)
            {
                Studentas temp;
                ivedimas(temp, generavimas);
                studentai.push_back(temp);
            }
        }
        else
        {
            string ats;
            while (true)
            {
                Studentas temp;
                ivedimas(temp, generavimas);
                studentai.push_back(temp);
                cout << "Ar notire ivesti dar studenta (taip/ne): ";
                ats = atsakymoIvedinimoPatikrinimas();
                if (ats == "ne")
                    break;
            }
        }
    }

    for (auto &stud : studentai)
    {
        stud.calculateRez();
        cout << stud.getVid() << " " << stud.getMed() << endl;
    }

    bufer_write(studentai);
}

void Application::ivedimas(Studentas &temp, bool generavimas)
{
    cout << endl;
    cout << "Iveskite studento pavarde: ";
    temp.setlastName(cin);
    cout << "Iveskite studento varda: ";
    temp.setFirstName(cin);

    cout << "Iveskite studento namu darbu kieki: ";
    temp.sethomeWorkAmount(ivestoSkaiciausPatikrinimas());
    cout << endl;

    if (generavimas)
    {
        for (int x = 0; x < temp.getHomeWorkAmount(); x++)
        {
            temp.sethomeWork(rand() % 10 + 1);
            cout << "Ivestas " << x + 1 << " pazymyss bus: " << temp.getHomeWork()[x] << endl;
        }
        temp.setExam(rand() % 10 + 1);
        cout << "Ivestas studento egzamino pazymys bus: " << temp.getExam() << endl;
    }
    else
    {
        for (int x = 0; x < temp.getHomeWorkAmount(); x++)
        {
            cout << "Iveskite " << x + 1 << " -a(-i) pazymi: ";
            temp.sethomeWork(ivestiPazymi());
        }
        cout << "iveskite studento egzamino pazymi: ";
        temp.setExam(ivestiPazymi());
    }
    cout << endl;
}

int Application::ivestiPazymi()
{
    while (true)
    {
        int paz = ivestoSkaiciausPatikrinimas();
        if (pazymioPatikrinimas(paz))
            return paz;
    }
}

void Application::bufer_read(vector<Studentas> &studentai, string file_name)
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
        Studentas t;
        std::istringstream lineStream(line);
        string s;
        lineStream >> s;
        t.setFirstName(s);
        lineStream >> s;
        t.setlastName(s);
        int mark;
        while (lineStream >> mark)
        {
            t.sethomeWork(mark);
        }
        t.getAndPopLastMark();
        studentai.push_back(t);
    }
}

void Application::bufer_write(vector<Studentas> &studentai)
{

    std::stringstream outputas;
    outputas << std::left << std::setw(20) << "Vardas";
    outputas << std::left << std::setw(20) << "Pavarde";
    outputas << std::left << std::setw(20) << "Galutinis (Vid.)";
    outputas << std::left << std::setw(20) << "Galutinis (Med.)";
    outputas << endl;

    for (auto &stud : studentai)
    {

        outputas << std::left << std::setw(20) << stud.getFirstName();
        cout << stud.getFirstName() << " ";
        outputas << std::left << std::setw(20) << stud.getlastName();
        cout << stud.getlastName() << " ";
        outputas << std::left << std::setw(20) << stud.getVid();
        cout << stud.getVid() << " ";
        outputas << std::left << std::setw(20) << stud.getMed();
        cout << stud.getMed() << endl;
        outputas << endl;
    }

    studentai.clear();
    std::ofstream out_f("rez.txt");
    out_f << outputas.rdbuf();
    out_f.close();
}
