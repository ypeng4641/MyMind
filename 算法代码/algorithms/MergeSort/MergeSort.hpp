#ifndef _MERGE_SORT_HPP
#define _MERGE_SORT_HPP

#include <stdio.h>
#include <string>
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

	int MergeSort(int* arr, int begin, int end)
	{
		int ret = 0;
		if(begin < end)
		{
			//Divide into sub array
			int amount = end - begin +1;
			int mid = (begin + end) / 2;	//calculate the middle index
			MergeSort(arr, begin, mid);
			MergeSort(arr, mid+1, end);

			//Make new array
			int bn1 = begin, bn2 = mid+1;
			int en1 = mid, en2 = end;
			int amn1 = en1 - bn1 +1, amn2 = en2 - bn2 +1;
			int* arr1 = new int[amn1], *arr2 = new int[amn2];
			for(int i = 0; i < amn1; ++i)
			{
				arr1[i] = arr[bn1 + i];
			}
			for(int i = 0; i < amn2; ++i)
			{
				arr2[i] = arr[bn2 + i];
			}

			//Merge into original array
			for(int k = begin, i = 0, j = 0; k <= end; ++k)
			{
				if(i < amn1)
				{
					if(j < amn2)
					{
						if(arr1[i] < arr2[j])
						{
							arr[k] = arr1[i];
							++i;
						}
						else
						{
							arr[k] = arr2[j];
							++j;
						}
					}
					else
					{//j out of range
						arr[k] = arr1[i];
						++i;
					}
				}
				else
				{//i out of range
					if(j < amn2)
					{
						arr[k] = arr2[j];
						++j;
					}
					else
					{//j out of range
						ret = -20160703;
					}
				}
			}
			
			delete[] arr1; arr1 = NULL;
			delete[] arr2; arr2 = NULL;
			OutputArr(std::string("Sorting: "), arr, begin, end);
		}
		else
		{
			//completed
		}

		return ret;
	}

}//algrm

#endif //_MERGE_SORT_HPP