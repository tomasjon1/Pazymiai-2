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

## PC stats
- CPU Intel Core i7-8750H
- RAM 16
- SSD 500GB

## Rezultatai
-------------------------
1000 irasu testavimas
Failo nuskaitymo laikas: 0.0119663 s
Studentu dalinimo i dvi grupes laikas: 0.002585 s
Surusiuotu studentu isvedimas i naujus failus uztruko: 0.0017015 s
-------------------------
10000 irasu testavimas
Failo nuskaitymo laikas: 0.0503948 s
Studentu dalinimo i dvi grupes laikas: 0.0180608 s
Surusiuotu studentu isvedimas i naujus failus uztruko: 0.0032375 s
-------------------------
-------------------------
100000 irasu testavimas
Failo nuskaitymo laikas: 0.489797 s
Studentu dalinimo i dvi grupes laikas: 0.173178 s
Surusiuotu studentu isvedimas i naujus failus uztruko: 0.0204416 s
-------------------------
-------------------------
1000000 irasu testavimas
Failo nuskaitymo laikas: 4.10158 s
Studentu dalinimo i dvi grupes laikas: 2.22148 s
Surusiuotu studentu isvedimas i naujus failus uztruko: 0.21376 s
-------------------------
-------------------------
1000000 irasu testavimas
Failo nuskaitymo laikas: 4.10158 s
Studentu dalinimo i dvi grupes laikas: 2.22148 s
Surusiuotu studentu isvedimas i naujus failus uztruko: 0.21376 s
-------------------------

