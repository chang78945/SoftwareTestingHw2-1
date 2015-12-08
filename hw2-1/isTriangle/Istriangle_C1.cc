#include <limits.h>
#include "Istriangle.h"
#include "gtest/gtest.h"

TEST(IsTriangleC1, determineTriangleType) {
	EXPECT_EQ("Value of a is not in the range of permitted values", determineTriangleType(0,100,100));
	EXPECT_EQ("Value of b is not in the range of permitted values", determineTriangleType(100,0,100));
	EXPECT_EQ("Value of c is not in the range of permitted values", determineTriangleType(100,100,0));
	EXPECT_EQ("Value of a,b is not in the range of permitted values", determineTriangleType(0,0,100));
	EXPECT_EQ("Value of a,c is not in the range of permitted values", determineTriangleType(0,100,0));
	EXPECT_EQ("Value of b,c is not in the range of permitted values", determineTriangleType(100,0,0));
	EXPECT_EQ("Value of a,b,c is not in the range of permitted values", determineTriangleType(0,0,0));
	EXPECT_EQ("Not a triangle", determineTriangleType(1,1,3));
	EXPECT_EQ("Equilateral", determineTriangleType(100,100,100));
	EXPECT_EQ("Isosceles", determineTriangleType(100,100,99));
	EXPECT_EQ("Isosceles", determineTriangleType(100,99,100));
	EXPECT_EQ("Isosceles", determineTriangleType(99,100,100));
	EXPECT_EQ("Scalence", determineTriangleType(3,4,5));
}

