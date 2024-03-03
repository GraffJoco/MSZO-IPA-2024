#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    // Random számokhoz szükségses seed
    srand((unsigned int)time(NULL));

    // a)
    // Létrehozunk egy változót, hogy eltároljuk az összegüket!
    int szum = 0;
    for (int i = 0; i < 10; i++) // 10 számot generálunk
    {
        int random = (rand() % 26) - 8; // Ha a tartományt feltoljuk 8-al, akkor a 0-25 tartományt kell legenerálnunk. Ez egy egyszerű 26-al való maradékos osztás, amelyet utána eltolhatunk -8-al.
        szum = szum + random;
        // szum += (rand() % 26) - 8; <- Egyszerűbben
    }
    
    // Kiszámoljuk az átlagot!
    double atlag = (double)szum / 10; // Figyelem! Az összeg int, de az átlag már nem feltétlen egész. 
    printf("A szamok osszege: %d\nA szamok atlaga: %lf\n",szum,atlag);

    // b)
    // Egyszerűen használhatunk 2 egymásba ágyazott ciklust, ahol a külső ciklus lesz az első tag, a belső ciklus a második tag a szorzatban.
    printf("Szorzotabla:\n");
    for (int i = 1; i < 11; i++) {
        for (int j = 1; j < 11; j++){ // nem lehet i, mivel az már létezik a külső ciklusban
            printf("%d * %d = %d\n",i,j,i*j);
        }
    }

    // c)
    // Mivel muszáj legalább 1 számot bekérni, használjunk do-while ciklust!
    double bekert;
    double szumma = 0;
    int vege = 0;
    do
    {
        printf("Adj meg egy szamot!: ");
        scanf_s("%lf",&bekert);
        szumma += bekert;
        printf("Akarsz meg megadni szamot? (1/0): ");
        scanf_s("%d", &vege);

    } while (vege != 0);
    printf("A szamaid osszege: %lf\n",szumma);

    // d)

    // A tartományon generálás:
    // A tartomány alsó határát betoljuk 0-ba, ekkor: 0-223
    // Ez a 224-el való maradékos osztásként kapható meg, amit utána eltolunk.
    int veletlen = rand() % 224 + 56;

    // Prímszám e?
    int prime = 1; // Logikai változóként használjuk
    // Jelenleg ez nem lényeges, de általában megnézzük, hogy a szám nem 0 vagy 1-e:
    if (veletlen <= 1) printf("Nem primszam!\n");
    // Ezután végigosztjuk maradékosan az összes olyan számmal, amely a felénél kisebb. Ha bármelyikkel való osztási maradék 0, vagyis osztható, akkor a szám nem prím!
    else {
        for (int i = 2; i <= veletlen / 2; i++) // 2-től indulunk, hiszen 0-val semmi, 1-el minden osztható
        {
            if (veletlen % i == 0) prime = 0; // Ha osztotta, a logikai változót 0-ra (hamisra) állítjuk.
        }
        if (prime) printf("A %d primszam!\n", veletlen); // Ha a prime változó nem 0
        else printf("A %d nem primszam!\n",veletlen); 
    }
    




    return 0;
}