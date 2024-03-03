# Bitműveletek

A számítógép a Neumann-elvek alapján 2-es számrendszerben dolgozik. Amikor C-ben programozunk és decimális számokat használunk, ez az átalakítás a háttérben megtörténik.

Például ***a*** = 7 esetén 2-es számrendszerbeli alak:
```
00000000 00000000 00000000 00000111
```
Ebben az esetben mind a 4 byteot ábrázoltuk, hiszen az int mérete C-ben 4 byte. Az egyszerűsítés kedvéért a következőkben csak az utolsó byteot írjuk ki, mivel kis számokkal dolgozunk.

Matematikai műveletek esetén egyszerűen összeadhatunk / kivonhatunk számokat egymásból, ekkor a decimális értéküknek megfelelően  egy új érték keletkezik.

Bitműveletek esetén a műveletet a számok minden bitjére páronként hattatjuk. Az első bit az elsővel, a második a másodikkal képez eredményt és így tovább.

## Komplementer képzés

A komplementer képzés egyoperandusú bitművelet, azaz csak 1 változóra hat. Minden bit komplementerét, azzaz ellentettjét képezi. 

A komplementer művelet jele a C-ben: **~**

Igazságtábla: (ha A a bitünk)

| A | ~A |
| :-: | :-: |
| 0 | 1 |
| 1 | 0 |

Így például az ***a*** szám komplementere:

```
~a  = 11111000
```

Fontos, hogy a nem ábrázolt bitekből is 1-ek lettek!

## Biteltolás/shiftelés

A biteket eltolhatjuk 2 irányba. Balra tolás esetén az összes bit balra mozdul el, így a bal szélen lévő törlődik, míg a jobb szélen lévő helyére egy 0 kerül. Jobbra tolás esetén pont az ellenkező történik.

Az eltolások jele C-ben: << (balra) és >> (jobbra).

Például az ***a*** szám eltolva jobbra és balra 1-el:

```
a >> 1 = 00000011, jobbra tolás
a << 1 = 00001110, balra tolás 
```

A syntax C-ben:
```C
int a = 7;
a = a << 1; // 1-el balra tolva
a = a >> 1; // 1-el jobbra tolva
```

## OR művelet

A 2 szám minden bitjére páronként hattatjuk a VAGY műveletet.

A VAGY művelet jele C-ben: **|**

| A | B | A \| B|
| :-: | :-: | :-: |
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

Ezzel a művelettel adott biteket egyszerűen beállíthatunk.
Állítsuk be például a 4. bitet az ***a*** számban!
Ehhez eltoljuk az 1-et 3-al balra, így egy olyan 2-es számrendszerbeli számot kapunk, melynek 4. bitje 1, a többi pedig 0. Ha ezt az ***a*** számmal "összevagyoljuk", a 4. bit mindenképp 1 lesz, hiszen a VAGY műveletnél elegendő, ha a 2 bit közül az egyik 1 értékű. Mivel az eltolt szám összes többi bitje 0, így a többit változatlanul hagyja, így ha eredetileg 1-es volt, akkor 1 marad, ha 0-s, akkor pedig 0.
```
a: 00000111
(1 << 3): 00001000
a | (1 << 3): 00001111
```
Így a kódunk C-ben:
```C
int a = 7;
int a = a | (1 << 3);
printf("Az uj a: %d\n", a); // Az új érték így 15
```
Lényeges, hogy amíg a | a bitműveletet jelenti, addig a || egy logikai operátor, azaz nem új értéket hoz létre, hanem a 2 oldalon álló kifejezést hasonlítja össze.

Az alábbi kód alapján például egy szám megfelel, ha nagyobb mint 5, VAGY páros. (nem kizáró vagy!)
```C
if (a > 5 || (a % 2 == 0)) printf("Megfelel!\n");
```

## AND művelet

A 2 szám minden bitjére páronként hattatjuk az ÉS műveletet.

Az ÉS művelet jele a C-ben: **&**

