#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct koordinata
{
	char nev; //ABC
	double x;
	double y;
	double z;
};

int main(void)
{
	srand((unsigned int)time(NULL));
	
	printf("Mennyi pont legyen? ");
	int n;
	scanf_s("%i", &n);
	
	//dinamikus tomb mert nincs n elore megadva
	struct koordinata* pontok = (struct koordinata*)malloc(sizeof(struct koordinata) * n);

	//feltoltes
	for (int i = 0; i < n; i++)
	{
		pontok[i].x = (double)rand() * 200 / RAND_MAX - 100; //[-100;100] generalas
		pontok[i].y = (double)rand() * 200 / RAND_MAX - 100;
		pontok[i].z = (double)rand() * 200 / RAND_MAX - 100;
		pontok[i].nev = i + 'A'; //generalt sorrendben elnevezes, itt most nem vesszuk figyelembe ha 26-nal tobb pont van
	}

	//leghosszabb es legrovidebb szakasz kereses
	double max = 0; //leheto legkisebb kezdoertek hogy biztos lelegyen valtva. Ha pl 1-et adnank meg meg van az nagyon minimalis esely hogy minden generalt hossz 1nel kisebb, ekkor nem kapnank meg az igazi adatot
	double min = 200*200*3; //majd kiderul miert a leheto legnagyobb hossz negyzetevel szamolunk
	//altalaban min maxnal az elso viszgalando ertekeket tesszuk be

	int hosszu1 = 0, hosszu2 = 0, rovid1 = 0, rovid2 = 0; //a rovid, hosszu szakasz vegpontjainak indexeit taroljuk ezekben

	for (int i = 0; i < n; i++) //1. pont iteracio
	{
		for (int j = 0; j < i; j++) //nem kell n-ig vizsgalni a 2.pontot akkor minden szakaszt 2-szer mernenk +kulon kikene ternunk arra ha i==j hiszen ekkor egy hamis 0 tavolsagu min hosszt kapnank
		{
			//mivel a gyokvonas egy idoigenyes feladat a gepnek, bevett szokas ahol lehet kerulni
			//hossz osszehasonlitasnal ugyanazt kapjuk ha a negyeztuket hasonlitjuk ossze, ezzel futasi idot takaritva meg
			double hossznegyzet = pow(pontok[i].x - pontok[j].x, 2) + pow(pontok[i].y - pontok[j].y, 2) + pow(pontok[i].z - pontok[j].z, 2);
			if (max < hossznegyzet)
			{
				max = hossznegyzet;
				hosszu1 = i;
				hosszu2 = j;
			}
			if (min > hossznegyzet)
			{
				min = hossznegyzet;
				rovid1 = i;
				rovid2 = j;
			}
		}
	}
	//kiiratas
	for (int i = 0; i < n; i++)
	{
		printf("%c: (%.2lf;%.2lf;%.2lf)\n", pontok[i].nev, pontok[i].x, pontok[i].y, pontok[i].z);
	}
	//itt vonunk gyokot, n*n/2 gyokvnas helyett igy csak 2-t vegeztunk el
	printf("\n");
	printf("A leghosszabb szakasz: %c%c; Hossza: %.2lf\n", pontok[hosszu1].nev, pontok[hosszu2].nev, sqrt(max));
	printf("A legrovidebb szakasz: %c%c; Hossza: %.2lf\n", pontok[rovid1].nev, pontok[rovid2].nev, sqrt(min));

	free(pontok); //nem elfelejteni

	return 0;
}