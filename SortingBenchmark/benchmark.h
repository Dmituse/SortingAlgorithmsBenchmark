#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

#include "sorts.h"

template<typename Func>
long long measure(Func sortFunc, std::vector<int> data)
{
    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(data);
    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

void runBenchmarks(const std::vector<int>& original)
{
    std::cout << "\nРезультаты (мс):\n";

    std::cout << "std::sort:        "
        << measure([](auto& v) { std::sort(v.begin(), v.end()); }, original)
        << "\n";

    std::cout << "Bubble sort:      "
        << measure(bubbleSort, original)
        << "\n";

    std::cout << "Insertion sort:   "
        << measure(insertionSort, original)
        << "\n";

    std::cout << "Selection sort:   "
        << measure(selectionSort, original)
        << "\n";

    std::cout << "Quick sort:       "
        << measure(quickSort, original)
        << "\n";

    std::cout << "Merge sort:       "
        << measure(mergeSort, original)
        << "\n";
}
