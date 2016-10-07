#include "MediamSelect.hpp"
#include <random>

int main(int argc, char *argv[])
{
	//srand(123);
	int arr[] = {rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand()};
	int begin = 0, end = sizeof(arr)/sizeof(int)-1;
	algrm::OutputArr(std::string("Init array: "), arr, begin, end);

	int index = 5;
	int value = 0;
	algrm::MediamSelect(arr, begin, end, index, value);

	printf("End alg: WantedIndex(%d), SelectedValue(%d)", index, value);

	getchar();
	return 0;
}
