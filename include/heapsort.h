#pragma once
#include <vector>
#include <utility>
#include <cstddef>

inline void heapify(std::vector<double>& a, size_t n, size_t i) {
    while (true) {
        size_t largest = i, l = 2 * i + 1, r = 2 * i + 2;
        if (l < n && a[l] > a[largest]) largest = l;
        if (r < n && a[r] > a[largest]) largest = r;
        if (largest == i) return;
        std::swap(a[i], a[largest]);
        i = largest;
    }
}

inline void heapsort(std::vector<double>& a) {
    size_t n = a.size();
    if (n < 2) return;
    for (size_t i = n / 2; i-- > 0;) heapify(a, n, i);
    for (size_t end = n - 1; end > 0; --end) {
        std::swap(a[0], a[end]);
        heapify(a, end, 0);
    }
}