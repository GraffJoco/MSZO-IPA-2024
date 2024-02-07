/* IPA 6. HETI GYAKORLAT - STRUKTÚRÁK, FÜGGVÉNYEK */

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
double korTerulete(double R) {
    return M_PI * R * R;
}
// Ugyanaz, mint korTerulete: double -> double, korTerulete(R) = PI * R^2

// Példa: Függvény paraméterekkel, ami nem ad vissza értéket
void kiir(double val) {
    printf("%lf\n", val);
}

// Összetettebb példa: Fibonacci sor, rekurzió
int Fibonacci(unsigned int ertek) {
    if (ertek == 1 || ertek == 0) return ertek;
    return Fibonacci(ertek - 1) + Fibonacci(ertek - 2);
}

// Probléma: lassú a kód ~35 felett
// Megoldás: Optimalizált Fibonacci algoritmus, ami globális változókat használ
int* Fib_ertekek = NULL;
int Fib_max;

int FibonacciGyors(unsigned int ertek) {
    // Létrehozunk egy tömböt, amiben tároljuk az eddigi adatokat
    if (Fib_ertekek == NULL) {
        Fib_ertekek = calloc(ertek, sizeof(unsigned int));
        Fib_ertekek[1] = 1;
        Fib_max = ertek;
    }

    // Ha az első hívott függvényben vagyunk, akkor a tömböt reseteljük is
    if (ertek == Fib_max) {
        int ret = FibonacciGyors(ertek - 1) + FibonacciGyors(ertek - 2);
        free(Fib_ertekek);
        Fib_ertekek = NULL;
        return ret;
    }
    
    // Ha nem, és nincs érték a cellában, akkor rakunk be
    // Azért gyorsabb a sima algoritmusnál, mert ha az if szerint
    // már van érték a tömbben, nem kell újra hívni a függvényt
    // tehát többször is felhasználható egy érték
    if (ertek >= 2 && Fib_ertekek[ertek] == 0)
        Fib_ertekek[ertek] = FibonacciGyors(ertek - 1) + FibonacciGyors(ertek - 2);
    return Fib_ertekek[ertek];
}

/* STRUKTÚRÁK */
// Megj.: kurzustól függően lehet, hogy csak ez a rész lesz a 6. heti gyakorlaban
// Azoknál a csoportoknál a függvények nem lesznek benne az első ZH-ban

// Struktúra - több, különbözű típusú, névvel ellátott érték egymás után egy,
// kombinált változóban
// Programozási tapasztalatokkal rendelkezőknek: primitív objektum, nincsenek tagfv-k

// Példa: 3D vektor

struct vektor {
    double x;
    double y;
    double z;
}; // Pontosvessző a végére!

// Más fajta típusok is lehetnek benne

struct hallgato {
    double KKI;
    int eddigiKreditek;
};

// Struktúrák lehetnek függvényekben is!
// Példa: vektorok skaláris szorzása

double skalarSzoroz(struct vektor egyik, struct vektor masik) {
    return (egyik.x * masik.x) + (egyik.y * masik.y) + (egyik.z * masik.z);
}

int main() {
    // Függvények tesztelése
    kiir(korTerulete(2));
    printf("Sima Fib: ");
    printf("%u\n", Fibonacci(30));
    printf("Gyors Fib: ");
    printf("%u\n", FibonacciGyors(30));

    // Struktúrák
    // Példány létrehozása
    struct vektor vec1 = { 0.2, 0.3, -1.5 };
    struct vektor vec2;
    vec2.x = 5.0; vec2.y = 4; vec2.z = 2.0;

    // Struktúra függvények hívása
    printf("A ket vektor skalarszorzata: %lf\n", skalarSzoroz(vec1, vec2));

    // Struktúra tömbök
    struct vektor matrix[3];
    
    srand(time(NULL));
    for (int i = 0; i < 3; i++) {
        matrix[i].x = (double)rand() / (double)RAND_MAX;
        matrix[i].y = (double)rand() / (double)RAND_MAX;
        matrix[i].z = (double)rand() / (double)RAND_MAX;
        printf("%lf, %lf, %lf\n", matrix[i].x, matrix[i].y, matrix[i].z);
    }
}
