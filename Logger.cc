#include "Logger.h"
#include "Transaction.h"
Logger::Logger(){
	
}
void Logger::setControl(BankControl* a){bank =a;}
void Logger:: update(){

  if(bank->getLast()->getAmount()>1000){
	flagTrans.add(bank->getLast());

	}


}
TransArray& Logger::getArr(){return flagTrans;}
