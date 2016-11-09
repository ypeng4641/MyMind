#ifndef _BUBBLE_SORT_H
#define _BUBBLE_SORT_H

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

void BubbleSort(int arr[], int len)
{
	int swapCnt = 0;
	do
	{
		swapCnt = 0;
		for(int i = 0; i < len-1; ++i)
		{
			if(arr[i] > arr[i+1])
			{
				int tmp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = tmp;
				++swapCnt;
			}
		}
		OutputArr("Sorting: ", arr, len);
	}
	while(swapCnt > 0);
}

}//namespace algrm
#endif