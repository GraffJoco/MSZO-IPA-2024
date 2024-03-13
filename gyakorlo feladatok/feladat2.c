#include <stdio.h>
#include <math.h> // matematikai függvények

int main(){

    // a)
    int a;
    printf("Adjon meg egy egesz szamot!: ");
    scanf_s("%d",&a);

    // Megvizsgáljuk, hogy pozitív e. Ha igen, megnézzük, hogy páros e vagy páratlan. Különben negatív.
    if(a > 0) {
        if (a % 2 == 0) printf("A szam pozitiv es paros!\n");
        else printf("A szam pozitiv es paratlan!\n");
    }
    else printf("A szam negativ!\n");

    // b)
    double elso,masodik,harmadik;
    printf("Adjon meg 3 szamot \"a b c\" formatumban!: ");
    scanf_s("%lf %lf %lf", &elso, &masodik, &harmadik);

    // Feltételezzük, hogy az első szám a legnagyobb!
    double max = elso;

    // Megnézzük, hogy a másik 2 nagyobb e nála! Ha igen, az lesz a legnagyobb!
    if (masodik > max) max = masodik;
    if (harmadik > max) max = harmadik;

    printf("A legnagyobb szam: %lf\n", max);

    // c)
    double a1,b,c; // az a változó már létezik
    printf("Adja meg egy masodfoku egyenlet 3 egyutthatojat \"a b c\" formatumban!: ");
    scanf_s("%lf %lf %lf",&a1, &b,&c);

    // Számoljuk ki a diszkriminánst!
    double diszkriminans = b * b - 4 * a1 * c;
    if (diszkriminans > 0){
        double megoldas1 = (-b + sqrt(diszkriminans)) / (2*a);
        double megoldas2 = (-b - sqrt(diszkriminans)) / (2*a);
        printf("A 2 megoldas: %lf es %lf", megoldas1, megoldas2);
    }
    else if (diszkriminans == 0) printf("Az egyetlen megoldas: %lf",(-b + sqrt(diszkriminans)) / (2*a));
    else printf("Nincs megoldas!\n");

    // d)
    // A feladat lényegében a Pitagorasz-tétel alkalmazását kéri, hiszen a külső pontból húzott érintő mindig merőleges a sugárra.
    // A háromszög 2 befogója a pontok távolsága és a sugár, az átfogó pedig az érintő.
    double r = 3;
    double l = 4;
    if (l <= r) printf("A pont nem a koron kivul van!\n");
    else {
        double erinto = sqrt(r*r+l*l);
        printf("Az erinto hossza: %lf\n", erinto);
    }

    // e)
    double a2, b2;
    printf("Adja meg az a es b parametereket \"a b\" formatumban!: ");
    scanf_s("%lf %lf", &a2,&b2);
    // Rendezzük át az egyenletet x-re!
    // x = arccos(-b/a) / 7
    //Ellenőrizzük, hogy a nem 0 e!
    if (a2 == 0) printf("Hiba! 0-val valo osztas!\n");
    // Ellenőrizzük, hogy az értelmezési tartományba esünk-e! Ekkora -1 <= -b/a <= 1
    else if (-b2/a2 > 1 || -b2/a2 < -1) printf("Nincs megoldas!\n"); 
    else {
        double x = acos(-b2/a2) / 7;
        printf("Az egyenlet megoldasa: %lf\n", x);
    }

    return 0;
}