| A | B | A \& B|
| :-: | :-: | :-: |
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

Ezzel a művelettel adott biteket egyszerűen kitörölhetünk.
Töröljük ki például a 2. bitet az ***a*** számban!
Ehhez eltoljuk az 1-et 1-el balra, így egy olyan 2-es számrendszerbeli számot kapunk, melynek 2. bitje 1, a többi pedig 0. Mivel törölni akarunk, a többit pedig változatlanul hagyni, ezért hattasuk a komplementer műveletet erre, így csak a 2. bit 0, a többi 1. Ha ezt az ***a*** számmal "összeéseljuk", a 2. bit mindenképp 0 lesz, hiszen az ÉS művelet esetén csak akkor lehet 1 az eredmény, ha a 2 bit közül mindkettő 1 értékű. Mivel az eltolt szám összes többi bitje 1, így a többit változatlanul hagyja, így ha eredetileg 1-es volt, akkor 1 marad, ha 0-s, akkor pedig 0.
```
a: 00000111
(1 << 1): 00000010
~(1 << 1): 11111101
a & ~(1 << 3): 00000101
```
Így a kódunk C-ben:
```C
int a = 7;
int a = a & ~(1 << 1);
printf("Az uj a: %d\n", a); // Az új érték így 5
```
Lényeges, hogy amíg a & a bitműveletet jelenti, addig a && egy logikai operátor, azaz nem új értéket hoz létre, hanem a 2 oldalon álló kifejezést hasonlítja össze.

Az alábbi kód alapján például egy szám megfelel, ha nagyobb mint 5 ÉS páros.
```C
if (a > 5 && (a % 2 == 0)) printf("Megfelel!\n");
```

## XOR művelet (kizáró VAGY)

A 2 szám minden bitjére páronként hattatjuk az XOR műveletet.

A XOR művelet jele a C-ben: **^**

| A | B | A ^ B|
| :-: | :-: | :-: |
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

A művelet például titkosításra használható. Vegyünk egy "maszkot", amely a titkosításunk kulcsa lesz. Ha ezt hattatjuk az ***a*** számra, azzal "kódóljuk", majd ismét alkalmazva a maszkot "dekódolhatjuk". (Ennek oka, hogy (A^B)^B = A)
```
a: 00000111
maszk: 10101010
a ^ maszk: 10101101 (kódolva)
(a ^ maszk) ^ maszk: 00000111 (eredeti szám)
```
Így a kódunk C-ben:
```C
int a = 7;
int maszk = 0b10101010;
int kodolt = a ^ maszk;
printf("Titkositva: %d\n", kodolt); // random szám a maszk alapján
int dekodolt = kodolt ^ maszk;
printf("Dekodolva: %d\n", dekodolt); // ismét 7
```

## Kettes komplemens

Az egészek kettes komplemensén az ellentétes előjelű ábrázolásukat értjük kettes számrendszerben. Az utolsó bit jelzi az előjelet (0, ha pozitív, 1 ha negatív). A modern számítógépek ezt a típusú negatív számábrázolást kezelik a legjobban.

A kettes komplemens képzés lényege, hogy vesszük a szám bitenkénti komplementerét, majd hozzáadunk 1-et. (A hozzáadásnál ha az első bit 0 volt, akkor 1 lesz, ha 1, akkor 0, majd tolódik az összeadás a következő bitre.)

Vegyük az ***a*** kettes komplemensét!
```
a: 00000111
~a: 11111000
(~a) + 1: 11111001
```

Így a kódunk C-ben:
```C
int a = 7;
int komplemens = (~a) + 1;
printf("A(z) %d kettes komplemense: %d\n",a,komplemens);
```

## További segédanyagok

Amennyiben valaki jobban el szeretne merülni a bitmágia különböző varázslataiban:

- [Bitműveletek wikipédia](https://en.wikipedia.org/wiki/Bitwise_operations_in_C)
- [Geeksforgeeks](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)
