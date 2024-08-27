#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 2048
#define RANDOM_LETTERS_COUNT 26

char generateRandomChar() {
    return (rand() % 94) + 33; 
}

char generateRandomLetter() {
    return (rand() % RANDOM_LETTERS_COUNT) + 'A'; 
}

char generateRandomNumber() {
    return (rand() % 10) + '0'; 
}

void encryptChar(char c, char *output) {
    int asciiValue = (int)c;
    int encryptedValue = (asciiValue * 3 + 7) % 256;
    char randomLetter = generateRandomLetter();
    char randomNumber = generateRandomNumber();

    sprintf(output, "%03d %c %c ", encryptedValue, randomLetter, randomNumber);
}

char decryptChar(const char *input) {
    int encryptedValue;
    char randomLetter;
    char randomNumber;
    
    sscanf(input, "%d %c %c", &encryptedValue, &randomLetter, &randomNumber);

    // Corrected decryption formula
    int asciiValue = 0;
    for (int i = 0; i < 256; i++) {
        if ((i * 3 + 7) % 256 == encryptedValue) {
            asciiValue = i;
            break;
        }
    }
    return (char)asciiValue;
}

void encryptText(const char *input, char *output) {
    char encryptedChar[50];
    char *outputPtr = output;

    srand(time(NULL));

    while (*input) {
        encryptChar(*input, encryptedChar);
        sprintf(outputPtr, "%s", encryptedChar);
        outputPtr += strlen(encryptedChar);
        input++;
    }
    *outputPtr = '\0';
}

void decryptText(const char *input, char *output) {
    char buffer[MAX_LENGTH];
    const char *ptr = input;
    int index = 0;
    char decryptedChar;
    char encryptedPart[7];

    int length = strlen(input);
    while (ptr < input + length) {
        while (*ptr == ' ') ptr++; // skip spaces
        strncpy(encryptedPart, ptr, 6);
        encryptedPart[6] = '\0';
        ptr += 7;
        decryptedChar = decryptChar(encryptedPart);
        buffer[index++] = decryptedChar;
    }
    
    buffer[index] = '\0';
    strcpy(output, buffer);
}

int main() { 
    char text[] = "Hello, world this is a test for Encrypted Huntre";
    char encrypted[MAX_LENGTH] = {0};
    char decrypted[MAX_LENGTH] = {0};

    encryptText(text, encrypted);
    printf("Encrypted: %s\n", encrypted);

    decryptText(encrypted, decrypted);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
