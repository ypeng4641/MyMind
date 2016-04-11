#ifndef _QUICK_SORT_HPP
#define _QUICK_SORT_HPP

int PARTITION(int A[], p, r)
{
	int x = A[r];
	int i = p - 1;
	int j = p;
	for(; j < r; ++j)
	{
		if(A[j] <= x)
		{
			++i;
			int tmp = A[j];
			A[j] = A[i];
			A[i] = tmp;
			continue;
		}
	}

	int tmp = A[i+1];
	A[i+1] = A[r];
	A[r] = tmp;
	return i+1;
}

int* QUICKSORT(int A[], p, r)
{
	if(p < r)
	{
		int q = PARTITION(A, p, r);
		QUICKSORT(A, p, q-1);
		QUICKSORT(A, q+1, r);
	}
}

#endif//_QUICK_SORT_HPP
