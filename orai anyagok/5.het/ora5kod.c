/*5.het tematika:
- Mutatók
- Statikus tömbök
- Dinamikus tömbök
- malloc
- free
- for ciklus
*/

#include <stdio.h>  // printf, scanf(_s)
#include <conio.h>  // getch()
#include <math.h>   // matematikai készlet
#include <stdlib.h> // malloc

#define TMERET 10

int main(void)
{
    // Mutató használata
    int i = 100, j; // lokális statikus változó stack-en
    int *p = NULL;  // pointer
    p = &i;         // változó címét tárolja
    printf("i=%i &i=%i *p=%i p=%i &p=%p\n", i, &i, *p, p, p);

    i++; // ha változik a statikus változó
    printf("i=%i *p=%i\n", i, *p);

    *p = 20; // ha értéket adunk a pointer áltat mutatót változónak
    printf("i=%i *p=%i\n", i, *p);

    // precedencia szabály!!!
    *p++; // (*p)++ *p+1 *(p+1) melyik mit csinál?
    printf("i=%i *p=%i\n", i, *p);

    // dinamikus terület foglalás heap-re
    double *pd = (double *)malloc(sizeof(double));
    *pd = 43.25;
    printf("%f\n", *pd);
    free(pd);
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
    int ti[TMERET];
    for (i = 0; i < TMERET; i++)
        ti[i] = i * i;
    for (i = 0; i < TMERET;)
        printf("%d ", ti[i++]);
    printf("\n");

    // inicializálás
    int ti2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};     // 10 elemű tömb - statikus
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
    p = &ti2[tmeret - 1];      // visszafelé - pointer a tömb végére irányítva
    for (i = 0; i < tmeret; i++)
        printf("%d ", *(p--));
    printf("\n");

    // dinamikus tömbkezelés
    int *pi = (int *)malloc(tmeret * sizeof(int)); // 10 elemű tömb - dinamikus
    for (i = 0, j = tmeret - 1; i < tmeret; i++, j--)
        pi[i] = ti[j]; // pi[i] = *(ti+i)
    for (i = 0; i < tmeret; i++)
        printf("%i ", *(pi + i));
    printf("\n");
    free(pi); // felszabadítás

    return 0;
}
