#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define STR_HOSSZ 101
#define adat_nev "gyumolcs.txt"


int main()
{
    FILE* be;
    fopen_s(&be, adat_nev, "r");
    // ellenőrzés...

    char* sor = (char*)malloc(STR_HOSSZ);
    char* ujsor = (char*)malloc(STR_HOSSZ+3); // neveloknek

    while(!feof(be)) {

        if (fgets(sor, STR_HOSSZ, be) == NULL) continue;

        if (strlen(sor) > 0) {
        
        if (strchr("aeoui", tolower(sor[0])) != NULL) // első karakter
        {
            strcpy_s(ujsor, STR_HOSSZ, "az ");
            strcat_s(ujsor, STR_HOSSZ, sor);
        }
        else {
            strcpy_s(ujsor, STR_HOSSZ, "a ");
            strcat_s(ujsor, STR_HOSSZ, sor);
        }
        printf("%s", ujsor);
        }
    }

    free(sor);
    free(ujsor);
    fclose(be);
    return 0;

}