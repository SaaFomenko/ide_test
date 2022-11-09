#include <fstream>

std::ifstream fileIn(const char* path);
std::ofstream fileOut(const char* path);
int* arrInit(std::ifstream* fin, int size);
void handlerArr(int* arr, int size, std::ofstream* fout, int step = 1);
