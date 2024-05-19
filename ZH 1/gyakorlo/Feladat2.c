#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	//n bekeres
	int n;
	printf("Hany primszam? ");
	scanf_s("%i", &n);
	//dinamikus tomb mert nincs elore megadva az n
	int* primek = (int*)malloc(sizeof(int) * n);
	int szamlalo = 1; //ebben leptetjuk felfele a vizsgalando szamot. Valojaban 2-vel kezdunk mert mielott vizsgaljuk adunk hozza ++-t 

	for (int i = 0; i < n; i++) //n* ismeteljuk, ennyi primszam kell
	{
		int prim_e = 0; //igaz-hamis-nak hasznaljuk
		while (!prim_e) //addig megy amig nem talaltunk egy primet
		{
			szamlalo++; //a vizsgalando szam novelese 1-gyel minden iteracio elejen
			prim_e = 1; //feltesszuk hogy prim, ha a kovetkezo vizsgalo ciklus utan is 1 marad akkor prim a szam
			for (int j = 0; j < i; j++) //vegig megyunk minden eddigi primszamon, amibol ugye i db van
			{
				if (szamlalo % primek[j] == 0) { //megviszgaljuk oszthato e a j-edik primmel
					prim_e = 0; //ha igen akkor ez a szam nem prim
					break; //ez nem szukseges, csupan gyorsabb lesz tole a program, mert nem vizsgal tovabb ha mar kiderult hogy nem prim
				}
			}
		}//a ciklusbol akkor lepunk ki ha a szamlalo-ban prim van
		primek[i] = szamlalo; //es az lesz az i-edik primunk
	}

	//kiiratas
	printf("Elso %i prim:\n", n);
	for (int i = 0; i < n; i++)
	{
		printf("%i\n", primek[i]);
	}
	free(primek); //ezt nem elfelejteni
}