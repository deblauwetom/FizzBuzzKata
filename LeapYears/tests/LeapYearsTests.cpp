#include <gmock/gmock.h>
#include <gtest/gtest.h>

//#include "LeapYears.hpp"

using namespace testing;
using namespace std;
//using namespace katas;

bool isLeapYear(int year)
{
    auto divisableBy100 = ((year % 100) == 0 ? true : false);
    auto divisableBy400 = ((year % 400) == 0 ? true : false);
    auto divisableBy4 = ((year % 4) == 0 ? true : false);
    if (!divisableBy4) {
        return false;
    }
    if (divisableBy100 && !divisableBy400) {
        return false;
    }
    return true;
}

class LeapYearsFixture : public Test {
public:
};

TEST_F(LeapYearsFixture, GivenYearDivisableBy400_ThenIsLeapYear)
{
    auto year = 2000;

    EXPECT_TRUE(isLeapYear(year));
}

TEST_F(LeapYearsFixture, GivenYearDivisableBy100AndBy400_ThenIsLeapYear)
{
    auto year = 1600;

    EXPECT_TRUE(isLeapYear(year));
}

TEST_F(LeapYearsFixture, GivenYearDivisableBy100ButNotBy400_ThenIsNotLeapYear)
{
    auto year = 1800;

    EXPECT_FALSE(isLeapYear(year));
}

TEST_F(LeapYearsFixture, GivenYearDivisableBy4ButNotBy100_ThenIsLeapYear)
{
    EXPECT_TRUE(isLeapYear(2008));
    EXPECT_TRUE(isLeapYear(2012));
    EXPECT_TRUE(isLeapYear(2016));
}

TEST_F(LeapYearsFixture, GivenYearNotDivisableBy4_ThenIsNotLeapYear)
{
    EXPECT_FALSE(isLeapYear(2301));
}
