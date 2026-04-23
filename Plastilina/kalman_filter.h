#pragma once
#include "measurement.h"

class KalmanFilter
{
public:
	KalmanFilter();

	void init(double i_x, double i_y);
	void predict(double i_dt);
	void update(const Measurement& i_m, double i_dt);

	double getX() const;
	double getY() const;

private:
	double d_x, d_y, d_vx, d_vy;
};