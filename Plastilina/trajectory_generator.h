#pragma once

#include <vector>
#include "true_path_sample.h"

class TrajectoryGenerator {
public:
	std::vector<TruePathSample> generateStraightLine(
		double i_duration, double i_dt, double i_vx, double i_vy);
};