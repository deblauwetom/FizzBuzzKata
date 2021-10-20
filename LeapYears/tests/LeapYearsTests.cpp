#include <gmock/gmock.h>
#include <gtest/gtest.h>

//#include "LeapYears.hpp"

using namespace testing;
using namespace std;
//using namespace katas;

bool isLeapYear(int year)
{
    return true;
}

class LeapYearsFixture : public Test {
public:
};

TEST_F(LeapYearsFixture, GivenYearDivisableBy400_ThenIsLeapYear)
{
    auto year = 1200;

    EXPECT_TRUE(isLeapYear(year));
}
