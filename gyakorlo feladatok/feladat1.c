#include <stdio.h>

int main() {
    // a) feladat
    int a, b;
    printf("Adjon meg 2 egesz szamot \"a b\" formatumban!: ");
    scanf_s("%d %d",&a,&b);
    printf("A ket szam osszege: %d\n",a + b);
    printf("A ket szam szorzata: %d\n", a*b);
    printf("A maradekos osztas eredmenye: %d\n", a % b);

    // b) feladat
    double x, y;
    printf("Adja meg egy teglalap 2 oldalat \"x y\" formatumban!: ");
    scanf_s("%lf %lf",&x,&y);
    printf("A teglalap terulete: %lf\n", x*y);
    printf("A teglalap kerulete: %lf\n", 2*x+2*y);

    // c) feladat
    double T;
    printf("Adja meg a homersekletet Celsiusban!: ");
    scanf_s("%lf", &T);
    // Átszámítás Fahrenheitba a képlet alapján!
    double fahrenheit = (T * 9 / 5) + 32;
    printf("A homerseklet Fahrenheitban: %.3lf", fahrenheit);

    return 0;
}