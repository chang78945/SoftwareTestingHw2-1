#include <limits.h>
#include "nextDate.h"
#include "gtest/gtest.h"

TEST(nextDateMCDC, nextDate) {
	//line 24
	EXPECT_EQ("month not in 1 ... 12", nextDate(0,15,1912));//month < 1:true, month > 12:false
	EXPECT_EQ("6,16,1912", nextDate(6,15,1912));//month < 1:false, month > 12:false
	EXPECT_EQ("month not in 1 ... 12", nextDate(13,15,1912));//month > 12:true, month < 1:false
	EXPECT_EQ("6,16,1912", nextDate(6,15,1912));//month > 12:false, month < 1:false
	//line 26
	EXPECT_EQ("day not in 1 ... 31", nextDate(6,0,1912));//day < 1:true, day > 31:false
	EXPECT_EQ("6,16,1912", nextDate(6,15,1912));//day < 1:false, day > 31:false
	EXPECT_EQ("day not in 1 ... 31", nextDate(6,32,1912));//day > 31:true, day < 1:false
	EXPECT_EQ("6,16,1912", nextDate(6,15,1912));//day > 31:false, day < 1:false
	//line 28
	EXPECT_EQ("year not in 1812 ... 2012", nextDate(6,15,1811));//year < 1812:true, year > 2012:false
	EXPECT_EQ("6,16,1912", nextDate(6,15,1912));//year < 1812:false, year > 2012:false
	EXPECT_EQ("year not in 1812 ... 2012", nextDate(6,15,2013));//year > 2012:true, year < 1812:false
	EXPECT_EQ("6,16,1912", nextDate(6,15,1912));//year > 2012:false, year < 1812:false
	//line 31
	EXPECT_EQ("month not in 1 ... 12, day not in 1 ... 31, year not in 1812 ... 2012", nextDate(0,0,1811));//flagA:true, flagB:true, flagC:true
	EXPECT_EQ("day not in 1 ... 31, year not in 1812 ... 2012", nextDate(6,0,1811));//flagA:false, flagB:true, flagC:true
	EXPECT_EQ("month not in 1 ... 12, day not in 1 ... 31, year not in 1812 ... 2012", nextDate(0,0,1811));//flagB:true, flagA:true, flagC:true
	EXPECT_EQ("month not in 1 ... 12, year not in 1812 ... 2012", nextDate(0,15,1811));//flagB:false, flagA:true, flagC:true
	EXPECT_EQ("month not in 1 ... 12, day not in 1 ... 31, year not in 1812 ... 2012", nextDate(0,0,1811));//flagC:true, flagB:true, flagA:true
	EXPECT_EQ("month not in 1 ... 12, day not in 1 ... 31", nextDate(0,0,1912));//flagC:false, flagB:true, flagA:true
	//line 33
	EXPECT_EQ("month not in 1 ... 12, day not in 1 ... 31", nextDate(0,0,1912));//flagA:true, flagB:true
	EXPECT_EQ("day not in 1 ... 31", nextDate(6,0,1912));//flagA:false, flagB:true
	EXPECT_EQ("month not in 1 ... 12, day not in 1 ... 31", nextDate(0,0,1912));//flagB:true, flagA:true
	EXPECT_EQ("month not in 1 ... 12", nextDate(0,15,1912));//flagB:false, flagA:true
	//line 35
	EXPECT_EQ("month not in 1 ... 12, year not in 1812 ... 2012", nextDate(0,15,1811));//flagA:true, flagC:true
	EXPECT_EQ("year not in 1812 ... 2012", nextDate(6,15,1811));//flagA:false, flagC:true
	EXPECT_EQ("month not in 1 ... 12, year not in 1812 ... 2012", nextDate(0,15,1811));//flagC:true, flagA:true
	EXPECT_EQ("month not in 1 ... 12", nextDate(0,15,1912));//flagC:false, flagA:true
	//line 37
	EXPECT_EQ("day not in 1 ... 31, year not in 1812 ... 2012", nextDate(6,0,1811));//flagB:true, flagC:true
	EXPECT_EQ("year not in 1812 ... 2012", nextDate(6,15,1811));//flagB:false, flagC:true
	EXPECT_EQ("day not in 1 ... 31, year not in 1812 ... 2012", nextDate(6,0,1811));//flagC:true, flagB:true
	EXPECT_EQ("day not in 1 ... 31", nextDate(6,0,1912));//flagC:false, flagB:true
	//line 39
	EXPECT_EQ("month not in 1 ... 12", nextDate(0,15,1912));//flagA:true
	EXPECT_EQ("6,16,1912", nextDate(6,15,1912));//flagA:false
	//line 41
	EXPECT_EQ("day not in 1 ... 31", nextDate(6,0,1912));//flagB:true
	EXPECT_EQ("6,16,1912", nextDate(6,15,1912));//flagB:false
	//line 43
	EXPECT_EQ("year not in 1812 ... 2012", nextDate(6,15,1811));//flagC:true
	EXPECT_EQ("6,16,1912", nextDate(6,15,1912));//flagC:false
	//line 47
	EXPECT_EQ("4,16,1912", nextDate(4,15,1912));//month==4:true, month==6:false, month==9:false, month==11:false
	EXPECT_EQ("5,16,1912", nextDate(5,15,1912));//month==4:false, month==6:false, month==9:false, month==11:false
	EXPECT_EQ("6,16,1912", nextDate(6,15,1912));//month==6:true, month==4:false, month==9:false, month==11:false
	EXPECT_EQ("5,16,1912", nextDate(5,15,1912));//month==6:false, month==4:false, month==9:false, month==11:false
	EXPECT_EQ("9,16,1912", nextDate(9,15,1912));//month==9:true, month==4:false, month==6:false, month==11:false
	EXPECT_EQ("5,16,1912", nextDate(5,15,1912));//month==9:false, month==4:false, month==6:false, month==11:false
	EXPECT_EQ("11,16,1912", nextDate(11,15,1912));//month==11:true, month==4:false, month==6:false, month==9:false
	EXPECT_EQ("5,16,1912", nextDate(5,15,1912));//month==11:false, month==4:false, month==6:false, month==9:false
	//line 48
	EXPECT_EQ("Invalid input date", nextDate(4,31,1912));//day==31:true
	EXPECT_EQ("4,16,1912", nextDate(4,15,1912));//day==31:false
	//line 51
	EXPECT_EQ("2,16,1912", nextDate(2,15,1912));//month==2:true
	EXPECT_EQ("3,16,1912", nextDate(3,15,1912));//month==2:false
	//line 52
	EXPECT_EQ("Invalid input date", nextDate(2,30,2000));//year%4==0:true, day>29:true
	EXPECT_EQ("Invalid input date", nextDate(2,30,1911));//year%4==0:false, day>29:true
	EXPECT_EQ("Invalid input date", nextDate(2,30,2000));//day>29:true, year%4==0:true
	EXPECT_EQ("2,16,2000", nextDate(2,15,2000));//day>29:false, year%4==0:true
	//line 54
	EXPECT_EQ("Invalid input date", nextDate(2,29,1911));//year%4!=0:true, day>28:true
	EXPECT_EQ("3,1,2000", nextDate(2,29,2000));//year%4!=0:false, day>28:true
	EXPECT_EQ("Invalid input date", nextDate(2,29,1911));//day>28:true, year%4!=0:true
	EXPECT_EQ("2,16,1911", nextDate(2,15,1911));//day>28:false, year%4!=0:true
	//line 57
	EXPECT_EQ("12,16,1912", nextDate(12,15,1912));//month==12:true
	EXPECT_EQ("3,16,1912", nextDate(3,15,1912));//month==12:false
	//line 58
	EXPECT_EQ("Invalid input date", nextDate(12,31,2012));//day==31:true, year==2012:true
	EXPECT_EQ("12,16,2012", nextDate(12,15,2012));//day==31:false, year==2012:true
	EXPECT_EQ("Invalid input date", nextDate(12,31,2012));//year==2012:true, day==31:true
	EXPECT_EQ("1,1,1913", nextDate(12,31,1912));//year==2012:false, day==31:true
	//line 61
	EXPECT_EQ("Invalid input date", nextDate(4,31,1912));//flag:true
	EXPECT_EQ("4,16,1912", nextDate(4,15,1912));//flag:false
	//line 65
	EXPECT_EQ("1,16,1912", nextDate(1,15,1912));//month==1:true, month==3:false, month==5:false, month==7:false, month==8:false, month==10:false
	EXPECT_EQ("6,16,1912", nextDate(6,15,1912));//month==1:false, month==3:false, month==5:false, month==7:false, month==8:false, month==10:false
	EXPECT_EQ("3,16,1912", nextDate(3,15,1912));//month==3:true, month==1:false, month==5:false, month==7:false, month==8:false, month==10:false
	EXPECT_EQ("6,16,1912", nextDate(6,15,1912));//month==3:false, month==1:false, month==5:false, month==7:false, month==8:false, month==10:false
	EXPECT_EQ("5,16,1912", nextDate(5,15,1912));//month==5:true, month==1:false, month==3:false, month==7:false, month==8:false, month==10:false
	EXPECT_EQ("6,16,1912", nextDate(6,15,1912));//month==5:false, month==1:false, month==3:false, month==7:false, month==8:false, month==10:false
	EXPECT_EQ("7,16,1912", nextDate(7,15,1912));//month==7:true, month==1:false, month==3:false, month==5:false, month==8:false, month==10:false
	EXPECT_EQ("6,16,1912", nextDate(6,15,1912));//month==7:false, month==1:false, month==3:false, month==5:false, month==8:false, month==10:false
	EXPECT_EQ("8,16,1912", nextDate(8,15,1912));//month==8:true, month==1:false, month==3:false, month==5:false, month==7:false, month==10:false
	EXPECT_EQ("6,16,1912", nextDate(6,15,1912));//month==8:false, month==1:false, month==3:false, month==5:false, month==7:false, month==10:false
	EXPECT_EQ("10,16,1912", nextDate(10,15,1912));//month==10:true, month==1:false, month==3:false, month==5:false, month==7:false, month==8:false
	EXPECT_EQ("6,16,1912", nextDate(6,15,1912));//month==10:false, month==1:false, month==3:false, month==5:false, month==7:false, month==8:false
	//line 66
	EXPECT_EQ("5,16,1912", nextDate(5,15,1912));//day<31:true
	EXPECT_EQ("6,1,1912", nextDate(5,31,1912));//day<31:false
	//line 68
	EXPECT_EQ("6,1,1912", nextDate(5,31,1912));
	//line 73
	EXPECT_EQ("4,16,1912", nextDate(4,15,1912));//month==4:true, month==6:false, month==9:false, month==11:false
	EXPECT_EQ("5,16,1912", nextDate(5,15,1912));//month==4:false, month==6:false, month==9:false, month==11:false
	EXPECT_EQ("6,16,1912", nextDate(6,15,1912));//month==6:true, month==4:false, month==9:false, month==11:false
	EXPECT_EQ("5,16,1912", nextDate(5,15,1912));//month==6:false, month==4:false, month==9:false, month==11:false
	EXPECT_EQ("9,16,1912", nextDate(9,15,1912));//month==9:true, month==4:false, month==6:false, month==11:false
	EXPECT_EQ("5,16,1912", nextDate(5,15,1912));//month==9:false, month==4:false, month==6:false, month==11:false
	EXPECT_EQ("11,16,1912", nextDate(11,15,1912));//month==11:true, month==4:false, month==6:false, month==9:false
	EXPECT_EQ("5,16,1912", nextDate(5,15,1912));//month==11:false, month==4:false, month==6:false, month==9:false
	//line 74
	EXPECT_EQ("6,16,1912", nextDate(6,15,1912));//day<30:true
	EXPECT_EQ("7,1,1912", nextDate(6,30,1912));//day<30:false
	//line 76
	EXPECT_EQ("7,1,1912", nextDate(6,30,1912));
	//line 81
	EXPECT_EQ("12,16,1912", nextDate(12,15,1912));//month==12:true
	EXPECT_EQ("3,16,1912", nextDate(3,15,1912));//month==12:false
	//line 82
	EXPECT_EQ("12,16,1912", nextDate(12,15,1912));//day<31:true
	EXPECT_EQ("1,1,1913", nextDate(12,31,1912));//day<31:false
	//line 84
	EXPECT_EQ("1,1,1913", nextDate(12,31,1912));
	//line 90
	EXPECT_EQ("2,16,1912", nextDate(2,15,1912));//month==2:true
	EXPECT_EQ("3,16,1912", nextDate(3,15,1912));//month==2:false
	//line 91
	EXPECT_EQ("2,16,1912", nextDate(2,15,1912));//day<28:true
	EXPECT_EQ("3,1,1911", nextDate(2,28,1911));//day<28:false
	//line 94
	EXPECT_EQ("2,16,1911", nextDate(2,15,1911));//year%4!=0:true
	EXPECT_EQ("2,29,2000", nextDate(2,28,2000));//year%4!=0:false
	//line 99
	EXPECT_EQ("3,1,1912", nextDate(2,29,1912));//day==29:true
	EXPECT_EQ("2,16,1912", nextDate(2,15,1912));//day==29:false
	//line 103
	EXPECT_EQ("2,16,1912", nextDate(2,15,1912));
}

