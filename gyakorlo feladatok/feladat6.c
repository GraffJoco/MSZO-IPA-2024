#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define STR_HOSSZ 1001

int main()
{
    char vers[] = "Tudom en mar, mit csinalok:\n\
szoftverfejlesztonek allok.\n\
Lesz majd harom monitorom,\n\
a szekemet odatolom,\n\
bucsut intek minden nyugnek,\n\
Nyomkodom a billentyuket.\n\
Mozi, szinhaz? Masnak hagyom,\n\
nekem mindig van programom.\n\
Kodot irok, mint a kemek,\n\
szamitogepul beszelek.\n\
Kitalalsz egy jo kis tervet,\n\
elmondom a kompjuternek.\n\
Igy fejlesztek szoftvert, sokat,\n\
telefonra jatekokat,\n\
GPS-t a kocsitokba\n\
(belefer egy kicsi tokba),\n\
szimulalhatsz helikoptert,\n\
hogyha irok neki szoftvert,\n\
hatart csak a kepzelet szab!\n\
Es egesz nap gepezek csak.\n";

    // a) sorok számának meghatározása

    // 2 féle módon is lehet:

    int sorok = 0; // összegzés
    char* tmp = vers; // versre mutató pointer
    while(tmp) { // amíg nem ad NULL pointert

        tmp = strchr(tmp, '\n'); // \n keresése amíg nem NULL pointer
        if (tmp) {
            sorok++; 
            tmp++; // eltolás, hogy ne önmagát találja meg
        }
    }

    printf("Az elso modszerrel %d darab sor van.\n", sorok);

    sorok = 0;
    for (int i = 0; vers[i] != '\0'; i++)
    {
        if (vers[i] == '\n') sorok++;
    }
    printf("A masodik modszerrel %d darab sor van.\n", sorok);

    // b) mondatok számának meghatározása


    int mondatok = 0;
    for (int i = 0; vers[i] != '\0'; i++) {
        if (vers[i] == '.' || vers[i] == '?' || vers[i] == '!') {
            mondatok++;
        }
    }
    printf("%d darab mondat van.\n", mondatok);

    // c) magánhangzók száma

    // ötlet: keressünk egy konstans mássalhangzó stringben

    tmp = vers;
    int maganhangzok = 0;
    while (*tmp) { // amíg nem 0 az érték

    if (strchr("aeiouAEIOU", *tmp) != NULL) maganhangzok++;
    tmp++;

    }
    printf("%d darab maganhangzo van.\n", maganhangzok);

    // d) határozott és határozatlan névelők száma

    int hatarozott = 0;
    int hatarozatlan = 0;

    char* next, *darab; // feldaraboljuk a szöveget
    char* delim = " .,!?\n:";
    char* masolat = (char*)malloc(STR_HOSSZ); // ezzel dolgozunk
    strcpy_s(masolat, STR_HOSSZ,vers);

    darab = strtok_s(masolat,delim,&next); // elso darab
    while (darab) { // amig letezik
        if (strcmp(darab, "az") == 0 || strcmp(darab, "a") == 0) hatarozott++; 
        if (strcmp(darab, "egy") == 0) hatarozatlan++;
        darab = strtok_s(NULL, delim, &next);
    }
    printf("A versben %d db hatarozott es %d darab hatarozatlan nevelo van!\n", hatarozott, hatarozatlan);

    // e) adott karakterrel kezdődő szavak meghatározása
    printf("Adjon meg egy karaktert! ");
    char adott;
    // scanf_s("%c", &adott); nem lenne jó, mert a bufferben maradna a \n
    adott = _getch();

    printf("Ezzel a karakterrel kezdodo szavak:\n");

    strcpy_s(masolat, STR_HOSSZ, vers); // ezzel dolgozunk

    darab = strtok_s(masolat, delim, &next);
    while (darab) {
        if (darab[0] == adott) printf("%s\n", strupr(darab)); // strupr - stringekre, toupper - karakterekre
        darab = strtok_s(NULL, delim, &next);
    }
    
    printf("\n");

    
    // f)

    printf("Adjon meg egy mondatreszt!\n");
    char* mondatresz = (char*)malloc(STR_HOSSZ);
    gets_s(mondatresz, STR_HOSSZ);
    if (strstr(vers, mondatresz) != NULL) printf("Benne van!\n");
    else printf("Nincs benne!\n");

    free(mondatresz);

    // g)
    
    int szamlalo = 0;
    strcpy_s(masolat, STR_HOSSZ, vers); // ezzel dolgozunk

    darab = strtok_s(masolat, delim, &next);
    while (darab) {
        
        
        if (strlen(darab) % 2 == 0) szamlalo++; // ha páros, növeljük a számlálót
        darab = strtok_s(NULL, delim, &next);
    }
    printf("%d darab paros szamu karakterbol allo szo van benne\n", szamlalo);

    // h) összefűzés
    char* osszes = (char*)malloc(STR_HOSSZ);
    memset(osszes, 0, STR_HOSSZ); // lenullázás

    strcpy_s(masolat, STR_HOSSZ, vers); // ezzel dolgozunk

    darab = strtok_s(masolat, delim, &next);
    while (darab) {
        
        strcat_s(osszes, STR_HOSSZ, darab);
        darab = strtok_s(NULL, delim, &next);
    }    

    printf("%s\n", osszes);

    free(osszes);
    free(masolat);

    return 0;

}