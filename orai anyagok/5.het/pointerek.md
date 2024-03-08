# Pointerek

## Gyors talpaló az IPA legnehezebb fogalmához

### Alapok

A pointerek (mutatók) számok, amik mutatják, hogy egy érték hol található a memóriában (hanyadik byte). Ezek használatával tudjuk a gép memóriáját manipulálni, pl.: tömböket használni. Ezek a pointerek egy bizonyos típushoz mutatnak, `tipus*`-gal jelöljük, egy változó címét/pointerét pedig az `&` operátorral tudjuk megszereni (emiatt kell az a `scanf` függvényben)  

```C
// Int pointer
int valtozo = 5;

int* ptr = &valtozo;

// Ha nincs a pointer változónak értéke, ajánlott NULL-t írni

double* ures = NULL;
```

Pointerrel egy változó/memóriacím értékét felül lehet írni a `*` operátor használatával:

```C
// ptr címét ( = valtozo) felülírjuk
*ptr = 15;

printf("%d\n", valtozo); // 15
```

A `scanf` például így írja a változókba az új értékeket.  

### Tömbök

A tömb egy speciális esete a pointereknek. Azt engedi, hogy egy változóban több, azonos típusú értéket tároljunk, amiket a `tomb[index]` szintaxissal lehet elérni (hasonlóan a diszkrét értékekhez mechatronika alapjaiban). Ezek az indexek a $[0;meret[$ tartományban találhatóak  
A tömbök a háttérben pointerek, amiket `index * sizeof(tipus)`-sal eltolunk. Ez feltételezi, hogy az ottani cím is a miénk, és erre a célra szolgál csak. **A rossz memóriaterületre mutatás kicímzés, ami automatikus PótZH-t jelent**.  
Két fajtája van: statikus és dinamikus

### Statikus tömb

A statikus tömb az egyszerűbb típus, de van egy megkötése: a tömb elemeinek számát fordításkor kell tudni (ergo egy számot lehet csak írni, mint méretet).

A statikus tömbök a következőképpen néznek ki:

```C
int tomb[3]; // 3 index van

// 5 elemű tömb, kapcsos zárójeles felsorolással lehet értékeket is adni
double masik[5] = { -0.5, 3.0, 2.9, 0.0, -3.14 };

masik[3] = tomb[1]; // HIBA: tomb[1]-nek nek adtunk értéket!

tomb[2] = masik[4]; // Jó, van érték, indexek stimmelnek

masik[5] = 6; // KICÍMZÉS!!
```
