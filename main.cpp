#include <iostream>
#include <fstream>

bool checkCondition(
		const bool* check,
		const std::string msg,
		const char* path
		)
{

	bool flag = false;
	if (!*check)
	{
		std::cout << msg << path << std::endl;
	  flag = true;	
	}

	return flag;
}

int* arrInit(
		const int* size,
		std::ifstream* fin
		)
{
  int* arr = new int[*size];
	
	for (int i = 0; i < *size; ++i)
	{
		*fin >> arr[i];
	}
	
	return arr;
}

void handlerArr(int* arr, const int* size)
{
	std::cout << *size << std::endl;

	for(int i = 0; i < *size; ++i)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

int main() {
	const char* in_file = { "./in.txt" };
	const char* out_file = { "./in.txt" };
  const std::string msg[] = {
    "Не удалось отрыть файл, проверьте права доступа и его наличие по адресу: ",
    "Не удалось создаь файл, проверьте права доступа по адресу: ",
  };

	int x = 0;
	int y = 0;

	std::ifstream fin (in_file);

	bool check = fin.is_open();

	check = checkCondition(&check, msg[0], in_file);
	if (check) return 1;
	
	fin >> x;
	int* arr1 = arrInit(&x, &fin);

	fin >> y;
	int* arr2 = arrInit(&y, &fin);

	handlerArr(arr1, &x);
	handlerArr(arr2, &y);
 
	delete[] arr1;
	arr1 = nullptr;
	delete[] arr2;
	arr2 = nullptr;

  return 0;
}
