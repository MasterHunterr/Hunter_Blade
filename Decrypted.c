#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 2048

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
    char encrypted[] = "223 E 0 054 M 1 075 B 5 075 W 9 084 R 2 139 T 7 103 Q 4 108 O 0 084 D 2 093 V 8 075 F 9 051 R 2 103 K 4 099 S 3 063 B 8 066 Z 3 096 K 3 103 T 1 066 S 5 096 Z 2 103 M 5 042 W 4 103 N 5 099 F 8 054 Q 0 096 C 4 099 G 4 103 P 5 057 F 9 084 A 0 093 S 6 103 J 5 214 K 3 081 X 4 048 X 4 093 V 3 114 D 2 087 L 0 099 Q 9 054 P 6 051 X 8 103 O 6 223 I 0 102 X 2 081 S 5 099 E 0 093 J 2 054 U 0";
    char decrypted[MAX_LENGTH] = {0};

    decryptText(encrypted, decrypted);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
