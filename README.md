```

```

# Programa skirta studentų pažymių vidurkiui ir medianai apskaičiuoti.

### Kaip paleisti programą?<br>
Versijoje [v0.1.1](https://github.com/domastyd/Pazymys/blob/v0.1/v0.1.1.cpp) yra naudojami C tipo masyvai. Tačiau, rekomenduojama naudoti programos [v0.1.2](https://github.com/domastyd/Pazymys/blob/v0.1/v0.1.2.cpp) versiją. Joje yra naudojami vector tipo konteineriai, kurie paspartina programos veiklą. 
Norint pasinaudoti šia programa, Jums reikia įsijungti terminal. Su komanda cd nueiti iki savo v0.1.2.cpp failo ir įrašyti "g++ -o main v0.1.2.cpp" komandą ir kai programa bus sukompiliuota, įrašyti "main.cpp" arba "./main".

### Paleidus programą Jums reikės:<br>
- Pasirinkti ar norite matyti studentų pažymių medianas.
- Pasirinkti ar studentų skaičius yra fiksuotas, su galimybė nutraukti studentų duomenų suvedimą.
- Pasirinkti ar norite matyti automatiškai sugeneruotus duomenis, turėsite įvesti studentų vardus ir pavardes bei namų darbų kiekį vienam studentui.
- Pasirinkus įvesti duomenis patiems, turėsite įvesti šįuos duomenis: studentų vardus, pavardes, jų namų darbų kiekį, pažymius ir egzamino pažymį).

(Pažymių vidurkis sudaromis vadovaujantis šia formule: galutinis = 0.4 * vidurkis + 0.6 * egzaminas)<br>
(Pažymių mediana sudaroma vadovaujantis šia formule: mediana = 0.4 * pažymių mediana + 0.6 * egzaminas)<br>

### Pasirinkus šiuos nustatymus matysite sudarytą lentelę su studentu pavardėmis, vardais ir pažymių vidurkiais ir/arba medianomis.

-------------------------
1000 irasu testavimas
Failo generavimo laikas: 0.0090721 s
Studentu dalinimo i dvi grupes laikas: 0.0009283 s
Surusiuotu studentu isvedimas i naujus failus uztruko: 0.0265609 s
Visos programos veikimo laikas: 12.5268 s
-------------------------
-------------------------
10000 irasu testavimas
Failo generavimo laikas: 0.0208313 s
Studentu dalinimo i dvi grupes laikas: 0.0044929 s
Surusiuotu studentu isvedimas i naujus failus uztruko: 0.0224853 s
Visos programos veikimo laikas: 6.23675 s
-------------------------
-------------------------
100000 irasu testavimas
Failo nuskaitymo laikas: 0.350059 s
Studentu dalinimo i dvi grupes laikas: 0.0965414 s
Surusiuotu studentu isvedimas i naujus failus uztruko: 0.182653 s
-------------------------
-------------------------
100000 irasu testavimas
Failo generavimo laikas: 0.164239 s
Studentu dalinimo i dvi grupes laikas: 0.0438312 s
Surusiuotu studentu isvedimas i naujus failus uztruko: 0.159213 s
Visos programos veikimo laikas: 7.61452 s
-------------------------
-------------------------
10000000 irasu testavimas
Failo generavimo laikas: 16.7132 s
Studentu dalinimo i dvi grupes laikas: 6.11869 s
Surusiuotu studentu isvedimas i naujus failus uztruko: 15.3828 s
Visos programos veikimo laikas: 103.824 s
-------------------------
