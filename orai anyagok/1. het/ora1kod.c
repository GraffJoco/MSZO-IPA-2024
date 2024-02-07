// Fejállományok (header fájlok): <> rendszer, "" saját
#include <stdio.h>	// standard input/output

// Definició, előfordító behelyettesíti, nincs ;
#define PI 3.14159

// Globális változók helye, végig a memóriában marad, "memória pazarlás"

// Főprogram
int main(void)					// A program belépési pontja
{
	printf("Hello MOGI :)\n");	// kiíratás a konzolra, \n új sor
	
	//lokális változók
	int a;						// egész változó, csak deklarálás, ekkor a memóriaszemét nem törlődik, csak egybőli értékadásnál
	const int b = -20;			// konstans, kötelező értéket adni, nem változtatható
	unsigned int egesz, Egesz;	// kis / nagy betűk megkülönböztetve
    // hosszabb nevek esetén pl. zacskosTej vagy zacskos_tej

    // ha elkezdjük írni, az Intellisense felajánl kiegészítést tabozva
    egesz = 20;		// 20
	Egesz = 0xA;	// 10, hexadecimálisban a 0x miatt, (0...9, A,B...F)
	Egesz = 0b1101; // bináris, Visual Studio sajátossága, nem alap C
    a = 030;        // oktális számrendszer, mivel előtte 0 van
    a = 30;

	Egesz = b;	// értékadás (signed -> unsigned) ?
    
    printf("%d\n", Egesz); // sima intként printeljük
    printf("%u\n", Egesz); // unsigned intként printeljük, így helyes

	//b = 2;   // b csak olvasható, const errort ad, ha változtatnánk


	printf("a erteke: %d \n", a);				// %d vagy %i egész
	printf("a erteke oktalisan: 0%o \n", a);		// %o oktális
	printf("a erteke hexadecimalisan: 0x%x \n", a);	// %x hexa
	printf("a merete a memoriaban: %i byte\n", sizeof(a));	//sizeof változó vagy típus mérete
	printf("short int merete a memoriaban: %i byte\n", sizeof(short int));
	printf("long long merete a memoriaban: %i byte\n", sizeof(long long));	// szám LL

	printf("a = %d, b = %d\n", a, b);			// annyi változó, ahány a formátumban szerepel

	double tort = 3.14;		// tizedestört mindig . , de! magyarban (,) ezért fájlkezelésben problémás

	printf("tort erteke: %f\n", tort);		// float
	printf("tort erteke: %5.1f\n", tort);	// 1 tizedes, 5 összes
	printf("tort erteke: %.1f\n", tort);	// 1.tizedes
	printf("tort erteke: %e\n", tort);		// normál alak
	printf("tort erteke: %g\n", tort);		// amelyik rövidebb: %e vagy %f
	printf("double merete: %d byte\n", sizeof(tort));

	float pi = 3.14159f;	// float szám után f!

	printf("a pi erteke: %.4f\n", pi);
	printf("a pi erteke: %.4f\n", PI);		// PI definició behelyettesítődik
	printf("float merete: %d byte\n", sizeof(float));

	char c = 67;			// ASCII karakter 'C', nagy A 65-től

	printf("c erteke int-ben: %d \n", c);
	printf("c ASCII karaktere: %c \n", c);
	printf("char merete: %d byte\n", sizeof(char));


	return 0;
    // return 1; pl. hibakód kilépés
}

// Visual Studio funkciók:
/*
Oldalt lerakhatóak STOP pontok, így megfigyelhető a változók állapota a kód futása közben. -> Debuggolás

Típusok:

int:
- egész számokat tartalmaz
- implementációfüggő a mérete, C-ben 4 byte
- lehet pozitív és negatív
- módosítószavak: short (2 byte), long (legalább 4 byte, de lehet 8), long long (legalább 8 byte), unsigned (nemnegatív, 2x-es tartomány)

float:
- lebegőpontos számok
- 8 tizedesjegy pontosság
- 4 byte

double:
- lebegőpontos számok
- 15 tizedesjegy pontosság
- 8 byte
- ezt szokás használni float helyett

char: 1 byte
*/