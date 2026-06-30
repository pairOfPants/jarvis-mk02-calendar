#include "../../src/domain/Time.h"
#include "TimeTests.h"

bool TimeConstructorTest()
{
    Time time1;
    Time time2(12, 30, 45);
    Time time3("12:30:45");

    ASSERT_TRUE(time1.getHour() == 0);
    ASSERT_TRUE(time1.getMinute() == 0);
    ASSERT_TRUE(time1.getSecond() == 0);

    ASSERT_TRUE(time2.getHour() == 12);
    ASSERT_TRUE(time2.getMinute() == 30);
    ASSERT_TRUE(time2.getSecond() == 45);

    ASSERT_TRUE(time3.getHour() == 12);
    ASSERT_TRUE(time3.getMinute() == 30);
    ASSERT_TRUE(time3.getSecond() == 45);

    return true;
}

bool TimeConstructorNonNumberTest()
{
    try {
        Time time("invalid_time_string");
    } catch (const std::invalid_argument& e) {
        return true; // Test passed, exception was thrown
    }
    return false; // Test failed, no exception was thrown
}

bool TimeConstructorInvalidDelimeterTest()
{
    try {
        Time time("12-30-45");
    } catch (const std::invalid_argument& e) {
        return true; // Test passed, exception was thrown
    }
    return false; // Test failed, no exception was thrown
}

bool TimeConstructorInvalidHourTest()
{
    try {
        Time time(25,0,0);
    } catch (const std::invalid_argument& e) {
        return true; // Test passed, exception was thrown
    }
    return false; // Test failed, no exception was thrown
}

bool TimeConstructorInvalidMinuteTest()
{
    try {
        Time time(12,60,0);
    } catch (const std::invalid_argument& e) {
        return true; // Test passed, exception was thrown
    }
    return false; // Test failed, no exception was thrown
}

bool TimeConstructorInvalidSecondTest()
{
    try {
        Time time(12,0,60);
    } catch (const std::invalid_argument& e) {
        return true; // Test passed, exception was thrown
    }
    return false; // Test failed, no exception was thrown
}

bool TimeConstructorNegativeHourTest()
{
    try {
        Time time(-1,0,0);
    } catch (const std::invalid_argument& e) {
        return true; // Test passed, exception was thrown
    }
    return false; // Test failed, no exception was thrown
}

bool TimeConstructorNegativeMinuteTest()
{
    try {
        Time time(12,-1,0);
    } catch (const std::invalid_argument& e) {
        return true; // Test passed, exception was thrown
    }
    return false; // Test failed, no exception was thrown
}

bool TimeConstructorNegativeSecondTest()
{
    try {
        Time time(12,0,-1);
    } catch (const std::invalid_argument& e) {
        return true; // Test passed, exception was thrown
    }
    return false; // Test failed, no exception was thrown
}

bool TimeGettersTest()
{
    Time time(12, 30, 45);

    ASSERT_TRUE(time.getHour() == 12);
    ASSERT_TRUE(time.getMinute() == 30);
    ASSERT_TRUE(time.getSecond() == 45);

    return true;
}

bool TimeSettersTest()
{
    Time time;

    time.setHour(12);
    time.setMinute(30);
    time.setSecond(45);

    ASSERT_TRUE(time.getHour() == 12);
    ASSERT_TRUE(time.getMinute() == 30);
    ASSERT_TRUE(time.getSecond() == 45);

    return true;
}

bool TimeOutputOperatorTest()
{
    Time time(12, 30, 45);
    std::ostringstream oss;
    oss << time;

    ASSERT_TRUE(oss.str() == "12:30:45");

    return true;
}

bool TimeStringTest()
{
    Time time("12:30:45");

    ASSERT_TRUE(time.getHour() == 12);
    ASSERT_TRUE(time.getMinute() == 30);
    ASSERT_TRUE(time.getSecond() == 45);

    return true;
}

bool TimeStringCatchInvalidDelimiterTest()
{
    try {
        Time time("12-30-45");
    } catch (const std::invalid_argument& e) {
        return true; // Test passed, exception was thrown
    }
    return false; // Test failed, no exception was thrown
}

bool TimeStringCatchInvalidHourTest()
{
    try {
        Time time("25:30:45");
    } catch (const std::invalid_argument& e) {
        return true; // Test passed, exception was thrown
    }
    return false; // Test failed, no exception was thrown
}

bool TimeStringCatchInvalidMinuteTest()
{
    try {
        Time time("12:60:45");
    } catch (const std::invalid_argument& e) {
        return true; // Test passed, exception was thrown
    }
    return false; // Test failed, no exception was thrown
}

