/* IPA 10. HETI GYAKORLAT - FÁJLKEZELÉS*/

#include <stdio.h> // Fájlok kezelése
#include <stdlib.h>
#include <string.h>

#define BUFFER_MERET 256

int main() {
    // Fájl megnyitása olvasás módban
    FILE* fajl;
    fopen_s(&fajl, "adatok.txt", "r");
    char* buffer = (char*)malloc(BUFFER_MERET);

    // Sor olvasása (végén van \n karakter)
    fgets(buffer, BUFFER_MERET, fajl);
    printf("%s", buffer);

    // Ha jól van formázva, scanf-hez hasonlóan lehet belőle olvasni
    // FONTOS - fscanf_s és scanf_s is megáll "whitespace" karaktereknél (tab, szóköz, \n)
    int egyikAdat;
    double masikAdat;
    fscanf_s(fajl, "%d;%lf", &egyikAdat, &masikAdat);
    printf("Beolvastam: %d-t es %.2lf-t\n", egyikAdat, masikAdat);

    fclose(fajl); // free()-hez hasonlóan a fájlt be kell zárni!

    // PÉLDA: Pontosvesszős CSV fájl feldolgozása
    // hallgatok.csv-ben nevek és pontszámok vannak
    // Írd ki kollegak.txt fajlba, hogy ki kapott ötöst
    // Üres sorokra figyelj!
    FILE* output;
    fopen_s(&fajl, "hallgatok.csv", "r");
    fopen_s(&output, "kollegak.txt", "w");

    fgets(buffer, BUFFER_MERET, fajl); // Első sort átugorjuk, ott nincs adat
    while (!feof(fajl)) {
        fgets(buffer, BUFFER_MERET, fajl);
        if (strnlen_s(buffer, BUFFER_MERET) < 5) continue;

        char* temp; // Strtoknak kell
        char* nev = strtok_s(buffer, ";", &temp);
        char* pontstr = strtok_s(NULL, "\n", &temp);
        int pontszam = atoi(pontstr);

        if (pontszam >= 85)
            fprintf_s(output, "%s %d ponttal otos lett\n", nev, pontszam);
    }

    fclose(fajl);
    fclose(output);
    free(buffer);
}