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
  printf("A szaz szam szummaja %d\n", szumma);

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

  // d.
  int *dtomb = (int*)malloc(sizeof(int) * 30);
  int i = 0;
  // Mivel lehet, hogy az elsőre nem sikerül megfelelő számot sorsolni, while ciklust használunk
  while (i < 30)
  {
    int szam = (rand() % 2000) + 1;
    if (szam % 2 == 0 && szam % 7 == 0)
    {
      dtomb[i] = szam; // ha a szám megfelelő, elmentjük, majd léptetünk
      i++;
    }
  }
  printf("4-el vagy 5-tel oszthato szamok:\n");
  for (int i = 0; i < 30; i++)
  {
    if(dtomb[i] % 4 == 0 || dtomb[i] % 5 == 0) printf("%d ",dtomb[i]);
  }
  printf("\nA tomb rendezve:\n");
  
  // Buborékrendezés
  for (int i = 29; i >= 0; i--)
  {
    for (int j = 0; j < i; j++)
    {
      if (dtomb[j] < dtomb[j+1])
      {
        int tmp = dtomb[j];
        dtomb[j] = dtomb[j+1];
        dtomb[j+1] = tmp;
      }
    }
  }
  for (int i = 0; i < 30; i++)
  {
    printf("%d ", dtomb[i]);
  }
  free(dtomb);

   // e)
  
  printf("\nHany fibonacci szamot szeretnel? ");
  scanf_s("%d", &n);
    
  int* fib = (int*)malloc(sizeof(int) * n); // A Fibonacci sorozat elemeit tartalmazó tömb
  // Az első 2 szám 1-es
  fib[0] = 1;
  fib[1] = 1;
  if (n > 2) { // csak akkor megyünk tovább, ha legalább 3 elemünk van
    for (int i = 2; i < n; i++) // a második indextől indulunk
    {
      fib[i] = fib[i-1] + fib[i-2];
    }
  }
  // Elemek kiiratása:
  for (int i = 0; i < n; i++)
  {
    printf("%d ", fib[i]);
  }
  
free(fib);
  

return 0;
}
