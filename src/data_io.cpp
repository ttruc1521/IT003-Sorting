#include "data_io.h"
#include <cstdio>
#include <stdexcept>

std::string data_path(const std::string& dir, int index) {
    return dir + "/data_" + std::to_string(index) + ".txt";
}

void write_data(const std::string& path, const std::vector<double>& a) {
    FILE* f = std::fopen(path.c_str(), "w");
    if (!f) throw std::runtime_error("Khong mo duoc file: " + path);
    for (double x : a) std::fprintf(f, "%.3f\n", x);
    std::fclose(f);
}

std::vector<double> read_data(const std::string& path) {
    FILE* f = std::fopen(path.c_str(), "r");
    if (!f) throw std::runtime_error("Khong mo duoc file: " + path);
    std::vector<double> a;
    double x;
    while (std::fscanf(f, "%lf", &x) == 1) a.push_back(x);
    std::fclose(f);
    return a;
}