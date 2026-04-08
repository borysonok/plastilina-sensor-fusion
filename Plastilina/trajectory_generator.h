#pragma once

#include "true_path_sample.h"

#include <vector>

class TrajectoryGenerator {
public:
	std::vector<TruePathSample> generateStraightLine(
		double i_duration, double i_dt, double i_vx, double i_vy);
};