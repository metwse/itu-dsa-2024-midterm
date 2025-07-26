#include "q7.h"

#include <stdio.h>


int main()
{
	int arr[1024];
	int input;
	int len = 0;

	printf("Enter numbers (-1 to stop): ");
	while (1) {
		if (scanf("%d", &input) != 1)
			return 1;

		if (input == -1) {
			break;
		} else {
			arr[len] = input;
			len++;
		}
	}

	printf("Longest sublist is: %d\n", longest_sublist(arr, len, 0));
}
