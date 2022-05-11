#include "headers/data.h"
#include "headers/Application.h"

int main()
{
    Studentas stud1("Tomas", "Jonauskas", 8, 8);
    Studentas stud2;

    cout << stud1.getFirstName() << " " << stud1.getlastName() << " " << stud1.getVid() << " " << stud1.getMed() << endl;
    cout << stud2.getFirstName() << " " << stud2.getlastName() << " " << stud2.getVid() << " " << stud2.getMed() << endl;

    cout << "----------------------------------------------" << endl;

    Studentas stud3(stud1);
    cout << stud1.getFirstName() << " " << stud1.getlastName() << " " << stud1.getVid() << " " << stud1.getMed() << endl;
    cout << stud3.getFirstName() << " " << stud3.getlastName() << " " << stud3.getVid() << " " << stud3.getMed() << endl;

    cout << "----------------------------------------------" << endl;

    stud2 = stud1;
    cout << stud1.getFirstName() << " " << stud1.getlastName() << " " << stud1.getVid() << " " << stud1.getMed() << endl;
    cout << stud2.getFirstName() << " " << stud2.getlastName() << " " << stud2.getVid() << " " << stud2.getMed() << endl;

    cout << "----------------------------------------------" << endl;

    Studentas stud4("Test1", "Testauskas", 10, 10);
    cout << (stud1 < stud4) << endl;
    cout << (stud1 > stud4) << endl;

    cout << "----------------------------------------------" << endl;

    Application app;
    app.run();
    return 0;
}
