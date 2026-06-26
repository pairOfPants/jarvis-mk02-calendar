#include "Time.h"

Time::Time() : hour(0), minute(0), second(0) {}
Time::Time(int hour, int minute, int second){
    if(second < 0 || second > 59){
        throw std::invalid_argument("Invalid second value. Second must be between 0 and 59.");
    }
    else if(minute < 0 || minute > 59){
        throw std::invalid_argument("Invalid minute value. Minute must be between 0 and 59.");
    }
    else if(hour < 0 || hour > 23){
        throw std::invalid_argument("Invalid hour value. Hour must be between 0 and 23.");
    }

    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

int Time::getHour() { return hour; }
int Time::getMinute() { return minute; }
int Time::getSecond() { return second; }

int Time::setHour(int hour) {
    if(hour < 0 || hour > 23){
        throw std::invalid_argument("Invalid hour value. Hour must be between 0 and 23.");
        return -1;
    }
    this->hour = hour;
    return 0;
}

int Time::setMinute(int minute) {
    if(minute < 0 || minute > 59){
        throw std::invalid_argument("Invalid minute value. Minute must be between 0 and 59.");
        return -1;
    }
    this->minute = minute;
    return 0;
}

int Time::setSecond(int second) {
    if(second < 0 || second > 59){
        throw std::invalid_argument("Invalid second value. Second must be between 0 and 59.");
        return -1;
    }
    this->second = second;
    return 0;
}

Time& Time::operator=(const Time& oldTime) {
    if (this != &oldTime) {
        this->hour = oldTime.hour;
        this->minute = oldTime.minute;
        this->second = oldTime.second;
    }
    return *this;
}

bool Time::operator>(const Time& other) const
{
    if(this->hour > other.hour && this->minute > other.minute && this->second > other.second){
        return true;
    }
    return false;
}

bool Time::operator>=(const Time& other) const
{
    if(this->hour >= other.hour && this->minute >= other.minute && this->second >= other.second){
        return true;
    }
    return false;
}

bool Time::operator<(const Time& other) const
{
    if(this->hour < other.hour && this->minute < other.minute && this->second < other.second){
        return true;
    }
    return false;
}

bool Time::operator<=(const Time& other) const
{
    if(this->hour <= other.hour && this->minute <= other.minute && this->second <= other.second){
        return true;
    }
    return false;
}

bool Time::operator==(const Time& other) const
{
    if(this->hour == other.hour && this->minute == other.minute && this->second == other.second){
        return true;
    }
    return false;
}
