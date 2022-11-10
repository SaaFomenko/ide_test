#include <iostream>
#include <fstream>
#include "functions.h"

int main() {
	const char* in_file = { "./in.txt" };
	const char* out_file = { "./out.txt" };
  const std::string msg = "Данные были преобразованы и записаны в файл: ";
  const std::string err_msg = "Данные в файле не соответствуют алгоритму, в файле нечетное число строк";

	int row_count = 0;
	std::string row = "";

	std::ifstream fin = fileIn(in_file);
	bool check = fin.is_open();
	if (!check) return 1;

	while(std::getline(fin, row))
	{
		++row_count;
	}

	fin.clear();
	fin.seekg(0);

	int arr_count = row_count / 2;

	if (row_count%2)
	{
		std::cout << err_msg[0] << std::endl;
		fin.close();

		return 1;
	}	

	int* arr_stack[arr_count]{};
	int size_stack[arr_count]{};  

	int size = 0;

	for (int i = 0; fin >> size; ++i)
	{
		int* arr = arrInit(&fin, size);

		arr_stack[i] = arr;
		size_stack[i] = size;
	}
	
	std::ofstream fout = fileOut(out_file);
	check = fout.is_open();
	if (!check) return 1;

	for (int i = arr_count - 1; i >= 0; --i)
	{
		handlerArr(arr_stack[i], size_stack[i], &fout);
	 
		delete[] arr_stack[i];
		arr_stack[i] = nullptr;
	}

	fin.close();
	fout.close();

	std::cout << msg << out_file << std::endl;

  return 0;
}
