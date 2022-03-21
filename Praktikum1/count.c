#include <stdio.h>
#include <stdlib.h>
int main () 
{
	int input, count = 0, words = 0, i, chars;
	char array[256];

	printf("Enter a word or a phrase: \n");
    	
	while (((input = getchar()) != '\n') && (count < (256 -1)))
	{
		array[count++] = input;
	}
	array[count] = '\0';
	
	int lenArray = sizeof(array);
	
	for (i = 0; i < lenArray; i++) 
	{
		if ((array[i] == ' ') || (array[i] == '\t')) 
		{
			words++;
		}
	}

	chars = count - words;
	printf("%s %d %s", "\n You have entered: ",count, "characters with space and tab");
	printf("%s %d %s", "\n You have entered: ",chars, "characters");
	printf("%s %d %s", "\n You have entered: ",words, "words \n");
	return 0;
}
