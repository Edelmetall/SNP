#include <stdlib.h>
#include <stdio.h>
// Es ist genau 1 bit Unterschied, aus diesem Grund funktioniert es
// 01000001 A => 01100001 a
int main(){
  char word[8] = "sREedEv";
  char *wordptr = &word[0];

  while(wordptr < &word[7]) {
    printf("UPPERCASE: %c\n", *wordptr & '_'); // converts the char into uppercase regardless of the current casing
    printf("LOWERCASE: %c\n", *wordptr | ' '); // converts the char into lowercase regardless of the current casing
    wordptr++;
  }

  return EXIT_SUCCESS;
}
