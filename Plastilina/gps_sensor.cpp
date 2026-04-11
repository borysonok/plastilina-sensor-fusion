#include "gps_sensor.h"

#include "measurement.h"
#include "true_path_sample.h"

#include <random>


GPSSensor::GPSSensor(double i_sigma) : d_gen(std::random_device{}()), d_noise(0.0, i_sigma)
{

}

Measurement GPSSensor::measure(const TruePathSample& i_smpl)
{
	Measurement res;

	res.t = i_smpl.t;
	res.x = i_smpl.x + d_noise(d_gen);
	res.y = i_smpl.y + d_noise(d_gen);

	return res;
}