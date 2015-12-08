#include "nextDate.h"
#include <sstream>

using namespace std;

string int2str(int &i) {
  string s;
  stringstream ss(s);
  ss << i;

  return ss.str();
}

string nextDate(int month, int day, int year){
	string output = "";
	int tomorrowMonth = month;
	int tomorrowDay = day;
	int tomorrowYear = year;
    bool flag = false;
    bool flagA = false;
    bool flagB = false;
    bool flagC = false;
    
	if((month < 1) || (month > 12))
        flagA = true;
	if(( day< 1) || (day > 31))
        flagB = true;
	if((year < 1812) || (year > 2012))
        flagC = true;
		
    if(flagA&&flagB&&flagC)
        output = "month not in 1 ... 12, day not in 1 ... 31, year not in 1812 ... 2012";
    else if(flagA&&flagB)
        output = "month not in 1 ... 12, day not in 1 ... 31";
    else if(flagA&&flagC)
        output = "month not in 1 ... 12, year not in 1812 ... 2012";
    else if(flagB&&flagC)
        output = "day not in 1 ... 31, year not in 1812 ... 2012";
    else if(flagA)
        output = "month not in 1 ... 12";
    else if(flagB)
        output = "day not in 1 ... 31";
    else if(flagC)
        output = "year not in 1812 ... 2012";
	else
	{
		if(month==4||month==6||month==9||month==11){
			if(day==31)
				flag = true;
		}
		else if(month==2){
			if(year%4==0&&day>29)
				flag = true;
			else if(year%4!=0&&day>28)
				flag = true;
		}
		else if(month==12){
			if(day==31&&year==2012)
				flag = true;
		}
		if(flag)
			output = "Invalid input date";
		else
		{
			if(month==1||month==3||month==5||month==7||month==8||month==10){
				if(day<31)	
					tomorrowDay = tomorrowDay + 1;
				else{
					tomorrowDay = 1;
					tomorrowMonth = tomorrowMonth + 1; 
				}
			}
			else if(month==4||month==6||month==9||month==11){
				if(day<30)	
					tomorrowDay = tomorrowDay + 1;
				else{
					tomorrowDay = 1;
					tomorrowMonth = tomorrowMonth + 1; 
				}
			}
			else if(month==12){
				if(day<31)	
					tomorrowDay = tomorrowDay + 1;
				else{
					tomorrowDay = 1;
					tomorrowMonth = 1;
					tomorrowYear = tomorrowYear + 1; 
				}
			}
			else if(month==2){
				if(day<28)
					tomorrowDay = tomorrowDay + 1;
				else{
					if(year%4!=0){
						tomorrowDay = 1;
						tomorrowMonth = 3;
					}
					else{
						if(day==29){
							tomorrowDay = 1;
							tomorrowMonth = 3;
						}
						else
							tomorrowDay = tomorrowDay + 1;
					}				
				}
			}
			output = int2str(tomorrowMonth) + "," + int2str(tomorrowDay) + "," + int2str(tomorrowYear);
		}
	}
	return output;
}

