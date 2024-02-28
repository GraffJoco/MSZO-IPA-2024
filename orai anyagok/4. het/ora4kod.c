#include <stdio.h>
#include <time.h>       // az srand() seedjéhez
#include <math.h>       // matematikai függvényekhez
#include <stdlib.h>		// random, RAND_MAX

int main(void)
{

    // RANDOM SZÁMOK
	time_t ido;
	ido = time(NULL); // 1970. jan 1-től eltelt sec
	printf("%li\n", ido);
	srand(ido);  // véletlenszám generálása az idővel
	
	// véletlenszám generálása az idővel
	srand((unsigned int)time(NULL));  // egy lépésben

	int szam = rand(); // random szám
    printf("%i\n", szam);

	int szam2 = rand();
	printf("%i\n", szam2);

	printf("rand tartomanya 0 - %i\n", RAND_MAX);

    // határok állítása
	szam = rand() % 100;  // 0..99
	szam = rand() % 101;  // 0..100
	printf("%i\n", szam);

    // eltolás
	szam = (rand() % 101) - 50;    // -50..50

	// -20..20 2 lépésenként
	szam = 2 * ((rand()%21) - 10);
	printf("%i\n", szam);

	double tort = (double)rand() / RAND_MAX ; // 0..1 közötti tört
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
		//if (i % 2 == 0) continue; // kihagyja, ha páros
		printf("%i\n", i);
		i++;

		//if (i == 5) break; // kiugrás
	}

    // for{}

    for (int i = 0; i < 30; i++)
    {
        if (i % 3 != 0) continue;
        printf("%i\n", i);
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
		if (bekert < random) printf("Tul kicsi a tipp!\n");
		if (bekert > random) printf("Tul nagy a tipp!\n");


	} while (tippszam < maxtippszam && bekert != random); // pontosvessző!
	if (bekert == random) printf("Eltalalta a szamot! Tippek szama: %i\n", tippszam);
	if (tippszam == maxtippszam) printf("Kifogyott a lepesekbol! RIP\n");
	
	
	// Bináris keresés használata gyökmeghatározásra

	double x1 = 1;
	double x2 = 4;
	double xk = (x1 + x2) / 2;
	double eps = 1e-6; // limit
	int lepes = 0;
	const int MAXLEPES = 1e3;

	while (fabs(sin(xk)) > eps && lepes < MAXLEPES) // fabs: abszolút érték doublere
	{
		if (sin(x1) * sin(xk) > 0) x1 = xk; // Átmegy-e a 0-n? -> határok elmozdítása
		else x2 = xk;
		
		xk = (x1 + x2) / 2; // Középső érték újraszámolása
		lepes++;
		printf("%i. %.12lf\n", lepes, xk);
	}
	if (lepes == MAXLEPES) printf("Elerte a max lepesszamot, nincs eredmeny.\n"); // Végtelen ciklus megelőzése
	
	printf("\n");
	
    // Karakterek

	char c; // a,b,c...
	c = 70; // nagy F lesz, mert ez az ASCII codeja
	printf("%i\n", c);
	printf("%c\n",c);

	c = 'A';  // Lekérhető ASCIIben
	printf("A(z) %c karakter ASCII codeja: %i\n", c,c);


    // getch() függvény
    // scanf beveszi az entert következő bemenetként és errort dob, ezért itt nem jó

	do
	{
		printf("Haza szeretnel e mar menni? [i/n] ");
		//scanf_s("%c", c); // nem jó
		c = getch(); // bekér egy karaktert, nem kell entert ütni
		if (c == 'c') continue; // c esetén nincs echo
		printf("%c\n", c); //echo, latom hogy mit utok be
		if (c == 'I') break;
		if (c == 'N') break;
		if (c == 'q') return -123; // visszateresi kod: -123
	} while (c != 'i' && c != 'n');

	printf("Ilyen koran?\n");


	return 0;
}
