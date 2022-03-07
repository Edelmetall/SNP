#include <stdio.h>
#include <stdbool.h>

int main(void) {
    printf("Text: ");
    int wordCount = 0;
    int charCount = 0;
    char c;
    bool inWord = false;
    while ((c = getchar()) != '\n') {
        if (c == '\t' || c == ' ') {
            inWord = false;
        } else {
            if (!inWord) {
                inWord = true;
                wordCount++;
            }
            charCount++;
        }
    }

    printf("Anzahl Zeichen: %d - Anzahl Wörter: %d\n", charCount, wordCount);
}