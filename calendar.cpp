#include "calendar.h"

using namespace std;

Date::Date() : year(0), month(0), day(0), date_string("") {}
Date::Date(int year, int month, int day) {
    if(day < 1 || day > 31){
        throw invalid_argument("Invalid day value. Day must be between 1 and 31.");
    }
    else if(month < 1 || month > 12){
        throw invalid_argument("Invalid month value. Month must be between 1 and 12.");
    }
    else if(year < 2000){
        throw invalid_argument("Invalid year value. System only goes back to year 2000.");
    }

    this->year = year;
    this->month = month;
    this->day = day;
    date_string = "";
}
Date::Date(string date_string) : date_string(date_string) 
{
    if(date_string.size() != 10)
    {
        throw invalid_argument("Invalid date format. Expected format: DD/MM/YYYY");
    }
    char delimiter = '/';
    size_t pos = 0;
    //each correct date will have exactly 2 delimiters
    pos = date_string.find(delimiter); //position of first delimeter
    if(pos == string::npos){
        throw invalid_argument("Invalid date format. Expected format: DD/MM/YYYY");   
    }
    day = stoi(date_string.substr(0, pos)); //extracts the day from the string

    date_string.erase(0, pos + 1); //removes the day and delimiter from the string
    pos = date_string.find(delimiter); //position of second delimeter
    if(pos == string::npos){
        throw invalid_argument("Invalid date format. Expected format: DD/MM/YYYY");
    }
    month = stoi(date_string.substr(0, pos)); //extracts the month from the string
    date_string.erase(0, pos + 1); //removes the month and delimiter from the string
    year = stoi(date_string); //the remaining string is the year
    date_string = "";


    //further check for correct values 
    if(day < 1||day > 31){
        throw invalid_argument("Invalid day value. Day must be between 1 and 31.");
    }
    else if(month < 1||month > 12){
        throw invalid_argument("Invalid month value. Month must be between 1 and 12.");
    }
    else if(year < 2000){
        throw invalid_argument("Invalid year value. System only goes back to year 2000.");
    }
}

int Date::getDay() { return day; }
int Date::getMonth() { return month; }
int Date::getYear() { return year; }

int Date::setDay(int day) {
    if(day < 1 || day > 31){
        throw invalid_argument("Invalid day value. Day must be between 1 and 31.");
        return -1;
    }
    this->day = day;
    return 0;
}

int Date::setMonth(int month) {
    if(month < 1 || month > 12){
        throw invalid_argument("Invalid month value. Month must be between 1 and 12.");
        return -1;
    }
    this->month = month;
    return 0;
}

int Date::setYear(int year) {
    if(year < 2000){
        throw invalid_argument("Invalid year value. System only goes back to year 2000.");
        return -1;
    }
    this->year = year;
    return 0;
}

Date& Date::operator=(const Date& oldDate) {
    if (this != &oldDate) {
        this->year = oldDate.year;
        this->month = oldDate.month;
        this->day = oldDate.day;
        this->date_string = oldDate.date_string;
    }
    return *this;
}


Event::Event() {
    startDate = new Date();
    endDate = new Date();
    name = "";
    description = "";
    repeatType = NONE;
}

Event::Event(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear, std::string name, std::string description) {
    startDate = new Date(startYear, startMonth, startDay);
    endDate = new Date(endYear, endMonth, endDay);
    this->name = name;
    this->description = description;
    repeatType = NONE;
}

Event::Event(Date* startDate, Date* endDate, std::string name, std::string description) {
    this->startDate = new Date(*startDate);
    this->endDate = new Date(*endDate);
    this->name = name;
    this->description = description;
    repeatType = NONE;
}   


Event::Event(const Event& other)
{
    startDate = new Date(*other.startDate);
    endDate = new Date(*other.endDate);

    name = other.name;
    description = other.description;
    repeatType = other.repeatType;
}

Event& Event::operator=(const Event& other)
{
    if (this != &other)
    {
        delete startDate;
        delete endDate;

        startDate = new Date(*other.startDate);
        endDate = new Date(*other.endDate);

        name = other.name;
        description = other.description;
        repeatType = other.repeatType;
    }

    return *this;
}

Event::~Event() {
    delete startDate;
    delete endDate;
    startDate = nullptr;
    endDate = nullptr;
}

Date* Event::getStartDate() { return startDate; }
Date* Event::getEndDate() { return endDate; }
string Event::getName() { return name; }
string Event::getDescription() { return description; }

int Event::setStartDate(Date* startDate) {
    if(startDate->getDay() >=1 && startDate->getDay() <= 31 && startDate->getMonth() >= 1 && startDate->getMonth() <= 12 && startDate->getYear() >= 2000){
        delete this->startDate;
        this->startDate = new Date(*startDate);
        return 0;
    }
    else
    {
        throw invalid_argument("Invalid date value. Please ensure the date is valid.");
        return -1;
    }
}

int Event::setEndDate(Date* endDate) {
   if(endDate->getDay() >=1 && endDate->getDay() <= 31 && endDate->getMonth() >= 1 && endDate->getMonth() <= 12 && endDate->getYear() >= 2000){
        delete this->endDate; 
        this->endDate = new Date(*endDate);
        return 0;
    }
    else
    {
        throw invalid_argument("Invalid date value. Please ensure the date is valid.");
        return -1;
    }
}

int Event::setName(string name) {
    this->name = name;
    return 0;
}

int Event::setDescription(string description) {
    this->description = description;
    return 0;
}

// int main()
// {
//     return 0;
// }

