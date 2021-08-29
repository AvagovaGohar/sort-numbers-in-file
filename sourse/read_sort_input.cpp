#ifndef MY_SORTING_CODE
#define MY_SORTING_CODE

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

namespace snif //sort numbers in file
{
  const int gegabyte = 268435356; // one gegabype
  const int size_of_one_arr = 52000000; // nearly 200 MB
  int index = 0;

  int read_from_file(std::ifstream & fs, std::vector<int>& arr) {
    int count = 0;
    std::string tmp;
    while (count<size_of_one_arr && !fs.eof())
    {
      std::stringstream stream;
      fs >> tmp;
      stream << tmp;
      int num;
      stream >> num;
      arr.push_back(num);
      ++count;
    }
    return count;
  }
  void input_in_file(std::vector<int>& arr, int size) {
    std::ofstream os;
    os.open(std::to_string(index) + "_file_name.txt");
    for (int i = 0; i < size; i++)
    {
      os << arr[i] << '\n';
    }
    os.close();
    ++index;
  }
  int quick_pivot(std::vector<int>& arr, int s, int e) {
    int i = s, e2 = e - 1;
    for (int j = s; j < e; ++j) {
      if (arr[e2] > arr[j]) {
        std::swap(arr[i], arr[j]);
        ++i;
      }
    }
    std::swap(arr[i], arr[e2]);
    return i;
  }
  void quick_sort(std::vector<int>& arr, int s, int e) {
    if (s < e) {
      int pivot = quick_pivot(arr, s, e);
      quick_sort(arr, s, pivot);
      quick_sort(arr, pivot + 1, e);
    }
  }
  void merge(char* where) {
    std::vector<std::ifstream>files;
    files.reserve(index);
    std::vector<int>numbers;
    for (int i = 0; i < index; i++)
    {
      files.push_back(std::ifstream(std::to_string(i) + "_tmp_file.txt"));
    }
    std::ofstream sorted;
    sorted.open(where);
    int count = index;
    while (count!=0)
    {
      int min = INT32_MAX;
      int ind = 0;
      for (int i = 0; i < index; i++)
      {
        if (!files[i].eof())
        {
          std::string tmp;
          files[i] >> tmp;
          std::stringstream ss(tmp);
          int num;
          ss >> num;
          if (num<min)
          {
            min = num;
            ind = i;
          }
        }
        else {
          --count;
        }
      }
      sorted << min << '\n';
      std::string tmp;
      std::getline(files[ind], tmp);
    }
    for (int i = 0; i < index; i++)
    {
      files[i].close();
    }
    sorted.close();
  }
}
#endif MY_SORTING_CODE
