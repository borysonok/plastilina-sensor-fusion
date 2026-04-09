#include "csv_writer.h"
#include "trajectory_generator.h"

int main()
{
	TrajectoryGenerator generator;

	const double duration = 10.0;

	// delta t
	const double dt = 0.1;

	// linear velocity
	const double vx = 2.0;
	const double vy = 1.0;

	auto linePath = generator.generateStraightLine(duration, dt, vx, vy);

	const double radius = 5.0;
	const double angularSpeed = 0.75;

	auto circlePath = generator.generateCircularLine(duration, dt, radius, angularSpeed);

	saveCSV(linePath, "true_line_path.csv");
	saveCSV(circlePath, "true_circle_path.csv");

	return 0;
}