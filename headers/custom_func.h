//
// Created by Tung Chin Chen on 2021/7/3.
//

#ifndef CAL_WORK_HOURS_CPP_CUSTOM_FUNC_H
#define CAL_WORK_HOURS_CPP_CUSTOM_FUNC_H

#include "./common_headers.h"

std::vector<std::string> split(std::string &line, char delimeter);
int calculateOverWorkedHoursInMinutes(std::string leaveTime, std::string actualLeaveTime);
std::string calDiffAndReturnNewTime(std::string time1, std::string time2, std::string offsetEndHours);

#endif //CAL_WORK_HOURS_CPP_CUSTOM_FUNC_H
