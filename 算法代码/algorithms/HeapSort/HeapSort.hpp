#ifndef _HEAP_SORT_HPP
#define _HEAP_SORT_HPP

#include <stdio.h>
#include <string>
namespace algrm
{
#ifndef OUTPUT_ARR
#define OUTPUT_ARR
	std::string OutputArr(std::string info, int* arr, int size)
	{
		std::string out(info);
		char buf[16];
		for(int i = 0; i < size; ++i)
		{
			sprintf(buf, "%d ", arr[i]);
			out.append(buf);
		}
		puts(out.c_str());
		return out;
	}
#endif

#define PARENT(i) (((i+1) >> 1) -1)
#define LEFT(i) (((i+1) << 1) -1)
#define RIGHT(i) ((i+1) << 1)

	int Heapify(int *arr, int size)
	{
		int ret = 0;

		int minIndex = 0;
		int leftIndex = LEFT(0);
		int rightIndex = RIGHT(0);
		if(leftIndex < size && arr[leftIndex] < arr[minIndex])
			minIndex = leftIndex;
		if(rightIndex < size && arr[rightIndex] < arr[minIndex])
			minIndex = rightIndex;

		if(minIndex != 0)
		{
			int temp = arr[minIndex];
			arr[minIndex] = arr[0];
			arr[0] = temp;

			ret = Heapify(arr + minIndex, size - minIndex);
		}
		else
		{//Completed
		}
		return ret;
	}

	int HeapSort(int *arr, int begin, int end)
	{
		int ret = 0;
		int amount = end - begin +1;

		//Build a heap
		int leafIndex = (begin + amount/2 -1) +1;
		for(int i = leafIndex -1; i >= 0; --i)
		{
			ret = Heapify(arr + i, amount-i);
			if(ret != 0)
				break;

			OutputArr("Sorting: ", arr + i, amount-i);
		}

		//New memory
		int *arrTemp = new int[amount];
		memcpy(arrTemp, arr, sizeof(int)*amount);

		//Pop minimum to original array
		for(int i = 0; i < amount; ++i)
		{
			ret = Heapify(arrTemp + i, amount-i);
			if(ret != 0)
				break;

			arr[i] = arrTemp[i];
			OutputArr("Sorting: ", arrTemp + i, amount-i);
		}

		return ret;
	}

}//namespace algrm

#endif//_HEAP_SORT_HPP