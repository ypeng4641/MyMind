#include <stdio.h>

#include "heap-struct.hpp"

std::vector HEAPSORT(std::vector a)
{
	std::vector sort;

	a = BUILED_MAX_HEAP(a);
	for(int i = a.size(); i >= 2; --i)
	{
		sort.push_back(a.pop_front());

		MAX_HEAPIFY(a, 0);
	}
}
