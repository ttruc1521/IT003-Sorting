#pragma once
#include <vector>
#include <utility>

inline void quicksort_impl(std::vector<double>& a, long lo, long hi) {
    while (lo < hi) {
        long mid = lo + (hi - lo) / 2;
        if (a[mid] < a[lo]) std::swap(a[mid], a[lo]);
        if (a[hi] < a[lo]) std::swap(a[hi], a[lo]);
        if (a[hi] < a[mid]) std::swap(a[hi], a[mid]);
        double pivot = a[mid];

        long i = lo, j = hi;
        while (i <= j) {
            while (a[i] < pivot) ++i;
            while (a[j] > pivot) --j;
            if (i <= j) { std::swap(a[i], a[j]); ++i; --j; }
        }
        if (j - lo < hi - i) { quicksort_impl(a, lo, j); lo = i; }
        else                 { quicksort_impl(a, i, hi); hi = j; }
    }
}

inline void quicksort(std::vector<double>& a) {
    if (a.size() > 1) quicksort_impl(a, 0, static_cast<long>(a.size()) - 1);
}