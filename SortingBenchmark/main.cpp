#include <iostream>
#include <vector>
#include <string>

#include "generators.h"
#include "benchmark.h"

int main()
{
    std::size_t size;
    int dataType;

    std::cout << "Введите размер массива: ";
    std::cin >> size;

    std::cout << "Выберите тип данных:\n";
    std::cout << "1 - случайные\n";
    std::cout << "2 - отсортированные\n";
    std::cout << "3 - обратно отсортированные\n";
    std::cout << "4 - почти отсортированные\n";
    std::cin >> dataType;

    std::vector<int> data = generateArray(size, dataType);

    std::cout << "\nРезультаты (мкс):\n";
    runBenchmarks(data);

    std::cout << "\nНажмите Enter для выхода...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}