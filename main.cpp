#include "headers/common_headers.h"
#include "headers/custom_func.h"

#include "source/parse_time.cpp"

static std::string year = "2021";
static std::string month = "06";
static std::string workStartHours = "09:00";
static std::string workEndHours = "18:30";

std::vector<std::string> workHours()
{
    std::vector<std::string> workHoursList;
    // read from file
    std::fstream file;
    std::string fileName = "./input/workTime_" + month + ".txt";
    file.open(fileName, std::ios::in);
    std::string line;
    while(file >> line)
        workHoursList.emplace_back(line);
    file.close();
    return workHoursList;
}

void outputToConsoleAndWriteToFile(const std::string message, std::stringstream &fileStream)
{
    std::cout << message << std::endl;
    fileStream << message << std::endl;
}

int main()
{
    std::cout << "Enter year and month (format: yyyy-MM): " << std::endl;
    std::string yearMonth;
    getline(std::cin, yearMonth);
    std::vector<std::string> yearMonthVector = split(yearMonth, '-');
    year = yearMonthVector.at(0);
    month = yearMonthVector.at(1);

    std::stringstream outputStream;
    int totalOverWorkedHours = 0;
    std::vector<std::string> workHoursList = workHours();
    std::vector<std::string>::iterator it;
    for(it = workHoursList.begin(); it != workHoursList.end(); it++)
    {
        std::vector<std::string> data = split(*it, ',');
        outputToConsoleAndWriteToFile("date: " + data.at(0), outputStream);
        if(data.size() > 3)
        {
            // Saturdays, count time difference
            outputToConsoleAndWriteToFile("isSaturday", outputStream);
            int mins = calculateOverWorkedHoursInMinutes(data.at(1), data.at(2));
            outputToConsoleAndWriteToFile("actual arrive hour: " + data.at(1), outputStream);
            outputToConsoleAndWriteToFile("actual leave hour: " + data.at(2), outputStream);
            outputToConsoleAndWriteToFile("over worked in minutes: " + std::to_string(mins), outputStream);
            outputToConsoleAndWriteToFile("over worked in hours: " + std::to_string(mins / 60), outputStream);
            totalOverWorkedHours += mins / 60;
        }
        else
        {
            // weekdays, calculate actual leave time first, then count time difference
            std::string calculatedLeaveHours = calDiffAndReturnNewTime(workStartHours, data.at(1), workEndHours);
            outputToConsoleAndWriteToFile("actual arrive hour: " + data.at(1), outputStream);
            outputToConsoleAndWriteToFile("actual leave hour: " + data.at(2), outputStream);
            outputToConsoleAndWriteToFile("leave hour: " + calculatedLeaveHours, outputStream);
            int mins = calculateOverWorkedHoursInMinutes(calculatedLeaveHours, data.at(2));
            outputToConsoleAndWriteToFile("over worked in minutes: " + std::to_string(mins), outputStream);
            outputToConsoleAndWriteToFile("over worked in hours: " + std::to_string(mins / 60), outputStream);
            totalOverWorkedHours += mins / 60;
        }
        outputToConsoleAndWriteToFile("\n", outputStream);
        outputToConsoleAndWriteToFile("total over worked hours: " + std::to_string(totalOverWorkedHours), outputStream);
    }

    // write to file
    std::fstream outputFile;
    outputFile.open("./output/workTime_" + month + ".txt", std::ios::out);
    if(outputFile.is_open())
        outputFile << outputStream.str();
    outputFile.close();
    return 0;
}
