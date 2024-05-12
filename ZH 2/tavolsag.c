#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define STR_HOSSZ 101
#define adat_nev "tavolsag.txt"


int main()
{
    FILE* be;
    fopen_s(&be, adat_nev, "r");
    // ellenőrzés...

    char* sor = (char*)malloc(STR_HOSSZ);
    char* sormasolat = (char*)malloc(STR_HOSSZ);
    char* delim = "/ ";
    char* next, * p;

    while (!feof(be)) {

        if (fgets(sor, STR_HOSSZ, be) == NULL) continue;
        if (strlen(sor) > 0) {

            strcpy_s(sormasolat, STR_HOSSZ, sor);

            // átváltás m/s és s-ban, majd szorzás
            p = strtok_s(sor, delim, &next);
            double seb = atof(p);
            if (strstr(p, "km")) {
                seb *= 1000;
            }
            p = strtok_s(NULL, delim, &next);
            if (strstr(p, "min")) seb /= 60;
            else if (strstr(p, "h")) seb /= 3600;

            p = strtok_s(NULL, delim, &next);
            double ido = atof(p);
            if (strstr(p, "min")) ido *= 60;
            else if (strstr(p, "h")) ido *= 3600;

            double tav = ido * seb;
            printf("%s = %lf m\n",sormasolat, tav);
        }
    }

    free(sormasolat);
    free(sor);
    fclose(be);
    return 0;

}