# 1. ZH felkészítő feladatok

Itt találhatóak az egyes feladatok, amik remélhetőleg tudnak segíteni majd az 1. Zárthelyire való felkészülésben. Minden feladathoz ki van írva, hogy milyen tudást igényel az általunk használt megoldásban (de programozásnál természetesen minden megoldás ugyanúgy elfogadott, ha működik a tiéd, az is jó).  
Lehetnek feladatok, amik nehezebbek az első zárthelyinél. Ezeket **(\*)**-al jelöljük Ha ezt meg tudod oldani, akkor biztos készen állsz az első ZH-ra.  
Egyéb feladatokat lehet az előző évi MSZO konzultációban is találni.

## Zárthelyik

Kérj a felhasználótól egy pozitív egész számot (addig csináld, amíg kapsz egyet), és hozz létre egy akkora dinamikus tömböt. Töltsd fel a tömböt random pontszámokkal $(p \in [0; 100])$. Írd ki a hallgatói pontszámokat, és a jegyet. Végén írd ki az átlag pontszámot, jegyet, és bukási rátát!

Jegyek a normális osztályozás alapján vannak osztva:  

Egyes: $p < 40$  
Kettes: $40 \leq p < 55$  
Hármas: $55 \leq p < 70$  
Négyes: $70 \leq p < 85$  
Ötös: $85 \leq p$

## Futó diákok

Egy gimnáziumi testnevelés órán a diákokat betonon futással kínozzák a 40 °C-ban. A diákoknak 30 percen át kell minél többet futniuk, hogy jó jegyet kaphassanak.

a) Kérje be a felhasználótól, hogy hány diák jár az osztályba! Amennyiben a megadott szám nem lehetséges, írjon ki hibaüzenetet és lépjen ki a programból!

b) Készítsen egy dinamikus tömböt, ami az osztályba járó embereket tárolja! Az diákok legyenek sorszámozva (azonosító), legyen nemük (logikai változóként), valamint tároljuk el, hogy hány (egész) métert futottak (tegyük fel, hogy senki nem futott 6km-nél többet, se 1 km-nél kevesebbet). A nem és a futott távolság legyenek random generáltak. (A struktúrát átnevezhetjük "diak"-nak a rövidítés kedvéért.)

c) Írja ki a konzolra, hogy ki futotta a legtöbbet és a legkevesebbet! (elegendő 1 diák mindkettőhöz) Ha egy kör 500 méter volt, hány egész kört futott a legtöbbet futó? Mennyi volt az osztály átlagsebessége m/s-ban és km/h-ban? (nem a sebességek átlaga!)

d) Határozza meg külön-külön a fiúk és a lányok által futott átlagos távolságot! Ki volt az a diák, aki által futott távolság legközelebb volt a 2 átlag átlagához?

e) Határozza meg, hogy hány százaléka a lányoknak futott többet, mint a fiúk által átlagosan futott távolság!

f) Akinek sikerült legalább 4km-t futni, az ötöst kapott. Hány ilyen diák volt?

g) Kérjen be egy számot a konzolról méterben! Hányan futottak ennél kevesebbet? Volt olyan diák, aki pont ennyit futott?

h) Tegyük fel, hogy a fogyasztott energia mindenkinél egyenesen arányos az általa futott távolsággal, és ez a konstans 261,25 kJ/km. Legalább hány (egész) mekis sajtburgert vegyen az osztály, ha szeretné visszatölteni az energiáját? (1 sajtburger = 1243 kJ) Mennyi pénzbe kerül ez, ha 650 forint egy burger?

i) Budapest és Szeged távolsága körülbelül 180km. Képes lenne-e az osztály váltófutást tartani a két város között?

j) Rendezze sorba a diákokat futott távolság alapján növekvő sorrendbe!

k) Szedje külön dinamikus tömbökbe a lányokat és a fiúkat!



## **(\*)** Életjáték

Az életjáték, vagy [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) egy alap szintű szimulációs játék. A játék a következő módon írható le: van egy kétdimenziós mátrixunk, az elemeit cellának hívjuk. Minden cellának két állapota lehet: életben van, vagy halott. Minden játéklépésben egy cella élő lesz (akkor is, ha halott volt), ha pontosan 3 szomszédja él. Ha egy élő cellának nem 2 vagy 3 élő szomszédja van, akkor meghal.  
A feladat a következő: kérj be a felhasználótól két pozitív, egész számot, ami a mátrix méretét fogja jelölni. A felhasználótól kérd be, hogy max. hány élő cellával induljon a játék. Ezeket az élő cellákat szórd el random szám generátorokkal (nem kell ellenőrizni, hogy ezek ütköznek-e). Első lépésnél írd ki a mátrixot. Élő cellát `X`-el, halottat `.`-tal jelöld. Utána szimulálj le egy lépést, és írd ki azt is.  
Feladathoz kell:

- többdimenziós dinamikus tömb
- ciklusok
- random számok
- függvények (nem kötelező, de szebb a kód)

## Neptun kód generátor  

Csinálj egy programot, ami random generál egy neptun kódot. Minden kód 6 karakterből áll, ezek angol betűk vagy számok legyenek. Egy új szabály is van, hogy minden karakter legyen eredeti. Írd ki a generált kódot a konzolba.

Feladathoz kell:

- Karakterkódok ismerete
- Statikus tömbhasználat
- Random számgenerátor

## A Rossz ZH  

Egy, itt meg nem nevezett tanszék meg akarja szivatni a hallgatókat. A legjobb hallgató max 76%-ot írt. Kérd be, hogy hány hallgató (n N+ ) írt ZH-t. Generáld le a pontszámokat. A tanszék döntheti el, hogy 40% és 50% között mennyi legyen a kettes határa. Úgy húzd meg a határt, hogy a bukási ráta maximum legyen, de ne érje el a 65%-ot. Ha ez lehetetlen, mert >65% írt 40% alatt, akkor írd ki, hogy a ZH érvénytelen. Ha azért, mert >65% írt 50% fölött, akkor írd ki, hogy “nem is lett olyan rossz”. Különben írd ki a bukók számát, és arányát.

Feladatnak két megoldása van

Elsőhöz kell:

- Random számok
- Statikus tömb
- Algoritmusok ismerete

Másodikhoz kell:

- Random számok
- Dinamikus tömb
