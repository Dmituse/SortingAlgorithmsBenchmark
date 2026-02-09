#pragma once
#include <vector>
#include <algorithm>
#include <random>

std::vector<int> generateArray(std::size_t size, int type)
{
    std::vector<int> data(size);

    for (std::size_t i = 0; i < size; ++i)
        data[i] = static_cast<int>(i);

    std::random_device rd;
    std::mt19937 gen(rd());

    if (type == 1) {
        std::shuffle(data.begin(), data.end(), gen);
    }
    else if (type == 3) {
        std::reverse(data.begin(), data.end());
    }
    else if (type == 4) {
        std::shuffle(data.begin(), data.end(), gen);
        std::sort(data.begin(), data.begin() + size * 0.9);
    }

    return data;
}
