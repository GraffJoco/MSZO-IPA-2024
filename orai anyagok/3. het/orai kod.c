/* IPA 3. HETI GYAKORLAT: ELÁGAZÁSOK */

#include <stdio.h> // printf, scanf

int main() {
    // Fontos kérdéseket teszünk fel a felhasználónak
    int valasz;
    printf("Szereted a tejet (1/0)? ");
    scanf_s("%d", &valasz);

    // A választ értelmezzük
    // C-ben ha az érték nem 0, akkor igaznak számít
    if (valasz) {
        printf("Nagyon jo\n");
    } else {
        // Ha nem, akkor "else"-be kerül
        printf("Szomoruva tettel\n");
    }

    // Matematikai feltételek
    // Példa: Abszolút érték
    double szam;
    printf("Kerek egy szamot, visszaadom az abszolut erteket! ");
    scanf_s("%lf", &szam);
    // Kapcsos zárójel nem kell egy utasításnál
    if (szam > 0.0) printf("A szam abszolut erteke sajat maga: %lf\n", szam);
    else printf("A szam abszolut erteke az ellentettje: %lf\n", -szam);

    // Példa: Szignum függvény
    printf("Kerek egy szamot, aminek az elojelet kiirom! ");
    scanf_s("%lf", &szam);
    if (szam > 0.0) {
        printf("A szam elojele 1!\n");
    } else if (szam < 0.0) {
        printf("A szam elojele -1!\n");
    } else printf("A szam elojele 0!\n");

    // Switch: több, numerikus feltétel egymás után
    int kedvenc;
    printf("Mi a kedvenc szamod? ");
    scanf_s("%d", &kedvenc);

    switch (kedvenc) {
        case 69:
            printf("Nice\n");
            break;
        case 420:
            printf("Funny number hahaha\n");
            break;
        case 25:
            printf("5 * 5\n");
            break;
        default:
            printf("Kifogytam az otlekekbol\n");
            break;
    }

    // Kombinált feltételek
    int x, y;
    printf("Kerek ket egesz koordinatat x,y stilusban!" );
    scanf_s("%d,%d", &x, &y);

    if (x == 0 || y == 0) {
        printf("Tengelyen levo ertek\n");
    } else if (x >= 0 && y >= 0) {
        printf("Pozitiv x, Pozitiv y\n");
    } else if (x >= 0) { // y < 0 nem kell, feltételezni lehet
        printf("Pozitiv x, Nempozitiv y\n");
    } else if (x < 0 && y >= 0) {
        printf("Negativ x, Pozitiv y\n");
    } else {
        printf("Nempozitiv x, Nempozitiv y\n");
    }

    /* BITMŰVELETEK */
    // Ez csak egy minimális rész, ZH-n nem kérjük
    // Feladat: paritásbit számlálása -> 4 bites számnál páros vagy páratlan számú '1' értékű bit van?
    int ertek;
    printf("Kerek egy 4 bites szamot! ");
    scanf_s("%d", &ertek);
    
    // Ellenőrizzük, hogy a jó intervallumban van-e, x eleme [0; 16[ ?
    if (x < 0 || x >= 16) {
        printf("A szam nem 4 bites!\n");
    } else {
        int pozitiv_bitek = 0;
        pozitiv_bitek += ertek & 1;
        pozitiv_bitek += (ertek >> 1) & 1;
        pozitiv_bitek += (ertek >> 2) & 1;
        pozitiv_bitek += (ertek >> 3) & 1;

        if (pozitiv_bitek % 2 == 0) {
            printf("Paros szamu '1' erteku bit van a szamban!\n");
        } else {
            printf("Paratlan szamu '1' erteku bit van a szamban!\n");
        }
    }
}