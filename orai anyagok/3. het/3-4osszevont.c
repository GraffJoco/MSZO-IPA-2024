/* IPA 3. HETI GYAKORLAT: ELÁGAZÁSOK */

#include <stdio.h>   // printf, scanf
#include <stdbool.h> //bool
// 4.gyak
#include <time.h>   // az srand() seedjéhez
#include <math.h>   // matematikai függvényekhez
#include <stdlib.h> // random, RAND_MAX

int main()
{
    // Fontos kérdéseket teszünk fel a felhasználónak
    int valasz;
    printf("Szereted a tejet (1/0)? ");
    scanf_s("%d", &valasz);

    // A választ értelmezzük
    if (valasz == 1)
    { // két egyenlőségjel!
        printf("Nagyon jo\n");
    }
    else if (valasz != 0)
    {
        printf("Ez nincsen a valaszlehetosegek kozott!\n");
    }
    else
    {
        // Ha nem, akkor "else"-be kerül
        printf("Szomoruva tettel\n");
    }
    // C-ben minden nem 0 érték igaznak számít
    if (valasz)
    {
        printf("Nem nulla volt a valasz!\n");
    }

    // Matematikai feltételek
    // Példa: Abszolút érték
    double szam;
    printf("Kerek egy szamot, visszaadom az abszolut erteket! ");
    scanf_s("%lf", &szam);
    // Kapcsos zárójel nem kell egy utasításnál
    if (szam > 0.0)
        printf("A szam abszolut erteke sajat maga: %lf\n", szam);
    else
        printf("A szam abszolut erteke az ellentettje: %lf\n", -szam);

    // Példa: Szignum függvény
    printf("Kerek egy szamot, aminek az elojelet kiirom! ");
    scanf_s("%lf", &szam);
    if (szam > 0.0)
    {
        printf("A szam elojele 1!\n");
    }
    else if (szam < 0.0)
    {
        printf("A szam elojele -1!\n");
    }
    else
        printf("A szam elojele 0!\n");

    // Switch: több, numerikus feltétel egymás után
    int jegy;
    printf("Ipa jegy: ");
    scanf_s("%d", &jegy);

    switch (jegy)
    {
    case 5:
        printf("Jeles\n");
        break; // break; fontos!
    case 4:
        printf("Jó\n");
        break;
    case 3:
        printf("Közepes\n");
        break;
    case 2:
        printf("Elégséges\n");
        break;
    default: // minden más eset
        printf("Joe üzeni találkozunk jövőre is\n");
        break;
    }

    // Kombinált feltételek
    int x, y;
    printf("Kerek ket egesz koordinatat x,y stilusban!");
    scanf_s("%d,%d", &x, &y);

    if (x == 0 && y == 0)
    {
        printf("Origo\n");
    }
    else if (x == 0 || y == 0)
    {
        printf("Tengelyen levo ertek\n");
    }
    else if (x >= 0 && y >= 0)
    {
        printf("Pozitiv x, Pozitiv y\n");
    }
    else if (x >= 0)
    { // y < 0 nem kell, feltételezni lehet
        printf("Pozitiv x, negatív y\n");
    }
    else if (x < 0 && y >= 0)
    {
        printf("Negativ x, Pozitiv y\n");
    }
    else
    {
        printf("Negatív x, Negatív y\n");
    }

    bool van = true; // 1
    van = false;     // 0

    { // csak azért hogy lehessenek ugyanolyan nevű változók

        // 4.gyak
        //  RANDOM SZÁMOK

        time_t ido;           // long long int
        ido = time(NULL);     // 1970. jan 1-től eltelt sec
        printf("%li\n", ido); // long long int
        srand(ido);           // véletlenszám generálása az idővel

        // véletlenszám generálása az idővel
        srand((unsigned int)time(NULL)); // egy lépésben a signed int 2038-ban overflowol, csak egyszer

        int szam = rand(); // random szám
        printf("%i\n", szam);

        int szam2 = rand();
        printf("%i\n", szam2);

        printf("rand tartomanya 0 - %i\n", RAND_MAX);

        // határok állítása
        szam = rand() % 100; // 0..99
        szam = rand() % 101; // 0..100
        printf("%i\n", szam);

        // eltolás
        szam = (rand() % 101) - 50; // -50..50

        // -20..20 2 lépésenként
        szam = 2 * ((rand() % 21) - 10);
        printf("%i\n", szam);

        double tort = (double)rand() / RAND_MAX; // 0..1 közötti tört
        printf("%f\n", tort);

        tort = 10 * ((double)rand() / RAND_MAX); // 0..10 közötti tört
        printf("%f\n", tort);

        // [0..10] 0.5 lépésközzel
        tort = (double)(rand() % 21) / 2;
        printf("%f\n", tort);

        // Ciklusok

        // Elöltesztelő ciklusok
        // while{}

        printf("\nCiklusok:\n");
        int i = 0;

        while (i < 10)
        {
            // if (i % 2 == 0) continue; // kihagyja, ha páros
            printf("%i\n", i);
            i++;

            // if (i == 5) break; // kiugrás
        }

        // Hátultesztelő ciklus -> do {} while(feltétel); , egyszer biztos lefut
        // Tippelős játék
        printf("\n");
        int random = rand() % 100 + 1;
        int bekert;
        int tippszam = 0;
        int maxtippszam = 10;

        do
        {
            printf("Adjon tippet: ");
            scanf_s("%i", &bekert);
            tippszam++;
            if (bekert < random)
                printf("Tul kicsi a tipp!\n");
            if (bekert > random)
                printf("Tul nagy a tipp!\n");

        } while (tippszam < maxtippszam && bekert != random); // pontosvessző!
        if (bekert == random)
            printf("Eltalalta a szamot! Tippek szama: %i\n", tippszam);
        else if (tippszam == maxtippszam)
            printf("Kifogyott a lepesekbol! RIP\n");

        // for{}

        for (int i = 0; i < 30; i++) //(;;;) is valid, i-- lefele
        {
            if (i % 3 != 0)
                continue;
            printf("%i\n", i);
        }

        // Bináris keresés használata gyökmeghatározásra (Intervallum felezés módszere)

        double x1 = 1;
        double x2 = 4;
        double xk = (x1 + x2) / 2;
        double eps = 1e-6; // limit
        int lepes = 0;
        const int MAXLEPES = 1e3;

        while (fabs(sin(xk)) > eps && lepes < MAXLEPES) // fabs: abszolút érték doublere, pl 0.1+0.2!=0.3
        {
            if (sin(x1) * sin(xk) > 0)
                x1 = xk; // Átmegy-e a 0-n? -> határok elmozdítása
            else
                x2 = xk;

            xk = (x1 + x2) / 2; // Középső érték újraszámolása
            lepes++;
            printf("%i. %.12lf\n", lepes, xk);
        }
        if (lepes == MAXLEPES)
            printf("Elerte a max lepesszamot, nincs eredmeny.\n"); // Végtelen ciklus megelőzése

        printf("\n");

        // Karakterek

        char c; // a,b,c...
        c = 70; // nagy F lesz, mert ez az ASCII codeja
        printf("%i\n", c);
        printf("%c\n", c);

        c = 'A'; // Lekérhető ASCIIben
        printf("A(z) %c karakter ASCII codeja: %i\n", c, c);

        // getch() függvény
        // scanf beveszi az entert következő bemenetként és errort dob, ezért itt nem jó

        do
        {
            printf("Haza szeretnel e mar menni? [i/n] ");
            // scanf_s("%c", c); // nem jó
            c = getch(); // bekér egy karaktert, nem kell entert ütni
            if (c == 'c')
                continue;      // c esetén nincs echo, újrakezdés
            printf("%c\n", c); // echo, latom hogy mit utok be
            if (c == 'I')
                break;
            if (c == 'N')
                break;
            if (c == 'q')
                return -123; // visszateresi kod: -123, főprogramból kilépés
        } while (c != 'i' && c != 'n');

        if (c == 'i' || c == 'I')
            printf("Ilyen koran?\n");

        /* BITMŰVELETEK */
        // Ez csak egy minimális rész, ZH-n nem kérjük
        // Feladat: paritásbit számlálása -> 4 bites számnál páros vagy páratlan számú '1' értékű bit van?
        int ertek;
        printf("Kerek egy 4 bites szamot! ");
        scanf_s("%d", &ertek);

        // Ellenőrizzük, hogy a jó intervallumban van-e, x eleme [0; 16[ ?
        if (x < 0 || x >= 16)
        {
            printf("A szam nem 4 bites!\n");
        }
        else
        {
            int pozitiv_bitek = 0;
            pozitiv_bitek += ertek & 1;
            pozitiv_bitek += (ertek >> 1) & 1;
            pozitiv_bitek += (ertek >> 2) & 1;
            pozitiv_bitek += (ertek >> 3) & 1;

            if (pozitiv_bitek % 2 == 0)
            {
                printf("Paros szamu '1' erteku bit van a szamban!\n");
            }
            else
            {
                printf("Paratlan szamu '1' erteku bit van a szamban!\n");
            }
        }
    }

    return 0;
}