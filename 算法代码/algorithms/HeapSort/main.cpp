#include "HeapSort.hpp"
#include <random>

int main(int argc, char *argv[])
{	
	int arr[] = {rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand()};	
	algrm::OutputArr(std::string("Init array: "), arr, sizeof(arr)/sizeof(int));

	algrm::HeapSort(arr, 0, sizeof(arr)/sizeof(int)-1);

	algrm::OutputArr(std::string("End alg: "), arr, sizeof(arr)/sizeof(int));

	getchar();
	return 0;
}
