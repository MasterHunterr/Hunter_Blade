#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 2048
#define RANDOM_WORDS_COUNT 10
#define RANDOM_LETTERS_COUNT 26
#define RANDOM_NUMBERS_COUNT 10

const char *randomWords[] = {
   "bey", "zebra", "moose", "quartz", "fable", "whisk", "jungle", "vivid", "puzzle", "zodiac", "flame"
};


char generateRandomChar() {
    return (rand() % 94) + 33; 
}


char generateRandomLetter() {
    return (rand() % RANDOM_LETTERS_COUNT) + 'A'; 
}


char generateRandomNumber() {
    return (rand() % 10) + '0'; 
}


const char *generateRandomWord() {
    return randomWords[rand() % RANDOM_WORDS_COUNT];
}

using a mathematical equation
void encryptChar(char c, char *output) {
    int asciiValue = (int)c;
    int encryptedValue = (asciiValue * 3 + 7) % 256;
    char randomChar = generateRandomChar();
    char randomLetter = generateRandomLetter();
    char randomNumber = generateRandomNumber();
    const char *randomWord = generateRandomWord();

    sprintf(output, "%03d %c %c %s ", encryptedValue, randomLetter, randomNumber, randomWord);
}

char decryptChar(const char *input) {
    int encryptedValue;
    char randomLetter;
    char randomNumber;
    char randomWord[10];
    
    sscanf(input, "%d %c %c %s", &encryptedValue, &randomLetter, &randomNumber, randomWord);

    int asciiValue = (encryptedValue - 7 + 256) / 3; 
    return (char)asciiValue;
}


void encryptText(const char *input, char *output) {
    char encryptedChar[MAX_LENGTH];
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
    char encryptedPart[50];

    while (*ptr) {
        sscanf(ptr, "%s", encryptedPart);
        ptr += strlen(encryptedPart) + 1;
        decryptedChar = decryptChar(encryptedPart);
        buffer[index++] = decryptedChar;
    }
    buffer[index] = '\0';
    strcpy(output, buffer);
}

int main() {
    char text[] = "Hello";
    char encrypted[MAX_LENGTH] = {0};
    char decrypted[MAX_LENGTH] = {0};

    encryptText(text, encrypted);
    printf("Encrypted: %s\n", encrypted);

    decryptText(encrypted, decrypted);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
