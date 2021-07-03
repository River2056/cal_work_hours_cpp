//
// Created by Tung Chin Chen on 2021/7/3.
//

#include "../headers/common_headers.h"
#include "../headers/custom_func.h"

std::vector<std::string> workHours()
{
    std::vector<std::string> workHoursList;
    workHoursList.emplace_back("0601,09:16,19:38");
    workHoursList.emplace_back("0602,09:01,18:30");
    workHoursList.emplace_back("0603,09:20,20:30");
    workHoursList.emplace_back("0604,13:20,18:45,Y");
    return workHoursList;
}

int main()
{
//    std::vector<std::string> workHoursList = workHours();
//    std::vector<std::string>::iterator it;
//    for(it = workHoursList.begin(); it != workHoursList.end(); it++)
//    {
//        std::vector<std::string> data = split(*it, ',');
//
//    }

    std::string time = calDiffAndReturnNewTime("09:00", "11:56", "18:30");
    int t = calculateOverWorkedHoursInMinutes("13:50", "18:50");

//    std::cout << time << std::endl;
    std::cout << "overWorked hours in minutes: " << t << std::endl;
    std::cout << "overWorked hours: " << t / 60 << std::endl;
    return 0;
}