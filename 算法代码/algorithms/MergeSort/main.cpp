#include "MergeSort.hpp"
#include <random>

int main(int argc, char* argv[])
{
	int arr[] = {rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand()};	
	algrm::OutputArr(std::string("Init array: "), arr, 0, sizeof(arr)/sizeof(int)-1);

	algrm::MergeSort(arr, 0, sizeof(arr)/sizeof(int)-1);

	algrm::OutputArr(std::string("End alg: "), arr, 0, sizeof(arr)/sizeof(int)-1);

	getchar();
	return 0;
}