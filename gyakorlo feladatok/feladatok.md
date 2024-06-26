# Gyakorló feladatok

A feladatok megoldása megtalálható a sorszámuknak megfelelő *.c* kiterjesztésű fájlban.

## 1. Adatok bekérése a konzolról

a) Kérj be 2 egész számot! Írasd ki a képernyőre az összegüket, a szorzatukat és az első szám másodikkal való maradékos osztásának eredményét!

b) Kérd be egy téglalap 2 oldalának hosszát (nem feltétlen egész)! Írasd ki a képernyőre a területét és a kerületét!

c) Kérj be egy hőmérsékleti értéket °C-ban! Váltsd át Fahrenheitba, majd írasd ki a konzolra 3 tizedesjegy pontossággal!

## 2. Elágazások

a) Kérj be egy egész számot! Vizsgáld meg, hogy pozitív-e! Ha igen, akkor páros vagy páratlan?

b) Kérj be 3 számot! Írasd ki közülük a legnagyobbat!

c) Kérd be egy másodfokú egyenlet 3 együtthatóját! Vizsgáld meg, hogy hány megoldás van, majd írasd ki azokat!

d) Határozza meg egy r sugarú körnek a középpontjától l távolságra lévő pontból húzott érintőjének a hosszát! Ellenőrizze, hogy a pont nem esik e a körön belülre vagy a körre!

e) Oldja meg az a * cos(7x) + b = 0 egyenletet, ahol a és b konzolról beadott paraméterek! (Elegendő 1 megoldás megadása.)

## 3. Random számok és ciklusok

a) Generálj 10 random egész számot -8 és 17 között! Írasd ki az összegüket és az átlagukat!

b) Írasd ki a szorzótáblát soronként "a * b = c" formátumban!

c) Kérj be számokat addig, amíg a felhasználó nem jelzi, hogy elég! Írasd ki az összegüket! (bónusz: és az átlagukat)

d) Generálj egy véletlen számot 56 és 279 között! Vizsgáld meg, hogy prímszám-e!


## 4. Tömbök

a) Egy 30 elemes egész statikus tömböt tölts fel random számokkal 0 és 100 között, az átlagukat írd ki!

b) Kérj egy n egész számot a felhasználótól,
ha nem lehet akkora tömb, akkor írd ki, hogy "Rossz érték", és lépj ki -1 kóddal.
Ha jó, akkor hozz létre n db nemegész számot [1; 5] között, és írd ki
a szorzatukat.

c) Hozz létre egy n elemű egész tömböt, amiben tárolod a hallgatók pontszámát [0; 100].
Ez alapján ossz jegyeket, írj ki minden pontszámot "[pontok; jegy]" formátumban,
valamint csinálj kis statisztikát, hogy hányan milyen jegyet kaptak.

d) Hozz létre egy 30 elemből álló dinamikus tömböt, amely egész számokat tárol. Töltsd fel 1 és 2000 közötti, 2-vel és 7-tel is osztható számokkal. Írd ki azokat a számokat, amelyek oszthatóak 4-gyel vagy 5-tel! Az eredeti tömböt rendezd csökkenő sorrendbe, majd írasd ki az elemeit!

e) Írasd ki a Fibonacci sorozat első n elemét!

## 5. Struktúrák és függvények

a) Készíts egy komplex szám struktúrát! Hozz létre egy dinamikus tömböt, amely konzolról beadott darabszámú komplex számot tartalmaz! A valós és képzetes részek is -100 és 100 között legyenek. Írj függvényeket 2 komplex szám összeadására, kivonására és szorzására. Próbáld ki ezeket a tömb pár elemén!

b) Hozz létre egy hallgató struktúrát! Legyen egy azonosítója, amely egy 4 jegyű egész szám, illetve egy korrigált kreditindex értéke. Tárold el őket egy tetszőleges méretű tömbben, random generálva. Írasd ki a konzolra azon hallgatók azonosítóját, akik kaptak kollégiumi férőhelyet, ha a minimum KKI 3.98 volt! (az azonosítók ismétlődésétől tekintsünk el)

c) Írj egy függvényt, amely bemenete egy n egész szám, visszatérési értéke pedig az első n pozitív egész szám összege!


## 6. Stringkezelés

Adott az alábbi vers:
```C
char vers[] = "Tudom en mar, mit csinalok:\n\
szoftverfejlesztonek allok.\n\
Lesz majd harom monitorom,\n\
a szekemet odatolom,\n\
bucsut intek minden nyugnek,\n\
Nyomkodom a billentyuket.\n\
Mozi, szinhaz? Masnak hagyom,\n\
nekem mindig van programom.\n\
Kodot irok, mint a kemek,\n\
szamitogepul beszelek.\n\
Kitalalsz egy jo kis tervet,\n\
elmondom a kompjuternek.\n\
Igy fejlesztek szoftvert, sokat,\n\
telefonra jatekokat,\n\
GPS-t a kocsitokba\n\
(belefer egy kicsi tokba),\n\
szimulalhatsz helikoptert,\n\
hogyha irok neki szoftvert,\n\
hatart csak a kepzelet szab!\n\
Es egesz nap gepezek csak.\n";
```
Feladatok:

a) Határozzuk meg, hogy hány sorból áll a vers!

b) Határozzuk meg, hogy hány mondatból áll a vers!

c) Hány magánhangzó van a szövegben?

d) Határozzuk meg a határozott ("a", "az") és határozatlan ("egy") névelők számát!

e) Kérjünk be egy karaktert a konzolról! Írassuk ki az összes olyan szót **csupa nagybetűvel**, ami ezzel a betűvel kezdődik!

f) Kérjünk be egy szót / mondatrészt a konzolról! Tartalmazza-e ezt a vers egy sora?

g) Hány olyan szó van, ami páros számú betűből áll?

h) Fűzzük egybe az összes szót, egy hosszú karakterláncba, bármi elválasztó karaktert kihagyva!






