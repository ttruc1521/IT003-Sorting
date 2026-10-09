#pragma once
#include <string>
#include <vector>

void write_data(const std::string& path, const std::vector<double>& a);
std::vector<double> read_data(const std::string& path);
std::string data_path(const std::string& dir, int index);  