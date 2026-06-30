#include "DateTime.h"

DateTime::DateTime(): date(), time(){}

DateTime::DateTime(const Date& d, const Time& t = Time()): date(d), time(t){}

DateTime::DateTime(int year, int month, int day, int hour, int minute, int second = 0): date(year, month, day), time(hour, minute, second) {}

DateTime DateTime::now()
{
    return DateTime(
        Date::getCurrentDate(),
        Time::getCurrentTime());
}

bool DateTime::operator<(const DateTime& other) const
{
    if (date < other.date)
        return true;

    if (other.date < date)
        return false;

    return time < other.time;
}

bool DateTime::operator>(const DateTime& other) const
{
    if (date > other.date)
        return true;

    if (other.date > date)
        return false;

    return time > other.time;
}

bool DateTime::operator<=(const DateTime& other) const
{
    return !(*this > other);
}

bool DateTime::operator>=(const DateTime& other) const
{
    return !(*this < other);
}

bool DateTime::operator==(const DateTime& other) const
{
    return date == other.date && time == other.time;
}

std::ostream& operator<<(std::ostream& os, const DateTime& dt)
{
    os << dt.date << " " << dt.time;
    return os;
}

Date& DateTime::getDate()
{
    return date;
}

const Date& DateTime::getDate() const
{
    return date;
}

Time& DateTime::getTime()
{
    return time;
}

const Time& DateTime::getTime() const
{
    return time;
}

DateTime now()
{
    return DateTime(Date::getCurrentDate(), Time::getCurrentTime());
}

bool isValidDateTime(DateTime dt)
{
    return (dt.getDate().getYear() >= 2000 &&
            dt.getDate().getMonth() >= 1 && dt.getDate().getMonth() <= 12 &&
            dt.getDate().getDay() >= 1 && dt.getDate().getDay() <= 31 &&
            dt.getTime().getHour() >= 0 && dt.getTime().getHour() <= 23 &&
            dt.getTime().getMinute() >= 0 && dt.getTime().getMinute() <= 59 &&
            dt.getTime().getSecond() >= 0 && dt.getTime().getSecond() <= 59);
}
