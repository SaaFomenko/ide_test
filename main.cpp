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

void handlerArr(int* arr, const int* size, std::ofstream* fout)
{
	std::cout << *size << std::endl;
	*fout << *size << "\n";

	int temp = arr[0];
	arr[0] = arr[*size - 1];
	arr[*size - 1] = temp;

	for(int i = 0; i < *size; ++i)
	{
		std::cout << arr[i] << " ";
		*fout << arr[i] << " ";
	}

	std::cout << std::endl;
	*fout << "\n";
}

int main() {
	const char* in_file = { "./in.txt" };
	const char* out_file = { "./out.txt" };
  const std::string msg[] = {
    "Не удалось отрыть файл, проверьте права доступа и его наличие по адресу: ",
    "Не удалось создаь файл, проверьте права доступа по адресу: ",
		"Данные были преобразованы и записаны в файл: ",
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

	fin.close();

	std::ofstream fout (out_file);

	check = fout.is_open();

	check = checkCondition(&check, msg[1], out_file);
	if (check) return 1;

	handlerArr(arr2, &y, &fout);
	handlerArr(arr1, &x, &fout);

	fout.close();

	std::cout << msg[2] << out_file << std::endl;
 
	delete[] arr1;
	arr1 = nullptr;
	delete[] arr2;
	arr2 = nullptr;

  return 0;
}
