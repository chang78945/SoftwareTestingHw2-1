#include <limits.h>
#include "commission.h"
#include "gtest/gtest.h"

TEST(commissionMCDC, commission) {
	//line 39,40,44,47,50,53,56,60
	EXPECT_EQ("$1860", commission("50,50,50,50,50,50,-1"));
	//line 42 
	EXPECT_EQ("locks not in 1...70", commission("0,80,90,-1"));//val < 1:true, val > 70:false
	EXPECT_EQ("$1420", commission("70,80,90,-1"));//false < 1:false, val > 70:false
	EXPECT_EQ("locks not in 1...70", commission("80,80,90,-1"));//val > 70:true, val < 1:false
	EXPECT_EQ("$1420", commission("70,80,90,-1"));//false > 70:false, val < 1:false
	//line 48 
	EXPECT_EQ("stocks not in 1...80", commission("70,0,90,-1"));//val < 1:true, val > 80:false
	EXPECT_EQ("$1420", commission("70,80,90,-1"));//false < 1:false, val > 80:false
	EXPECT_EQ("stocks not in 1...80", commission("70,90,90,-1"));//val > 80:true, val < 1:false
	EXPECT_EQ("$1420", commission("70,80,90,-1"));//false > 80:false, val < 1:false
	//line 54 
	EXPECT_EQ("barrels not in 1...90", commission("70,80,0,-1"));//val < 1:true, val > 90:false
	EXPECT_EQ("$1420", commission("70,80,90,-1"));//false < 1:false, val > 90:false
	EXPECT_EQ("barrels not in 1...90", commission("70,80,100,-1"));//val > 90:true, val < 1:false
	EXPECT_EQ("$1420", commission("70,80,90,-1"));//false > 90:false, val < 1:false
	//line 64
	EXPECT_EQ("locks not in 1...70, stocks not in 1...80, barrels not in 1...90", commission("0,0,0,-1"));//flagA:true, flagB:true, flagC:true
	EXPECT_EQ("stocks not in 1...80, barrels not in 1...90", commission("50,0,0,-1"));//flagA:false, flagB:true, flagC:true
	EXPECT_EQ("locks not in 1...70, stocks not in 1...80, barrels not in 1...90", commission("0,0,0,-1"));//flagB:true, flagA:true, flagC:true
	EXPECT_EQ("locks not in 1...70, barrels not in 1...90", commission("0,50,0,-1"));//flagB:false, flagA:true, flagC:true
	EXPECT_EQ("locks not in 1...70, stocks not in 1...80, barrels not in 1...90", commission("0,0,0,-1"));//flagC:true, flagB:true, flagA:true
	EXPECT_EQ("locks not in 1...70, stocks not in 1...80", commission("0,0,50,-1"));//flagC:false, flagB:true, flagA:true
	//line 66
	EXPECT_EQ("locks not in 1...70, stocks not in 1...80", commission("0,0,50,-1"));//flagA:true, flagB:true
	EXPECT_EQ("stocks not in 1...80", commission("50,0,50,-1"));//flagA:false, flagB:true
	EXPECT_EQ("locks not in 1...70, stocks not in 1...80", commission("0,0,50,-1"));//flagB:true, flagA:true
	EXPECT_EQ("locks not in 1...70", commission("0,50,50,-1"));//flagB:false, flagA:true
	//line 68
	EXPECT_EQ("locks not in 1...70, barrels not in 1...90", commission("0,50,0,-1"));//flagA:true, flagC:true
	EXPECT_EQ("barrels not in 1...90", commission("50,50,0,-1"));//flagA:false, flagC:true
	EXPECT_EQ("locks not in 1...70, barrels not in 1...90", commission("0,50,0,-1"));//flagC:true, flagA:true
	EXPECT_EQ("locks not in 1...70", commission("0,50,50,-1"));//flagC:false, flagA:true
	//line 70
	EXPECT_EQ("stocks not in 1...80, barrels not in 1...90", commission("50,0,0,-1"));//flagB:true, flagC:true
	EXPECT_EQ("barrels not in 1...90", commission("50,50,0,-1"));//flagB:false, flagC:true
	EXPECT_EQ("stocks not in 1...80, barrels not in 1...90", commission("50,0,0,-1"));//flagC:true, flagB:true
	EXPECT_EQ("stocks not in 1...80", commission("50,0,50,-1"));//flagC:false, flagB:true
	//line 72
	EXPECT_EQ("locks not in 1...70", commission("0,50,50,-1"));//flagA:true
	EXPECT_EQ("$860", commission("50,50,50,-1"));//flagA:false
	//line 74
	EXPECT_EQ("stocks not in 1...80", commission("50,0,50,-1"));//flagB:true
	EXPECT_EQ("$860", commission("50,50,50,-1"));//flagB:false
	//line 76
	EXPECT_EQ("barrels not in 1...90", commission("50,50,0,-1"));//flagC:true
	EXPECT_EQ("$860", commission("50,50,50,-1"));//flagC:false
	//line 84
	EXPECT_EQ("$1420", commission("70,80,90,-1"));//sales > 1800:true
	EXPECT_EQ("$10", commission("1,1,1,-1"));//sales > 1800:false
	//line 89
	EXPECT_EQ("$167.5", commission("20,10,10,-1"));//sales > 1000:true
	EXPECT_EQ("$10", commission("1,1,1,-1"));//sales > 1000:false
	//line 93
	EXPECT_EQ("$10", commission("1,1,1,-1"));
}

