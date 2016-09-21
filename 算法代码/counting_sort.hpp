#include <stdio.h>
#include <vector>

int CountingSort(std::vector<int> A, std::vector<int> B, int k)
{
	std::vector<int> C(k, 0);
	B.resize(A.size(), 0);

	for(int i = 0; i < A.size(); ++i)
	{
		++C[A[i]];
	}

	for(int i = 1; i < k; ++i)
	{
		C[i] += C[i-1];
	}

	for(int i = 0; i < A.size(); ++i)
	{
		B[C[A[i]]] = A[i];
		--C[A[i]];
	}

	return 0;
}

