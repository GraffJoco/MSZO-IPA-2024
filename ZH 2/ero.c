#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define STR_HOSSZ 101
#define adat_nev "ero.txt"

typedef struct {
    int x, y,  z;
}vektor;

int main()
{
    FILE* be;
    fopen_s(&be, adat_nev, "r");
    // ellenőrzés...

    char* sor = (char*)malloc(STR_HOSSZ);
    char* delim = " ";
    char* next, * p;

    vektor eredoM;
    eredoM.x = 0;
    eredoM.y = 0;
    eredoM.z = 0;
    vektor eredoF;
    eredoF.x = 0;
    eredoF.y = 0;
    eredoF.z = 0;

    while (!feof(be)) {

        if (fgets(sor, STR_HOSSZ, be) == NULL) continue;
        if (strlen(sor) > 0) {

            p = strtok_s(sor, delim, &next);
            int rx = atoi(p);
            p = strtok_s(NULL, delim, &next);
            int ry = atoi(p);
            p = strtok_s(NULL, delim, &next);
            int rz = atoi(p);
            p = strtok_s(NULL, delim, &next);
            int Fx = atoi(p);
            p = strtok_s(NULL, delim, &next);
            int Fy = atoi(p);
            p = strtok_s(NULL, delim, &next);
            int Fz = atoi(p);

            // eredő erő számítása
            eredoF.x += Fx;
            eredoF.y += Fy;
            eredoF.z += Fz;

            // nyomaték a keresztszorzás képletéből
            // r x F
            eredoM.x += ry* Fz - rz * Fy;
            eredoM.y += rz*Fx - rx * Fz;
            eredoM.z += rx * Fy - ry * Fx;
            
        }
    }

    printf("Az eredo erovektor: (%d;%d;%d)\n",eredoF.x,eredoF.y,eredoF.z);
    printf("Az eredo nyomatekvektor: (%d;%d;%d)\n",eredoM.x,eredoM.y,eredoM.z);

    if(eredoF.x == 0 && eredoF.y == 0 && eredoF.z == 0 && eredoM.x == 0 && eredoM.y == 0 && eredoM.z == 0) printf("Egyensulyban van!\n");
    else printf("Nincs egyensulyban!\n");
    
    free(sor);
    fclose(be);
    return 0;

}