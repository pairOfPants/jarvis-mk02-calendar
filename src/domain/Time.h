#include <string>
#include <iostream>
#include <chrono> //for getting current date

class Time{
    public:
        Time();
        Time(int hour, int minute, int second);
        int getHour();
        int getMinute();
        int getSecond();
        int setHour(int hour);
        int setMinute(int minute);
        int setSecond(int second);
        static Time getCurrentTime()
        {
            auto now = std::chrono::system_clock::now();
            std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
            std::tm* localTime = std::localtime(&currentTime);
            Time time = Time(localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
            return time;
        }
         friend std::ostream& operator<<(std::ostream& os, const Time& time){
            if(time.hour < 10) os << "0";
            os << time.hour << ":";
            if(time.minute < 10) os << "0";
            os << time.minute << ":"; 
            if(time.second < 10) os << "0";
            os << time.second;
            return os;
        }
        Time& operator=(const Time& oldTime);
        bool operator>(const Time& other) const;
        bool operator>=(const Time& other) const;
        bool operator<(const Time& other)const;
        bool operator<=(const Time& other)const;
        bool operator==(const Time& other) const;

    private:
        int hour;
        int minute;
        int second;
};