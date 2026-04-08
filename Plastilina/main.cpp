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

	auto path = generator.generateStraightLine(duration, dt, vx, vy);

	saveCSV(path, "true_line_path.csv");

	return 0;
}