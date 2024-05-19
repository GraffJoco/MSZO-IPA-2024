#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Segédfv, ha hibás az azonosító, kilép errorral a programból
void assertReg(int regVal, int sorSzam) {
    if (regVal < 0 || regVal > 7) {
        printf("Kicimzes az %d. sorban!\n", sorSzam);
        exit(-1); // mivel nem main-ben vagyunk, csak exit lehet itt
    }
}

// String hosszok
#define HOSSZ 512
#define fajlnev "utasitasok.txt"

int main() {
    // regiszterek, tömbben automatikusan 0-7-es indexszel
    int reg[8];
    for (int i = 0; i < 8; i++) {
        reg[i] = 0;
    }

    // Fájl megnyitása
    FILE* fajl;
    fopen_s(&fajl, fajlnev, "r");

    if (fajl == NULL) {
        printf("Nem sikerult az %s fajlt megnyitni!\n", fajlnev);
        exit(-1);
    }

    char sor[HOSSZ];
    int sorSzam = 0;
    while (!feof(fajl)) {
        sorSzam++;
        fgets(sor, HOSSZ, fajl);
        if (strlen(sor) == 0) {continue;}

        char* ctx;
        char* elsoszo = strtok_s(sor, " ", &ctx);
        
        // Utasítások
        if (strcmp(elsoszo, "mov") == 0) {
            int a = atoi(strtok_s(NULL, ",", &ctx));
            int b = atoi(strtok_s(NULL, "\n", &ctx));

            assertReg(a, sorSzam);
            assertReg(b, sorSzam);

            reg[a] = reg[b];
        }
        if (strcmp(elsoszo, "add") == 0) {
            int a = atoi(strtok_s(NULL, ",", &ctx));
            int b = atoi(strtok_s(NULL, "\n", &ctx));

            assertReg(a, sorSzam);
            assertReg(b, sorSzam);

            reg[a] += reg[b];
        }
        if (strcmp(elsoszo, "adv") == 0) {
            int a = atoi(strtok_s(NULL, ",", &ctx));
            int v = atoi(strtok_s(NULL, "\n", &ctx));

            assertReg(a, sorSzam);

            reg[a] += v;
        }
        if (strcmp(elsoszo, "cmp") == 0) {
            int a = atoi(strtok_s(NULL, ",", &ctx));
            int b = atoi(strtok_s(NULL, "\n", &ctx));

            assertReg(a, sorSzam);
            assertReg(b, sorSzam);

            if (reg[a] != reg[b]) {
                reg[a] = 0;
            } else {
                reg[a] = 1;
            }
        }
        if (strcmp(elsoszo, "jnz") == 0) {
            int a = atoi(strtok_s(NULL, ",", &ctx));
            int v = atoi(strtok_s(NULL, "\n", &ctx));

            assertReg(a, sorSzam);
            // Sorok átugrása azzal, hogy sorSzamot növeljük,
            // és v db sort olvasunk be fájlból
            if (reg[a] != 0) {
                sorSzam += v;
                for (int i = 0; i < v; i++) {
                    fgets(sor, HOSSZ, fajl);
                }
            }
        }
        if (strcmp(elsoszo, "wrg") == 0) {
            int a = atoi(strtok_s(NULL, "\n", &ctx));
            assertReg(a, sorSzam);
            printf("%d\n", reg[a]);
        }
        if (strcmp(elsoszo, "rrg") == 0) {
            int a = atoi(strtok_s(NULL, "\n", &ctx));
            assertReg(a, sorSzam);
            scanf("%d", &reg[a]);
        }
    }

    fclose(fajl);
}
