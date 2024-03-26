#include <stdlib.h> // srand, rand, exit
#include <stdio.h> // printf, scanf
#include <time.h> // time

int main() {
    // Ahhoz, hogy egyszerűbben meg tudjuk oldani,
    // a következő trükköt tudjuk használni:
    // mi lenne, ha nem a hallgatók pontjait tárolnánk tömbben,
    // hanem, hogy az adott pontszámot hány hallgató kapta?
    // Más szóval, ahelyett, hogy az adott index a hallgató pontszámát
    // tárolná, az adott index azt tárolja, hogy hányan kaptak index pontot

    srand((unsigned int) time(NULL));

    int bukasok = 0;
    int n;
    printf("Hany hallgato irt ZH-t? ");
    scanf_s("%d", &n);

    // Rossz input keresése
    if (n <= 0) {
        printf("Csak pozitiv szamu hallgato lehet!\n");
        exit(-1); // itt return -1; is elfogadható
    }

    // 101 elem, mert a pontszámok [0;76] intervallumban 77 egyedi értéket vehetnek fel
    int pontszamok[77];
    // Tömb lenullázása
    for (int i = 0; i < 77; i++) {
        pontszamok[i] = 0;
    }
    
    // pontszámok betöltése
    for (int i = 0; i < n; i++) {
        const int pontszam = rand() % 77;
        pontszamok[pontszam]++;
    }

    // [0; 40[ között biztos bukás
    for (int i = 0; i < 40; i++) {
        bukasok += pontszamok[i];
    }

    // >= 65% 40% alatt írt => érvénytelen ZH
    if ((double)bukasok >= n * 0.65) {
        printf("ZH ervenytelen, %d hallgato irt 40 pont alatt, ami az ossz %.1lf%%-a\n", bukasok, (double)bukasok/n*100.0);
        exit(-1); // return -1; is elfogadható
    }

    int szamlalo = 40;
    while ((double)bukasok + pontszamok[szamlalo] < n * 0.65 && szamlalo < 50) {
        bukasok += pontszamok[szamlalo];
        szamlalo++;
    }

    if (szamlalo < 50) {
        printf("Ahhoz, hogy meg elfogadhato legyen a ZH, a kettes hatara %d pont volt\n", szamlalo);
        printf("%d-bol %d hallgato bukott, ami %.1lf%%\n", n, bukasok, (double)bukasok / n * 100.0);
    } else {
        printf("Nem is lett olyan rossz, csak %.1lf%%-nak nem ment\n", (double)bukasok / n * 100.0);
    }
}