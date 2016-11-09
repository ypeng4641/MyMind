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

	void Merge(int arr[], int begin, int mid, int end)
	{
		//Make new array
		int amn = end - begin +1;
		int* arrTmp = new int[amn];
		memcpy(arrTmp, arr+begin, sizeof(int)*amn);

		//Merge into original array
		for(int k = begin, i = 0, j = mid+1-begin; k <= end; ++k)
		{
			if(i > mid-begin)
			{
				arr[k] = arrTmp[j];
				++j;
			}
			else if(j > end-begin)
			{
				arr[k] = arrTmp[i];
				++i;
			}
			else
			{
				arr[k] = (arrTmp[i] < arrTmp[j])?(arrTmp[i++]):(arrTmp[j++]);
			}
		}
		
		delete[] arrTmp; arrTmp = NULL;
	}

	int MergeSort(int* arr, int begin, int end)
	{
		int ret = 0;
		if(begin < end)
		{
			//Divide into sub array
			int mid = (begin + end) / 2;	//calculate the middle index
			MergeSort(arr, begin, mid);
			MergeSort(arr, mid+1, end);

			Merge(arr, begin, mid, end);
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