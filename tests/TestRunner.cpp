#include "TestFramework.h"
// Domain tests
#include "domain/DateTests.h"
#include "domain/TimeTests.h"
#include "domain/DateTimeTests.h"
#include "domain/EventTests.h"
// Application tests
#include "application/CalendarServiceTests.h"


int main()
{
    TestRunner runner;

    //Domain Layer Tests
    registerDateTests(runner);
    registerTimeTests(runner);
    registerDateTimeTests(runner);
    registerEventTests(runner);
    
    //Application Layer Tests
    registerCalendarServiceTests(runner);

    //Future Layers Below

    return runner.run();
}