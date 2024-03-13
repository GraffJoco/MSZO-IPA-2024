/* IPA 6. HETI GYAKORLAT - STRUKTÚRÁK*/

#include <stdio.h>  // printf, scanf(_s)
#include <stdlib.h> // RANAD_MAX, malloc
#include <time.h>   // time

#define TMERET 10

/* STRUKTÚRÁK */

// Struktúra - több, különbözű típusú, névvel ellátott érték egymás után egy,
// kombinált változóban
// Programozási tapasztalatokkal rendelkezőknek: primitív objektum, nincsenek tagfv-k

// Példa: 2D vektor
struct p2D
{
    double x;
    double y;
    // int index;  //további adatok
};

// Állnév
typedef unsigned int termeszetes;

// Stuktúra állnévvel
typedef struct
{
    int x, y;
} pixel_t;

typedef struct p2D pixel_t2;

int main(void)
{
    int i;
    srand((unsigned int)time(NULL));

    // statikus tömb
    // 0,0.5,1...100
    double st[TMERET];
    double *pp = st; // végigjárás pointerrel
    for (i = 0; i < TMERET; i++)
        *(pp++) = (double)(rand() % 201) / 2; // st[i]
    // a program végéig megmarad!!!!;
    printf("statikus tomb: %x\n", st); // pointere

    // Megszámolás
    int db = 0;
    for (i = 0; i < TMERET; i++)
        if (st[i] < 50)
            db++;
    printf("A 50-nel kisebb szamok: %d\n", db);

    // Buborék rendezés

    for (i = TMERET - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++) // i helyett Tmerettel lenne 1 ciklus
        {
            if (st[j] > st[j + 1])
            {
                double tmp = st[j];
                st[j] = st[j + 1];
                st[j + 1] = tmp;
            }
        }
    }
    printf("Rendezeve:\n");
    for (i = 0; i < TMERET; i++)
        printf("%.1lf ", st[i]);
    printf("\n");

    // statikus 2d-s tömb
    int tb[3][4] = {{1, 2, 3, 4},
                    {2, 3, 4, 5},
                    {3, 4, 5, 6}};

    // dinamikus 2D -tömb
    int sor = 3;
    int oszlop = 4;
    int **Matrix = (int **)malloc(sizeof(int *) * sor);
    for (int i = 0; i < sor; i++)
        Matrix[i] = (int *)malloc(sizeof(int) * oszlop);
    // feltöltés
    for (int i = 0; i < sor; i++)
        for (int j = 0; j < oszlop; j++)
            if (i == j)
                Matrix[i][j] = 1;
            else
                Matrix[i][j] = 0;
    // kiírás
    for (int i = 0; i < sor; i++)
    {
        for (int j = 0; j < oszlop; j++)
            printf("%5i", Matrix[i][j]);
        printf("\n");
    }
    // felszabadítás fordított sorrendben
    for (int i = 0; i < sor; i++)
        free(Matrix[i]);
    free(Matrix);

    // typedef használata
    termeszetes ipajegy = 5;

    // statikus struktúra
    struct p2D P;
    // adatok elérése
    P.x = 5;
    P.y = 5;

    // typedef használatával
    pixel_t Origo;
    Origo.x = 5;

    // dinamikus struktúra
    struct p2D *Pont = (struct p2D *)malloc(sizeof(struct p2D));

    (*Pont).x = 3;
    Pont->y = 5;

    free(Pont);

    // 2 pontnak foglalok le helyetű
    struct p2D *Szakasz = (struct p2D *)malloc(2 * sizeof(struct p2D));

    Szakasz[0].x = 1;
    (Szakasz + 0)->y = 2;
    (Szakasz + 1)->x = 3;
    (*(Szakasz + 1)).x = 4;

    // Joe kerte: haromoperandusu oparator

    int nagyobbX = (Szakasz[0].x > Szakasz[1].x) ? 0 : 1;
    // if (nagyobbX) {...} else {...}

    (Szakasz[0].x > Szakasz[1].x) ? printf("0 x-e nagyobb") : printf("1 x-e nagyobb");

    free(Szakasz);

    return 0;
}
