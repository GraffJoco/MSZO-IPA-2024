# Processzor

Szimuláljunk le egy számítógépes processzort! Ennek a processzornak 8 (int) regisztere van, 0-7-es indexekkel, ami mind 0 kezdőértékről indul. A processzor a következő utasításokat ismeri:

- *mov a,b*: *a* regiszterbe másolja *b* regiszter értékét

- *add a,b*: *a* regiszterhez hozzáadja *b* regiszter értékét

- *adv a,v*: *a* regiszterhez hozzáad *v*-t

- *cmp a,b*: *a* regiszter = 0, ha *b* regiszter != *a*, különben *a* = 1

- *jnz a, v*: ha *a* regiszter != 0, átugorja a következő *v* sort

- *wrg a*: *a* regiszter értékét kiírja a konzolba

- *rrg a*: *a* regiszter értékét beolvassa a konzolból

Egy utasitasok.txt fájlt olvass be (írd ki, ha nem tudtad), és ezek alapján a szabályok alapján szimuláld le a processzort (egy sor = 1 utasítás)! Ha egy sor üres, vagy rossz kulcsszót tartalmaz, akkor ugord át, de ha rossz regiszter azonosítót kapsz, akkor írd ki, hogy „Kicímzés az {x}. sorban!”, és lépj ki -1-es kóddal a programból!
