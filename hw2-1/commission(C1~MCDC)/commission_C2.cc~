#include <limits.h>
#include "commission.h"
#include "gtest/gtest.h"

TEST(commissionC1, commission) {
		EXPECT_EQ("locks not in 1...70, stocks not in 1...80, barrels not in 1...90", commission("-2,-2,-2,-1"));
		EXPECT_EQ("locks not in 1...70, stocks not in 1...80", commission("-2,-2,50,-1"));
		EXPECT_EQ("locks not in 1...70, barrels not in 1...90", commission("-2,50,-2,-1"));
		EXPECT_EQ("locks not in 1...70", commission("-2,50,50,-1"));
		EXPECT_EQ("stocks not in 1...80, barrels not in 1...90", commission("50,-2,-2,-1"));
		EXPECT_EQ("stocks not in 1...80", commission("50,-2,50,-1"));
		EXPECT_EQ("barrels not in 1...90", commission("50,50,-2,-1"));
		EXPECT_EQ("locks not in 1...70, stocks not in 1...80, barrels not in 1...90", commission("50,50,50,-2,-2,-2,-1"));
		EXPECT_EQ("locks not in 1...70, stocks not in 1...80", commission("50,50,50,-2,-2,50,-1"));
		EXPECT_EQ("locks not in 1...70, barrels not in 1...90", commission("50,50,50,-2,50,-2,-1"));
		EXPECT_EQ("locks not in 1...70", commission("50,50,50,-2,50,50,-1"));
		EXPECT_EQ("stocks not in 1...80, barrels not in 1...90", commission("50,50,50,50,-2,-2,-1"));
		EXPECT_EQ("stocks not in 1...80", commission("50,50,50,50,-2,50,-1"));
		EXPECT_EQ("barrels not in 1...90", commission("50,50,50,50,50,-2,-1"));
		EXPECT_EQ("$1420", commission("70,80,90,-1"));
		EXPECT_EQ("$167.5", commission("20,10,10,-1"));
		EXPECT_EQ("$10", commission("1,1,1,-1"));
		EXPECT_EQ("$2420", commission("50,50,50,70,80,90,-1"));
		EXPECT_EQ("$1150", commission("50,50,50,20,10,10,-1"));
		EXPECT_EQ("$880", commission("50,50,50,1,1,1,-1"));
}

