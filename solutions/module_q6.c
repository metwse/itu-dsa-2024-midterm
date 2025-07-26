#include "q6.h"


void reverse_string(char *str, int len)
{
	if (len > 3)
		reverse_string(str + 1, len - 2);

	if (len > 1) {
		char hold = str[0];
		str[0] = str[len - 1];
		str[len - 1] = hold;
	}
}
