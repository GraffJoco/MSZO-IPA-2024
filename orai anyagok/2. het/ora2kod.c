/*2. heti tematika:
- Változók hatásköre (Globális/lokális)
- Típuskonverziók
- implicit / explicit típusmódosítás
- Kifejezések kiértékelése
- Műveletek sorrendisége
- Aritmetikai műveletek: +, -, *, / , %
- Matematikai kifejezések (math.h)
- scanf függvény
*/

// Matematikai konstansok definicióinak használata <math.h> elött
// pl.: M_PI
#define _USE_MATH_DEFINES

#include <stdio.h> // printf, scanf(_s)
#include <math.h>  // matematikai készlet, fuggvények

#define PI 3.14159
#define PIbecsult (22 / 7) // zarojelek kozott megadhato szamolas
#define DUPLA(x) (x * 2)

// globális változók, memóriában maradnak
int egesz;
double tort = PI;
const unsigned int konstans = 3; // nem változtatható meg az értéke, és deklarárásnál meg kell adni

int main(void)
{
    // globális változó akkor is használható, ha nincs kezdeti értéke. Ilyenkor 0 lesz
    printf("egesz erteke: %i\n", egesz);
    // konstans = 4; //hiba, erteke nem változtatható
    printf("konstans duplaja: %u\n", DUPLA(konstans)); // művelet végezhető vele

    // lokális változók (printf elött értéket kell adni neki)
    int i = 10;         // értékadás
    double d = i;       // implicit típus-átalakítás (kicsi -> nagy), automatikus, lehet hiba pl signed->unsigned
    float f = (float)d; // explicit típus-átalakítások (nagy -> kicsi), nekünk kell, a (típus) csak az utána lévő adatra hat
    f = (float)42.56;   // vagy 42.56f
    i = (int)f;         // adatvesztés, eltűnik a törtrész (42)

    // változók hatóköre
    {
        int i = 5;
        int z = 10; // z változó a hatókörön kívül nem lesz használható
        printf("belso i erteke: %i; z erteke = %i\n", i, z);
    }
    // itt már nincs z változó, és i is a külsõ változó lesz, a belsö értéke elveszik
    printf("kulso i erteke: %i\n", i);

    // bal érték, jobb érték fogalma
    tort = (double)1 / 2; // vagy  1 / 2.0, különben int marad

    // műveletek sorrendisége + típusok
    tort = (5 + 3 * 2 - 6) / ((double)3 / 2) * 5;

    int a = 10;
    int b;
    a = a + 1; // a=11;
    // összevont alak +=, -= , *=, /=
    a += 2; // a=13;

    // egy operandusú műveletek
    a = 14;
    b = a++; // b=14 a=15 utótag / post-increment
    b = ++a; // b=16 a=16 előtag / pre-increment

    a = 10;
    // különbség bemutatása printf-el:
    printf("a++ kiiratasa: %d\n",a++);
    printf("a erteke a++ utan: %d\n", a);
    a = 10;
    printf("++a kiiratasa: %d\n",++a);
    printf("a erteke ++a utan: %d\n", a);

    int db = 21 / 5;      // egész osztás (4)
    int maradek = 21 % 5; // maradék (modulus)

    // matematikai műveletek <math.h>
    // sin - szinus radiánban!
    // cos - koszinusz radiánban
    // pow - hatványozás pow(alap, kitevõ), a ^ az bitművelet, nem hatványozás
    // sqrt - gyökvonás
    // exp - e^x
    // log - természetes alapú logaritmus
    // log10 - 10-es alapú logaritmus
    double szamolas = pow(sin(M_PI / 3), (double)2 / 3); //(sin(PI/3))^(2/3)

    int szam_egesz;
    printf("Adjon meg egy egesz szamot: ");
    // érték beolvasása a változóba (címet & kell megadni, ez lesz a pointer, kesobbi tananyag)
    scanf("%i", &szam_egesz); // Microsoft biztonságos verzió scanf_s, ellenorzi mit kapott, zh-ba inkabb ezt
    printf("A megadott szam: %i\n", szam_egesz);

    double szam_tort;
    printf("Adjon meg egy tort szamot: ");
    scanf("%lf", &szam_tort); // double/float esetén %lf kell
    printf("A megadott szam: %lf\n", szam_tort);

    int ora, perc;
    printf("Kerem adja meg a pontos idot \"ora:perc\" alakban: "); // a \ kilepo karakter, idezojel igy lehet a szovegben
    // magat is ki lehet leptetni, kódban \\ -> konzolban \ 
    // több elem beolvasása
    scanf("%i:%i", &ora, &perc);
    printf("A pontos ido: %i:%i\n", ora, perc);

    // változók felcserélése, tobb megoldas
    a = 10;
    b = 20;

    // csere segédváltozóval (mindig működik, tobb memoria hasznalat)
    int c = a;
    a = b;
    b = a;

    // csere segédváltozó nélkül (számoknál és elromolhat pl.: túlcsordulás, tobb szamolasi ido)
    a = a + b;
    b = a - b;
    a = a - b;

    // csere segédváltozó nélkül (egész számoknál)
    a ^= b; // a = a ^ b;	^ bitenkénti kizáró vagy (XOR művelet)
    b ^= a;
    a ^= b;

    return 0;
}
