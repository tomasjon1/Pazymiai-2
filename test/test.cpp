#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../data.h"
#include "../application.h"
#include "../generation.h"
#include "../application.h"
#include "../validation.h"
#include "../human.h"

TEST_CASE("Istestuoti vardo gavima")
{
    Studentas stud("Tomas", "Jonauskas", 8, 7);
    REQUIRE(stud.getFirstName() == "Tomas");
}

TEST_CASE("Istestuoti egzamino ivedima")
{
    Studentas stud;
    stud.setExam(8);
    REQUIRE(stud.getExam() == 8);
}

TEST_CASE("Apskaiciuoti vidurki ")
{
    Studentas stud;

    stud.sethomeWork(8);
    stud.sethomeWork(8);
    stud.sethomeWork(8);
    stud.sethomeWork(8);
    stud.setExam(8);
    stud.calculateAvarage();

    REQUIRE(stud.getVid() == 8);
}

TEST_CASE("Apskaiciuoti mediana ")
{
    Studentas stud;

    stud.sethomeWork(8);
    stud.sethomeWork(8);
    stud.sethomeWork(8);
    stud.sethomeWork(8);
    stud.setExam(8);
    stud.calculateMedian();

    REQUIRE(stud.getMed() == 8);
}
