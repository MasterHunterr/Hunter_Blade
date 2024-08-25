#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 64
#define MIN_LENGTH 30


int binaryDecode(const char *input) {
    int value = 0;
    while (*input) {
        value = (value << 1) | (*input - '0');
        input++;
    }
    return value;
}


int hexDecode(const char *input) {
    int value;
    sscanf(input, "%X", &value);
    return value;
}


int decimalDecode(const char *input) {
    int value;
    sscanf(input, "%d", &value);
    return value;
}

void customDecrypt(char *input, char *output) {
    int inputLength = strlen(input);
    int outputIndex = 0;

    for (int i = 0; i < inputLength;) {
        char buffer[9] = {0};

        if (strncmp(input + i, "Hunter", 6) == 0) {
            i += 6; 
            continue;
        }

        if (isdigit(input[i])) {
            if (i + 7 < inputLength && (input[i] == '0' || input[i] == '1')) {
                strncpy(buffer, input + i, 8);
                output[outputIndex++] = (char)binaryDecode(buffer);
                i += 8;
            } else if (isxdigit(input[i + 1])) { 
                strncpy(buffer, input + i, 2);
                output[outputIndex++] = (char)hexDecode(buffer);
                i += 2;
            } else {
                int j = 0;
                while (isdigit(input[i + j])) {
                    buffer[j] = input[i + j];
                    j++;
                }
                output[outputIndex++] = (char)decimalDecode(buffer);
                i += j;
            }
        } else if (isalpha(input[i]) || ispunct(input[i])) {
            i++; 
        } else {
            i++; 
        }
    }

    output[outputIndex] = '\0';
}

int main() {
    char input[MAX_LENGTH + 1] = "011010000110010101101100Hunter6C6F";
    char output[MAX_LENGTH + 1];

    customDecrypt(input, output);

    printf("Decrypted: %s\n", output);

    return 0;
}
