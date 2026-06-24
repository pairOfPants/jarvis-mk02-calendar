#include "calendar.h"
#include <sstream>
//TEST CASES BELOW, MAIN AT BOTTOM
int DateConstructorTest()
{

    try
    {
        Date date1; //default constructor
        Date date2(2023, 3, 15); //constructor with year, month, day
        Date date3("15/03/2023"); //constructor with string
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}

int DateSettersTest()
{
    Date date;

    try
    {
        date.setDay(15);
        date.setMonth(3);
        date.setYear(2023);
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}

int DateGettersTest()
{
    Date date(2023, 3, 15);

    if(date.getDay() != 15) return -1;
    if(date.getMonth() != 3) return -1;
    if(date.getYear() != 2023) return -1;

    return 0;
}

int DateOutputOperatorTest()
{
    Date date(2023, 3, 15);
    std::ostringstream os;
    os << date;

    if(os.str() != "15/03/2023") return -1;

    return 0;
}

int DateStringTest()
{
    Date date("15/03/2023");
    if(date.getDay() != 15 || date.getMonth() != 3 || date.getYear() != 2023) return -1;
    return 0;
}

int DateInvalidDayTest()
{
    Date date;
    try
    {
        date.setDay(32); //invalid day
    }
    catch(const std::invalid_argument& e)
    {
        //std::cerr << e.what() << '\n';
        return 0; //test passed
    }

    return -1; //test failed
}

int DateInvalidMonthTest()
{
    Date date;
    try
    {
        date.setMonth(13); //invalid month
    }
    catch(const std::invalid_argument& e)
    {
        //std::cerr << e.what() << '\n';
        return 0; //test passed
    }

    return -1; //test failed
}   

int DateInvalidYearTest()
{
    Date date;
    try
    {
        date.setYear(1999); //invalid year
    }
    catch(const std::invalid_argument& e)
    {
        //std::cerr << e.what() << '\n';
        return 0; //test passed
    }

    return -1; //test failed
}   

int DateSetInvalidDayTest()
{
    Date date;
    try
    {
        date.setDay(0); //invalid day
    }
    catch(const std::invalid_argument& e)
    {
        //std::cerr << e.what() << '\n';
        return 0; //test passed
    }

    return -1; //test failed
}

int DateSetInvalidMonthTest()
{
    Date date;
    try
    {
        date.setMonth(0); //invalid month
    }
    catch(const std::invalid_argument& e)
    {
        //std::cerr << e.what() << '\n';
        return 0; //test passed
    }

    return -1; //test failed
}

int DateSetInvalidYearTest()
{
    Date date;
    try
    {
        date.setYear(1999); //invalid year
    }
    catch(const std::invalid_argument& e)
    {
        //std::cerr << e.what() << '\n';
        return 0; //test passed
    }

    return -1; //test failed
}

int DateOverloadedAssignmentOperatorTest()
{
    Date date1(2023, 3, 15);
    Date date2;
    date2 = date1;

    if(date2.getDay() != 15 || date2.getMonth() != 3 || date2.getYear() != 2023) return -1;
    return 0;
}

int EventConstructorTest()
{
    try
    {
        Event event1; //default constructor
        Event event2(15, 3, 2023, 16, 3, 2023, "Meeting", "Project meeting"); //constructor with dates and details
        Date startDate(2023, 3, 15);
        Date endDate(2023, 3, 16);
        Event event3(&startDate, &endDate, "Meeting", "Project meeting"); //constructor with date pointers and details
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
        return -1; //test failed
    }

    return 0;
}

int EventDestructorTest()
{
    Event* event = new Event(15, 3, 2023, 16, 3, 2023, "Meeting", "Project meeting");
    delete event; //should not cause any memory leaks or crashes
    return 0;
}

int EventGettersTest()
{
    Date startDate(2023, 3, 15);
    Date endDate(2023, 3, 16);
    Event event(&startDate, &endDate, "Meeting", "Project meeting");

    if(event.getStartDate()->getDay() != 15 || event.getStartDate()->getMonth() != 3 || event.getStartDate()->getYear() != 2023) return -1;
    if(event.getEndDate()->getDay() != 16 || event.getEndDate()->getMonth() != 3 || event.getEndDate()->getYear() != 2023) return -1;
    if(event.getName() != "Meeting") return -1;
    if(event.getDescription() != "Project meeting") return -1;

    return 0;
}

int EventSettersTest()
{
    Date startDate(2023, 3, 15);
    Date endDate(2023, 3, 16);
    Event event(&startDate, &endDate, "Meeting", "Project meeting");

    Date newStartDate(2023, 4, 1);
    Date newEndDate(2023, 4, 2);
    event.setStartDate(&newStartDate);
    event.setEndDate(&newEndDate);
    event.setName("New Meeting");
    event.setDescription("New project meeting");

    if(event.getStartDate()->getDay() != 1 || event.getStartDate()->getMonth() != 4 || event.getStartDate()->getYear() != 2023) return -1;
    if(event.getEndDate()->getDay() != 2 || event.getEndDate()->getMonth() != 4 || event.getEndDate()->getYear() != 2023) return -1;
    if(event.getName() != "New Meeting") return -1;
    if(event.getDescription() != "New project meeting") return -1;

    return 0;
}

int EventInvalidDateTest()
{
    Date startDate(2023, 3, 15);
    Date endDate(2023, 3, 16);
    Event event(&startDate, &endDate, "Meeting", "Project meeting");

    try
    {
        Date invalidStartDate(1999, 1, 1); //invalid year
        event.setStartDate(&invalidStartDate);
    }
    catch(const std::invalid_argument& e)
    {
        //std::cerr << e.what() << '\n';
        return 0; //test passed
    }

    return -1; //test failed
}



int main()
{
    int testCasesPassed = 0;
    int totalTestCases = 0;
    std::cout << "Tests on DATE data type..." << std::endl;
    if(DateConstructorTest() == 0) testCasesPassed++;
    else std::cerr << "DateConstructorTest failed." << std::endl;
    totalTestCases++;
    if(DateSettersTest() == 0) testCasesPassed++;
    else std::cerr << "DateSettersTest failed." << std::endl;
    totalTestCases++;
    if(DateGettersTest() == 0) testCasesPassed++;
    else std::cerr << "DateGettersTest failed." << std::endl;
    totalTestCases++;
    if(DateOutputOperatorTest() == 0) testCasesPassed++;
    else std::cerr << "DateOutputOperatorTest failed." << std::endl;
    totalTestCases++;
    if(DateStringTest() == 0) testCasesPassed++;
    else std::cerr << "DateStringTest failed." << std::endl;
    totalTestCases++;
    if(DateInvalidDayTest() == 0) testCasesPassed++;
    else std::cerr << "DateInvalidDayTest failed." << std::endl;
    totalTestCases++;
    if(DateInvalidMonthTest() == 0) testCasesPassed++;
    else std::cerr << "DateInvalidMonthTest failed." << std::endl;
    totalTestCases++;
    if(DateInvalidYearTest() == 0) testCasesPassed++;
    else std::cerr << "DateInvalidYearTest failed." << std::endl;
    totalTestCases++;
    if(DateSetInvalidDayTest() == 0) testCasesPassed++;
    else std::cerr << "DateSetInvalidDayTest failed." << std::endl;
    totalTestCases++;
    if(DateSetInvalidMonthTest() == 0) testCasesPassed++;
    else std::cerr << "DateSetInvalidMonthTest failed." << std::endl;
    totalTestCases++;
    if(DateSetInvalidYearTest() == 0) testCasesPassed++;
    else std::cerr << "DateSetInvalidYearTest failed." << std::endl;
    totalTestCases++;
    if(DateOverloadedAssignmentOperatorTest() == 0) testCasesPassed++;
    else std::cerr << "DateOverloadedAssignmentOperatorTest failed." << std::endl;
    totalTestCases++;
    std::cout << "Tests on DATE data type completed. " << testCasesPassed << "/" << totalTestCases << " test cases passed." << std::endl;

    testCasesPassed = 0;
    totalTestCases = 0;
    std::cout << "Tests on EVENT data type..." << std::endl;
    if(EventConstructorTest() == 0) testCasesPassed++;
    else std::cerr << "EventConstructorTest failed." << std::endl;
    totalTestCases++;
    if(EventDestructorTest() == 0) testCasesPassed++;
    else std::cerr << "EventDestructorTest failed." << std::endl;
    totalTestCases++;
    if(EventGettersTest() == 0) testCasesPassed++;
    else std::cerr << "EventGettersTest failed." << std::endl;
    totalTestCases++;
    if(EventSettersTest() == 0) testCasesPassed++;
    else std::cerr << "EventSettersTest failed." << std::endl;
    totalTestCases++;
    if(EventInvalidDateTest() == 0) testCasesPassed++;
    else std::cerr << "EventInvalidDateTest failed." << std::endl;
    totalTestCases++;
    std::cout << "Tests on EVENT data type completed. " << testCasesPassed << "/" << totalTestCases << " test cases passed." << std::endl;


    return 0;
}
