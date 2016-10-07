#ifndef _MEDIAM_SELECT_HPP
#define _MEDIAM_SELECT_HPP

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

	int QuickSort(int* arr, int begin, int end)
	{
		int ret = 0;
		if(begin < end)
		{
			int refer = arr[end];
			int amount = end - begin +1;

			int dvIndex = begin -1;
			int refIndex = begin;
			for(; refIndex < end; ++refIndex)
			{
				if(arr[refIndex] < refer)
				{
					++dvIndex;
					int tmp = arr[dvIndex];
					arr[dvIndex] = arr[refIndex];
					arr[refIndex] = tmp;
				}
			}

			dvIndex += 1;
			int tmp = arr[dvIndex];
			arr[dvIndex] = arr[end];
			arr[end] = tmp;

			OutputArr("Sorting: ", arr, begin, end);
			ret = QuickSort(arr, begin, dvIndex-1);
			ret = QuickSort(arr, dvIndex+1, end);
		}

		return ret;
	}

	int InsertionSort(int *arr, int begin, int end)
	{
		int ret = 0;
		int tarIndex = begin+1;
		for(; tarIndex <= end; ++tarIndex)
		{
			int tar = arr[tarIndex];
			int i = tarIndex-1;
			for(; i >= begin; --i)
			{
				if(tar < arr[i])
					arr[i+1] = arr[i];
				else
					break;
			}
			arr[i+1] = tar;
			OutputArr("Sorting: ", arr, begin, end);
		}

		return  ret;
	}

	int Mediam(int *arr, int begin, int end, int& index)
	{
		int ret = 0;
		if(end <= begin)
		{
			index = begin;
			return ret;
		}
		const int amount = end - begin +1;
		const int part = 5;
		int newLen = amount / part;
		int rem = amount % part;
		if(rem != 0)
			newLen += 1;

		int rest = amount;
		int dvIndex = begin -1;
		for(int i = 0; i < newLen; ++i, rest -= part)
		{
			int tmpBegin = begin + i*part;
			int tmpEnd = 0;
			if(rest > part)
			{
				tmpEnd = tmpBegin + part-1;
			}
			else
			{
				tmpEnd = tmpBegin + rest-1;
			}
			//ret = QuickSort(arr, tmpBegin, tmpEnd);
			ret = InsertionSort(arr, tmpBegin, tmpEnd);
			int mdmIndex = (tmpBegin + tmpEnd) /2;

			++dvIndex;
			int tmp = arr[dvIndex];
			arr[dvIndex] = arr[mdmIndex];
			arr[mdmIndex] = tmp;
		}
		
		OutputArr("Mediam: ", arr, begin, dvIndex);
		if(newLen <= 1)
			index = dvIndex;
		else
			ret = Mediam(arr, begin, dvIndex, index);
		
		return ret;
	}

	int MediamSelect(int *arr, int begin, int end, int wanted, int& selectValue)
	{
		int ret = 0;
		if(end <= begin)
		{
			selectValue = arr[begin];
			return ret;
		}

		int mdmIndex = 0;
		ret = Mediam(arr, begin, end, mdmIndex);
		int tmp = arr[mdmIndex];
		arr[mdmIndex] = arr[end];
		arr[end] = tmp;

		int ref = arr[end];
		int dvIndex = begin -1;
		int refIndex = begin;
		for(; refIndex < end; ++refIndex)
		{
			if(arr[refIndex] < ref)
			{
				++dvIndex;
				int tmp = arr[dvIndex];
				arr[dvIndex] = arr[refIndex];
				arr[refIndex] = tmp;
			}
		}

		dvIndex += 1;
		tmp = arr[dvIndex];
		arr[dvIndex] = arr[end];
		arr[end] = tmp;
		
		int seq = dvIndex-begin+1;
		if(seq < wanted)
		{
			OutputArr("Calculating: ", arr, dvIndex+1, end);
			ret = MediamSelect(arr, dvIndex+1, end, wanted-seq, selectValue);
		}
		else if(seq > wanted)
		{
			OutputArr("Calculating: ", arr, begin, dvIndex-1);
			ret = MediamSelect(arr, begin, dvIndex-1, wanted, selectValue);
		}
		else
		{//Completed
			selectValue = arr[dvIndex];
		}

		return ret;
	}

}//namespace algrm

#endif//_MEDIAM_SELECT_HPP