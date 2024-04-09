#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct p2D {
    double x;
    double y;
};

// függvény visszatérési értékkel
double szumma(double a, double b, double c)
{
	if (a < 0) return NAN;  // ha nincs értelmes visszatérési érték, akkor Not a Number-el tér vissza
	return a + b + c;
}

// eljárás (nincs visszatérési értéke)
void haromszoros(double szam)
{
	printf("A szam haromszorosa: %lf", szam * 3);
}

// érték szerinti paraméter átadás
void csere_a(int a, int b)        //a és b lokális egész számok
{
	int tmp = a; a = b; b = tmp;
}

// mutató használata
void csere_p(int* a, int* b)        //a és b egészre mutató pointerek
{
	int tmp = *a; *a = *b; *b = tmp;
}

// double tomb átlagát adja
double tatlag(double* t, int n)
{
	int i;
	double summa = 0;
	for (i = 0; i < n; i++) summa += t[i];
	return summa / n;
}

// double tomb elemeit írja ki
void tkiir(double* t, int n)
{
	int i;
	for (i = 0; i < n; i++) printf("%f\n",t[i]);
}

// 2 pont felezőpontja
struct p2D felez(struct p2D A, struct  p2D B)
{
	struct p2D fele;
	fele.x = (A.x + B.x) / 2;
	fele.y = (A.y + B.y) / 2;
	return fele;
}

// point koordinátáinak kiírása
void kiir(struct p2D P)
{
	printf("[%.2f;%.2f]", P.x, P.y);
}

// point koordinátái 0,0
void torol(struct p2D* P)
{
	P->x = 0;
	(*P).y = 0;
}

// szakaszok hossza
double szakaszhossz(struct p2D* P, int meret)
{
	int i = 0;
	double hossz = 0;
	for (i = 0; i < meret - 1; i++)
		hossz += sqrt(pow(P[i].x - P[i + 1].x, 2) + pow(P[i].y - P[i + 1].y, 2));
	return hossz;
}
