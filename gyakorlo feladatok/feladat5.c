#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// a) komplex szám struktúra létrehozása
struct komplex {
    double re, im;
};

// függvények
struct komplex k_osszead(struct komplex k1, struct komplex k2) {

    struct komplex k; // összeg változója
    k.re = k1.re + k2.re;
    k.im = k1.im + k2.im;
    return k;
}
struct komplex k_kivon(struct komplex k1, struct komplex k2) {
    struct komplex k;
    k.re = k1.re - k2.re;
    k.im = k1.im - k2.im;
    return k;
}
struct komplex k_szoroz(struct komplex k1, struct komplex k2) {

    struct komplex k;
    k.re = k1.re * k2.re - k1.im * k2.im;
    k.im = k1.re * k2.im + k1.im * k2.re;
    return k; 
}

// b) struktúra
struct hallgato {
    int azonosito;
    double KKI;
};

// c) a függvény:

int elson(int n)
{
    int szumma = 0;
    for (int i = 1; i <= n; i++) // lehet 0-val is indítani, nem változtat rajta
    {
        szumma += i;
    }
    return szumma;
}

int main() {

srand((unsigned int)time(NULL));
// a)
int db;
printf("Hany darab komplex szam legyen? ");
scanf_s("%d",&db); // bónusz: ellenőrizzük, hogy legalább 2 e az érték

struct komplex* szamok = (struct komplex*)malloc(sizeof(struct komplex) * db);
for (int i = 0; i < db; i++)
{
    szamok[i].re = (rand() % 201) - 100;
    szamok[i].im = (rand() % 201) - 100;
}
struct komplex osszeg = k_osszead(szamok[0],szamok[1]);
printf("Ket komplex szam osszege: %lf + %lfi\n", osszeg.re, osszeg.im);
struct komplex kivont = k_kivon(szamok[0],szamok[1]);
printf("Ket komplex szam kulonbsege: %lf + %lfi\n", kivont.re, kivont.im);
struct komplex szoroz = k_szoroz(szamok[0],szamok[1]);
printf("Ket komplex szam szorzata: %lf + %lfi\n",szoroz.re, szoroz.im);
free(szamok);

// b)

// statikus tömbben tároljuk
struct hallgato lista[30];
for (int i = 0; i < 10; i++)
{
    lista[i].azonosito = (rand() % 9000) + 1000; // random négyjegyű szmá, összesen 9000 db van, a 0-t eloltjuk 1000-be
    lista[i].KKI = (rand() / (double)RAND_MAX )* 7; // tegyük fel, hogy a senkinek nincs most 7-nél nagyobb KKI-ja 
}
// kielemzés, ezt lehetne az előző ciklusba is írni
printf("A kollegiumi helyet kapott hallgatok: \n");
for (int i = 0; i < 10; i++)
{
    if (lista[i].KKI >= 3.98) printf("%d\n",lista[i].azonosito);
}

// c) függvény meghívása
int n;
printf("Az elso hany pozitiv egesz szam osszegere vagy kivancsi? ");
scanf_s("%d",&n);
printf("Az elso %d pozitiv egesz szam osszege: %d\n", n, elson(n));


    return 0;
}