#pragma once

#include"measurement.h"
#include"true_path_sample.h"


class SensorBase
{
public:
	virtual ~SensorBase() = default;

	virtual Measurement measure(const TruePathSample& i_path) = 0;
};