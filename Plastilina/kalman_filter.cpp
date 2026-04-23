#include "kalman_filter.h"
#include "measurement.h"

KalmanFilter::KalmanFilter() : d_x(0), d_y(0), d_vx(0), d_vy(0)
{
}

void KalmanFilter::init(double i_x, double i_y)
{
	d_x = i_x;
	d_y = i_y;
}

void KalmanFilter::predict(double i_dt)
{
	d_x += d_vx * i_dt;
	d_y += d_vy * i_dt;
}

void KalmanFilter::update(const Measurement& i_m, double i_dt)
{
	const double alpha = 0.5;

	// TODO: temporary, remove once a matrix solution added
	double newX = alpha * i_m.x + (1 - alpha) * d_x;
	double newY = alpha * i_m.y + (1 - alpha) * d_y;

	d_vx = (newX - d_x) / i_dt;
	d_vy = (newY - d_y) / i_dt;

	d_x = newX;
	d_y = newY;
}

double KalmanFilter::getX() const { return d_x; }

double KalmanFilter::getY() const { return d_y; }