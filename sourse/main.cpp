#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include "read_sort_input.cpp"

int main(int argc, char* argv[])
{
	
	std::ofstream os(argv[1]);
	for (int i = 0; i < gegabyte; ++i) {
		os << std::to_string(rand() % INT32_MAX/2)<<'\n';
	}
	std::vector<int> arr;
	std::ifstream fs;
	fs.open(argv[1]);
	while (!fs.eof())
	{
		int size = snif::read_from_file(fs, arr);
		snif::quick_sort(arr, 0, size);
		snif::input_in_file(arr, size);
		arr.clear();
	}
	snif::merge(argv[2]);
	fs.close();
}
