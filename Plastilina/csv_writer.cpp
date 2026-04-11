#include "csv_writer.h"

#include "measurement.h"
#include "true_path_sample.h"

#include <fstream>
#include <string>
#include <vector>

void saveCSV(const std::vector<TruePathSample>& i_data, const std::string& i_filename)
{
	std::ofstream file(i_filename);
	file << "t,x,y,vx,vy\n";
	for (const auto& s : i_data)
	{
		file << s.t << ","
			<< s.x << ","
			<< s.y << ","
			<< s.vx << ","
			<< s.vy << "\n";
	}
}

void saveCSV(const std::vector<Measurement>& i_gps, const std::string& i_filename)
{
	std::ofstream file(i_filename);
	file << "t,x,y\n";
	for (const auto& s : i_gps)
	{
		file << s.t << ","
			<< s.x << ","
			<< s.y << "\n";
	}
}