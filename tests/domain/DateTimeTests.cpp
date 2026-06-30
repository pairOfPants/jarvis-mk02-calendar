#include "DateTimeTests.h"
#include "../../src/domain/DateTime.h"

bool DateTimeConstructorTest()
{
    DateTime dt1;
    DateTime dt2(2023, 3, 15, 12, 30, 45);
    DateTime dt3(Date(2023, 3, 15), Time(12, 30, 45));

    ASSERT_TRUE(dt1.getDate().getYear() == 0);
    ASSERT_TRUE(dt1.getDate().getMonth() == 0);
    ASSERT_TRUE(dt1.getDate().getDay() == 0);
    ASSERT_TRUE(dt1.getTime().getHour() == 0);
    ASSERT_TRUE(dt1.getTime().getMinute() == 0);
    ASSERT_TRUE(dt1.getTime().getSecond() == 0);

    ASSERT_TRUE(dt2.getDate().getYear() == 2023);
    ASSERT_TRUE(dt2.getDate().getMonth() == 3);
    ASSERT_TRUE(dt2.getDate().getDay() == 15);
    ASSERT_TRUE(dt2.getTime().getHour() == 12);
    ASSERT_TRUE(dt2.getTime().getMinute() == 30);
    ASSERT_TRUE(dt2.getTime().getSecond() == 45);

    ASSERT_TRUE(dt3.getDate().getYear() == 2023);
    ASSERT_TRUE(dt3.getDate().getMonth() == 3);
    ASSERT_TRUE(dt3.getDate().getDay() == 15);
    ASSERT_TRUE(dt3.getTime().getHour() == 12);
    ASSERT_TRUE(dt3.getTime().getMinute() == 30);
    ASSERT_TRUE(dt3.getTime().getSecond() == 45);

    return true;
}

bool DateTimeGettersTest()
{
    DateTime dt(2023, 3, 15, 12, 30, 45);

    ASSERT_TRUE(dt.getDate().getYear() == 2023);
    ASSERT_TRUE(dt.getDate().getMonth() == 3);
    ASSERT_TRUE(dt.getDate().getDay() == 15);
    ASSERT_TRUE(dt.getTime().getHour() == 12);
    ASSERT_TRUE(dt.getTime().getMinute() == 30);
    ASSERT_TRUE(dt.getTime().getSecond() == 45);

    return true;
}

bool DateTimeOperatorGTTest()
{
    DateTime dt1(2023, 3, 15, 12, 30, 45);
    DateTime dt2(2023, 3, 15, 12, 30, 46);
    DateTime dt3(2023, 3, 15, 12, 30, 45);

    ASSERT_TRUE(dt2 > dt1); // Should be true
    ASSERT_FALSE(dt1 > dt2); // Should be false
    ASSERT_FALSE(dt1 > dt3); // Should be false

    return true;
}

bool DateTimeOperatorGTETest()
{
    DateTime dt1(2023, 3, 15, 12, 30, 45);
    DateTime dt2(2023, 3, 15, 12, 30, 46);
    DateTime dt3(2023, 3, 15, 12, 30, 45);

    ASSERT_TRUE(dt2 >= dt1); 
    ASSERT_FALSE(dt1 >= dt2); 
    ASSERT_TRUE(dt1 >= dt3); //true in this case because they are equal and the operator is >=

    return true;
}

bool DateTimeOperatorLTTest()
{
    DateTime dt1(2023, 3, 15, 12, 30, 45);
    DateTime dt2(2023, 3, 15, 12, 30, 46);
    DateTime dt3(2023, 3, 15, 12, 30, 45);

    ASSERT_TRUE(dt1 < dt2); 
    ASSERT_FALSE(dt2 < dt1); 
    ASSERT_FALSE(dt1 < dt3);

    return true;
}

bool DateTimeOperatorLTETest()
{
    DateTime dt1(2023, 3, 15, 12, 30, 45);
    DateTime dt2(2023, 3, 15, 12, 30, 46);
    DateTime dt3(2023, 3, 15, 12, 30, 45);

    ASSERT_TRUE(dt1 <= dt2); 
    ASSERT_FALSE(dt2 <= dt1); 
    ASSERT_TRUE(dt1 <= dt3); //true in this case because they are equal and the operator is <=

    return true;
}

bool DateTimeOperatorEQTest()
{
    DateTime dt1(2023, 3, 15, 12, 30, 45);
    DateTime dt2(2023, 3, 15, 12, 30, 46);
    DateTime dt3(2023, 3, 15, 12, 30, 45);

    ASSERT_FALSE(dt1 == dt2); 
    ASSERT_TRUE(dt1 == dt3); 

    return true;
}

bool DateTimeOutputOperatorTest()
{
    DateTime dt(2023, 3, 15, 12, 30, 45);
    std::ostringstream oss;
    oss << dt;

    std::string expectedOutput = "15/03/2023 12:30:45";
    ASSERT_TRUE(oss.str() == expectedOutput);

    return true;
}



void registerDateTimeTests(TestRunner& runner)
{
    runner.addTest(
        "DateTime Constructor Test",
         DateTimeConstructorTest
    );
    runner.addTest(
        "DateTime Getters Test", 
        DateTimeGettersTest
    );
    runner.addTest(
        "DateTime Operator > Test", 
        DateTimeOperatorGTTest
    );
    runner.addTest(
        "DateTime Operator >= Test", 
        DateTimeOperatorGTETest
    );
    runner.addTest(
        "DateTime Operator < Test", 
        DateTimeOperatorLTTest
    );
    runner.addTest(
        "DateTime Operator <= Test", 
        DateTimeOperatorLTETest
    );
    runner.addTest(
        "DateTime Operator == Test", 
        DateTimeOperatorEQTest
    );
    runner.addTest(
        "DateTime Output Operator Test", 
        DateTimeOutputOperatorTest
    );
}