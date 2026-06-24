#ifndef CALENDAR
#define CALENDAR
#include <string>
#include <iostream> //for std::ostream

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

        friend std::ostream& operator<<(std::ostream& os, const Date& date){
            if(date.day < 10) os << "0";
            os << date.day << "/";
            if(date.month < 10) os << "0";
            os << date.month << "/" << date.year;
            return os;
        }
        Date& operator=(const Date& oldDate);


    private:
        int year;
        int month;
        int day;
        std::string date_string;

       
};

//events may differ from dates in that events need to be dynamically allocated, whereas dates are fixed.
class Event{
    public:

    //constructors
        Event();
        Event(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear, std::string name, std::string description);
        Event(Date* startDate, Date* endDate, std::string name, std::string description);
        Event(const Event& other);
        Event& operator=(const Event& other);
        ~Event();

    enum REPEAT_TYPE { NONE, DAILY, WEEKLY, MONTHLY, YEARLY, N_DAYS, CUSTOM };
    //getters & setters
    Date* getStartDate();
    Date* getEndDate();
    std::string getName();
    std::string getDescription();

    int setStartDate(Date* startDate);
    int setEndDate(Date* endDate);
    int setName(std::string name);
    int setDescription(std::string description);

    //utility functions


    private:
        Date* startDate;
        Date* endDate;
        std::string name;
        std::string description;
        Event* subEvent; //ex. Make breakfast -> Pack lunch -> Get dressed -> Drive to work
        REPEAT_TYPE repeatType;
};

class Calendar{
    public:
        Calendar();
        Calendar(int year, int month, int day);
        void print_calendar(int year, int month);
    private:


};



#endif