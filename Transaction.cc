#include "defs.h"
#include "Transaction.h"
using namespace std;
int Transaction::nextTransNum = 1000;
Transaction::Transaction(double c, int t, TransType x, TransState y) 
{ 
  transAmount  = c;
  accNum = t;
  transType = x;
  transNum = nextTransNum++;
  transState = y;
}
int Transaction::getId(){return transNum;}
TransState Transaction::getTransState() { return transState; }
TransType Transaction::getTransType() { return transType; }
int      Transaction::getAcctNum()  { return accNum;  }
double Transaction::getTransAmount()     { return transAmount;     }
int   Transaction::getTransNum()  { return transNum;  }
void Transaction::setTime(string& x){transDate=x;}
string Transaction::getTime(){return transDate;}
double Transaction::getAmount(){
	return transAmount;
}
