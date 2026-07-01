#include "CalendarServiceTests.h"
#include "../../src/application/CalendarService.h"

bool calendarServiceAddEventTest()
{
    CalendarService calendarService;
    Event event(DateTime(2023, 3, 15, 12, 30, 45), DateTime(2023, 3, 15, 13, 30, 45), "Meeting", "Project discussion", "Conference Room");
    int result = calendarService.addEvent(event);
    ASSERT_TRUE(result == 0);
    ASSERT_TRUE(calendarService.getEvents().size() == 1);
    return true;
}

bool calendarServiceRemoveEventTest()
{
    CalendarService calendarService;
    Event event(DateTime(2023, 3, 15, 12, 30, 45), DateTime(2023, 3, 15, 13, 30, 45), "Meeting", "Project discussion", "Conference Room");
    calendarService.addEvent(event);
    int result = calendarService.removeEvent(event);
    ASSERT_TRUE(result == 0);
    ASSERT_TRUE(calendarService.getEvents().size() == 0);
    return true;
}

bool calendarServiceUpdateEventTest()
{
    CalendarService calendarService;
    Event oldEvent(DateTime(2023, 3, 15, 12, 30, 45), DateTime(2023, 3, 15, 13, 30, 45), "Meeting", "Project discussion", "Conference Room");
    Event newEvent(DateTime(2023, 3, 15, 14, 30, 45), DateTime(2023, 3, 15, 15, 30, 45), "Updated Meeting", "Updated discussion", "Updated Conference Room");
    calendarService.addEvent(oldEvent);
    int result = calendarService.updateEvent(oldEvent, newEvent);
    ASSERT_TRUE(result == 0);
    ASSERT_TRUE(calendarService.getEvents().size() == 1);
    ASSERT_TRUE(calendarService.getEvents()[0].getTitle() == "Updated Meeting");
    return true;
}

bool calendarServiceSearchSingleEventByNameTest()
{
    CalendarService calendarService;
    Event event1(DateTime(2023, 3, 15, 12, 30, 45), DateTime(2023, 3, 15, 13, 30, 45), "Meeting", "Project discussion", "Conference Room");
    Event event2(DateTime(2023, 3, 16, 12, 30, 45), DateTime(2023, 3, 16, 13, 30, 45), "Workshop", "Training session", "Training Room");
    calendarService.addEvent(event1);
    calendarService.addEvent(event2);
    auto foundEvents = calendarService.searchEvents("Meeting");
    ASSERT_TRUE(foundEvents.size() == 1);
    ASSERT_TRUE(foundEvents[0]->getTitle() == "Meeting");
    return true;
}

bool calendarServiceSearchMultipleEventsByNameTest()
{
    CalendarService calendarService;
    Event event1(DateTime(2023, 3, 15, 12, 30, 45), DateTime(2023, 3, 15, 13, 30, 45), "Meeting", "Project discussion", "Conference Room");
    Event event2(DateTime(2023, 3, 16, 12, 30, 45), DateTime(2023, 3, 16, 13, 30, 45), "Meeting", "Training session", "Training Room");
    calendarService.addEvent(event1);
    calendarService.addEvent(event2);
    auto foundEvents = calendarService.searchEvents("Meeting");
    ASSERT_TRUE(foundEvents.size() == 2);
    return true;
}

bool calendarServiceSearchEventByNameNotFoundTest()
{
    CalendarService calendarService;
    Event event(DateTime(2023, 3, 15, 12, 30, 45), DateTime(2023, 3, 15, 13, 30, 45), "Meeting", "Project discussion", "Conference Room");
    calendarService.addEvent(event);
    auto foundEvents = calendarService.searchEvents("Nonexistent Event");
    ASSERT_TRUE(foundEvents.size() == 0);
    return true;
}

bool calendarServiceSearchEventByIdTest()
{
    CalendarService calendarService;
    Event event1(DateTime(2023, 3, 15, 12, 30, 45), DateTime(2023, 3, 15, 13, 30, 45), "Meeting", "Project discussion", "Conference Room");
    Event event2(DateTime(2023, 3, 16, 12, 30, 45), DateTime(2023, 3, 16, 13, 30, 45), "Workshop", "Training session", "Training Room");
    event1.setId(1);
    event2.setId(2);
    calendarService.addEvent(event1);
    calendarService.addEvent(event2);
    auto foundEvents = calendarService.searchEvents(1);
    ASSERT_TRUE(foundEvents.size() == 1);
    ASSERT_TRUE(foundEvents[0]->getId() == 1);
    return true;
}

bool calendarServiceSearchEventByIdNotFoundTest()
{
    CalendarService calendarService;
    Event event(DateTime(2023, 3, 15, 12, 30, 45), DateTime(2023, 3, 15, 13, 30, 45), "Meeting", "Project discussion", "Conference Room");
    event.setId(1);
    calendarService.addEvent(event);
    auto foundEvents = calendarService.searchEvents(2);
    ASSERT_TRUE(foundEvents.size() == 0);
    return true;
}

