#include <stdio.h>
#include <stdlib.h> //atof
#include <string.h>
#include <math.h> //fabs

#define HOSSZ 101 
#define adat_nev "kecske.txt"

//atvalto fggv
double szogAtvalt(int szog, int szogperc) {
	return szog + (double)szogperc / 60;
}

//adat struktúra
struct kecskeadatok {
	char nev[HOSSZ]; //nev adattagnak
	double szog[4]; //a 4db szognek
};

int main(void)
{
	FILE* be;

	fopen_s(&be, adat_nev, "r"); //megnyitjuk a fajlt "r" readre nyitjuk meg
	if (!be)
	{
		printf("Hiba, nem tudtuk megnyitni a fajl-t/ Nem letezik a \"%s\"\n", adat_nev);
		return -1;
	}
	int n = 0;
	char* sor = (char*)malloc(HOSSZ); //fgets-bol ebbe rakjuk a beolvasott sorokat

	//A Zh-kban ha el kell menteni az adatokat meg lesz adva mennyi a maximum sor szám, akkor a tarolo tomb legyen akkora
	//De meg lehet határozni az adatok szamat elore ha végig megyunk az adatokon elore
	//Ugyanazokat az ellenorzeseket vegulis csak be kell masolni, amiket a fajl olvasasbol amugy is hasznalnank
	while (!feof(be)) {
		memset(sor, 0, HOSSZ);
		if (fgets(sor, HOSSZ, be) == NULL) //ures sorok ne legyenek számolva
			continue;
		if (strlen(sor) > 0 && strchr(sor, '\'') != NULL) //sorban kereses hogy van e a kert delimiter; a ' itt ugyanugy mint a "-t, egy \-jellel megtoldott alakban hasznalhato mert kulonleges karakter
		{
			n++;
		}
	}
	fclose(be);
	
	//ujra nyitása a fájlnak 
	fopen_s(&be, adat_nev, "r");
	if (!be){
		printf("Hiba, nem tudtuk megnyitni a fajl-t/ Nem letezik a \"%s\"\n", adat_nev);
		return -1;
	}
	
	char * next; //strtok-nak segédváltozó
	struct kecskeadatok* kecske = (struct kecskeadatok*)malloc(n * sizeof(struct kecskeadatok));
	int i = 0;

	while (!feof(be))
	{
		memset(sor, 0, HOSSZ); //reseteli a sor-t, nem marad benne memoria szemet az uj sornsl
		if (fgets(sor, HOSSZ, be) == NULL)
			continue; //fontos, lekezeli az ures sorokat
		if (strlen(sor) > 0 && strchr(sor, '\'') != NULL)
		{
			//nev levalasztasa
			strcpy_s(kecske[i].nev, HOSSZ, strtok_s(sor, "\t", &next));
			/*
			Kis magyarázat:
			Az strcpy_s-t kell használnunk itt mert el is szeretnénk menteni az erteket
			A "char* c1 =  strtok_s(sor, "\t", &next);" itt nem mukodne mert ez csak a pointeret masolja at
			a sor-nak, aminek mutatott tartalma megvaltozik amint egy ujabb sort olvasunk be a fajlbol.
			Nem mellesleg a statikus karaktertombon amugy sem lehet pointer muveleteket vegezni
			*/
			//4 szog szetvalasztasa es konvertalas
			for (int j = 0; j < 4; j++)
			{
				int szog, szogperc;
				//az atoi() a string int-té konvertalasa
				szog = atoi(strtok_s(NULL, "'", &next)); //szog erteke '-ig tart, az a delimiter
				szogperc = atoi(strtok_s(NULL, "\t", &next));//szogperc erteke \t-ig tart, az a delimiter
				kecske[i].szog[j] = szogAtvalt(szog, szogperc); 
			}
			i++;
		}
	}
	fclose(be); //mar nem olvasunk, fajl bezarasa

	double szumma = 0;
	int minIndex = 0; 
	double minErtek = 360; //itt egy olyan erteket adtam, ami biztos nagyobb minden erteknel (negyszog ossz szoge)
	
	for (int i = 0; i < n; i++)
	{
		double elteres = 0;
		for (int j = 0; j < 4; j++)
		{
			elteres += fabs(kecske[i].szog[j] - 90); //elteres kell, ezert kell a fabs (abszolut ertek fgv double-re)
		}
		if (elteres<minErtek) //min kereses
		{
			minIndex = i;
			minErtek = elteres;
		}
		szumma += elteres; //atlaghoz
	}
	double atlag = szumma / (n * 4);
	printf("Az elteresek atlaga: %lf\n", atlag);
	printf("A legkisebb ossz elterese %s nevu kecskenek van, erteke: %lf\n", kecske[minIndex].nev, minErtek);

	free(kecske);
	return 0;
}