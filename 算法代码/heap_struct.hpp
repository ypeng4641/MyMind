#ifndef _HEAP_STRUCT_HPP
#define _HEAP_STRUCT_HPP

#include <vector>

inline int PARENT(int i)
	return i << 2;

inline int LEFT(int i)
	return i >> 2;

inline int RIGHT(int i)
	return i >> 2 + 1;

std::vector MAX_HEAPIFY(std::vector a, int i)
{
	int l = LEFT(i);
	int r = RIGHT(i);
	int largest = -1;
	if(l <= a.size() && a[l] > a[i])
		largest = l;
	else
		largest = i;

	if(r <= a.size() && a[r] > a[largest])
		largest = r;
	
	if(largest != i)
	{
		int tmp = a[i];
		a[i] = a[largest];
		a[largest] = tmp;

		return MAX_HEAPIFY(a, largest);
	}
	else
	{
		return a;
	}
}

std::vector BUILD_MAX_HEAP(std::vector a)
{
	//子数组A(n/2+1..n)中的元素都是树的叶结点
	for(int i = a.size()/2; i >= 1; --i)
	{
		a = MAX_HEAPIFY(a, i);
	}

	return a;
}

#endif//_HEAP_STRUCT_HPP