bool calendarServiceGetEventsOnDateTest()
{
    CalendarService calendarService;
    Event event1(DateTime(2023, 3, 15, 12, 30, 45), DateTime(2023, 3, 15, 13, 30, 45), "Meeting", "Project discussion", "Conference Room");
    Event event2(DateTime(2023, 3, 16, 12, 30, 45), DateTime(2023, 3, 16, 13, 30, 45), "Workshop", "Training session", "Training Room");
    calendarService.addEvent(event1);
    calendarService.addEvent(event2);
    auto foundEvents = calendarService.getEventsOnDate(DateTime(2023, 3, 15, 0, 0, 0));
    ASSERT_TRUE(foundEvents.size() == 1);
    ASSERT_TRUE(foundEvents[0]->getTitle() == "Meeting");
    return true;
}

bool calendarServiceGetEventsOnDateNoEventsTest()
{
    CalendarService calendarService;
    Event event(DateTime(2023, 3, 15, 12, 30, 45), DateTime(2023, 3, 15, 13, 30, 45), "Meeting", "Project discussion", "Conference Room");
    calendarService.addEvent(event);
    auto foundEvents = calendarService.getEventsOnDate(DateTime(2023, 3, 16, 0, 0, 0));
    ASSERT_TRUE(foundEvents.size() == 0);
    return true;
}

bool calendarServiceGetEventsInRangeTest()
{
    CalendarService calendarService;
    Event event1(DateTime(2023, 3, 15, 12, 30, 45), DateTime(2023, 3, 15, 13, 30, 45), "Meeting", "Project discussion", "Conference Room");
    Event event2(DateTime(2023, 3, 16, 12, 30, 45), DateTime(2023, 3, 16, 13, 30, 45), "Workshop", "Training session", "Training Room");
    calendarService.addEvent(event1);
    calendarService.addEvent(event2);
    auto foundEvents = calendarService.getEventsInRange(DateTime(2023, 3, 15, 0, 0, 0), DateTime(2023, 3, 16, 23, 59, 59));
    ASSERT_TRUE(foundEvents.size() == 2);
    return true;
}

bool calendarServiceGetEventsInRangeNoEventsTest()
{
    CalendarService calendarService;
    Event event(DateTime(2023, 3, 15, 12, 30, 45), DateTime(2023, 3, 15, 13, 30, 45), "Meeting", "Project discussion", "Conference Room");
    calendarService.addEvent(event);
    auto foundEvents = calendarService.getEventsInRange(DateTime(2023, 3, 16, 0, 0, 0), DateTime(2023, 3, 17, 23, 59, 59));
    ASSERT_TRUE(foundEvents.size() == 0);
    return true;
}

bool calendarServiceGetEventsInRangeCatchBadRangeTest()
{
    CalendarService calendarService;
    Event event(DateTime(2023, 3, 15, 12, 30, 45), DateTime(2023, 3, 15, 13, 30, 45), "Meeting", "Project discussion", "Conference Room");
    calendarService.addEvent(event);
    try {
        auto foundEvents = calendarService.getEventsInRange(DateTime(2023, 3, 17, 0, 0, 0), DateTime(2023, 3, 16, 23, 59, 59));
    } catch (const std::invalid_argument& e) {
        return true; // Test passed, exception was thrown
    }
    return false; // Test failed, no exception was thrown
}


void registerCalendarServiceTests(TestRunner& runner)
{
    runner.addTest(
        "CalendarService Add Event Test",
        calendarServiceAddEventTest
    );

    runner.addTest(
        "CalendarService Remove Event Test",
        calendarServiceRemoveEventTest
    );

    runner.addTest(
        "CalendarService Update Event Test",
        calendarServiceUpdateEventTest
    );

    runner.addTest(
        "CalendarService Search Single Event By Name Test",
        calendarServiceSearchSingleEventByNameTest
    );

    runner.addTest(
        "CalendarService Search Multiple Events By Name Test",
        calendarServiceSearchMultipleEventsByNameTest
    );

    runner.addTest(
        "CalendarService Search Event By Name Not Found Test",
        calendarServiceSearchEventByNameNotFoundTest
    );

    runner.addTest(
        "CalendarService Search Event By ID Test",
        calendarServiceSearchEventByIdTest
    );

    runner.addTest(
        "CalendarService Search Event By ID Not Found Test",
        calendarServiceSearchEventByIdNotFoundTest
    );

    runner.addTest(
        "CalendarService Get Events On Date Test",
        calendarServiceGetEventsOnDateTest
    );

    runner.addTest(
        "CalendarService Get Events On Date No Events Test",
        calendarServiceGetEventsOnDateNoEventsTest
    );

    runner.addTest(
        "CalendarService Get Events In Range Test",
        calendarServiceGetEventsInRangeTest
    );

    runner.addTest(
        "CalendarService Get Events In Range No Events Test",
        calendarServiceGetEventsInRangeNoEventsTest
    );

    runner.addTest(
        "CalendarService Get Events In Range Catch Bad Range Test",
        calendarServiceGetEventsInRangeCatchBadRangeTest
    );

}