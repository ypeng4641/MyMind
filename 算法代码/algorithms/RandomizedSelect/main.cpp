#include "RandomizedSelect.hpp"
#include <random>

int main(int argc, char *argv[])
{
	int arr[] = {rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand()};
	int begin = 2, end = sizeof(arr)/sizeof(int)-1;
	algrm::OutputArr(std::string("Init array: "), arr, begin, end);

	int index = 5;
	int value = 0;
	algrm::RandomizedSelect(arr, begin, end, index, value);

	printf("End alg: WantedIndex(%d), SelectedValue(%d)", index, value);

	getchar();
	return 0;
}
