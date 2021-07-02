#include "headers/common_headers.h"

#include "source/parse_time.cpp"

static std::string month = "06";
static std::string workStartHours = "09:00";
static std::string workEndHours = "18:30";

std::vector<std::string> split(std::string &line, char delimeter)
{
    std::vector<std::string> elems;
    std::stringstream ss(line);
    std::string s;
    while(std::getline(ss, s, delimeter))
        elems.emplace_back(s);
    return elems;
}

std::vector<std::string> workHours()
{
    std::vector<std::string> workHoursList;
    workHoursList.emplace_back("0601, 09:16, 19:38");
    workHoursList.emplace_back("0602, 09:01, 18:30");
    workHoursList.emplace_back("0603, 09:20, 20:30");
    return workHoursList;
}

int main()
{
    std::vector<std::string> workHoursList = workHours();
    std::vector<std::string>::iterator it;
    for(it = workHoursList.begin(); it != workHoursList.end(); it++)
    {
         std::vector<std::string> data = split(*it, ',');

         // substr first argument and parse into month, date
         std::string day = data.at(0);
         int m = std::stoi(day.substr(0, 2));
         int date = std::stoi(day.substr(2));

         std::istringstream workStart(workStartHours);
         struct std::tm workStartTm;
         std::istringstream actualArrive(data.at(1));
         struct std::tm actualArriveTm;
         workStart >> std::get_time(&workStartTm, "%H:%M");
         actualArrive >> std::get_time(&actualArriveTm, "%H:%M");

         time_t worktime = mktime(&workStartTm);
         time_t actualtime = mktime(&actualArriveTm);

         std::cout << workStartTm.tm_hour << std::endl;
         std::cout << workStartTm.tm_min << std::endl;
         std::cout << worktime << std::endl;

         std::cout << actualArriveTm.tm_hour << std::endl;
         std::cout << actualArriveTm.tm_min << std::endl;
         std::cout << actualtime << std::endl;
    }
    return 0;
}
