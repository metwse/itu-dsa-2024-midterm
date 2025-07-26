#include "q7.h"


int longest_sublist(int *arr, int len, int recursion)
{
	int filtered[len];
	int filtered_len = 0;
	int prev = arr[0];

	for (int i = 1; i < len; i++) {
		if (prev == arr[i]) {
			filtered[filtered_len] = arr[i];
			filtered_len++;
		} else {
			prev = arr[i];
		}
	}

	for (int i = 0; i < filtered_len; i++)
		arr[i] = filtered[i];

	if (filtered_len != 0)
		return longest_sublist(arr, filtered_len, recursion + 1);
	else
		return recursion + 1;
}
