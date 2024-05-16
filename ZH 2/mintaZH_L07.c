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
#define HOSSZ 64

int main() {
    // regiszterek, tömbben automatikusan 0-7-es indexszel
    int reg[8];
    for (int i = 0; i < 8; i++) {
        reg[i] = 0;
    }


}
