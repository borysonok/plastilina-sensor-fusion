#include "trajectory_generator.h"

#include "true_path_sample.h"

#include <vector>

std::vector<TruePathSample> TrajectoryGenerator::generateStraightLine(
	double i_duration,
	double i_dt,
	double i_vx,
	double i_vy)
{
	std::vector<TruePathSample> truePathLine;

	for (double i = 0; i <= i_duration; i += i_dt)
	{
		TruePathSample sample;
		sample.t = i;
		sample.x = i_vx * i; // S = V * T;
		sample.y = i_vy * i;
		sample.vx = i_vx;
		sample.vy = i_vy;

		truePathLine.push_back(sample);
	}

	return truePathLine;
}