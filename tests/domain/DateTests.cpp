#include "DateTests.h"
#include "../../src/domain/Date.h"

bool DateConstructorTest()
{
    Date date1;
    Date date2(2023,3,15);
    Date date3("03/15/2023");

    ASSERT_TRUE(date1.getYear() == 0);
    ASSERT_TRUE(date1.getMonth() == 0);
    ASSERT_TRUE(date1.getDay() == 0);

    ASSERT_TRUE(date2.getYear() == 2023);
    ASSERT_TRUE(date2.getMonth() == 3);
    ASSERT_TRUE(date2.getDay() == 15);

    ASSERT_TRUE(date3.getYear() == 2023);
    ASSERT_TRUE(date3.getMonth() == 3);
    ASSERT_TRUE(date3.getDay() == 15);

    return true;
}

bool DateConstructorInvalidDateTest()
{
    try{
        Date date(2023, 12, 32);
    } catch (const std::invalid_argument& e) {
        return true; // Test passed, exception was thrown
    }
    return false;
}

bool DateConstructorInvalidMonthTest()
{
    try{
        Date date(2023, 13, 15);
    } catch (const std::invalid_argument& e) {
        return true; // Test passed, exception was thrown
    }
    return false;
}

bool DateConstructorInvalidYearTest()
{
    try{
        Date date(1999, 12, 15);
    } catch (const std::invalid_argument& e) {
        return true; // Test passed, exception was thrown
    }
    return false;
}

bool DateConstructorNegativeDayTest()
{
    try{
        Date date(2023, 12, -1);
    } catch (const std::invalid_argument& e) {
        return true; // Test passed, exception was thrown
    }
    return false;
}

bool DateConstructorNegativeMonthTest()
{
    try{
        Date date(2023, -1, 15);
    } catch (const std::invalid_argument& e) {
        return true; // Test passed, exception was thrown
    }
    return false;
}

bool DateGettersTest()
{
    Date date(2023, 3, 15);
    ASSERT_TRUE(date.getYear() == 2023);
    ASSERT_TRUE(date.getMonth() == 3);
    ASSERT_TRUE(date.getDay() == 15);
    return true;
}

bool DateSettersTest()
{
    Date date;
    date.setYear(2023);
    date.setMonth(3);
    date.setDay(15);

    ASSERT_TRUE(date.getYear() == 2023);
    ASSERT_TRUE(date.getMonth() == 3);
    ASSERT_TRUE(date.getDay() == 15);

    return true;
}

bool DateOutputOperatorTest()
{
    Date date(2023, 3, 15);
    std::ostringstream oss;
    oss << date;
    ASSERT_TRUE(oss.str() == "15/03/2023");
    return true;
}

bool DateStringTest()
{
    Date date("03/15/2023");
    ASSERT_TRUE(date.getYear() == 2023);
    ASSERT_TRUE(date.getMonth() == 3);
    ASSERT_TRUE(date.getDay() == 15);
    return true;
}

bool DateStringCatchInvalidDelimitTest()
{
    try {
        Date date("03-15-2023");
    } catch (const std::invalid_argument& e) {
        return true; // Test passed, exception was thrown
    }
    return false; // Test failed, no exception was thrown
}

bool DateStringCatchInvalidFormatTest()
{
    try {
        Date date("2023/05/15");
    } catch (const std::invalid_argument& e) {
        return true; // Test passed, exception was thrown
    }
    return false; // Test failed, no exception was thrown
}

bool DateCatchInvalidDayTest()
{
    Date date;
    try{
        date.setDay(32);
    } catch (const std::invalid_argument& e) {
        return true; // Test passed, exception was thrown
    }
    return false;
}

bool DateCatchNegativeDayTest()
{
    Date date;
    try{
        date.setDay(-1);
    } catch (const std::invalid_argument& e) {
        return true; // Test passed, exception was thrown
    }
    return false;
}

bool DateCatchNegativeMonthTest()
{
    Date date;
    try{
        date.setMonth(-1);
    } catch (const std::invalid_argument& e) {
        return true; // Test passed, exception was thrown
    }
    return false;
}

bool DateCatchInvalidMonthTest()
{
    Date date;
    try{
        date.setMonth(13);
    } catch (const std::invalid_argument& e) {
        return true; // Test passed, exception was thrown
    }
    return false;
}

bool DateCatchInvalidYearTest()
{
    Date date;
    try{
        date.setYear(1999);
    } catch (const std::invalid_argument& e) {
        return true; // Test passed, exception was thrown
    }
    return false;
}

