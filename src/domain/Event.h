#include <string>
#include "DateTime.h"
class Event{
    public:

    //constructors
        Event();
        Event(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear, std::string title, std::string description, std::string location);
        Event(DateTime startDateTime, DateTime endDateTime, std::string title, std::string description, std::string location);
        Event(const Event& other) = default;
        Event& operator=(const Event& other) = default;

    enum REPEAT_TYPE { NONE, DAILY, WEEKLY, MONTHLY, YEARLY, N_DAYS, CUSTOM };
    //getters & setters
    DateTime& getStartDateTime();
    DateTime& getEndDateTime();
    REPEAT_TYPE& getRepeatType();
    std::string& getTitle();
    std::string& getLocation();
    std::string& getDescription();
    int& getId();
    std::string& getExternalId();
    EventStatus& getStatus();

    int setStartDateTime(DateTime& startDateTime);
    int setEndDateTime(DateTime &endDatetime);
    int setTitle(std::string title);
    int setRepeatType(REPEAT_TYPE repeatType);
    int setDescription(std::string description);
    int setLocation(std::string location);
    int setId(int id);
    int setExternalId(std::string externalId);
    int setStatus(EventStatus status);

    //utility functions
    friend std::ostream& operator<<(std::ostream& os, const Event& event){
        os << "Event: " << event.title << "\n";
        os << "Description: " << event.description << "\n";
        os << "Start Date: " << event.startDateTime.getDate() << "\n";
        os << "End Date: " << event.endDateTime.getDate() << "\n";
        os << "Start Time: " << event.startDateTime.getTime() << "\n";
        os << "End Time: " << event.endDateTime.getTime() << "\n\n";
        return os;
    }
    bool operator>(const Event& other);
    bool operator>=(const Event& other);
    bool operator<(const Event& other);
    bool operator<=(const Event& other);
    bool operator==(const Event& other);

    private:

        int id;
        std::string externalId;
        DateTime startDateTime;
        DateTime endDateTime;
        std::string title;
        std::string description;
        std::string location;
        Event* subEvent; //ex. Make breakfast -> Pack lunch -> Get dressed -> Drive to work
        REPEAT_TYPE repeatType;
        EventStatus status;

    //metadata for datanase
    bool dirty = false;
    bool deleted = false;
    time_t lastModified = 0;
    //Provider provider;

};

enum class EventStatus
{
    CONFIRMED,
    TENTATIVE,
    CANCELLED
};
