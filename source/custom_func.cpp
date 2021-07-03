//
// Created by Tung Chin Chen on 2021/7/3.
//

#include "../headers/common_headers.h"
#include "../headers/custom_func.h"

std::vector<std::string> split(std::string &line, char delimeter)
{
    std::vector<std::string> elems;
    std::stringstream ss(line);
    std::string s;
    while(std::getline(ss, s, delimeter))
        elems.emplace_back(s);
    return elems;
}

int calculateOverWorkedHoursInMinutes(std::string leaveTime, std::string actualLeaveTime)
{
    std::vector<std::string> data1 = split(leaveTime, ':');
    std::vector<std::string> data2 = split(actualLeaveTime, ':');
    int leaveTimeHour = std::stoi(data1.at(0));
    int leaveTimeMin = std::stoi(data1.at(1));
    int actualLeaveTimeHour = std::stoi(data2.at(0));
    int actualLeaveTimeMin = std::stoi(data2.at(1));

    int calHours = actualLeaveTimeHour - leaveTimeHour;
    int calMins = actualLeaveTimeMin - leaveTimeMin;
    int totalMins = 0;
    totalMins += calHours * 60;
    totalMins += calMins;
    return totalMins;
}

std::string calDiffAndReturnNewTime(std::string time1, std::string time2, std::string offsetEndHours)
{
    std::vector<std::string> data1 = split(time1, ':');
    std::vector<std::string> data2 = split(time2, ':');
    std::vector<std::string> data3 = split(offsetEndHours, ':');
    int startHour = std::stoi(data1.at(0));
    int startMin = std::stoi(data1.at(1));
    int endHour = std::stoi(data2.at(0));
    int endMin = std::stoi(data2.at(1));
    int offsetHr = std::stoi(data3.at(0));
    int offsetMin = std::stoi(data3.at(1));

    int hourDiff = endHour - startHour;
    int minDiff = endMin - startMin;

    offsetHr += hourDiff;
    offsetMin += minDiff;

    if(offsetMin > 60)
    {
        offsetHr += offsetMin / 60;
        offsetMin %= 60;
    }

    return std::to_string(offsetHr) + ":" + (offsetMin < 10 ? "0" + std::to_string(offsetMin) : std::to_string(offsetMin));
}