#include <stdio.h>

#define CHAR_0 48
#define CHAR_9 57

int isNumber(int i) {
    return (i >= CHAR_0) && (i <= CHAR_9);
}

int getValue(int i) {
    return i - CHAR_0;
}

int main() {
    FILE *file = fopen("./Day1/input.txt", "r");
    if (file == NULL) {
        printf("File could not be found");
        return 1;
    }

    int i;
    int firstCharVal = -1;
    int lastCharVal = -1;
    int sum = 0;
    while (1) {
        i = fgetc(file);

        // We have reached end of line
        if (i == (int) '\n' || i == EOF) {
            sum += (10 * firstCharVal) + lastCharVal;
            // Reset char values
            firstCharVal = lastCharVal = -1;

            if (i == EOF)
                break;

            continue;
        }

        // Determine if it's a character representing a number
        if (isNumber(i)) {
            if (firstCharVal == -1) {
                firstCharVal = lastCharVal = getValue(i);
            } else {
                lastCharVal = getValue(i);
            }
        }
    }

    printf("Day one solution is: %d\n", sum);
    return 0;
}