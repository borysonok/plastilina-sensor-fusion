#pragma once

#include "measurement.h"
#include "true_path_sample.h"

#include <string>
#include <vector>

void saveCSV(const std::vector<TruePathSample>& i_data, const std::string& i_filename);

void saveCSV(const std::vector<Measurement>& i_gps, const std::string& i_filename);