#include <stdio.h>
#include <vector>
#include "randomized-quick-sort.hpp"

int RandomizedSelect(std::vector A, int p, int r, int i)
{
	if(p == r)
		return A[p];
	int q = RANDOMIZED_PARTITION(A, p, r);
	int k = q - p + 1;

	if(k == i)
		return A[q];
	else if(i < k)
		return RandomizedSelect(A, p, q-1, i);
	else
		return RandomizedSelect(A, q-1, r, i-k);
}
