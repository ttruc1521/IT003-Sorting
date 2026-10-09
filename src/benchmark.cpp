
#include "data_io.h"
#include "quicksort.h"
#include "heapsort.h"
#include "mergesort.h"
#include "stdsort.h"
#include <algorithm>
#include <chrono>
#include <cstdio>
#include <functional>
#include <string>
#include <vector>

struct Algo {
    const char* name;
    std::function<void(std::vector<double>&)> fn;
};

static double time_ms(const Algo& algo, std::vector<double>& a) {
    auto t0 = std::chrono::steady_clock::now();
    algo.fn(a);
    auto t1 = std::chrono::steady_clock::now();
    return std::chrono::duration<double, std::milli>(t1 - t0).count();
}

int main(int argc, char** argv) {
    std::string dir = (argc > 1) ? argv[1] : "data";
    std::string out = (argc > 2) ? argv[2] : "results.csv";

    std::vector<Algo> algos = {
        {"Quicksort", quicksort}, {"Heapsort", heapsort},
        {"Mergesort", mergesort}, {"sort (C++)", std_sort}};
    const int NUM = 10;
    std::vector<std::vector<double>> res(NUM, std::vector<double>(algos.size()));

    for (int i = 1; i <= NUM; ++i) {
        auto original = read_data(data_path(dir, i));
        auto expected = original;
        std::sort(expected.begin(), expected.end());

        for (size_t k = 0; k < algos.size(); ++k) {
            auto a = original;                       // mỗi thuật toán dùng bản sao riêng
            double ms = time_ms(algos[k], a);
            bool ok = (a == expected);               // kiểm tra kết quả đúng
            res[i - 1][k] = ms;
            std::printf("Data %2d | %-11s | %9.2f ms | %s\n", i, algos[k].name, ms,
                        ok ? "OK" : "SAI KET QUA!");
        }
    }

    FILE* f = std::fopen(out.c_str(), "w");
    std::fprintf(f, "Data");
    for (auto& al : algos) std::fprintf(f, ",%s", al.name);
    std::fprintf(f, "\n");
    for (int i = 0; i < NUM; ++i) {
        std::fprintf(f, "%d", i + 1);
        for (double v : res[i]) std::fprintf(f, ",%.2f", v);
        std::fprintf(f, "\n");
    }
    std::fprintf(f, "Trung binh");
    std::printf("\nTrung binh: ");
    for (size_t k = 0; k < algos.size(); ++k) {
        double s = 0;
        for (int i = 0; i < NUM; ++i) s += res[i][k];
        std::fprintf(f, ",%.2f", s / NUM);
        std::printf("%s=%.2f  ", algos[k].name, s / NUM);
    }
    std::fprintf(f, "\n");
    std::printf("\n");
    std::fclose(f);
}