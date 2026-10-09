#include "data_gen.h"
#include <algorithm>
#include <functional>
#include <random>
#include <cmath>

std::vector<double> make_dataset(int index, size_t n, unsigned seed) {
    std::mt19937_64 rng(seed + index);
    std::uniform_real_distribution<double> dist(0.0, 1000000.0);

    std::vector<double> a(n);
    for (auto& x : a) x = std::round(dist(rng) * 1000.0) / 1000.0;  // 3 chữ số thập phân

    if (index == 1) std::sort(a.begin(), a.end());                         // tăng dần
    else if (index == 2) std::sort(a.begin(), a.end(), std::greater<>());  // giảm dần
    return a;                                                              // còn lại: ngẫu nhiên
}