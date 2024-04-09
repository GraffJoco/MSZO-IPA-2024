

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


/* STRUKTÚRÁK */

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

// typedef: elé syntax, végére név


// Struktúrák lehetnek függvényekben is!
// Példa: vektorok skaláris szorzása

double skalarSzoroz(struct vektor egyik, struct vektor masik) {
    return (egyik.x * masik.x) + (egyik.y * masik.y) + (egyik.z * masik.z);
}


int main() {
    // Függvények tesztelése
    kiir(korTerulete(2));

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
