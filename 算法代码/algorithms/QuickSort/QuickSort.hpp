#ifndef _QUICK_SORT_HPP
#define _QUICK_SORT_HPP

#include <stdio.h>
#include <string>
#include <random>
namespace algrm
{
#ifndef OUTPUT_ARR
#define OUTPUT_ARR
	std::string OutputArr(std::string info, int* arr, int begin, int end)
	{
		std::string out(info);
		char buf[16];
		for(int i = begin; i <= end; ++i)
		{
			sprintf(buf, "%d ", arr[i]);
			out.append(buf);
		}
		puts(out.c_str());
		return out;
	}
#endif

	int Patition(int arr[], int begin, int end)
	{
		//Patition
		int ref = arr[end];
		int dvIndex = begin -1, itIndex = begin;
		for(; itIndex < end; ++itIndex)
		{
			if(arr[itIndex] < ref)
			{
				++dvIndex;
				int temp = arr[itIndex];
				arr[itIndex] = arr[dvIndex];
				arr[dvIndex] = temp;
			}
		}

		dvIndex += 1;
		int temp = arr[end];
		arr[end] = arr[dvIndex];
		arr[dvIndex] = temp;

		return dvIndex;
	}

	int RandomizedQuickSort(int *arr, int begin, int end)
	{
		int ret = 0;
		int amount = end - begin +1;

		if(begin < end)
		{
			//Radomly select a reference
			int refIndex = begin + (rand() % amount);

			//Reference must be the end element
			int temp = arr[end];
			arr[end] = arr[refIndex];
			arr[refIndex] = temp;

			int dvIndex = Patition(arr, begin, end);
			OutputArr("Sorting: ", arr, begin, end);

			//Recursion
			ret = RandomizedQuickSort(arr, begin, dvIndex-1);
			ret = RandomizedQuickSort(arr, dvIndex+1, end);
		}
		else
		{//Completed
		}

		return ret;
	}

}//namespace algrm

#endif//_QUICK_SORT_HPP