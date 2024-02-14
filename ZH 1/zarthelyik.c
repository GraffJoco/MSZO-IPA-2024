#include <stdlib.h> // srand(), rand(), malloc(), free()
#include <stdio.h> // printf(), scanf_s()
#include <time.h> // time()

int main() {
    int hallgatoSzam = 0;
    int* hallgatok;
    int pontSzumma = 0;
    int jegySzumma = 0;
    int bukasok = 0;

    // random szám generátor beüzemelése
    srand(time(NULL));

    // hallgatók számának bekérése
    do {
        printf("Hany hallgato van a kurzuson? ");
        scanf_s("%d", &hallgatoSzam);
    } while (hallgatoSzam < 1);

    hallgatok = (int*)malloc(sizeof(int) * hallgatoSzam);
    for (int i = 0; i < hallgatoSzam; i++) {
        hallgatok[i] = rand() % 101; // Így [0;100] a pontszám
        
        int mostaniJegy;
        if (hallgatok[i] < 40) mostaniJegy = 1;
        else if (hallgatok[i] < 55) mostaniJegy = 2;
        else if (hallgatok[i] < 70) mostaniJegy = 3;
        else if (hallgatok[i] < 85) mostaniJegy = 4;
        else mostaniJegy = 5;

        printf("%d. hallgato: %d pont; jegy: %d\n", i + 1, hallgatok[i], mostaniJegy);
        
        pontSzumma += hallgatok[i];
        jegySzumma += mostaniJegy;
        if (mostaniJegy == 1) bukasok++;
    }

    printf("==========\n"); // Nem kötelező, de szebben néz ki ezzel
    printf("Statisztika:\n");
    printf("Atlag jegy: %lf\n", (double)jegySzumma / hallgatoSzam);
    printf("Atlag pontszam: %lf\n", (double)pontSzumma / hallgatoSzam);
    printf("Bukasok: %d\n", bukasok);
}