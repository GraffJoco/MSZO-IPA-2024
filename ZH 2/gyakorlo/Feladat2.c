#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define HOSSZ 101
#define adat_nev "adat.txt"
#define kimenet_nev "jegy.txt"

double suly2KKI(double suly, int telj);



int main(void)
{
	//fajl megnyitas




	FILE* be, * ki;

	fopen_s(&be, adat_nev, "r");
	if (!be)
	{
		printf("Hiba, nem tudtuk megnyitni a fajl-t/ Nem letezik a \"%s\"\n", adat_nev);
		return -1;
	}

	fopen_s(&ki, kimenet_nev, "w");
	if (!ki)
	{
		printf("Hiba: nem irhatunk a \"%s\" fajlba", kimenet_nev);
		return -1;
	}
	printf("A fajlokat megnyitottuk\n");




	//nev lekerdezes, szukseges valtozok

	char* diak = (char*)malloc(HOSSZ);
	printf("A kert diak neve:");
	gets_s(diak, HOSSZ);

	char* sor = (char*)malloc(HOSSZ);
	char* nev, * targynev, * next;
	double sulyAtlag = 0;
	int osszKredit = 0, teljKredit=0;

	//fajl feldolgozas
	while (!feof(be))
	{
		memset(sor, 0, HOSSZ);
		if (fgets(sor, HOSSZ, be) == NULL)
			continue;
		if (strlen(sor) > 0 && strchr(sor, '\t') != NULL)
		{
		
			//sor felbontas
			int kredit, jegy;
			nev = strtok_s(sor, "\t", &next);


			targynev = strtok_s(NULL, "\t", &next);
			kredit = atoi(strtok_s(NULL, "K", &next));
			jegy = atoi(strtok_s(NULL, "\n", &next));



			//nevre (+ jegyre) ellenorzes


			//stringek pointerek, nem lehet==vel osszehasonlitani
			if (strcmp(diak, nev) != 0) {
				continue;
			}

			if (jegy < 1 || jegy>5) 
			{
				printf("Ervenytelen jegy!");
				return -1;
			}




			//fajlba iras + atlagokhoz szukseges adatok


			fprintf(ki, "%s\t%i\t%i\n",targynev,kredit,jegy);

			sulyAtlag += jegy * kredit;
			osszKredit += kredit;
			if (jegy!=1)
			{
				teljKredit += kredit;
			}
		}
	}
	fclose(be);
	fclose(ki);



	//Atlagok szamitas es kiirasa

	sulyAtlag /= osszKredit;
	printf("%s sulyozott atlaga: %.2lf\n", diak, sulyAtlag);
	printf("%s KKI-ja: %.2lf\n", diak, suly2KKI(sulyAtlag, teljKredit));

	free(diak);
	free(sor);
	return 0;
}

//fgv
double suly2KKI(double suly, int telj)
{
	return suly*telj/30;
} 
