
#include "data_gen.h"
#include "data_io.h"
#include <iostream>
#include <string>
#include <filesystem>

int main(int argc, char** argv) {
    std::string dir = (argc > 1) ? argv[1] : "data";
    size_t n = (argc > 2) ? std::stoull(argv[2]) : 1000000;
    std::filesystem::create_directories(dir);

    for (int i = 1; i <= 10; ++i) {
        auto a = make_dataset(i, n, 2026);
        write_data(data_path(dir, i), a);
        std::cout << "Da tao " << data_path(dir, i) << " (" << a.size() << " phan tu)\n";
    }
}