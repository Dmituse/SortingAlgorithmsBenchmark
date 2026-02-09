#pragma once
#include <vector>
#include <algorithm>

// Пузырьковая сортировка
void bubbleSort(std::vector<int>& arr)
{
    for (size_t i = 0; i < arr.size(); ++i)
        for (size_t j = 0; j + 1 < arr.size() - i; ++j)
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
}

// Сортировка вставками
void insertionSort(std::vector<int>& arr)
{
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        size_t j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = key;
    }
}

// Сортировка выбором
void selectionSort(std::vector<int>& arr)
{
    for (size_t i = 0; i < arr.size(); ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

// Быстрая сортировка (quick sort)
void quickSortImpl(std::vector<int>& arr, int left, int right)
{
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++; j--;
        }
    }

    if (left < j) quickSortImpl(arr, left, j);
    if (i < right) quickSortImpl(arr, i, right);
}

void quickSort(std::vector<int>& arr)
{
    if (!arr.empty())
        quickSortImpl(arr, 0, static_cast<int>(arr.size()) - 1);
}

// Сортировка слиянием (merge sort)
void merge(std::vector<int>& arr, int left, int mid, int right)
{
    std::vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); ++k)
        arr[left + k] = temp[k];
}

void mergeSortImpl(std::vector<int>& arr, int left, int right)
{
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSortImpl(arr, left, mid);
    mergeSortImpl(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void mergeSort(std::vector<int>& arr)
{
    if (!arr.empty())
        mergeSortImpl(arr, 0, static_cast<int>(arr.size()) - 1);
}
