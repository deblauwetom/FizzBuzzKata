#include <gmock/gmock.h>
#include <gtest/gtest.h>

//#include "LeapYears.hpp"

using namespace testing;
using namespace std;
//using namespace katas;

bool isLeapYear(int year)
{
    auto isDivisableBy = [year](int i) {
        return (year % i) == 0;
    };
    if (!isDivisableBy(4)) {
        return false;
    }
    if (isDivisableBy(100) && !isDivisableBy(400)) {
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
    EXPECT_FALSE(isLeapYear(1700));
    EXPECT_FALSE(isLeapYear(1800));
    EXPECT_FALSE(isLeapYear(1900));
    EXPECT_FALSE(isLeapYear(2100));
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
    EXPECT_FALSE(isLeapYear(2302));
    EXPECT_FALSE(isLeapYear(1234));
}
