#include "csv_writer.h"

#include <fstream>

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