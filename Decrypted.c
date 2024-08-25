#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 2048

char decryptChar(const char *input) {
    int encryptedValue;
    char randomLetter;
    char randomNumber;
    char randomWord[10];
    
    sscanf(input, "%d %c %c %s", &encryptedValue, &randomLetter, &randomNumber, randomWord);

    int asciiValue = (encryptedValue - 7 + 256) / 3; 
    return (char)asciiValue;
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
    char encryptedText[MAX_LENGTH] = "183 A 4 zebra 193 B 8 moose 155 C 2 quartz 140 D 1 vivid";
    char decrypted[MAX_LENGTH] = {0};

    decryptText(encryptedText, decrypted);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
