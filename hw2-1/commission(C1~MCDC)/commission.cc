#include "commission.h"
#include <string>
#include <sstream>

using namespace std;

string double2str(double &dbl) {
	ostringstream strs;
	strs << dbl;
	string str = strs.str();
	return str;
}

int str2int(string str) {
	int val;
	istringstream is(str);
	is>>val;
	return val;
}

string commission(string str){
	int num = 0;
	int totalLocks = 0;
	int totalStocks = 0;
	int totalBarrels = 0;
	double lockprice = 45;
	double stockprice = 30;
	double barrelprice = 25;
	double lockSales, stockSales, barrelSales, sales, commission;
	bool flag = false;
	bool flagA = false;
	bool flagB = false;
	bool flagC = false;
	string sub_str, output;
	
	stringstream ss(str);
	while(getline(ss,sub_str,',')&&!flag){
		int val = str2int(sub_str);
		if(num == 0){
			if(val == -1)
				flag = true;
			else if(( val< 1) || (val > 70))
				flagA = true;
			else
				totalLocks = totalLocks + val;
		}
		else if(num == 1){
			if(( val< 1) || (val > 80))
				flagB = true;
			else
				totalStocks = totalStocks + val;
		}
		else{
			if((val < 1) || (val > 90))
				flagC = true;
			else
				totalBarrels = totalBarrels + val;
		}
		num++;
		if(num==3)
			num = 0;
	}
	
	if(flagA&&flagB&&flagC)
		output = "locks not in 1...70, stocks not in 1...80, barrels not in 1...90";
	else if(flagA&&flagB)
		output = "locks not in 1...70, stocks not in 1...80";
	else if(flagA&&flagC)
		output = "locks not in 1...70, barrels not in 1...90";
	else if(flagB&&flagC)
		output = "stocks not in 1...80, barrels not in 1...90";
	else if(flagA)
		output = "locks not in 1...70";
	else if(flagB)
		output = "stocks not in 1...80";
	else if(flagC)
		output = "barrels not in 1...90";
	else{
		lockSales = totalLocks * lockprice;
		stockSales = totalStocks * stockprice;
		barrelSales = totalBarrels * barrelprice;
		sales = lockSales + stockSales + barrelSales;
		
		if(sales > 1800){
			commission = 0.1 * 1000;           
			commission = commission + 0.15 * 800;
			commission = commission + 0.2 * (sales - 1800);
		}
		else if(sales > 1000){
			commission = 0.1 * 1000;             
			commission = commission + 0.15 * (sales - 1000);
		}
		else
			commission = 0.1 * sales;
		output = "$" + double2str(commission);
	}
	return output;
}

