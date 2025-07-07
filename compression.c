#include <stdio.h>
#include <string.h>

// Function to compress using Run-Length Encoding
void compressRLE(char str[]) {
    int i, count;
    char current;

    printf("Compressed Output: ");
    for (i = 0; i < strlen(str); i++) {
        current = str[i];
        count = 1;

        while (str[i] == str[i + 1]) {
            count++;
            i++;
        }

        printf("%c%d", current, count);
    }
    printf("\n");
}

// Function to decompress RLE string
void decompressRLE(char str[]) {
    int i = 0;
    char ch;
    int count;

    printf("Decompressed Output: ");
    while (str[i] != '\0') {
        ch = str[i++];
        count = 0;
        while (str[i] >= '0' && str[i] <= '9') {
            count = count * 10 + (str[i] - '0');
            i++;
        }

        for (int j = 0; j < count; j++)
            printf("%c", ch);
    }
    printf("\n");
}

int main() {
    char input[] = "aaabbbbccddddd";
    char compressed[] = "a3b4c2d5";  // Example RLE compressed version of input

    printf("Original Input: %s\n", input);
    compressRLE(input);

    printf("\nGiven Compressed String: %s\n", compressed);
    decompressRLE(compressed);

    return 0;
}
