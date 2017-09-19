/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/*  Program:  Simple Banking System                */
/*  Author:   Christine Laurendeau                 */
/*  Date:     08-JUN-2016                          */
/*                                                 */
/*  (c) 2016 Christine Laurendeau                  */
/*  All rights reserved.  Distribution and         */
/*  reposting, in part or in whole, without the    */
/*  written consent of the author, is illegal.     */
/*                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#include "BankControl.h"
#include "Account.h"
#include "Customer.h"
#include <sstream>
#include <iostream>
#include "Transaction.h"
#include "Logger.h"
using namespace std;

BankControl::BankControl()
{
  init();
}

BankControl::~BankControl(){
  for(int i=0;i<bank.getCust().getSize();i++){
    delete (bank.getCust().get(i));
  }for(int i=0;i<bank.getAccounts().getSize();i++){
    delete (bank.getAccounts().get(i));
  }
}
Transaction* BankControl::getLast(){
	return last;

}
void BankControl::launch()
{
  int choice;

  while (1) {
    choice = -1;
    view.mainMenu(choice);
    if (choice == 1) {		// Admin menu
      processAdmin();
    }
    else if (choice == 2) {	// Customer menu
      processCust();
    }
    else {
      break;
    }
  }
}

void BankControl::processAdmin()
{
  int      choice;
  int      custId;
  AcctType acctType;

  while (1) {
    choice = -1;
    view.adminMenu(choice);
    if (choice == 1) {		// add account
      view.readCustId(custId);
      view.readAcctType(acctType);
      int flag=0;
      for(int i=0;i<bank.getCust().getSize();i++){
	if(custId==bank.getCust().get(i)->getid()){
	  Account* acct = new Account(bank.getCust().get(i), acctType);
          bank.addAcct(acct);
	  flag=1;
	}
      }
    if (flag==0)
 	cout<<"the id you just input is not in our database"<<endl;
      view.pause();
    }
    else if (choice == 2) {	// print accounts
      view.printAccounts(bank);
      view.pause();
    }
    else if (choice == 3) {//print customer
      view.printCustomers(bank);
      view.pause();
    }
	else if (choice == 4) {//print Flagged transaction
      Observer** obj = getlist();
		Logger* log = (Logger*)(obj[0]);
	
	view.printTrans(log->getArr());
      view.pause();
    }
    else {
      break;
    }
  }
}

void BankControl::processCust()
{
  int choice;

  while (1) {
    choice = -1;
    view.custMenu(choice);
    if (choice == 1) {	// check balance
      int acctNum;
      int flagForSearch=0;
	  cout<<"please input the account number that you want to check"<<endl;
    string str;
        getline(cin, str);
 	 stringstream ss(str);
 	 ss >> acctNum;
      for(int i=0;i<bank.getAccounts().getSize();i++){
      	if(acctNum==bank.getAccounts().get(i)->getAcctNum()){
      		cout<<"the current balance of Account "<<acctNum<<" is :"<<bank.getAccounts().get(i)->getBalance()<<endl;
		  	flagForSearch=1;
		 }
	  }
	  if(flagForSearch==0){
	  	cout<<"Sorry, the account you are looking for is not in our database."<<endl;
	  }
    }
	if(choice==2){
		cout<<"please input the account number that you want to deposit:"<<endl;
		Transaction* x;
    		int acctNum;
		double transAmount;
		string str;
        	getline(cin, str);
 	 	stringstream ss(str);
 	 	ss >> acctNum;
		cout<<"please input the amount that you want to deposit:"<<endl;
		
        	getline(cin, str);
 	 	stringstream ss1(str);
 	 	ss1 >> transAmount;
		if(transAmount>=0){
			for(int i=0;i<bank.getAccounts().getSize();i++){
      				if(acctNum==bank.getAccounts().get(i)->getAcctNum()){
					bank.getAccounts().get(i)->deposit(transAmount);
					
					x=new Transaction(transAmount,acctNum,DEPOSIT,SUCCESSFUL);
					trans.update(x);
					last = x;
                                        notify();
					
				}
			}
		}
		
		else{
	
			x=new Transaction(transAmount,acctNum,DEPOSIT,FAILED);
			trans.update(x);
			last = x;
                        notify();
		}
	}
	if(choice==3){
		Transaction* x;
		cout<<"please input the account number that you want to withdrawal:"<<endl;
    		int acctNum;
		double transAmount;
		string str;
        	getline(cin, str);
 	 	stringstream ss(str);
 	 	ss >> acctNum;
		cout<<"please input the amount that you want to withdrawal:"<<endl;
		
        	getline(cin, str);
 	 	stringstream ss1(str);
 	 	ss1 >> transAmount;
		if(transAmount>=0){
			for(int i=0;i<bank.getAccounts().getSize();i++){
      			if(acctNum==bank.getAccounts().get(i)->getAcctNum()){			
					if(bank.getAccounts().get(i)->getBalance()>transAmount){
						bank.getAccounts().get(i)->withdraw(transAmount);
						
						x=new Transaction(transAmount,acctNum,WITHDRAWAL,SUCCESSFUL);
						trans.update(x);
						last = x;
                                                notify();
						}
					else{
						
						x=new Transaction(transAmount,acctNum,WITHDRAWAL,FAILED);
						trans.update(x);
						last = x;
                                                notify();
						}
					}
			}
}

		else{
			Transaction* x;
			x=new Transaction(transAmount,acctNum,WITHDRAWAL,FAILED);
			trans.update(x);
			last = x;
                        notify();
}
}
	if(choice==4){
		trans.retrieve(trans.getTransArray());		

}
    else {
      break;
    }

    view.pause();

  }
}

void BankControl::subscribe(Observer* obj){  
  Subject::subscribe(obj);
  ((Logger *)obj)->setControl(this);

}

void BankControl::init()
{
  /*
     This function is so ugly!  It's because we're using 
     statically allocated memory, instead of dynamically
     alloated.  Don't worry, we'll fix this in Assignment #2.
  */
  Customer* cust;
  Account* acc;
  cust = new Customer(1001,"Mike");
  bank.addCust(cust);
  cust = new Customer(1002,"Jake");
  bank.addCust(cust);
  cust = new Customer(1003,"Rose");
  bank.addCust(cust);
  cust = new Customer(1004,"Jerry");
  bank.addCust(cust);
  cust = new Customer(1005,"Tom");
  bank.addCust(cust);
  cust = new Customer(1006,"Lucy");
  bank.addCust(cust);
  cust = new Customer(1007,"Lily");
  bank.addCust(cust);
  cust = new Customer(1008,"Harry");
  bank.addCust(cust);
  cust = new Customer(1009,"Lei");
  bank.addCust(cust);
  cust = new Customer(1010,"Lee");
  bank.addCust(cust);
  cust = new Customer(1011,"Kevin");
  bank.addCust(cust);
  cust = new Customer(1012,"Cury");
  bank.addCust(cust);




  acc = new Account(bank.getCust().get(0), SAVINGS);
  bank.addAcct(acc);
  acc = new Account(bank.getCust().get(1), SAVINGS);
  bank.addAcct(acc);
  acc = new Account(bank.getCust().get(2), CHEQUING);
  bank.addAcct(acc);
  acc = new Account(bank.getCust().get(3), SAVINGS);
  bank.addAcct(acc);
  acc = new Account(bank.getCust().get(4), CHEQUING);
  bank.addAcct(acc);
  acc = new Account(bank.getCust().get(5), SAVINGS);
  bank.addAcct(acc);
  acc = new Account(bank.getCust().get(6), CHEQUING);
  bank.addAcct(acc);
  acc = new Account(bank.getCust().get(7), CHEQUING);
  bank.addAcct(acc);
  acc = new Account(bank.getCust().get(8), CHEQUING);
  bank.addAcct(acc);
  acc = new Account(bank.getCust().get(9), SAVINGS);
  bank.addAcct(acc);
  acc = new Account(bank.getCust().get(10), CHEQUING);
  bank.addAcct(acc);
  acc = new Account(bank.getCust().get(11), CHEQUING);
  bank.addAcct(acc);
  acc = new Account(bank.getCust().get(10), CHEQUING);
  bank.addAcct(acc);
  acc = new Account(bank.getCust().get(1), SAVINGS);
  bank.addAcct(acc);
  acc = new Account(bank.getCust().get(3), SAVINGS);
  bank.addAcct(acc);
}

