#include <limits.h>
#include "nextDate.h"
#include "gtest/gtest.h"

TEST(nextDateC2, nextDate) {
	EXPECT_EQ("month not in 1 ... 12", nextDate(0,15,1912));
	EXPECT_EQ("day not in 1 ... 31", nextDate(6,0,1912));
	EXPECT_EQ("year not in 1812 ... 2012", nextDate(6,15,1811));
	EXPECT_EQ("month not in 1 ... 12, day not in 1 ... 31", nextDate(0,0,1912));
	EXPECT_EQ("month not in 1 ... 12, year not in 1812 ... 2012", nextDate(0,15,1811));
	EXPECT_EQ("day not in 1 ... 31, year not in 1812 ... 2012", nextDate(6,0,1811));
	EXPECT_EQ("month not in 1 ... 12, day not in 1 ... 31, year not in 1812 ... 2012", nextDate(0,0,1811));
	EXPECT_EQ("Invalid input date", nextDate(6,31,1912));
	EXPECT_EQ("6,16,1912", nextDate(6,15,1912));
	EXPECT_EQ("7,1,1912", nextDate(6,30,1912));
	EXPECT_EQ("Invalid input date", nextDate(2,30,2000));
	EXPECT_EQ("Invalid input date", nextDate(2,29,1911));
	EXPECT_EQ("2,16,1912", nextDate(2,15,1912));
	EXPECT_EQ("3,1,1911", nextDate(2,28,1911));
	EXPECT_EQ("3,1,2000", nextDate(2,29,2000));
	EXPECT_EQ("2,29,2000", nextDate(2,28,2000));
	EXPECT_EQ("Invalid input date", nextDate(12,31,2012));
	EXPECT_EQ("12,16,1912", nextDate(12,15,1912));
	EXPECT_EQ("1,1,1913", nextDate(12,31,1912));
	EXPECT_EQ("5,16,1912", nextDate(5,15,1912));
	EXPECT_EQ("6,1,1912", nextDate(5,31,1912));
}

