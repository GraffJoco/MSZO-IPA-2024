#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STR_HOSSZ 101
#define max_szoszam 101 // ha ez nincs megadva, meg kell szamolnunk a szavak szamat!
#define adat_nev "szavak.txt"

typedef struct {

    char szo[STR_HOSSZ];
    int hossz;

} szohossz;


int main() {

    FILE* be;
    fopen_s(&be, adat_nev, "r");

    if (!be) {
        printf("Nem sikerult megnyitni a %s fajlt!\n", adat_nev);
        return -1;
    }

    char* sor = (char*)malloc(STR_HOSSZ);
    char* next, * p;
    char* delim = ".,!? \n\r";

    szohossz szavak[max_szoszam]; // tömb létrehozása 
    for (int i = 0; i < max_szoszam; i++)
    {
        szavak[i].hossz = 0; // kinullázás alapból
    }
    int db = 0; // szavak indexelése

    while (!feof(be))
    {
        if (fgets(sor, STR_HOSSZ, be) == NULL) continue;

        if (strlen(sor) > 0) {

            p = strtok_s(sor, delim, &next);
            strcpy_s(szavak[db].szo, STR_HOSSZ, p);
            szavak[db].hossz = strlen(p); 
            db++;// eltolás

            while ((p = strtok_s(NULL, delim, &next)) != NULL) {
                    strcpy_s(szavak[db].szo, STR_HOSSZ, p);
                    szavak[db].hossz = strlen(p);
                    db++;// eltolás
                
            }
        }
    }
    db--;
    
    // sorba rendezés szószám szerint
    for (int i = db - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (szavak[j].hossz > szavak[j + 1].hossz) {
                szohossz temp = szavak[j];
                szavak[j] = szavak[j + 1];
                szavak[j + 1] = temp;
            }
        }
    }

    int maxhossz = szavak[db - 1].hossz; // sorba van rendezve, ez a legnagyobb;
    for (int i = 1; i < maxhossz + 1; i++)
    {
        int szamlalo = 0;
        for (int j = 0; j < db; j++)
        {
            if (i == szavak[j].hossz) szamlalo++;
        }
        printf("%d hosszu szobol %d db van!\n", i, szamlalo);
        szamlalo = 0; // ujra nullazas
    }

    FILE* ki;
    fopen_s(&ki, "szavakrendezve.txt", "w");
    // ellenőrzés...
    for (int i = 1; i < maxhossz + 1; i++)
    {
        fprintf(ki,"%d hosszu szavak:\n",i);
        for (int j = 0; j < db; j++)
        {
            if (i == szavak[j].hossz) fprintf(ki, "%s\n", szavak[j].szo);
        }
    }

    fclose(ki);
    fclose(be);
    free(sor);
    return 0;
}