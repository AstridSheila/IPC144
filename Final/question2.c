//Astrid Bailey
//IPC144N1F
//April 16, 2026

#include <stdio.h>

unsigned int packCharacters(char a, char b, char c, char d);
void displayBits(unsigned int value);

int main(){

    char a, b, c, d;
    printf("%s", "Enter four letters to be packed:\n");
    scanf("%c %c %c %c", &a, &b, &c, &d);
    unsigned int packed = packCharacters(a, b, c, d);

    displayBits(packed);

    return 0;
}

unsigned int packCharacters(char a, char b, char c, char d){
    unsigned int packedInt = a;
    unsigned int firstPacked = a;
    displayBits(firstPacked);
    packedInt = packedInt << 8;
    packedInt = packedInt | b;
    unsigned int secondPacked = b;
    displayBits(secondPacked);
    packedInt = packedInt << 8;
    packedInt = packedInt | c;
    unsigned int thirdPacked = c;
    displayBits(thirdPacked);
    packedInt = packedInt << 8;
    packedInt = packedInt | d;
    unsigned int fourthPacked = d;
    displayBits(fourthPacked);
    return packedInt;
}

void displayBits(unsigned int value) {
    // Assumes 32-bit int
    unsigned int displayMask = 1 << 31; 
    printf("%10u = ", value);

    for (unsigned int c = 1; c <= 32; c++) {
        putchar(value & displayMask ? '1' : '0');
        value <<= 1; // Shift value left by 1

        if (c % 8 == 0) { // Print space after every 8 bits
            putchar(' ');
        }
    }
    putchar('\n');
}