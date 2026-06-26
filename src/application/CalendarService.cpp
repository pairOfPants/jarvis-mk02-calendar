#include "CalendarService.h"

int CalendarService::addEvent(const Event& event)
{
    events.push_back(event);
    sort(); //sorts after each addition
    return 0;
}

int CalendarService::removeEvent(const Event& event)
{
    auto it = std::find(events.begin(), events.end(), event);
    if (it != events.end()) {
        events.erase(it);
        return 0;
    }
    return -1; // Event not found
}

int CalendarService::updateEvent(const Event& oldEvent, const Event& newEvent)
{
    auto it = std::find(events.begin(), events.end(), oldEvent);
    if (it != events.end()) {
        *it = newEvent;
        return 0;
    }
    return -1; // Event not found
}

//TODO: update to use binary search to find event by name
std::vector<const Event*> CalendarService::searchEvents(const std::string& name) const
{
    std::vector<const Event*> foundEvents;
    for(auto &event : events) {
        if(event.getTitle() == name) {
            foundEvents.push_back(&event);
        }
    }
    return foundEvents;
}

//TODO: update to use binary search to find event by id
std::vector<const Event*> CalendarService::searchEvents(const int id) const
{
    std::vector<const Event*> foundEvents;
    for(auto &event : events) {
        if(event.getId() == id) {
            foundEvents.push_back(&event);
        }
    }
    return foundEvents;
}

const std::vector<Event>& CalendarService::getEvents() const
{
    return events;
}

std::vector<const Event*> CalendarService::getEventsOnDate(const DateTime& dateTime) const
{
    std::vector<const Event*> eventPtrs;
    for (const auto& event : events) {
        if (event.getStartDateTime().getDate() == dateTime.getDate()) {
            eventPtrs.push_back(&event);
        }
    }
    return eventPtrs;
}

std::vector<const Event*> CalendarService::getEventsInRange(const DateTime& startDateTime, const DateTime& endDateTime) const
{
    std::vector<const Event*> eventPtrs;
    for (const auto& event : events) {
        if (event.getStartDateTime() >= startDateTime && event.getEndDateTime() <= endDateTime)  {
            eventPtrs.push_back(&event);
        }
    }
    return eventPtrs;
}

void CalendarService::sort()
{
    std::sort(this->events.begin(), this->events.end());
}