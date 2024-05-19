#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct betu
{
	char c;
	int ertek;
};

int main(void)
{
	srand((unsigned int)time(NULL));

	printf("Hany zsetonod van?");
	int n;
	scanf_s("%i", &n);

	struct betu* zseton =
		(struct betu*)malloc(sizeof(struct betu)*n);
	for (int i = 0; i < n; i++)
	{
		zseton[i].c = rand() % 26 + 'a'; //random karakter generalas
	}
	for (int i = 0; i < n; i++) //egyezo karakterek egyenlo ertekenek garantalasa
	{
		int volt = 0; //false
		for (int j = 0; j < i; j++)
		{
			if (zseton[j].c == zseton[i].c) { //ha van mar ilyen karakter
				volt = 1;
				zseton[i].ertek = zseton[j].ertek;
				break;
			}
		}
		if (!volt) //ha meg nem volt general erteket
			zseton[i].ertek = rand() % 10 + 1;
	}
	for (int i = 0; i < n; i++) //abc sorba rendezes
	{
		for (int j = 0; j < i; j++)
		{
			if (zseton[i].c < zseton[j].c)
			{
				struct betu tmp = zseton[i]; //az egesz structurat egyszerre atmasoljuk, nem csak adattagot (nem kell '.')
				zseton[i] = zseton[j];
				zseton[j] = tmp;
			}
		}
	}
	printf("\n");
	printf("Betu zsetonok:\n");
	//kiiratas
	for (int i = 0; i < n; i++)
	{
		printf("%c\t", zseton[i].c);
	}
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("%i\t", zseton[i].ertek);
	}
	printf("\n");

	//0. feladat folytatas
	//legtobb pontot ero betu/betuk
	int max = zseton[0].ertek;
	for (int i = 1; i < n; i++) //max ertek meghatarozas
	{
		if (max < zseton[i].ertek)
			max = zseton[i].ertek;
	}
	printf("A maximalis ertek: %i\n", max);
	printf("Max erteku betu/betuk:");
	for (int i = 0; i < n; i++) //megfelelo betuk kiiratasa
	{
		if (zseton[i].ertek == max)
			printf("\t%c", zseton[i].c);
	}
	printf("\n");
	//osszpontszam es atlag
	int szum = 0;
	double atlag;
	for (int i = 0; i < n; i++)
	{
		szum += zseton[i].ertek;
	}
	atlag = (double)szum / n;
	printf("Az osszertek: %i\n", szum);
	printf("Az ertekek atlaga: %lf\n", atlag);


	free(zseton);


	return 0;
}