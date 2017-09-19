#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include <iostream>
using namespace std;
#include "defs.h"
class Transaction{
public:
	Transaction(double, int, TransType, TransState);
	TransType getTransType();
	int getAcctNum();
	double getTransAmount();
	int getTransNum();
	void setTime(string&);
	TransState getTransState();
	int getId();
	string getTime();
	double getAmount();
private:
	double transNum;
	TransType transType;
	TransState transState;
	string transDate;
	int accNum;
	double transAmount;
	static int nextTransNum;
};
#endif
