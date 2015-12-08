#include <limits.h>
#include "Istriangle.h"
#include "gtest/gtest.h"

TEST(IsTriangleMCDC, determineTriangleType) {
	//line 12
	EXPECT_EQ("Equilateral", determineTriangleType(100,100,100));//a<1:true, a>200:false
	EXPECT_EQ("Value of a is not in the range of permitted values", determineTriangleType(0,100,100));//a<1:false, a>200:false
	EXPECT_EQ("Equilateral", determineTriangleType(100,100,100));//a>200:true, a<1:false
	EXPECT_EQ("Value of a is not in the range of permitted values", determineTriangleType(201,100,100));//a>200:false, a<1:false
	//line 14
	EXPECT_EQ("Equilateral", determineTriangleType(100,100,100));//b<1:true, b>200:false
	EXPECT_EQ("Value of b is not in the range of permitted values", determineTriangleType(100,0,100));//b<1:false, b>200:false
	EXPECT_EQ("Equilateral", determineTriangleType(100,100,100));//b>200:true, b<1:false
	EXPECT_EQ("Value of b is not in the range of permitted values", determineTriangleType(100,201,100));//b>200:false, b<1:false
	//line 16
	EXPECT_EQ("Equilateral", determineTriangleType(100,100,100));//c<1:true, c>200:false
	EXPECT_EQ("Value of c is not in the range of permitted values", determineTriangleType(100,100,0));//c<1:false, c>200:false
	EXPECT_EQ("Equilateral", determineTriangleType(100,100,100));//c>200:true, c<1:false
	EXPECT_EQ("Value of c is not in the range of permitted values", determineTriangleType(100,100,201));//c>200:false, c<1:false
	//line 19
	EXPECT_EQ("Value of a,b,c is not in the range of permitted values", determineTriangleType(0,0,0));//flagA:true, flagB:true, flagC:true
	EXPECT_EQ("Value of b,c is not in the range of permitted values", determineTriangleType(100,0,0));//flagA:false, flagB:true, flagC:true
	EXPECT_EQ("Value of a,b,c is not in the range of permitted values", determineTriangleType(0,0,0));//flagB:true, flagA:true, flagC:true
	EXPECT_EQ("Value of a,c is not in the range of permitted values", determineTriangleType(0,100,0));//flagB:false, flagA:true, flagC:true
	EXPECT_EQ("Value of a,b,c is not in the range of permitted values", determineTriangleType(0,0,0));//flagC:true, flagA:true, flagB:true
	EXPECT_EQ("Value of a,b is not in the range of permitted values", determineTriangleType(0,0,100));//flagC:false, flagA:true, flagB:true
	//line 21
	EXPECT_EQ("Value of a,b is not in the range of permitted values", determineTriangleType(0,0,100));//flagA:true, flagB:true
	EXPECT_EQ("Value of b is not in the range of permitted values", determineTriangleType(100,0,100));//flagA:false, flagB:true
	EXPECT_EQ("Value of a,b is not in the range of permitted values", determineTriangleType(0,0,100));//flagB:true, flagA:true
	EXPECT_EQ("Value of a is not in the range of permitted values", determineTriangleType(0,100,100));//flagB:false, flagA:true
	//line 23
	EXPECT_EQ("Value of a,c is not in the range of permitted values", determineTriangleType(0,100,0));//flagA:true, flagC:true
	EXPECT_EQ("Value of c is not in the range of permitted values", determineTriangleType(100,100,0));//flagA:false, flagC:true
	EXPECT_EQ("Value of a,c is not in the range of permitted values", determineTriangleType(0,100,0));//flagC:true, flagA:true
	EXPECT_EQ("Value of a is not in the range of permitted values", determineTriangleType(0,100,100));//flagC:false, flagA:true
	//line 25
	EXPECT_EQ("Value of b,c is not in the range of permitted values", determineTriangleType(100,0,0));//flagB:true, flagC:true
	EXPECT_EQ("Value of c is not in the range of permitted values", determineTriangleType(100,100,0));//flagB:false, flagC:true
	EXPECT_EQ("Value of b,c is not in the range of permitted values", determineTriangleType(100,0,0));//flagC:true, flagB:true
	EXPECT_EQ("Value of b is not in the range of permitted values", determineTriangleType(100,0,100));//flagC:false, flagB:true
	//line 27
	EXPECT_EQ("Value of a is not in the range of permitted values", determineTriangleType(0,100,100));//flagA:true
	EXPECT_EQ("Equilateral", determineTriangleType(100,100,100));//flagA:false
	//line 29
	EXPECT_EQ("Value of b is not in the range of permitted values", determineTriangleType(100,0,100));//flagB:true
	EXPECT_EQ("Equilateral", determineTriangleType(100,100,100));//flagB:false
	//line 31
	EXPECT_EQ("Value of c is not in the range of permitted values", determineTriangleType(100,100,0));//flagC:true
	EXPECT_EQ("Equilateral", determineTriangleType(100,100,100));//flagC:false
	//line 35
	EXPECT_EQ("Not a triangle", determineTriangleType(3,1,1));//a>=b+c:true, b>=a+c:false, c>=a+b:false
	EXPECT_EQ("Isosceles", determineTriangleType(1,3,3));//a>=b+c:false, b>=a+c:false, c>=a+b:false
	EXPECT_EQ("Not a triangle", determineTriangleType(1,3,1));//b>=a+c:true, a>=b+c:false, c>=a+b:false
	EXPECT_EQ("Isosceles", determineTriangleType(3,1,3));//b>=a+c:false, a>=b+c:false, c>=a+b:false
	EXPECT_EQ("Not a triangle", determineTriangleType(1,1,3));//c>=a+b:true, a>=b+c:false, b>=a+c:false
	EXPECT_EQ("Isosceles", determineTriangleType(3,3,1));//c>=a+b:false, a>=b+c:false, b>=a+c:false
	//line 39
	EXPECT_EQ("Equilateral", determineTriangleType(100,100,100));//a==b:true, b==c:true
	EXPECT_EQ("Isosceles", determineTriangleType(99,100,100));//a==b:false, b==c:true
	//line 41
	EXPECT_EQ("Isosceles", determineTriangleType(100,100,99));//a==b:true, a!=c:true
	EXPECT_EQ("Isosceles", determineTriangleType(100,99,99));//a==b:false, a!=c:true
	//line 43
	EXPECT_EQ("Isosceles", determineTriangleType(100,99,100));//a==c:true, a!=b:true
	EXPECT_EQ("Isosceles", determineTriangleType(100,99,99));//a==c:false, a!=b:true
	//line 45
	EXPECT_EQ("Isosceles", determineTriangleType(99,100,100));//b==c:true, b!=a:true
	EXPECT_EQ("Isosceles", determineTriangleType(100,99,100));//b==c:false, b!=a:true
	//line 47
	EXPECT_EQ("Scalence", determineTriangleType(3,4,5));
}

