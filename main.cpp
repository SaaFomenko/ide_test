#include <iostream>
#include <fstream>
#include "functions.h"

int main() {
	const char* in_file = { "./in.txt" };
	const char* out_file = { "./out.txt" };
  const std::string msg = "Данные были преобразованы и записаны в файл: ";
	int** arr_stack[2]{};
	int size_stack[2]{};  
	int i = 0;

	int size = 0;

	std::ifstream fin = fileIn(in_file);
	bool check = fin.is_open();
	if (!check) return 1;
	
	std::ofstream fout = fileOut(out_file);
	check = fout.is_open();
	if (!check) return 1;

	while (fin >> size)
	{
		int* arr = arrInit(&fin, size);

		arr_stack[i] = arr;
		size_stack[i] = size;
		++i;
	}

	for (int j = i - 1; j >= 0; --j)
	{
		handlerArr(arr_stack[j], size_stack[j], &fout);
 
		delete[] arr;
		arr = nullptr;

	}

	fin.close();
	fout.close();

	std::cout << msg << out_file << std::endl;

  return 0;
}
