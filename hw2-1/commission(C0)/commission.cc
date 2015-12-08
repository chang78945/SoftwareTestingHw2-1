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

string commission(int locks, int stocks, int barrels){
	int totalLocks = 0;
	int totalStocks = 0;
	int totalBarrels = 0;
	double lockprice = 45;
	double stockprice = 30;
	double barrelprice = 25;
	double lockSales;
	double stockSales;
	double barrelSales;
	double sales;
	double commission;
    bool flagA = false;
    bool flagB = false;
    bool flagC = false;
    
	if((locks < 1) || (locks > 70))
        flagA = true;
	if(( stocks< 1) || (stocks > 80))
        flagB = true;
	if((barrels < 1) || (barrels > 90))
        flagC = true;
        
    if(flagA&&flagB&&flagC)
    	if(locks == -1)
    		return "stocks not in 1...80, barrels not in 1...90";
    	else
        	return "locks not in 1...70, stocks not in 1...80, barrels not in 1...90";
    else if(flagA&&flagB)
    	if(locks == -1)
    		return "stocks not in 1...80";
    	else
        	return "locks not in 1...70, stocks not in 1...80";
    else if(flagA&&flagC)
    	if(locks == -1)
    		return "barrels not in 1...90";
    	else
        	return "locks not in 1...70, barrels not in 1...90";
    else if(flagB&&flagC)
        return "stocks not in 1...80, barrels not in 1...90";
    else if(flagA)
    	if(locks == -1)
    		return "Program terminates";
    	else
        	return "locks not in 1...70";
    else if(flagB)
        return "stocks not in 1...80";
    else if(flagC)
        return "barrels not in 1...90";
	
	totalLocks = totalLocks + locks;
	totalStocks = totalStocks + stocks;
	totalBarrels = totalBarrels + barrels;
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
	return "$" + double2str(commission);
}

