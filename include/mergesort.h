#pragma once
#include <vector>
#include <cstddef>

inline void mergesort_impl(std::vector<double>& a, std::vector<double>& tmp,
                           size_t lo, size_t hi) {      // sắp xếp đoạn [lo, hi)
    if (hi - lo < 2) return;
    size_t mid = lo + (hi - lo) / 2;
    mergesort_impl(a, tmp, lo, mid);
    mergesort_impl(a, tmp, mid, hi);

    size_t i = lo, j = mid, k = lo;
    while (i < mid && j < hi) tmp[k++] = (a[j] < a[i]) ? a[j++] : a[i++];
    while (i < mid) tmp[k++] = a[i++];
    while (j < hi)  tmp[k++] = a[j++];
    for (k = lo; k < hi; ++k) a[k] = tmp[k];
}

inline void mergesort(std::vector<double>& a) {
    std::vector<double> tmp(a.size());
    mergesort_impl(a, tmp, 0, a.size());
}