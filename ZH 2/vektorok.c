#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STR_HOSSZ 101
#define adat_nev "vektor.csv"

typedef struct {
    int x,y,z;

} vektor;

int main() {

    // a) megnyitás
    FILE *be;
    fopen_s(&be, adat_nev, "r");
    if(!be)
    {
        printf("Nem sikerult megnyitni a %s fajlt!\n", adat_nev);
        return -1;
    }
    printf("Fajl kinyitva!\n");

    // b)

    char* sor = (char*)malloc(STR_HOSSZ);
    char* next, *p;
    char* delim = ";";

    vektor jelen;
    vektor eredo;
    eredo.x = 0; eredo.y = 0; eredo.z = 0;
    vektor max;
    int i = 1;

    double maxhossz = 0;
    double minhossz = 1000; // ha lesz ilyen feladat, megadom a mint

    int szamlalo = 0;

    fgets(sor, STR_HOSSZ, be);

    while(!feof(be))
    {
        memset(sor, 0, STR_HOSSZ);
        if (fgets(sor, STR_HOSSZ, be) == NULL) continue;        
        if (strlen(sor) > 0 && strchr(sor, ';') != NULL) {

        p = strtok_s(sor, delim, &next);
        jelen.x = atoi(p);
        p = strtok_s(NULL, delim, &next);
        jelen.y = atoi(p);
        p = strtok_s(NULL, delim, &next);
        jelen.z = atoi(p);

        // b)
        double hossz = sqrt(jelen.x * jelen.x + jelen.y * jelen.y + jelen.z * jelen.z);
        printf("A %d. vektor hossza: %lf\n", i++, hossz);

        // c)
        if (hossz > maxhossz) { 
            maxhossz = hossz;
            max.x = jelen.x;
            max.y = jelen.y;
            max.z = jelen.z;
        }
        if (hossz < minhossz) minhossz = hossz;

        // d)

        if (hossz < 10) szamlalo++;

        // e)
        if (jelen.x * 0 + jelen.y * -3 + jelen.z * 8 == 0) printf("A (%d;%d;%d) meroleges a (0;-3;8)-ra\n", jelen.x, jelen.y, jelen.y);

        // f)
        eredo.x += jelen.x;
        eredo.y += jelen.y;
        eredo.z += jelen.z;

        }
    }

    printf("A leghosszabb vektor hossza: %lf\n", maxhossz);
    printf("A legrovidebb vektor hossza: %lf\n", minhossz);

    printf("%d db 10-nel rovidebb vektor volt\n", szamlalo);

    printf("Az eredo vektor: (%d;%d;%d)\n",eredo.x,eredo.y, eredo.z);
    if (sqrt(pow(eredo.x, 2)+ pow(eredo.y, 2) + pow(eredo.z, 2)) > maxhossz) printf("Az eredo hosszabb, mint a leghosszabb vektor!\n");
    else printf("Az eredo rovidebb, mint a leghosszabb vektor!\n");

    printf("A legnagyobb hosszusagu vektor: (%d;%d;%d)\n", max.x, max.y, max.z);

    free(sor);
    fclose(be);


    return 0;
}