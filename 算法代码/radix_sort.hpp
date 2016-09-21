#include <stdio.h>
#include <vector>
#include <counting-sort.hpp>

std::vector RadixSort(std::vector A, int d)
{
	for(int i = 0; i < d; ++i)
	{
		std::vector B;
		CountingSort(A, B, 10);
		A = B;
	}
	return A;
}

