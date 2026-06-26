#include <iostream>
#include <string>
#include <chrono> //for getting current date
class Date{
    public:
    //constructors
        Date();
        Date(std::string date_string); //e.g. "2023-03-15"
        Date(int year, int month, int day);
    //getters & setters
        int getDay();
        int getMonth();
        int getYear();
        int setDay(int day);
        int setMonth(int month);
        int setYear(int year);
        static Date getCurrentDate(){
            auto now = std::chrono::system_clock::now();
            std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
            std::tm* now_tm = std::localtime(&now_time_t);
            Date currentDate = Date(now_tm->tm_year + 1900, now_tm->tm_mon +1, now_tm->tm_mday); //tm_years = years since 1900 for some reason, month is 0-indexed
            return currentDate;
        }

        friend std::ostream& operator<<(std::ostream& os, const Date& date){
            if(date.day < 10) os << "0";
            os << date.day << "/";
            if(date.month < 10) os << "0";
            os << date.month << "/" << date.year;
            return os;
        }
        Date& operator=(const Date& oldDate);
        bool operator>(const Date& other)const;
        bool operator>=(const Date& other)const;
        bool operator<(const Date& other)const;
        bool operator<=(const Date& other)const;
        bool operator==(const Date& other)const;


    private:
        int year;
        int month;
        int day;
        std::string date_string;

       
};