#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>		//atof-hoz

#define STR_HOSSZ 101
#define adat_nev "szamok.txt"
#define kimenet_nev "szamokuj.txt"

//A ',' cseréje '.'-ra (magyar szövegfájl feldolgozásához)
void decsep(char* c);

int main(void)
{

	//Filekezelés
	//SZÖVEGFÁJLOK
	FILE* be, * ki;

	fopen_s(&be, adat_nev, "r");	//megnyitás olvasásra
	if (!be)                        //hiba esetén
	{
		printf("Hiba: a fajl nem talalhato (%s)\n", adat_nev);
		//getchar();
		return -1;                    //vissza a hívóhoz
	}
	    
	fopen_s(&ki, kimenet_nev, "w");		 //létrehoz v. felülír
	if (!ki)
	{
		printf("Hiba: a fajl nem írhato (%s)\n", kimenet_nev);
		//getchar();
		return -1;                    //vissza a hívóhoz
	}
	printf("Fileok kinyitva\n");
	
	char* sor = (char*)malloc(STR_HOSSZ);      //hely a soroknak
	char* s1, * s2, *next;
	
	while (!feof(be))
	{
		memset(sor, 0, STR_HOSSZ);            //előző string törlése
		if (fgets(sor, STR_HOSSZ, be) == NULL)
			continue;						  //sor beolvasása a fájlból Enterig v. STR_HOSSZ db-ig

		//ha sikerült beolvasni valamit -> feldolgozzuk
		if (strlen(sor) > 0 && strchr(sor, '\t') != NULL) //nem üres, van benne elválasztó
		{
			decsep(sor);                    //magyar számok átalakítása

			s1 = strtok_s(sor, "\t", &next);			//szöveg darabolása 
			s2 = strtok_s(NULL, "\t", &next);

			double x = atof(s1);            //darabolt szöveg konvertálása számmá
			double y = atof(s2);

			//sscanf_s(sor, "%lf\t%lf", &x, &y);	// így is lehet

			//kiírtatás képernyőre
			printf("%6.4lf\t%6.4lf\t%6.4lf\n", x, y, x + y);
			
			//kiíratás file-ba
			fprintf(ki, "%6.4lf\t%6.4lf\t%6.4lf\n", x, y, x + y);
			
		} //nem üres, van benne elválasztó
	}

	fclose(be);        //fileok bezárása
	fclose(ki);
	
	free(sor);        //memória felszabadítása

	//Törlés
	char torol;
	do                    //Törlés? csak i,I,n,N fogadható el
	{
		printf("Toroljuk (I/N):");
		torol = toupper(_getch());    //a bekért karakter nagybetűre konvertálása 
		printf("%c\n", torol);
	} while (!((torol == 'I') || (torol == 'N')));

	if (torol == 'I')
	{
		_unlink(adat_nev);                //eredeti törlése, remove könyvtárt is tud törölni
		rename(kimenet_nev, adat_nev);    //új átnevezése az eredeti nevére 
		printf("OK\n");
	}

	return 0;
}

//A ',' cseréje '.'-ra (magyar szövegfájl feldolgozásához)
void decsep(char* c)
{
	int i = 0;
	while (c[i] != '\0')
	{
		if (c[i] == ',') c[i] = '.';
		i++;
	}
}