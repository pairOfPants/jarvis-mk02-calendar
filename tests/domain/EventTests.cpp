#include "../../src/domain/Event.h"
#include "EventTests.h"


bool EventConstructorTest()
{
    DateTime startDateTimeEmpty = DateTime();
    DateTime endDateTimeEmpty = DateTime();
    Event event = Event();
  
    DateTime startDateTime(2023, 3, 15, 12, 30, 45);
    DateTime endDateTime(2023, 3, 15, 13, 30, 45);
    Event event2(startDateTime, endDateTime, "Meeting", "Project discussion", "Conference Room");

    ASSERT_TRUE(event.getStartDateTime() == startDateTimeEmpty);
    ASSERT_TRUE(event.getEndDateTime() == endDateTimeEmpty);
    ASSERT_TRUE(event.getTitle() == "");
    ASSERT_TRUE(event.getDescription() == "");
    ASSERT_TRUE(event.getLocation() == "");

    ASSERT_TRUE(event2.getStartDateTime() == startDateTime);
    ASSERT_TRUE(event2.getEndDateTime() == endDateTime);
    ASSERT_TRUE(event2.getTitle() == "Meeting");
    ASSERT_TRUE(event2.getDescription() == "Project discussion");
    ASSERT_TRUE(event2.getLocation() == "Conference Room");

    return true;
}

bool eventGettersTest()
{
    Event event(DateTime(2023, 3, 15, 12, 30, 45), DateTime(2023, 3, 15, 13, 30, 45), "Meeting", "Project discussion", "Conference Room");
    ASSERT_TRUE(event.getStartDateTime() == DateTime(2023, 3, 15, 12, 30, 45));
    ASSERT_TRUE(event.getEndDateTime() == DateTime(2023, 3, 15, 13, 30, 45));
    ASSERT_TRUE(event.getTitle() == "Meeting");
    ASSERT_TRUE(event.getDescription() == "Project discussion");
    ASSERT_TRUE(event.getLocation() == "Conference Room");
    ASSERT_TRUE(event.getRepeatType() == Event::REPEAT_TYPE::NONE);
    ASSERT_TRUE(event.getStatus() == Event::EventStatus::CONFIRMED);
    ASSERT_TRUE(event.getId() == 0);
    ASSERT_TRUE(event.getExternalId() == "");
    return true;
}

bool eventSettersTest()
{
    Event event;
    DateTime startDateTime(2023, 3, 15, 12, 30, 45);
    DateTime endDateTime(2023, 3, 15, 13, 30, 45);
    event.setStartDateTime(startDateTime);
    event.setEndDateTime(endDateTime);
    event.setTitle("Meeting");
    event.setDescription("Project discussion");
    event.setLocation("Conference Room");
    event.setRepeatType(Event::REPEAT_TYPE::DAILY);
    event.setStatus(Event::EventStatus::TENTATIVE);
    event.setId(1);
    event.setExternalId("external_123");

    ASSERT_TRUE(event.getStartDateTime() == DateTime(2023, 3, 15, 12, 30, 45));
    ASSERT_TRUE(event.getEndDateTime() == DateTime(2023, 3, 15, 13, 30, 45));
    ASSERT_TRUE(event.getTitle() == "Meeting");
    ASSERT_TRUE(event.getDescription() == "Project discussion");
    ASSERT_TRUE(event.getLocation() == "Conference Room");
    ASSERT_TRUE(event.getRepeatType() == Event::REPEAT_TYPE::DAILY);
    ASSERT_TRUE(event.getStatus() == Event::EventStatus::TENTATIVE);
    ASSERT_TRUE(event.getId() == 1);
    ASSERT_TRUE(event.getExternalId() == "external_123");
    return true;
}

bool eventOperatorGTTest()
{
    Event event1(DateTime(2023, 3, 15, 12, 30, 45), DateTime(2023, 3, 15, 13, 30, 45), "Meeting", "Project discussion", "Conference Room");
    Event event2(DateTime(2023, 3, 15, 12, 30, 46), DateTime(2023, 3, 15, 13, 30, 45), "Meeting", "Project discussion", "Conference Room");

    ASSERT_TRUE(event2 > event1); 
    ASSERT_FALSE(event1 > event2); 
    ASSERT_FALSE(event1 > event1); 

    return true;
}

bool eventOperatorGTETest()
{
    Event event1(DateTime(2023, 3, 15, 12, 30, 45), DateTime(2023, 3, 15, 13, 30, 45), "Meeting", "Project discussion", "Conference Room");
    Event event2(DateTime(2023, 3, 15, 12, 30, 46), DateTime(2023, 3, 15, 13, 30, 45), "Meeting", "Project discussion", "Conference Room");

    ASSERT_TRUE(event2 >= event1); 
    ASSERT_FALSE(event1 >= event2); 
    ASSERT_TRUE(event1 >= event1); 

    return true;
}

bool eventOperatorLTTest()
{
    Event event1(DateTime(2023, 3, 15, 12, 30, 45), DateTime(2023, 3, 15, 13, 30, 45), "Meeting", "Project discussion", "Conference Room");
    Event event2(DateTime(2023, 3, 15, 12, 30, 46), DateTime(2023, 3, 15, 13, 30, 45), "Meeting", "Project discussion", "Conference Room");

    ASSERT_TRUE(event1 < event2); 
    ASSERT_FALSE(event2 < event1); 
    ASSERT_FALSE(event1 < event1); 

    return true;
}

bool eventOperatorLTETest()
{
    Event event1(DateTime(2023, 3, 15, 12, 30, 45), DateTime(2023, 3, 15, 13, 30, 45), "Meeting", "Project discussion", "Conference Room");
    Event event2(DateTime(2023, 3, 15, 12, 30, 46), DateTime(2023, 3, 15, 13, 30, 45), "Meeting", "Project discussion", "Conference Room");

    ASSERT_TRUE(event1 <= event2); 
    ASSERT_FALSE(event2 <= event1); 
    ASSERT_TRUE(event1 <= event1); 

    return true;
}

bool eventOperatorEQTest()
{
    Event event1(DateTime(2023, 3, 15, 12, 30, 45), DateTime(2023, 3, 15, 13, 30, 45), "Meeting", "Project discussion", "Conference Room");
    Event event2(DateTime(2023, 3, 15, 12, 30, 46), DateTime(2023, 3, 15, 13, 30, 45), "Meeting", "Project discussion", "Conference Room");
    Event event3(DateTime(2023, 3, 15, 12, 30, 45), DateTime(2023, 3, 15, 13, 30, 45), "Meeting", "Project discussion", "Conference Room");

    ASSERT_FALSE(event1 == event2); 
    ASSERT_TRUE(event1 == event3); 

    return true;
}

void registerEventTests(TestRunner& runner)
{
    runner.addTest("Event Constructor Test", EventConstructorTest);
    runner.addTest("Event Getters Test", eventGettersTest);
    runner.addTest("Event Setters Test", eventSettersTest);
    runner.addTest("Event Operator > Test", eventOperatorGTTest);
    runner.addTest("Event Operator >= Test", eventOperatorGTETest);
    runner.addTest("Event Operator < Test", eventOperatorLTTest);
    runner.addTest("Event Operator <= Test", eventOperatorLTETest);
    runner.addTest("Event Operator == Test", eventOperatorEQTest);

}