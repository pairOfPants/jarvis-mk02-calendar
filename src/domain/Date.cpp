#include "Date.h"
#include <iostream>
#include <string>

Date::Date() : year(0), month(0), day(0), date_string("") {}
Date::Date(int year, int month, int day) {
    if(day < 1 || day > 31){
        throw std::invalid_argument("Invalid day value. Day must be between 1 and 31.");
    }
    else if(month < 1 || month > 12){
        throw std::invalid_argument("Invalid month value. Month must be between 1 and 12.");
    }
    else if(year < 2000){
        throw std::invalid_argument("Invalid year value. System only goes back to year 2000.");
    }

    this->year = year;
    this->month = month;
    this->day = day;
    date_string = "";
}
Date::Date(std::string date_string) : date_string(date_string) 
{
    if(date_string.size() != 10)
    {
        throw std::invalid_argument("Invalid date format. Expected format: DD/MM/YYYY");
    }
    char delimiter = '/';
    size_t pos = 0;
    //each correct date will have exactly 2 delimiters
    pos = date_string.find(delimiter); //position of first delimeter
    if(pos == std::string::npos){
        throw std::invalid_argument("Invalid date format. Expected format: DD/MM/YYYY");   
    }
    month = std::stoi(date_string.substr(0, pos)); //extracts the day from the string

    date_string.erase(0, pos + 1); //removes the day and delimiter from the string
    pos = date_string.find(delimiter); //position of second delimeter
    if(pos == std::string::npos){
        throw std::invalid_argument("Invalid date format. Expected format: DD/MM/YYYY");
    }
    day = std::stoi(date_string.substr(0, pos)); //extracts the month from the string
    date_string.erase(0, pos + 1); //removes the month and delimiter from the string
    year = std::stoi(date_string); //the remaining string is the year
    date_string = "";


    //further check for correct values 
    if(day < 1||day > 31){
        throw std::invalid_argument("Invalid day value. Day must be between 1 and 31.");
    }
    else if(month < 1||month > 12){
        throw std::invalid_argument("Invalid month value. Month must be between 1 and 12.");
    }
    else if(year < 2000){
        throw std::invalid_argument("Invalid year value. System only goes back to year 2000.");
    }
}

int Date::getDay() { return day; }
int Date::getMonth() { return month; }
int Date::getYear() { return year; }

int Date::setDay(int day) {
    if(day < 1 || day > 31){
        throw std::invalid_argument("Invalid day value. Day must be between 1 and 31.");
        return -1;
    }
    this->day = day;
    return 0;
}

int Date::setMonth(int month) {
    if(month < 1 || month > 12){
        throw std::invalid_argument("Invalid month value. Month must be between 1 and 12.");
        return -1;
    }
    this->month = month;
    return 0;
}

int Date::setYear(int year) {
    if(year < 2000){
        throw std::invalid_argument("Invalid year value. System only goes back to year 2000.");
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

bool Date::operator>(const Date& other)const 
{
    if(!(this->year > other.year || this->month > other.month || this->day > other.day)){
        return false;
    }
    return true;
}

bool Date::operator>=(const Date& other)const {
    if(*this > other || *this == other){
        return true;
    }
    return false;
}

bool Date::operator<(const Date& other) const {
    if(!(*this >= other)) {
        return true;
    }
    return false;
}

bool Date::operator<=(const Date& other)const {
    if(!(*this > other)) {
        return true;
    }
    return false;
}   

bool Date::operator==(const Date& other) const {
    if(this-> year == other.year && this->month == other.month && this->day == other.day){
        return true;
    }
    return false;
}