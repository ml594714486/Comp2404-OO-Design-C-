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

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "View.h"
using namespace std;

void View::mainMenu(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n                   BANKING SYSTEM MAIN MENU\n\n";
  cout<< "          1. Admin menu \n\n";
  cout<< "          2. Customer menu \n\n";
  cout<< "          0. Exit\n\n";

  while (choice < 0 || choice > 2) {
    cout << "Enter your selection:  ";
    choice = readInt();
  }
}

void View::adminMenu(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n                   BANKING SYSTEM ADMIN MENU\n\n";
  cout<< "          1. Add account \n\n";
  cout<< "          2. Print accounts \n\n";
  cout<< "          3. Pring customer\n\n";
  cout<< "          4. Print Flagged Transaction\n\n";
  cout<< "          0. Exit\n\n";

  while (choice < 0 || choice > 4) {
    cout << "Enter your selection:  ";
    choice = readInt();
  }
}

void View::custMenu(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n                   BANKING SYSTEM CUSTOMER MENU\n\n";
  cout<< "          1. Check balance \n\n";
  cout<< "          2. Deposit \n\n";
  cout<< "          3. Withdrawal \n\n";
  cout<< "          4. Print Transactions \n\n";
  cout<< "          0. Exit\n\n";

  while (choice < 0 || choice > 4) {
    cout << "Enter your selection:  ";
    choice = readInt();
  }
}

void View::printAccounts(Bank& bank)
{
  // The stringstream class helps us convert from numeric values to string.
  // The I/O manipulation functions help us make the output look pretty.

  stringstream ss;

  cout << endl << "ACCOUNTS: " << endl;

  for (int i=0; i<bank.getAccounts().getSize(); i++) {

    Account* acct = bank.getAccounts().get(i);

    if (acct->getAcctType() == CHEQUING)
      cout << "Chequing:  ";
    else if (acct->getAcctType() == SAVINGS)
      cout << "Savings:   ";
    else
      cout << "General:   ";
    
    int temp=bank.getAccounts().get(i)->getCust()->getid();
    string custName;
    for(int i=0;i<bank.getCust().getSize();i++)
	{
		if(temp==bank.getCust().get(i)->getid())
			custName=bank.getCust().get(i)->getname();	
	}
    cout << custName<< "  " << setw(4) << "  ";

    ss << setw(8) << fixed << setprecision(2) << acct->getBalance();
    cout << "  $" << ss.str() << endl;
    ss.str("");
  }
}

void View::printBalance(double b)
{
  // The stringstream class helps us convert from numeric values to string.
  // The I/O manipulation functions help us make the output look pretty.

  stringstream ss;
  ss << setw(8) << fixed << setprecision(2) << b;
  cout << endl << "Your balance is $" << ss.str() << endl << " -- press enter to continue...";
  cin.get();
}

void View::printError(string err)
{
  cout << endl << err << " -- press enter to continue...";
  cin.get();
}

void View::readCustId(int& id)
{
  string str;

  cout << "Customer id: ";
  getline(cin, str);
  stringstream ss(str);
  ss >> id;
}

void View::readAcctType(AcctType& acctType)
{
  string str;
  int    num;

  cout << "Account type [1 for chequing, 2 for savings]: ";
  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  if (num == 1)
    acctType = CHEQUING;
  else if (num == 2)
    acctType = SAVINGS;
  else
    acctType = GENERAL;
}

int View::readInt()
{
  string str;
  int    num;

  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  return num;
}

void View::pause()
{
  string str;

  cout << endl << "\nPress enter to continue...";
  getline(cin, str);
}

void View::printCustomers(Bank& bank){
  stringstream ss;

  cout << endl << "CUSTOMERS: " << endl;

  for (int i=0; i<bank.getCust().getSize(); i++) {

    cout << "ID: "<<bank.getCust().get(i)->getid() << "  " << "Name: "<<bank.getCust().get(i)->getname() << endl;
 
    ss.str("");
  }
}
void View::printTrans(TransArray& arr){
	for (int i=0;i<arr.getSize();i++)
	{
          stringstream ss;
	  ss<<arr.get(i)->getId()<<" ";
	  cout<<"Transaction id: "<<ss.str();
          ss.str("");
	if (arr.get(i)->getTransType() == DEPOSIT){
		  cout<<"TransactionType: "<<"Deposit   ";}
        if (arr.get(i)->getTransType() == WITHDRAWAL){
	  cout<<"TransactionType: "<<"Withdrawal   ";}
        if (arr.get(i)->getTransType() == DEBITPURCHASE){
	  cout<<"TransactionType: "<<"Debit_Purchase   ";}
        if (arr.get(i)->getTransType() == CHEQUE){
	  cout<<"TransactionType: "<<"Cheque   ";}
       
	if (arr.get(i)->getTransState() == SUCCESSFUL){
		  cout<<"TransactionState: "<<"Successful   ";}
        else{
	  cout<<"TransactionState: "<<"Failed   ";}
           
	cout<<arr.get(i)->getTime()<<"   ";
	ss<<arr.get(i)->getAcctNum();
        cout<<"AccountNumber:"<<ss.str()<<"   ";
        ss.str("");
	ss<<arr.get(i)->getTransAmount();
        cout<<"Amount:"<<ss.str();
        ss.str("");
        cout<<"\n"<<endl;
	
}

}
