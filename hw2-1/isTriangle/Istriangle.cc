#include "Istriangle.h"
#include <string>

using namespace std;

string determineTriangleType(int a, int b, int c){
    bool flagA = false;
    bool flagB = false;
    bool flagC = false;
    string output;
    
    if((a < 1) || (a > 200))
        flagA = true;
    if((b < 1) || (b > 200))
        flagB = true;
    if((c < 1) || (c > 200))
        flagC = true;
    
    if(flagA&&flagB&&flagC)
        output = "Value of a,b,c is not in the range of permitted values";
    else if(flagA&&flagB)
        output = "Value of a,b is not in the range of permitted values";
    else if(flagA&&flagC)
        output = "Value of a,c is not in the range of permitted values";
    else if(flagB&&flagC)
        output = "Value of b,c is not in the range of permitted values";
    else if(flagA)
        output = "Value of a is not in the range of permitted values";
    else if(flagB)
        output = "Value of b is not in the range of permitted values";
    else if(flagC)
        output = "Value of c is not in the range of permitted values";
    else
	{
		if((a >= b + c)||(b >= a + c)||(c >= a + b))
			output = "Not a triangle";			
		else
		{
			if((a == b)&&(b == c))
				output = "Equilateral";
			else if((a == b)&&(a != c))
				output = "Isosceles";
			else if((a == c)&&(a != b))
				output = "Isosceles";
			else if((b == c)&&(b != a))
				output = "Isosceles";
			else
				output = "Scalence";	
		}
	}
	return output;
}

