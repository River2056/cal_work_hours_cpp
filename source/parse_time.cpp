#include "../headers/common_headers.h"

void parse_time_demo()
{
    // parse time demo using get_time
    struct std::tm tm = {};
    std::istringstream ss("2021-07-02 09:00");
    ss.imbue(std::locale("zh_CN.utf-8"));
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M");

    std::cout << tm.tm_year << std::endl;
    std::cout << tm.tm_wday << std::endl;
    std::cout << tm.tm_hour << std::endl;
    std::cout << tm.tm_min << std::endl;
    std::cout << std::put_time(&tm, "%Y-%m-%d %H:%M") << std::endl;

    // convert to current time
    time_t t = mktime(&tm);
    struct tm* currTime = localtime(&t);
    std::cout << "current week day: " << currTime->tm_wday << std::endl;
}