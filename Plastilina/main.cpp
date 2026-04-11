#include "csv_writer.h"
#include "gps_sensor.h"
#include "measurement.h"
#include "trajectory_generator.h"

#include <vector>

int main()
{
	TrajectoryGenerator generator;

	const double duration = 10.0;

	// Time frame (delta)
	const double dt = 0.1;

	// Linear velocity
	const double vx = 2.0;
	const double vy = 1.0;

	// Straight line path
	auto linePath = generator.generateStraightLine(duration, dt, vx, vy);

	const double radius = 5.0;
	const double angularSpeed = 0.75;

	// Circular path
	auto circlePath = generator.generateCircularLine(duration, dt, radius, angularSpeed);

	// Write true data.
	saveCSV(linePath, "true_line_path.csv");
	saveCSV(circlePath, "true_circle_path.csv");

	/////////////////////////////////// GPS ////////////////////////////////////////

	GPSSensor gps(0.5);

	// Read line path from GPS.
	std::vector<Measurement> gpsLinePath;
	for (const auto& sm : linePath)
	{
		gpsLinePath.push_back(gps.measure(sm));
	}

	// Read circular path from GPS.
	std::vector<Measurement> gpsCirclePath;
	for (const auto& sm : circlePath)
	{
		gpsCirclePath.push_back(gps.measure(sm));
	}

	// Write GPS data.
	saveCSV(gpsLinePath, "gps_line_path.csv");
	saveCSV(gpsCirclePath, "gps_circle_path.csv");

	////////////////////////////////////////////////////////////////////////////////


	return 0;
}