#pragma once

#include "sensor_base.h"

#include "measurement.h"
#include "true_path_sample.h"

#include <random>

class GPSSensor : public SensorBase
{
public:
	GPSSensor(double i_sigma);

	Measurement measure(const TruePathSample& i_path) override;

private:
	std::mt19937 d_gen;
	std::normal_distribution<double> d_noise;
};
