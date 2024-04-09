#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

// b) struktúra létrehozása
typedef struct {
    int id; // azonosító, beszámozzuk
    int nem; // 1 ha lány, 0 ha fiú
    int tav; // futott távolság
} diak;

int main()
{
    // random seed
    srand((unsigned int)time(NULL));
    
    // a)

    int letszam;
    printf("Hany diak legyen? ");
    scanf_s("%d",&letszam);

    if (letszam < 1) { // nem lehet 0 vagy negatív diák
        printf("A letszam nem lehet 1-nel kisebb!\n");
        return -1;
    }

    // b)
    diak* tomb = (diak*) malloc(sizeof(diak) * letszam);
    for (int i = 0; i < letszam; i++)
    {
        tomb[i].id = i+1;
        tomb[i].nem = rand() % 2;
        tomb[i].tav = rand() % 5001 + 1000;
    }
    
    // c)
    // átlagsebességhez összeg
    int szum = 0;
    int teljesido = letszam * 30 * 60; // mindenki 30 percig futott, átváltjuk másodpercbe

    // maximum és minimumhoz indexek mentése, alap értékek
    int max = tomb[0].tav;
    int min = tomb[0].tav;
    int maxindex, minindex;

    for (int i = 0; i < letszam; i++)
    {
        // maximum és minimum keresése
        if (tomb[i].tav > max) {
            max = tomb[i].tav;
            maxindex = i;
        }
        if (tomb[i].tav < min) {
            min = tomb[i].tav;
            minindex = i;
        }
        // összegzés
        szum += tomb[i].tav; 
    }

    printf("A maximum futott tav: %d A diak: %d.\n", max, tomb[maxindex].id);
    printf("A minimum futott tav: %d A diak: %d.\n", min, tomb[minindex].id);

    int korok = max / 500; // elég az egész szám
    printf("A legtobbet futo %d kort futott.\n",korok);

    double atlagsebesseg = (double)szum / teljesido; // átkasztolás!
    printf("Az atlagsebesseg m/s-ban: %.3lf\n", atlagsebesseg); // 3 tizedesjegy pontosság, opcionális
    double v_kmh = atlagsebesseg * 3.6;
    printf("Az atlagsebesseg km/h-ban: %.3lf\n",v_kmh);

    // d)

    // külön számoljuk a fiúk és lányokat, illetve a távolságokat
    
    int fiudb = 0;
    int lanydb = 0;
    int fiuszum = 0;
    int lanyszum = 0;

    for (int i = 0; i < letszam; i++)
    {
        if (tomb[i].nem == 1)
        {
            lanydb++;
            lanyszum += tomb[i].tav;
        }
        else {
            fiudb++;
            fiuszum += tomb[i].tav;
        }
    }

    double fiuatlag = (double) fiuszum / fiudb;
    double lanyatlag = (double) lanyszum / lanydb;
    double atlagatlag = (fiuatlag + lanyatlag) / 2;
    printf("A fiuk atlaga: %.3lf\n", fiuatlag);
    printf("A lanyok atlaga: %.3lf\n", lanyatlag);

    // legközelebb az átlagátlaghoz?

    int kozelindex = 0;
    int mintav = max; // a maximum futottnál biztos lesz kisebb távolság

    for (int i = 0; i < letszam; i++)
    {
        if (fabs(atlagatlag - tomb[i].tav) < mintav) {
            mintav = fabs(atlagatlag - tomb[i].tav);
            kozelindex = i;
        }
    }
    printf("Legkozelebb a %d. diak volt\n", tomb[kozelindex].id);

    // e)

    int tobbetfutott = 0; // számlálás
    for (int i = 0; i < letszam; i++)
    {
        if (tomb[i].nem == 1 && tomb[i].tav > fiuatlag) tobbetfutott++;
    }

    double szazalek = tobbetfutott / (double)lanydb * 100;
    printf("A lanyok %.3lf%%-a futott tobbet mint a fiuk altal atlagosan futott tavolsag.\n", szazalek);
    
    // f)
    int otos = 0;
    for (int i = 0; i < letszam; i++)
    {
        if (tomb[i].tav > 4000) otos++;
    }
    printf("%d db otos lett\n",otos);

    // g)
     int hatar;
     printf("Mi legyen a hatar? ");
     scanf_s("%d",&hatar);

     int kevesebbetfutott = 0;
     for (int i = 0; i < letszam; i++)
     {
        if (tomb[i].tav < hatar) kevesebbetfutott++;
     }
     printf("Kevesebbet futott a hatarnal %d db diak\n", kevesebbetfutott);

    // h)

    double ossztav = (fiuszum + lanyszum) / 1000.0;
    double konstans = 261.25; // km-enként

    int burgerdb = (ossztav * konstans / 1243.0) + 1;
    int osszkoltseg = burgerdb * 650;

    printf("Az osztalynak %d db sajtburger kell, ami %d Ft-ba kerulne\n",burgerdb,osszkoltseg);

    // i)
           
    if (ossztav > 180000) printf("Kepesek lennenek valtot futni!\n");
    else printf("Nem lennenek kepesek valtot futni!\n");

    // j) buborékrendezés

    for (int i = letszam - 1; i >= 0; i--)
    {
        for (int  j = 0; j < i; j++)
        {
            if (tomb[j].tav > tomb[j+1].tav)
            {
                diak tmp = tomb[j];
                tomb[j] = tomb[j+1];
                tomb[j+1] = tmp;
            }
        }
    }
    // kiiratás
    /*for (int i = 0; i < letszam; i++)
    {
        printf("%d\n", tomb[i].id);
    }
    */

    // k)
    // változók, hogy tudjuk, jelenleg hol tartunk
    int fiuindex = 0;
    int lanyindex = 0;

    // lefoglalás
    diak* fiuk = (diak*) malloc(sizeof(diak) * fiudb);
    diak* lanyok = (diak*) malloc(sizeof(diak) * lanydb);
    
    for (int i = 0; i < letszam; i++)
    {
        if (tomb[i].nem == 1)
        {
            lanyok[lanyindex++] = tomb[i];
            // lehetne külön is a lanyindex++;
        }
        else fiuk[fiuindex++] = tomb[i];
    }
    

    free(lanyok);
    free(fiuk);
    free(tomb);
    return 0;
}