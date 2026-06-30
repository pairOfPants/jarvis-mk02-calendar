#include "Event.h"
Event::Event() {
    id = 0; //generate a random id for the event //TODO:
    externalId = ""; //this value is set from external calendar provider
    startDateTime = DateTime();
    endDateTime = DateTime();
    title = "";
    description = "";
    location = "";
    repeatType = NONE;
    status = EventStatus::CONFIRMED;
}

Event::Event(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear, std::string title, std::string description, std::string location) {
    id = 0; //generate a random id for the event //TODO:
    externalId = ""; //this value is set from external calendar provider
    startDateTime = DateTime(Date(startYear, startMonth, startDay), Time());
    endDateTime = DateTime(Date(endYear, endMonth, endDay), Time(23,59,59));
    this->title = title;
    this->description = description;
    this->location = location;
    repeatType = NONE;
    status = EventStatus::CONFIRMED;
}

Event::Event(DateTime startDateTime, DateTime endDateTime, std::string title, std::string description, std::string location) {
    id = 0; //generate a random id for the event //TODO:
    externalId = ""; //this value is set from external calendar provider
    this->startDateTime = DateTime(startDateTime);
    this->endDateTime = DateTime(endDateTime);
    this->title = title;
    this->description = description;
    this-> location = location;
    repeatType = NONE;
    status = EventStatus::CONFIRMED;
}   


// Event::Event(const Event& other)
// {
//     id = other.id;
//     externalId = other.externalId;
//     startDateTime = DateTime(other.startDateTime);
//     endDateTime = DateTime(other.endDateTime);

//     title = other.title;
//     description = other.description;
//     location = other.location;
//     repeatType = other.repeatType;
//     status = other.status;
// }

// Event& Event::operator=(const Event& other)
// {
//     if (this != &other)
//     {
//         id = other.id;
//         externalId = other.externalId;
//         startDateTime = DateTime(other.startDateTime);
//         endDateTime = DateTime(other.endDateTime);

//         title = other.title;
//         description = other.description;
//         repeatType = other.repeatType;
//         status = other.status;
//     }

//     return *this;
// }


DateTime Event::getStartDateTime() const { return startDateTime; }
DateTime Event::getEndDateTime() const { return endDateTime; }
std::string Event::getTitle() const { return title; }
std::string Event::getDescription() const { return description; }
std::string Event::getLocation() const { return location; }
Event::REPEAT_TYPE Event::getRepeatType() const { return repeatType; }
int Event::getId() const { return id; }
std::string Event::getExternalId() const { return externalId; }
Event::EventStatus Event::getStatus() const { return status; }

int Event::setId(int id) {this->id = id; return 0; }
int Event::setExternalId(std::string externalId) {this->externalId = externalId; return 0; }
int Event::setStatus(EventStatus status) {this->status = status; return 0; }


int Event::setStartDateTime(DateTime &startDateTime) {
    this->startDateTime = startDateTime;
    return 0;
}

int Event::setEndDateTime(DateTime &endDateTime) {
    this->endDateTime = endDateTime;
    return 0;
}

int Event::setLocation(std::string location) {
    this->location = location;
    return 0;
}


int Event::setTitle(std::string title) {
    this->title = title;
    return 0;
}

int Event::setDescription(std::string description) {
    this->description = description;
    return 0;
}

int Event::setRepeatType(REPEAT_TYPE repeatType) {
    this->repeatType = repeatType;
    return 0;
}

/*pseudo code for event conditional operators
if startDate < other.startDate
    return startDate < other.startDate

if startTime < other.startTime
    return startTime < other.startTime

if endDate < other.endDate
    return endDate < other.endDate

if endTime < other.endTime
    return endTime < other.endTime

return name < other.name
*/
bool Event::operator>(const Event& other){
    if (startDateTime != other.startDateTime) return startDateTime > other.startDateTime;
    if (endDateTime != other.endDateTime) return endDateTime > other.endDateTime;
    return title > other.title;
}

bool Event::operator>=(const Event& other){
    if (startDateTime != other.startDateTime) return startDateTime >= other.startDateTime;
    if (endDateTime != other.endDateTime) return endDateTime >= other.endDateTime;
    return title >= other.title;
}

bool Event::operator<(const Event& other){
    if (startDateTime != other.startDateTime) return startDateTime < other.startDateTime;
    if (endDateTime != other.endDateTime) return endDateTime < other.endDateTime;
    return title < other.title;
} 

bool Event::operator<=(const Event& other){
    if (startDateTime != other.startDateTime) return startDateTime <= other.startDateTime;
    if (endDateTime != other.endDateTime) return endDateTime <= other.endDateTime;
    return title <= other.title;
}

//TODO: change this to check ID and no other field, ID's are unique
bool Event::operator==(const Event& other){
    if(this->startDateTime != other.startDateTime) return false;
    if(this->endDateTime != other.endDateTime) return false;
    return this->title == other.title;
}