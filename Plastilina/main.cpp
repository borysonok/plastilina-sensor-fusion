#include "trajectory_generator.h"
#include "csv_writer.h"

int main()
{
    TrajectoryGenerator generator;

    auto path = generator.generateStraightLine(/*duration*/ 10.0, /*dt*/ 0.1,/*vx*/2.0,/*vy*/1.0);

    saveCSV(path, "true_line_path.csv");

    return 0;
}