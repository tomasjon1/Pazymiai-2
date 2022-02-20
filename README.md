```
# Programa skirta studentų pažymių vidurkiui ir medianai apskaičiuoti.
### Kaip paleisti programą?<br>
Versijoje [v0.1.1](https://github.com/domastyd/Pazymys/blob/v0.1/v0.1.1.cpp) yra naudojami C tipo masyvai. Tačiau, rekomenduojama naudoti programos [v0.1.2](https://github.com/domastyd/Pazymys/blob/v0.1/v0.1.2.cpp) versiją. Joje yra naudojami vector tipo konteineriai, kurie paspartina programos veiklą. 
Norint pasinaudoti šia programa, Jums reikia parsisiųsti failą v0.1.2.cpp ir įsijungti terminal. Su komanda cd nueiti iki savo v0.1.2.cpp failo ir įrašyti "g++ -o main v0.1.2.cpp" komandą ir kai programa bus sukompiliuota, įrašyti "main.cpp" arba "./main".

### Paleidus programą Jums reikės:<br>
- Pasirinkti ar norite įvesti fiksuotą duomenų skaičių, ar turėti galimybę baigti įvesti studentus duomenų įvedimo metu.<br>
- Jeigu pasirenkate įvesti fiksuotą duomenų skaičių, turėsite pasirinkti studentų skaičių, bei namų darbų kiekį skirtą vienam studentui.<br>
- Jeigu pasirenkate baigti įvesti duomenys duomenų įvedimo metu, Jūs turėsite pasirinkti namų darbų kiekį skirtą vienam studentui.<br>
- Įvedę šiuos duomenis, turėsite pasirinkti ar norite matyti automatiškai sugeneruotus studentų pažymius arba pažymius įvesti patys.<br>
- Pasirinke matyti automatiškai sugeneruotus duomenis, turėsite įvesti studentų vardus ir pavardes.<br>
- Pasirinkus įvesti duomenis patiems, turėsite įvesti šįuos duomenis: studentų vardus, pavardes, jų namų darbų pažymius ir egzamino pažymį).<br>
- Tada Jums reikės pasirinkti ar norite matyti studentų pažymių medianas.<br>

(Pažymių vidurkis sudaromis vadovaujantis šia formule: galutinis = 0.4 * vidurkis + 0.6 * egzaminas)<br>
(Pažymių mediana sudaroma vadovaujantis šia formule: mediana = 0.4 * pažymių mediana + 0.6 * egzaminas)<br>
### Pasirinkus šiuos nustatymus matysite sudarytą lentelę su studentu pavardėmis, vardais ir pažymių vidurkiais ir/arba medianomis.
```