#ifndef _RANDOMIZED_SELECT_HPP
#define _RANDOMIZED_SELECT_HPP

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

	int RandomizedSelect(int *arr, int begin, int end, int wantedSeq, int& selectedValue)
	{
		int ret = 0;
		int amount = end - begin +1;
		if(amount <= 1)
		{
			selectedValue = arr[begin];
			return ret;
		}

		//Randomly select a reference
		int refIndex = begin + rand() % amount;
		int temp = arr[end];
		arr[end] = arr[refIndex];
		arr[refIndex] = temp;

		//Patition
		int ref = arr[end];
		int dvIndex = begin -1, itIndex = begin;
		for(; itIndex <= end; ++itIndex)
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
		temp = arr[end];
		arr[end] = arr[dvIndex];
		arr[dvIndex] = temp;

		//Calculate the wantedIndex
		int seq = dvIndex - begin +1;
		if(seq < wantedSeq)
		{
			OutputArr("Calculating: ", arr, dvIndex+1, end);
			ret = RandomizedSelect(arr, dvIndex+1, end, wantedSeq - seq, selectedValue);
		}
		else if(seq > wantedSeq)
		{
			OutputArr("Calculating: ", arr, begin, dvIndex-1);
			ret = RandomizedSelect(arr, begin, dvIndex-1, wantedSeq, selectedValue);
		}
		else
		{//Completed
			selectedValue = arr[dvIndex];
		}

		return ret;
	}

}//namespace algrm

#endif//_RANDOMIZED_SELECT_HPP