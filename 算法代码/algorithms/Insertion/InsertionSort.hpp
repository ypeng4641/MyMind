#ifndef _INSERTION_SORT_HPP
#define _INSERTION_SORT_HPP

#include <stdio.h>
#include <string>
namespace algrm
{
#ifndef OUTPUT_ARR
#define OUTPUT_ARR
	std::string OutputArr(std::string info, int* arr, int arrLen)
	{
		std::string out(info);
		char buf[16];
		for(int i = 0; i < arrLen; ++i)
		{
			sprintf(buf, "%d ", arr[i]);
			out.append(buf);
		}
		puts(out.c_str());
		return out;
	}
#endif

	int InsertionSort(int* arr, int arrLen)
	{
		int ret = 0;
		for(int j = 1; j < arrLen; ++j)
		{
			int nxtTar = arr[j];
			int i = j - 1;
			for(; (arr[i] > nxtTar) && (i >= 0); --i)
			{
				arr[i+1] = arr[i];
			}
			arr[i+1] = nxtTar;
			OutputArr(std::string("Sorting: "), arr, arrLen);
		}
		return ret;
	}

}//namespace algrm

#endif//_INSERTION_SORT_HPP