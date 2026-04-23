#include "csv_writer.h"
#include "gps_sensor.h"
#include "kalman_filter.h"
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

	//////////////////////////////////// KF ////////////////////////////////////////

	// Line KF
	KalmanFilter lineKF;
	lineKF.init(gpsLinePath[0].x, gpsLinePath[0].y);

	std::vector<Measurement> lineEstimates;
	for (size_t i = 1; i < gpsLinePath.size(); ++i)
	{
		double dt = gpsLinePath[i].t - gpsLinePath[i - 1].t;

		lineKF.predict(dt);
		lineKF.update(gpsLinePath[i], dt);

		Measurement est;
		est.t = gpsLinePath[i].t;
		est.x = lineKF.getX();
		est.y = lineKF.getY();

		lineEstimates.push_back(est);
	}

	// Circle KF
	KalmanFilter circleKF;
	circleKF.init(gpsCirclePath[0].x, gpsCirclePath[0].y);

	std::vector<Measurement> circleEstimates;
	for (size_t i = 1; i < gpsCirclePath.size(); ++i)
	{
		double dt = gpsCirclePath[i].t - gpsCirclePath[i - 1].t;

		circleKF.predict(dt);
		circleKF.update(gpsCirclePath[i], dt);

		Measurement est;
		est.t = gpsCirclePath[i].t;
		est.x = circleKF.getX();
		est.y = circleKF.getY();

		circleEstimates.push_back(est);
	}

	// Write KF data.
	saveCSV(lineEstimates, "gps_line_KF_path.csv");
	saveCSV(circleEstimates, "gps_circle_KF_path.csv");

	////////////////////////////////////////////////////////////////////////////////

	return 0;
}