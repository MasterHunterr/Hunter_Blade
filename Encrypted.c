#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 64
#define MIN_LENGTH 30

char getRandomChar() {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
    return charset[rand() % (sizeof(charset) - 1)];
}

void binaryEncode(char *output, int value) {
    for (int i = 7; i >= 0; --i) {
        *output++ = (value & (1 << i)) ? '1' : '0';
    }
    *output = '\0';
}

void hexEncode(char *output, int value) {
    sprintf(output, "%X", value);
}


void decimalEncode(char *output, int value) {
    sprintf(output, "%d", value);
}

void customEncrypt(char *input, char *output) {
    int length = strlen(input);
    int outputLength = rand() % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH;
    int outputIndex = 0;

    for (int i = 0; i < length; i++) {
        char temp[9];
        int option = rand() % 3;
        
        switch (option) {
            case 0:
                binaryEncode(temp, input[i]);
                break;
            case 1:
                hexEncode(temp, input[i]);
                break;
            case 2:
                decimalEncode(temp, input[i]);
                break;
        }

        for (int j = 0; temp[j] != '\0' && outputIndex < outputLength; j++) {
            output[outputIndex++] = temp[j];
        }

        if (rand() % 10 == 0 && outputIndex < outputLength) { // كلما تم استيفاء هذا الشرط ، قم بإضافة "Hunter"
            strcpy(output + outputIndex, "Hunter");
            outputIndex += strlen("Hunter");
        } else if (rand() % 4 == 0 && outputIndex < outputLength) { // أضف رمز عشوائي
            output[outputIndex++] = getRandomChar();
        }

        if (outputIndex >= outputLength) break;
    }

    output[outputIndex] = '\0';
}

int main() {
    srand(time(0));
    char input[] = "HelloWorld";
    char output[MAX_LENGTH + 1];

    customEncrypt(input, output);

    printf("Encrypted: %s\n", output);

    return 0;
}
