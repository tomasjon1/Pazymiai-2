## V1.2

### Kaip paleisti programą?<br>
Versijoje [v1.2](https://github.com/tomasjon1/Pazymiai-2/tree/v1.2):
- Jums reikia įsijungti terminal.
- Su komanda cd nueiti iki savo v0.3.cpp failo. 
- Įrašyti `MinGW32-make`komandą.
- Įrašyti `main.cpp` arba `./main`.

### Paleidus programą Jums reikės:<br>
- Pasirinkti ar norite skaityti is failo.
  - Pasirinkti ar norite sugeneruoti norima duomenų faila, su norimu studentu dydžiu bei pazymiu kiekiu.
  - Arba ivesti failo pavadinima.
- Kitu atveju: 
  - Pasirinkti ar studentų skaičius yra fiksuotas, su galimybė nutraukti studentų   duomenų suvedimą.
  - Pasirinkti ar norite matyti automatiškai sugeneruotus duomenis, turėsite įvesti studentų vardus ir pavardes bei namų darbų kiekį vienam studentui.
  - Pasirinkus įvesti duomenis patiems, turėsite įvesti šįuos duomenis: studentų vardus, pavardes, jų namų darbų kiekį, pažymius ir egzamino pažymį).

### Pasirinkus skaityma is failo
- Studentai bus surasyti i 2 skirtingus failus: Vargsiukai.txt ir Kietekai.txt

### Pasirinkus duomenu ivedima ranka
- Matysite sudarytą lentelę su studentu pavardėmis, vardais ir pažymių vidurkiais ir medianomis "rez.txt" faile.

## PC stats
- CPU Intel Core i7-8750H
- RAM 16
- SSD 500GB

## Sturct vs Class (vector), Strategija 2 - skaidymas i grupes+
| Tipas  | 1000000 | 10000000 | 
| ------------- | ------------- | ------------- |
| Sturct  | 1.072736  | 9.413181  | 
| Class  | 0.583145 | 5.47949 | 


| Tipas  | 1000  | 10000 | 100000  | 1000000  | 10000000 | 
| ------------- | ------------- | ------------- | ------------- | ------------- | ------------- |
| O1  | 0.0147449 | 0.100956  | 0.584785 | 5.61137 | 57.8394  | 
| O2  | 0.0132218 | 0.100368 | 0.55616  | 5.52116  | 58.4422 | 
| O3  | 0.0134734 | 0.10079 | 0.558621  | 5.45973 | 58.3061 | 
