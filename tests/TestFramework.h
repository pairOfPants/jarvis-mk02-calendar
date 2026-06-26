/* AI Use Disclaimer:
PLEASE NOTE THAT THIS CODE WAS GENERATED USING THE HELP OF LLMS AND MAY
CONTAIN SECURITY VULNERABILITIES OR LOGIC ERRORS.

No files within ../src directory have been created with AI assistance,
and no actual test cases will be created using LLM support either.
*/
#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <exception>


#define ASSERT_TRUE(condition)                     \
    do                                             \
    {                                              \
        if (!(condition))                          \
        {                                          \
            return false;                          \
        }                                          \
    } while(false)



#define ASSERT_FALSE(condition)                    \
    do                                             \
    {                                              \
        if (condition)                             \
        {                                          \
            return false;                          \
        }                                          \
    } while(false)



#define ASSERT_EQUAL(expected, actual)             \
    do                                             \
    {                                              \
        if ((expected) != (actual))                \
        {                                          \
            return false;                          \
        }                                          \
    } while(false)



class TestRunner
{
public:

    using TestFunction = std::function<bool()>;


private:

    struct TestCase
    {
        std::string name;
        TestFunction function;
    };


    std::vector<TestCase> tests;


public:

    void addTest(
        const std::string& name,
        TestFunction function
    )
    {
        tests.push_back(
            {
                name,
                function
            }
        );
    }


    int run()
    {
        int passedTests = 0;
        int failedTests = 0;


        std::cout
            << "\n============================\n"
            << "Running "
            << tests.size()
            << " tests\n"
            << "============================\n\n";


        for(const auto& test : tests)
        {
            bool result = false;


            try
            {
                result = test.function();
            }
            catch(const std::exception& e)
            {
                std::cout
                    << "[ERROR] "
                    << test.name
                    << "\n"
                    << "Exception: "
                    << e.what()
                    << "\n\n";

                failedTests++;
                continue;
            }
            catch(...)
            {
                std::cout
                    << "[ERROR] "
                    << test.name
                    << "\n"
                    << "Unknown exception\n\n";

                failedTests++;
                continue;
            }



            if(result)
            {
                std::cout
                    << "[PASS] "
                    << test.name
                    << "\n";

                passedTests++;
            }
            else
            {
                std::cout
                    << "[FAIL] "
                    << test.name
                    << "\n";

                failedTests++;
            }
        }


        std::cout
            << "\n============================\n"
            << "Test Results\n"
            << "============================\n"
            << "Passed: "
            << passedTests
            << "\n"
            << "Failed: "
            << failedTests
            << "\n"
            << "Total:  "
            << tests.size()
            << "\n";


        return failedTests == 0 ? 0 : 1;
    }


    size_t testCount() const
    {
        return tests.size();
    }
};