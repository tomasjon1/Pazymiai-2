#include "../headers/application.h"

Application::Application()
{
}

Application::~Application()
{
}

void Application::run()
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
