/*5.het tematika:
- Mutatók
- Statikus tömbök
- Dinamikus tömbök
- malloc
- free
- for ciklus
*/

#include <stdio.h>  // printf, scanf(_s)
#include <math.h>   // matematikai készlet
#include <stdlib.h> // malloc

#define TMERET 10

int main(void)
{
    // Mutató használata
    int i = 100;   // lokális statikus változó stack-en
    int *p = NULL; // pointer
    p = &i;        // változó címét tárolja
    printf("i=%i &i=%p *p=%i p=%i &p=%p\n", i, &i, *p, p, &p);
    // pointer merete 8 byte 64-bites rsz-ben; 4 byte 32-bitesben; ez tipus fuggetlen

    // A valtozo és *pointer ugyanaz
    i++; // ha változik a statikus változó
    printf("i=%i *p=%i\n", i, *p);

    *p = 20; // ha értéket adunk a pointer áltat mutatót változónak
    printf("i=%i *p=%i\n", i, *p);

    // precedencia szabály!!!
    *p++; // elmozdul a pointer, KICIMZES!!, helyesen (*p)++ vagy ++*p
    printf("i=%i *p=%i\n", i, *p);
    // poineterrel vegezheto muveletek: ++/--; +/- int;
    // ugyanarra a tipus pointerre: ptr-ptr; ptr==ptr; ptr=ptr;

    // dinamikus terület foglalás heap-re
    double *pd = (double *)malloc(sizeof(double));
    *pd = 43.25;
    printf("%f\n", *pd);
    free(pd); //"Aki malloc-ol tegyen free-t is"
    // felszabadítás után már nem szabad használni!!
    printf("%f\n", *pd);

    // típus nélküli általános pointer
    void *pv = malloc(sizeof(double));
    printf("%x\n", pv);
    *(double *)pv = 43.25;
    printf("%lf\n", *(double *)pv);
    free(pv);
    pv = NULL;

    // Tömb és for ciklus
    // statikus tomb, a programnak lefutas elott tudnia kell a meretet, fix
    int ti[TMERET];              // a ti valojaban egy int pointer
    for (i = 0; i < TMERET; i++) // for (inicializalaskor;feltetel;itertacio vegen)
        ti[i] = i * i;           // lehetne *(ti+i)
    for (i = 0; i < TMERET;)     // a for (;;) is valid, ures feltetel olyan mintha (true) lenne
        printf("%d ", ti[i++]);
    printf("\n");

    // inicializálás
    int ti2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};     // 10 elemű tömb - statikus, a merete = {} kozotti elemszam
    const int tmeret = sizeof(ti2) / sizeof(ti2[0]); // megadja a tömb méretét  //sizeof(ti2)/sizeof(int)
    for (i = 0; i < tmeret; i++)
        printf("%i ", ti2[i]); // előre

    printf("\n");
    for (i = tmeret - 1; i >= 0; i--)
        printf("%d ", ti2[i]); // vissza felé

    printf("\n");

    p = ti2; // végigjárás pointerrel - pointer a tömb elejére irányítva
    for (i = 0; i < tmeret; i++)
        printf("%i ", *(p++)); // *p++ is elég

    p = &ti2[tmeret - 1]; // visszafelé - pointer a tömb végére irányítva
    for (i = 0; i < tmeret; i++)
        printf("%d ", *(p--));
    printf("\n");
    // mindketto utan p-t ujabb ertekadas elott nem szabad hasznalni mert elkoborolt

    // dinamikus tömbkezelés
    int j;
    int *pi = (int *)malloc(tmeret * sizeof(int)); // 10 elemű tömb - dinamikus -> nem fix a meret

    for (i = 0, j = tmeret - 1; i < tmeret; i++, j--) // vesszovel elvalasztva tobb parancs, deklaralasnal csak ugyaolyan tipusuak
        pi[i] = ti[j];                                // pi[i] = *(ti+i)
    for (i = 0; i < tmeret; i++)
        printf("%i ", *(pi + i));
    printf("\n");
    free(pi); // felszabadítás

    // Tömbökön végzett alapműveletek

    double* t = (double*) malloc(tmeret * sizeof(double)); // 10 elemű dinamikus double tömb

    // 1. inicializálás és adatok kiiratása
    for (int i = 0; i < tmeret; i++)
    {
        t[i] = i * i * i;
        printf("%.1lf ", t[i]);
    }
    printf("\n");

    // 2. Egy elem megkeresése - pl 64
    int index = -1; // ide tároljuk a talált elem indexét
    int van = 0; // ide tároljuk, hogy létezik e az elem
    for (int i = 0; i < tmeret; i++)
    {
        if (t[i] == 64) {
            van = 1;
            index = i;
        };
    }
    if (van == 0) printf("Az elem nem talalhato!\n");
    else printf("A keresett elem indexe: %d\n",index);

    // 3. Összeg és átlag számolása
    double szum = 0;
    for (int i = 0; i < tmeret; i++)
    {
        szum += t[i];
    }
    double atlag = szum / tmeret;
    printf("Az elemek osszege %lf, az atlaguk %lf\n",szum,atlag);

    // 4. Minimum és maximum keresés

    double max = t[0];
    double min = t[0];
    for (int i = 0; i < tmeret; i++)
    {
        if (t[i] > max) max = t[i];
        if (t[i] < min) min = t[i];
    }
    printf("A legnagyobb elem: %lf\n", max);
    printf("A legkisebb elem: %lf\n", min);

    // 5. Elemek módosítása: pl. felezzünk meg minden elemet
    for (int i = 0; i < tmeret; i++)
    {
        t[i] /= 2;
        printf("%.1lf ",t[i]);
    }

    // 6. Elemek megszámolása pl. 10 darab 1 és 10 közötti számból mennyi 4-es?
    int negyes = 0;
    for (int i = 0; i < tmeret; i++)
    {
        if (t[i] == 4) {
            negyes++;
        }
    }
    printf("\nA tombben %d darab 4-es van!\n", negyes);

    // 7. Rendezés
    // Buborék rendezés
	double tmp;
	for (i = tmeret - 1; i > 0; i--){
		for (j = 0; j < i; j++){
			if (t[j] > t[j + 1])
			{
				tmp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = tmp;
			}
		}
	}
	printf("Rendezeve:\n");
	for (i = 0; i<tmeret; i++)
		printf("%.1lf ", t[i]);
	printf("\n");

    // statikus 2d-s tömb
	int tb[3][4] = { { 1, 2, 3, 4 },
	{ 2, 3, 4, 5 },
	{ 3, 4, 5, 6 } };

	// dinamikus 2D -tömb
	int sor = 4;
	int oszlop = 4;
	int** Matrix = (int**)malloc(sizeof(int*) * sor);
	for (int i = 0; i < sor; i++) 
		Matrix[i] = (int*)malloc(sizeof(int) * oszlop);
	// feltöltés
	for (int i = 0; i < sor; i++)
		for (int j = 0; j < oszlop; j++)
			if (i == j) Matrix[i][j] = 1;
			else 		Matrix[i][j] = 0;
	// kiírás
	for (int i = 0; i < sor; i++)
	{
		for (int j = 0; j < oszlop; j++) printf("%5i", Matrix[i][j]);
		printf("\n");
	}
	// felszabadítás fordított sorrendben
	for (int i = 0; i < sor; i++)
		free(Matrix[i]);
	free(Matrix);
    


    free(t);

    return 0;
}
