#include "../headers/Application.h"

Application::Application(/* args */)
{
}

Application::~Application()
{
}

void Application::run()
{
    cout << "Ar studentu skaicius yra zinomas (taip/ne): ";
    // atsStudentuSkaicius = atsakymoIvedinimoPatikrinimas();
    cin >> atsStudentuSkaicius;
    cout << "Ar notire namu darbu pazymius generuoti automatiskai (taip/ne): ";
    // atsGeneravimas = atsakymoIvedinimoPatikrinimas();
    cin >> atsGeneravimas;
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
        // studentuKiekis = ivestoSkaiciausPatikrinimas();
        cin >> studentuKiekis;
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
            // ats = atsakymoIvedinimoPatikrinimas();
            cin >> ats;
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
    // data.pazymiuKiekis = ivestoSkaiciausPatikrinimas();
    int a;
    cin >> a;
    temp.sethomeWorkAmount(a);
    cout << endl;

    for (int x = 0; x < temp.getHomeWorkAmount(); x++)
    {
        cout << "Iveskite " << x + 1 << " -a(-i) pazymi: ";
        // temp.pazymiai.push_back(ivestiPazymi());
        cin >> a;
        temp.sethomeWork(a);
    }
    cout << "iveskite studento egzamino pazymi: ";
    // data.egzaminas = ivestiPazymi();
    cin >> a;
    temp.setexam(a);
}