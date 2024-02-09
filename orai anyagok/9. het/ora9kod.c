#include <stdio.h>
#include <stdlib.h>
#include <string.h> // stringkezelésre használt függvények
#include <ctype.h> // toupper, tolower

#define STR_HOSSZ 101 // konstans helyett define-al jelöljük a hosszat

//kiíratás betűnként
void betuz(char* c)
{
    while (*c)   // while(*c!=NULL)
    {
        printf("'%c' ", *c++);
    }
    printf("\n");
}
//kiíratás egyben
void kiir(char* c)
{
    if (c) printf("%s\n", c);
}


int main(void)
{
    // Programterületen található szövegre mutató pointer
    char* string = "C szoveg";    // a tömböt \0 zárja    (nem módosítható)
    betuz(string);                // kiíratás betűnként
    kiir(string);
    //string[1] = '-';            // nem változtatható karakterenként - csak olvasható
    string = "Char *";            // átdefiniálható -> átirányítjuk a pointert
    kiir(string);

    //Karaktertömb
    char a[21] = "karakter";     // max 20 betű + \0 (\0 automatikus)
    char b[] = { 't', 'o', 'm', 'b', '\0' };  //4 karakter + \0- t meg kell adni!!!
    //a = "String";              //nem használható pointer művelt
    a[0] = 'K';                  //tömb elemenként módosítható
    a[4] = 'K';
    kiir(a);
    printf("A b string hossza: %i\n", strlen(b));   // hossz \0-ig
    printf("A b memoria merete: %i\n", sizeof(b)); // teljes méret, \0-val együtt

    //dinamikus tömb esetén
    char* cpt = (char*)malloc(STR_HOSSZ);        //100 betű tárolására lesz alkalmas
    cpt[0] = 'a'; cpt[1] = 'b'; cpt[10] = 0;     //ismeretlen tartalom \0-ig
    kiir(cpt); // memóriaszeméttel együtt
    memset(cpt, 0, STR_HOSSZ);      //cpt összes eleme 0
                                    //lehetne strset(cpt,'\0'); de csak char *-ra működik

    // Stringkezelő függvények
    //másolás
    //cpt = a;                //ez nem tartalom másolás, csak ugyanoda fog mutatni a pointer!
    int i = 0;
    while (a[i])              //while(a[i]==0) - nem tudjuk a hosszát \0-ig kell menni
    {
        cpt[i] = a[i];        // cpt[i] = a[i++]; is lehetne
        i++;
    }
    cpt[i] = '\0';            //záródó \0
    kiir(cpt);

    //hozzáfűzés
    char* tmp = b;            //ugyanoda mutat
    // i = 0;                 //ha i=0 lenne, akkor csak b másolása lenne
    while (*tmp)              //while(*s_tmp!=NULL)
    {
        cpt[i] = *tmp;        //cpt[i++]=*tmp++  léptetéssel eggyütt
        tmp++; i++;           //külön léptetés
    }
    cpt[i] = '\0';
    kiir(cpt);

    // strcpy másolás, _s biztonságos verziónál meg kell adni a cél méretét, hogy ne lehessen túlírni
    strcpy_s(cpt, STR_HOSSZ, a);     //biztonságos verzió(hova, maximum mennyit szabad, miből)
    kiir(cpt);

    // strncpy_s: adott számú karakter másolása
    memset(cpt, 0, STR_HOSSZ);       //karaketer tömb ürítése
    strncpy_s(cpt, STR_HOSSZ, a, 3); //n db karater átmásolása, biztonságos verzió \0-t is hozzáadja
    kiir(cpt);

    strcpy_s(a, sizeof(a), b);       //a maximum méret statikus tömböknél sizeof()-al megadható
    kiir(a);

    // új érték adására is jó
    strcpy_s(a, sizeof(a), "char ");
    strcpy_s(b, sizeof(b), "*");
  
    // strcat_s: összefűzés
    strcat_s(a, sizeof(a), b);     // strcat_s(mihez, max mennyit szabad, mit) az első \0-t cseréli ki a mit-re
    kiir(a);

    // strncat_s: összefűzés n darab
    strncat_s(a, sizeof(a), " +5 karakter", 5);    //hozzáfűzzünk 5 karaktert ('a' nem lehet nagyobb, mint 20 karakter!!!)
    kiir(a);

    char s2[STR_HOSSZ];   //másoljuk bele 2x az a[]-t
    strcpy_s(s2, STR_HOSSZ, a);        //1. strcpy
    strcat_s(s2, STR_HOSSZ, " ");
    strcat_s(s2, STR_HOSSZ, a);        //2. strcat
    kiir(s2);

    // adott karakter keresése
    tmp = strchr(s2, 'r');        //strchr visszaadja a karakterre mutató pointert vagy NULL-t ha nincs
    kiir(tmp);
    tmp = strrchr(s2, 'r');       //strrchr visszaadja az utolsó karakterre mutató pointert (visszafelé halad)
    kiir(tmp);

    //betű megszámlálása
    tmp = s2;
    int db = 0;
    while (tmp) // amíg tart a string
    {
        tmp = strchr(tmp, 'k'); // a pointert a talált pozícióra helyezzük
        if (tmp)
        {
            tmp++;                   //átlépjük a 'k' karaktert
            db++;                    //növeljük a számálót
        }
    }
    printf("A k betuk szama: %i\n", db);

    //string keresés
    tmp = strstr(s2, "ar");           //strstr visszaadja a stringre mutató pointert
    kiir(tmp);
    char se[STR_HOSSZ];               //string eleje
    memset(se, 0, STR_HOSSZ);         //feltöltés /0-val, de 
    strncpy_s(se, sizeof(se), s2, tmp - s2);  //biztonságos n-es verziónál /0 it átmásolva
    kiir(se);

    //összehasonlítás
    char n1[] = "Attila";
    char n2[] = "Bela";
    int k = strcmp(n1, n2);
    switch (k)
    {
        case 1: printf("%s nagyobb, mint %s\n", n1, n2); break; // n1 hátrébb van az abc sorrendben
        case 0: printf("%s egyenlo %s\n", n1, n2); break;
        case -1: printf("%s kisebb, mint %s\n", n1, n2); break; // n1 előrébb van az abc sorrendben
    }

    //Konverziók
    double x = 3.14;
    char sx[10];
    sprintf_s(sx, sizeof(sx), "%f", x);         //számból -> szöveg, annyira nem sűrűn használt
    printf("%s\n", sx);

    strcpy_s(sx, sizeof(sx) , "6.28");
    sscanf_s(sx, "%lf", &x);           //szövegből -> szám
    printf("%lf\n", x);

    strcpy_s(sx, sizeof(sx), "9.42");
    x = atof(sx) / 3;                //szövegből -> double, atoi: int
    printf("%lf\n", x);

    //strtok_s: az eredeti tartalmat szétszedi úgy, hogy \0-t rak be a szeparáló elem helyére
    char adatok[] = "1.2;24.5;42.6;64"; // adathalmaz
    double szum = 0;
    char delim[] = ";"; // delimiter / elválasztó karakterek
    char *p, *next; // next pointer bemenet az strok_s-nek
    //strcpy_s(cpt, STR_HOSSZ, adatok);      //ha kell biztonsági másolat, mivel utána elveszítjük
    p = strtok_s(adatok, delim, &next);      //első híváskor
    while (p) // amíg nem NULL pointer a visszatérési érték
    {
        kiir(p);
        szum+= atof(p);
        p = strtok_s(NULL, delim, &next);    //további híváskor NULL
    }
    printf("Ez maradt az adatokbol: %s\n", adatok);
    printf("Az adatok osszege: %.3lf\n", szum);

    //Adatbevitel - teljes sor szövegre
    printf("kerek egy szoveget: ");
    gets_s(s2, STR_HOSSZ);                         //biztonságos Enter-ig,  Enter-t nem tárolja
    for (i = strlen(s2) - 1; i >= 0; i--)        //megfordít
        printf("%c", toupper(s2[i]));            //toUpper -> nagybetű, tolower -> kisbetű (ctype.h)
    printf("\n");
    
    free(cpt); // malloc miatt free!

	return 0;
}



