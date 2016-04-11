#ifndef _RANDOMIZED_QUICK_SORT_HPP
#define _RANDOMIZED_QUICK_SORT_HPP

#include "quick-sort.hpp"
#include <math.h>

int RANDOMIZED_PARTITION(int A[], int p, int r)
{
	int i = random(p, r);
	A[p] += A[r];
	A[r] = A[p] - A[r];
	A[p] = A[p] - A[r];
	return PARTITION(A, p, r);
}

int* RANDOMIZED_QUICKSORT(int A[], int p, int r)
{
	int q = RANDOMIZED_PARTITION(A, p, r);
	RANDOMIZED_QUICKSORT(A, p, q-1);
	RANDOMIZED_QUICKSORT(A, q+1, r);

	return A;
}

#endif//_RANDOMIZED_QUICK_SORT_HPP
