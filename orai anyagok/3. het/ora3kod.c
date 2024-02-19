/* IPA 3. HETI GYAKORLAT: ELÁGAZÁSOK */

#include <stdio.h> // printf, scanf

int main() {
    // Fontos kérdéseket teszünk fel a felhasználónak
    int valasz;
    printf("Szereted a tejet (1/0)? ");
    scanf_s("%d", &valasz);

    // A választ értelmezzük
    if (valasz == 1) { // két egyenlőségjel!
        printf("Nagyon jo\n");
    } else if (valasz != 0) {
        printf("Ez nincsen a valaszlehetosegek kozott!\n");
    } else {
        // Ha nem, akkor "else"-be kerül
        printf("Szomoruva tettel\n");
    }
    // C-ben minden nem 0 érték igaznak számít
    if (valasz) {
        printf("Nem nulla volt a valasz!\n");
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

    // Példa: Oszthatóság
    int egesz;
    printf("Kerek egy szamot, megmondom oszthato-e 7-tel!\n");
    scanf_s("%lf", &egesz);
    if (egesz % 7 == 0) printf("A %d oszthato 7-tel!\n",egesz);
    else printf("A %d nem oszthato 7-tel!", egesz);

    // Pontszámok, nem hatékony és hatékony módszer
    double pontszam = 32;
    
    if (100 > pontszam && pontszam >= 85) printf("Jeles\n");
	if (85 > pontszam && pontszam >= 70) printf("Jo\n");
	if (70 > pontszam && pontszam >= 55) printf("Kozepes\n");
	if (55 > pontszam && pontszam >= 40) printf("Elegseges\n");
	if (40 > pontszam && pontszam >= 0) printf("Elegtelen\n");
    
    if (pontszam < 40) printf("Elegtelen\n");
	else if (pontszam < 55) printf("Elegseges\n");
	else if (pontszam < 70) printf("Kozepes\n");
	else if (pontszam < 85) printf("Jo\n");
	else printf("Jeles\n");

    // Háromoperandusú művelet:
    // Keressük a maximumot!
    int a = 10;
    int b = 5;
    int max;
    
    if (a > b) max = a;
    else max = b;

    // rövidebben:
    max = (a > b) ? a : b; // háromoperandusú művelet!

    // Switch: több, numerikus feltétel egymás után (pl állapotautomaták)
    int kedvenc;
    printf("Mi a kedvenc szamod? ");
    scanf_s("%d", &kedvenc);

    switch (kedvenc) {
        case 69:
            printf("Nice\n");
            break; // break; fontos!
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
    // Példa: Melyik síknegyedbe esnek a pontok?
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

    /*
	Gyakorlo feladat
	- x változó bekérése
	- megfelelő tartomány meghatározása
	- számítás elvégzése
	- eredmény kiíratása
	*/
	double x, eredmeny;
	printf("Feladat:\nx="); scanf_s("%lf", &x);
	if (x  < -1) eredmeny= cos(x);
	else if (x >= 1) eredmeny = sqrt(x);
	else eredmeny = pow(sin(x), 3);
	printf("A feladat megoldasa:\neredmeny=%6.3lf\n", eredmeny);

    /* BITMŰVELETEK */
    // Ez csak egy minimális rész, ZH-n nem kérjük
    
    egesz = 7;

    // << elshiftelés / biteltolás
    // ~ invertálás

    // 2. bit beállítása:
    egesz |= 1 << 1;
    // 4. bit törlése
    egesz &= ~(1 << 3);
    
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