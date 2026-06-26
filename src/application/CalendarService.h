#include <vector>
#include "../domain/Event.h"
class CalendarService
{
    public:
        CalendarService() = default;
        ~CalendarService() = default;

        int addEvent(const Event& event);
        int removeEvent(const Event& event);
        int updateEvent(const Event& oldEvent, const Event& newEvent);
        int updateEvent(int id, const Event& newEvent);
        std::vector<const Event*> searchEvents(const std::string& name) const;
        std::vector<const Event*> searchEvents(const int id) const;
        const std::vector<Event>& getEvents() const;
        std::vector<const Event*> getEventsOnDate(const DateTime& dateTime) const;
        std::vector<const Event*> getEventsInRange(const DateTime& startDateTime, const DateTime& endDateTime) const;


    private:
        void sort();
        std::vector<Event> events;
};