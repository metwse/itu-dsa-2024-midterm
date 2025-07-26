#include "q6.h"

#include <string.h>
#include <stdio.h>


int main()
{
	char string[1024];

	printf("Enter a string for reversal: ");
	if (scanf("%s", string) != 1) {
		return 1;
	}

	reverse_string(string, strlen(string));

	printf("Reversed string: %s\n", string);
}
