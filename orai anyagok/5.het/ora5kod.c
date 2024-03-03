/*5.het tematika:
- Mutatók
- Statikus tömbök
- Dinamikus tömbök
- malloc
- free
- for ciklus
*/

#include <stdio.h>  // printf, scanf(_s)
#include <math.h>   // matematikai készlet
#include <stdlib.h> // malloc

#define TMERET 10

int main(void)
{
    // Mutató használata
    int i = 100;   // lokális statikus változó stack-en
    int *p = NULL; // pointer
    p = &i;        // változó címét tárolja
    printf("i=%i &i=%i *p=%i p=%i &p=%p\n", i, &i, *p, p, p);
    // pointer merete 8 byte 64-bites rsz-ben; 4 byte 32-bitesben; ez tipus fuggetlen

    // A valtozo és *pointer ugyanaz
    i++; // ha változik a statikus változó
    printf("i=%i *p=%i\n", i, *p);

    *p = 20; // ha értéket adunk a pointer áltat mutatót változónak
    printf("i=%i *p=%i\n", i, *p);

    // precedencia szabály!!!
    *p++; // elmozdul a pointer, KICIMZES!!, helyesen (*p)++ vagy ++*p
    printf("i=%i *p=%i\n", i, *p);
    // poineterrel vegezheto muveletek: ++/--; +/- int;
    // ugyanarra a tipus pointerre: ptr-ptr; ptr==ptr; ptr=ptr;

    // dinamikus terület foglalás heap-re
    double *pd = (double *)malloc(sizeof(double));
    *pd = 43.25;
    printf("%f\n", *pd);
    free(pd); //"Aki malloc-ol tegyen free-t is"
    // felszabadítás után már nem szabad használni!!
    printf("%f\n", *pd);

    // típus nélküli általános pointer
    void *pv = malloc(sizeof(double));
    printf("%x\n", pv);
    *(double *)pv = 43.25;
    printf("%lf\n", *(double *)pv);
    free(pv);
    pv = NULL;

    // Tömb és for ciklus
    // statikus tomb, a programnak lefutas elott tudnia kell a meretet, fix
    int ti[TMERET];              // a ti valojaban egy int pointer
    for (i = 0; i < TMERET; i++) // for (inicializalaskor;feltetel;itertacio vegen)
        ti[i] = i * i;           // lehetne *(ti+i)
    for (i = 0; i < TMERET;)     // a for (;;) is valid, ures feltetel olyan mintha (true) lenne
        printf("%d ", ti[i++]);
    printf("\n");

    // inicializálás
    int ti2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};     // 10 elemű tömb - statikus, a merete = {} kozotti elemszam
    const int tmeret = sizeof(ti2) / sizeof(ti2[0]); // megadja a tömb méretét  //sizeof(ti2)/sizeof(int)
    for (i = 0; i < tmeret; i++)
        printf("%i ", ti2[i]); // előre

    printf("\n");
    for (i = tmeret - 1; i >= 0; i--)
        printf("%d ", ti2[i]); // vissza felé

    printf("\n");

    p = ti2; // végigjárás pointerrel - pointer a tömb elejére irányítva
    for (i = 0; i < tmeret; i++)
        printf("%i ", *(p++)); // *p++ is elég

    p = &ti2[tmeret - 1]; // visszafelé - pointer a tömb végére irányítva
    for (i = 0; i < tmeret; i++)
        printf("%d ", *(p--));
    printf("\n");
    // mindketto utan p-t ujabb ertekadas elott nem szabad hasznalni mert elkoborolt

    // dinamikus tömbkezelés
    int j;
    int *pi = (int *)malloc(tmeret * sizeof(int)); // 10 elemű tömb - dinamikus -> nem fix a meret

    for (i = 0, j = tmeret - 1; i < tmeret; i++, j--) // vesszovel elvalasztva tobb parancs, deklaralasnal csak ugyaolyan tipusuak
        pi[i] = ti[j];                                // pi[i] = *(ti+i)
    for (i = 0; i < tmeret; i++)
        printf("%i ", *(pi + i));
    printf("\n");
    free(pi); // felszabadítás

    return 0;
}
