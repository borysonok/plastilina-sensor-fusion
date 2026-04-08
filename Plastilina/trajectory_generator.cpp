#include "trajectory_generator.h"

std::vector<TruePathSample> TrajectoryGenerator::generateStraightLine(
    double i_duration,
    double i_dt,
    double i_vx,
    double i_vy)
{
    std::vector<TruePathSample> truePathLine;

    for (double i = 0; i <= i_duration; i += i_dt)
    {
        TruePathSample smpl;
            smpl.t = i;
            smpl.x = i_vx * i;
            smpl.y = i_vy * i;
            smpl.vx = i_vx;
            smpl.vy = i_vy;

            truePathLine.push_back(smpl);
    }

    return truePathLine;
}