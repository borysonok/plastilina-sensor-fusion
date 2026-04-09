#include "trajectory_generator.h"

#include "true_path_sample.h"

#include <cmath>
#include <vector>

std::vector<TruePathSample> TrajectoryGenerator::generateStraightLine(
	double i_duration,
	double i_dt,
	double i_vx,
	double i_vy)
{
	std::vector<TruePathSample> line;
	for (double i = 0; i <= i_duration; i += i_dt)
	{
		TruePathSample sample;
		sample.t = i;
		sample.x = i_vx * i; // S = V * T;
		sample.y = i_vy * i;
		sample.vx = i_vx;
		sample.vy = i_vy;

		line.push_back(sample);
	}

	return line;
}

std::vector<TruePathSample> TrajectoryGenerator::generateCircularLine(
	double i_duration, double i_dt, double i_radius, double i_angularSpeed)
{
	std::vector<TruePathSample> circle;
	for (double i = 0; i <= i_duration; i += i_dt)
	{
		TruePathSample sample;
		sample.t = i;
		sample.x = i_radius * cos(i_angularSpeed * i);
		sample.y = i_radius * sin(i_angularSpeed * i);
		sample.vx = -i_radius * i_angularSpeed * sin(i_angularSpeed * i); // w = rot_angle / time; v = radius * w;
		sample.vy = i_radius * i_angularSpeed * cos(i_angularSpeed * i);

		circle.push_back(sample);
	}

	return circle;
}