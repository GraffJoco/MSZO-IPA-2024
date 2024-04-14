/* IPA 8. HETI GYAKORLAT - STRUKTÚRÁK, FÜGGVÉNYEK */

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* FÜGGVÉNYEK */

// Függvény: kód, ami többször hívható akárhonnan, és valamilyen funkcióval rendelkezik
// Függvénynek lehetnek paraméterei, és általában értéket ad vissza
// Ha nem ad vissza értéket, akkor `void` a típusa

// Példa: Függvény paraméterrel, ami értéket ad vissza
double szumma(double a, double b, double c) {
    return a + b + c;
}
//Atlag milyen?


// Példa: Függvény paraméterekkel, ami nem ad vissza értéket (eljaras)
void kiir(double val); //igy mindegy a sorrend, fuggveny prototipus mehetne .h fajba is, igy tobb fajlba is hasznalod

double korTerulete(double R) {
    if (R < 0) return NAN; //Not a Number
    else return M_PI * R * R;
}
// Ugyanaz, mint korTerulete: double -> double, korTerulete(R) = PI * R^2




//3D vektor

struct vektor {
    double x;
    double y;
    double z;
}; // Pontosvessző a végére!

// Struktúrák lehetnek függvényekben is!
struct vektor vektorSzoroz(struct vektor egyik, struct vektor masik) {
    struct vektor v;
    v.x=egyik.y*masik.z-egyik.z*masik.y;
    v.y=egyik.z*masik.x-egyik.x*masik.z;
    v.z=egyik.x*masik.y-egyik.y*masik.x;
    return v;
}

double skalarSzoroz(struct vektor egyik, struct vektor masik) {
    return (egyik.x * masik.x) + (egyik.y * masik.y) + (egyik.z * masik.z);
}

// mutató használata
void csere_p(int* a, int* b)        //a és b egészre mutató pointerek
{
	int tmp = *a; *a = *b; *b = tmp;
}

// Összetettebb példa: Fibonacci sor, rekurzió
int Fibonacci(unsigned int ertek) {
    if (ertek == 1 || ertek == 0) return ertek;
    return Fibonacci(ertek - 1) + Fibonacci(ertek - 2);
}


double singyok(double x1, double x2, double eps) { //eps limit
    // Bináris keresés használata gyökmeghatározásra (Intervallum felezés módszere)
    //Azzal a feltetelel mukodik hogy egy gyok van csak az adott intervallumon

        double xk = (x1 + x2) / 2;
        int lepes = 0;
        const int MAXLEPES = 1e3;

        while (fabs(sin(xk)) > eps && lepes < MAXLEPES) // fabs: abszolút érték doublere, pl 0.1+0.2!=0.3
        {
            if (sin(x1) * sin(xk) > 0)
                x1 = xk; // Átmegy-e a 0-n? -> határok elmozdítása
            else
                x2 = xk;

            xk = (x1 + x2) / 2; // Középső érték újraszámolása
            lepes++;
            printf("Lepes: %i; xk: %.12lf\n", lepes, xk);
        }
        if (lepes == MAXLEPES) {
            printf("Elerte a max lepesszamot, nincs eredmeny.\n"); // Végtelen ciklus megelőzése
            return NAN;
        }
        return xk;
}


int main() {
    // Függvények tesztelése
    double szum =szumma(2,3,4);
    printf("A szumma: %lf\n",szum);
    kiir(szum); //pont annyi parameternek kell lennie

    double beadott;
    scanf_s("%lf", &beadott);
    double megoldas = korTerulete(beadott);
    if (isnan(megoldas)) {
        printf("Nem ertelmes a sugar!\n");
        return -1;
    }
    printf("A terület: %lf\n",megoldas);

    // Struktúrák
    // Példány létrehozása
    struct vektor vec1 = { 0.2, 0.3, -1.5 };
    struct vektor vec2;
    vec2.x = 5.0; vec2.y = 4; vec2.z = 2.0;

    // Struktúra függvények hívása
    printf("A ket vektor skalarszorzata: %lf\n", skalarSzoroz(vec1, vec2));

    int a=0,b=1;
    csere(&a,&b);
    kiir(Fibonacci(5));

    kiir(singyok(1,4,1e-6));

}

//kifejtes
void kiir(double val) {
    printf("%lf\n", val);
}