bool DateOverloadedEqualityTest()
{
    Date date1(2023, 3, 15);
    Date date2(2023, 3, 15);
    Date date3(2024, 4, 16);

    ASSERT_TRUE(date1 == date2); // Should be true
    ASSERT_FALSE(date1 == date3); // Should be false

    return true;
}

bool DateOperatorGTTest()
{
    Date date1(2023, 3, 15);
    Date date2(2023, 3, 16);
    Date date3(2023, 3, 15);

    ASSERT_TRUE(date2 > date1); 
    ASSERT_FALSE(date1 > date2); 
    ASSERT_FALSE(date1 > date3); 

    return true;
}

bool DateOperatorGTETest()
{
    Date date1(2023, 3, 15);
    Date date2(2023, 3, 16);
    Date date3(2023, 3, 15);

    ASSERT_TRUE(date2 >= date1); 
    ASSERT_FALSE(date1 >= date2); 
    ASSERT_TRUE(date1 >= date3); //true in this case because they are equal and the operator is >=

    return true;
}

bool DateOperatorLTTest()
{
    Date date1(2023, 3, 15);
    Date date2(2023, 3, 16);
    Date date3(2023, 3, 15);

    ASSERT_TRUE(date1 < date2); 
    ASSERT_FALSE(date2 < date1); 
    ASSERT_FALSE(date1 < date3);

    return true;
}

bool DateOperatorLTETest()
{
    Date date1(2023, 3, 15);
    Date date2(2023, 3, 16);
    Date date3(2023, 3, 15);

    ASSERT_TRUE(date1 <= date2); 
    ASSERT_FALSE(date2 <= date1); 
    ASSERT_TRUE(date1 <= date3); //true in this case because they are equal and the operator is <=

    return true;
}

bool DateOperatorEQTest()
{
    Date date1(2023, 3, 15);
    Date date2(2023, 3, 16);
    Date date3(2023, 3, 15);

    ASSERT_FALSE(date1 == date2); 
    ASSERT_TRUE(date1 == date3);

    return true;
}



void registerDateTests(TestRunner& runner)
{
    runner.addTest(
        "Date Constructor Test",
        DateConstructorTest
    );
    runner.addTest(
        "Date Constructor Invalid Date Test",
        DateConstructorInvalidDateTest
    );
    runner.addTest(
        "Date Constructor Invalid Month Test",
        DateConstructorInvalidMonthTest
    );
    runner.addTest(
        "Date Constructor Invalid Year Test",
        DateConstructorInvalidYearTest
    );
    runner.addTest(
        "Date Constructor Negative Day Test",
        DateConstructorNegativeDayTest
    );
    runner.addTest(
        "Date Constructor Negative Month Test",
        DateConstructorNegativeMonthTest
    );
    runner.addTest(
        "Date Getter Test",
        DateGettersTest
    );
    runner.addTest(
        "Date Setter Test",
        DateSettersTest
    );
    runner.addTest(
        "Date Output Operator Test",
        DateOutputOperatorTest
    );
    runner.addTest(
        "Date String Test",
        DateStringTest
    );
    runner.addTest(
        "Date String Catch Invalid Delimiter Test",
        DateStringCatchInvalidDelimitTest
    );
    runner.addTest(
        "Date String Catch Invalid Format Test",
        DateStringCatchInvalidFormatTest
    );
    runner.addTest(
        "Date Catch Invalid Day Test",
        DateCatchInvalidDayTest
    );
    runner.addTest(
        "Date Catch Negative Day Test",
        DateCatchNegativeDayTest
    );  
    runner.addTest(
        "Date Catch Negative Month Test",
        DateCatchNegativeMonthTest
    );
    runner.addTest(
        "Date Catch Invalid Month Test",
        DateCatchInvalidMonthTest
    );
    runner.addTest(
        "Date Catch Invalid Year Test",
        DateCatchInvalidYearTest
    );
    runner.addTest(
        "Date Overloaded Equality Test",
        DateOverloadedEqualityTest
    );
    runner.addTest(
        "Date Operator > Test",
        DateOperatorGTTest
    );
    runner.addTest(
        "Date Operator >= Test",
        DateOperatorGTETest
    );
    runner.addTest(
        "Date Operator < Test",
        DateOperatorLTTest
    );
    runner.addTest(
        "Date Operator <= Test",
        DateOperatorLTETest
    );
    runner.addTest(
        "Date Operator == Test",
        DateOperatorEQTest
    );

}

