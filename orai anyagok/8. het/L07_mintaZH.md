# IPA L_07 Csoport mintaZH

Feladat: Egy kolléga a félévi eredményét próbálja értékelni.  

1. Csinálj egy `targy` nevű struktúrát, amiben két egész érték van: a kreditszám, és jegy. $2 pont$

2. Olvasd be a hallgatótól, hogy hány tárgya volt (ez a szám innentől $n$)! Ellenőrizd, hogy pozitív egész-e az érték (más értelmetlen lenne). Ha rossz értéket kaptunk, akkor lépjünk ki a programból egy error üzenettel! $2 pont$

3. Hozz létre egy $n$ méretű, `targy` típusú dinamikus tömböt, és töltsd fel! Minden tárgy jegye 1-5, kreditértéke 2-6 közötti egész szám. $4 pont$

4. Írd ki külön-külön a felvett-, és teljesített krediteket! $3 pont$

5. Számold ki a hallgató KKI-jét! $6 pont$  
A következő képlet alapjás lehet ezt számolni:  

$$KKI = {\sum{kredit \cdot jegy}\over 30}\cdot{teljesített kredit \over felvettkredit}$$  

*(Megj.: jegy = 0 bukott tárgy esetén)*

- Szintaktikai pontok: amennyiben megvan a kettes, akkor ezeket automatikusan megkapod, de szépséghiba esetén ebből le lehet vonni. $3 pont$