bool TimeStringCatchInvalidSecondTest()
{
    try {
        Time time("12:30:60");
    } catch (const std::invalid_argument& e) {
        return true; // Test passed, exception was thrown
    }
    return false; // Test failed, no exception was thrown
}

bool TimeOverloadedEqualityTest()
{
    Time time1(12, 30, 45);
    Time time2(12, 30, 45);
    Time time3(13, 31, 46);

    ASSERT_TRUE(time1 == time2); // Should be true
    ASSERT_FALSE(time1 == time3); // Should be false

    return true;
}

bool TimeOperatorGTTest()
{
    Time time1(12, 30, 45);
    Time time2(12, 30, 46);
    Time time3(12, 30, 45);

    ASSERT_TRUE(time2 > time1);
    ASSERT_FALSE(time1 > time2);
    ASSERT_FALSE(time1 > time3); 

    return true;
}

bool TimeOperatorGTETest()
{
    Time time1(12, 30, 45);
    Time time2(12, 30, 46);
    Time time3(12, 30, 45);

    ASSERT_TRUE(time2 >= time1); 
    ASSERT_FALSE(time1 >= time2); 
    ASSERT_TRUE(time1 >= time3); //true in this case because they are equal and the operator is >=

    return true;
}

bool TimeOperatorLTTest()
{
    Time time1(12, 30, 45);
    Time time2(12, 30, 46);
    Time time3(12, 30, 45);

    ASSERT_TRUE(time1 < time2); 
    ASSERT_FALSE(time2 < time1); 
    ASSERT_FALSE(time1 < time3);

    return true;
}

bool TimeOperatorLTETest()
{
    Time time1(12, 30, 45);
    Time time2(12, 30, 46);
    Time time3(12, 30, 45);

    ASSERT_TRUE(time1 <= time2); 
    ASSERT_FALSE(time2 <= time1); 
    ASSERT_TRUE(time1 <= time3); //true in this case because they are equal and the operator is <=

    return true;
}

bool TimeOperatorEQTest()
{
    Time time1(12, 30, 45);
    Time time2(12, 30, 46);
    Time time3(12, 30, 45);

    ASSERT_FALSE(time1 == time2); 
    ASSERT_TRUE(time1 == time3);

    return true;
}

void registerTimeTests(TestRunner& runner)
{
    runner.addTest(
        "Time Constructor Test",
        TimeConstructorTest
    );
    runner.addTest(
        "Time Constructor Non-Number Test",
        TimeConstructorNonNumberTest
    );
    runner.addTest(
        "Time Constructor Invalid Delimiter Test",
        TimeConstructorInvalidDelimeterTest
    );
    runner.addTest(
        "Time Constructor Invalid Hour Test",
        TimeConstructorInvalidHourTest
    );
    runner.addTest(
        "Time Constructor Invalid Minute Test",
        TimeConstructorInvalidMinuteTest
    );
    runner.addTest(
        "Time Constructor Invalid Second Test",
        TimeConstructorInvalidSecondTest
    );
    runner.addTest(
        "Time Constructor Negative Hour Test",
        TimeConstructorNegativeHourTest
    );
    runner.addTest(
        "Time Constructor Negative Minute Test",
        TimeConstructorNegativeMinuteTest
    );
    runner.addTest(
        "Time Constructor Negative Second Test",
        TimeConstructorNegativeSecondTest
    );
    runner.addTest(
        "Time Getters Test",
        TimeGettersTest
    );
    runner.addTest(
        "Time Setters Test",
        TimeSettersTest
    );
    runner.addTest(
        "Time Output Operator Test",
        TimeOutputOperatorTest
    );
    runner.addTest(
        "Time String Test",
        TimeStringTest
    );
    runner.addTest(
        "Time String Catch Invalid Delimiter Test",
        TimeStringCatchInvalidDelimiterTest
    );
    runner.addTest(
        "Time String Catch Invalid Hour Test",
        TimeStringCatchInvalidHourTest
    );
    runner.addTest(
        "Time String Catch Invalid Minute Test",
        TimeStringCatchInvalidMinuteTest
    );
    runner.addTest(
        "Time String Catch Invalid Second Test",
        TimeStringCatchInvalidSecondTest
    );
    runner.addTest(
        "Time Overloaded Equality Test",
        TimeOverloadedEqualityTest
    );
    runner.addTest(
        "Time Operator > Test",
        TimeOperatorGTTest
    );
    runner.addTest(
        "Time Operator >= Test",
        TimeOperatorGTETest
    );
    runner.addTest(
        "Time Operator < Test",
        TimeOperatorLTTest
    );
    runner.addTest(
        "Time Operator <= Test",
        TimeOperatorLTETest
    );
    runner.addTest(
        "Time Operator == Test",
        TimeOperatorEQTest
    );
}