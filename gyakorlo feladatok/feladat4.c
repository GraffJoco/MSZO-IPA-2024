/* 4. FELADATSOR: TÖMBÖK */

#include <stdio.h> // printf, scanf
#include <stdlib.h> // srand, rand, malloc, free
#include <time.h>

int main() {
  // Közös: random számgenerátor indítása
  srand(time(NULL));

  // a.
  int atomb[100]; // Tömb létrehozása
  int szumma = 0;
  double atlag;
  
  // i eleme [0; 99], mert minden tömb 0-(max-1) között indexelt
  for (int i = 0; i < 100; i++) {
    atomb[i] = rand() % 101; // 0 és 100 közötti random egész
    szumma += atomb[i];
  }

  atlag = (double)szumma / 100;
  printf("A szaz szam szummaja %d", szumma);

  // b.
  int n;
  printf("Mekkora legyen a tomb? ");
  scanf_s("%d", &n); // n beolvasása
  
  if (n <= 0) {
    printf("ERROR! Tomb meretenek pozitivnak kellene lennie, %d lett megadva!\n", n);
    exit(-1); // main-ben return -1; is jó
  }

  double* btomb = (double*)malloc(n * sizeof(double));
  double eredmeny = 1; // mivel szorzatról van szó, nem 0, hanem 1 a kezdőérték

  for (int i = 0; i < n; i++) {
    btomb[i] = (double)rand() / RAND_MAX * 4 + 1;
    eredmeny *= btomb[i];
  }

  printf("A szamok szorzata %lf!\n", eredmeny);
  free(btomb); // Felszabadításról meg ne feledkezz!
  
  // c.
  printf("Mekkora legyen a tomb? ");
  scanf_s("%d", &n); // n beolvasása

  if (n <= 0) {
    printf("ERROR! Tomb meretenek pozitivnak kellene lennie, %d lett megadva!\n", n);
    exit(-1); // main-ben return -1; is jó
  }

  int* ctomb = (int*)malloc(n * sizeof(int));

  int egyes = 0, kettes = 0, harmas = 0, negyes = 0, otos = 0;
  for (int i = 0; i < n; i++) {
    ctomb[i] = rand() % 101;
    if (ctomb[i] < 40) {
      printf("%d; 1\n", ctomb[i]);
      egyes++;
    } else if (ctomb[i] < 55) {
      printf("%d; 2\n", ctomb[i]);
      kettes++;
    } else if (ctomb[i] < 70) {
      printf("%d; 3\n", ctomb[i]);
      harmas++;
    } else if (ctomb[i] < 85) {
      printf("%d; 4\n", ctomb[i]);
      negyes++;
    } else {
      printf("%d; 5\n", ctomb[i]);
      otos++;
    }
  }
  printf("======\n");
  printf("Otos: %d\n", otos);
  printf("Negyes: %d\n", negyes);
  printf("Harmas: %d\n", harmas);
  printf("Kettes: %d\n", kettes);
  printf("Egyes: %d\n", egyes);
  free(ctomb);
}
