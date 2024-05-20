#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//a megadott meret
#define TMeret 24

struct hallgato {
	int ev;
	int balkez;
	int c;
};

int main(void)
{
	srand((unsigned int)time(NULL));

	//a meretet tudjuk, statikus tomb eleg
	struct hallgato l07[TMeret];

	//tomb feltoltese
	for (int i = 0; i < TMeret; i++)
	{
		//ev
		l07[i].ev = rand() % 4 + 18; //18-21 ev az 4 lehetoseget jelent -> %4
		//balkez
		if ((double)rand() / RAND_MAX < 0.09) //ha nincs (double) mindig 0 lesz a bal oldal vagyis mindig igaz lenne feltetel
			l07[i].balkez = 1;
		else
			l07[i].balkez = 0;
		//c
		if (rand()<RAND_MAX*0.9) //RAND_MAX-szal atszorozva nem kell a (double) es lefutasi ideje is gyorsabb (nincs osztas es a szorzas is csak konstansok kozott van)
			l07[i].c = 1;
		else
			l07[i].c = 0;
	}

	//bal kezesek szama
	int osszbalkez = 0;
	for (int i = 0; i < TMeret; i++)
	{
		if (l07[i].balkez) //minden nem 0 ertek igaz, ezert eleg ennyit irni
			osszbalkez++;
	}
	int osszjobbkez = TMeret - osszbalkez; //a ketkezeseket most kihagyjuk a szamitasbol, sry
	printf("A jobb:bal kezesek aranya: %i:%i\n", osszjobbkez, osszbalkez);
	//c szeretok szama
	int osszCszereto = 0;
	for (int i = 0; i < TMeret; i++)
	{
		if (l07[i].c) //minden nem 0 ertek igaz, ezert eleg ennyit irni
			osszCszereto++;
	}
	printf("C-t nagyon szeretok szama: %i\n", osszCszereto);

	//kirando hallgato index bekerese
	int index;
	printf("Hanyadik hallgato legyen kiirva?");
	scanf_s("%i", &index);
	//kiiratas
	printf("A(z) %i. hallgato adatai:\n",index);
	printf("%i eves\n", l07[index].ev);
	if (l07[index].balkez)
		printf("Balkezes\n");
	else
		printf("Jobbkezes\n");
	//ugyanaz a szerkezet switch-csel
	switch (l07[index].c)
	{
	case 1:
		printf("Nagyon szereti a C-t");
		break;
	default:
		printf("Moderáltan nagyon szereti a C-t");
		break;
	}

	return 0;
}