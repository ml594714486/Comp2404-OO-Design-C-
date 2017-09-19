#ifndef LOGGER_H
#define LOGGER_H
#include "Observer.h"
#include "TransArray.h"
#include "BankControl.h"

class Logger: public Observer{
	public:
		Logger();
		void setControl(BankControl*); 
		void update();
		TransArray& getArr();
	private:
		TransArray flagTrans;
		BankControl* bank;


};
#endif
