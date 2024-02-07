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
    scanf("%d", &kedvenc);

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
    scanf("%d,%d", &x, &y);

    if (x >= 0 && y >= 0) {
        printf("Pozitiv x, Pozitiv y\n");
    } else if (x >= 0) { // y < 0 nem kell, feltételezni lehet
        printf("Pozitiv x, Nempozitiv y\n");
    } else if (x < 0 && y >= 0) {
        printf("Negativ x, Pozitiv y\n");
    } else {
        printf("Nempozitiv x, Nempozitiv y\n");
    }

    /* BITMŰVELETEK */
}