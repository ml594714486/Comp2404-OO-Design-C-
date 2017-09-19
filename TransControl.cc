#include "TransControl.h"
#include "TransArray.h"
#include <sstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Transaction.h"
using namespace std;
TransControl::TransControl(){
	
}
TransControl::~TransControl(){
  for(int i=0;i<trans.getSize();i++){
    delete (trans.get(i));
  }
}
TransArray& TransControl::getTransArray(){return trans;}
void TransControl::update(Transaction* a){
	string tie;
	getTime(tie);
	a->setTime(tie);
	trans.add(a);
}

void TransControl::retrieve(TransArray& arr){
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
void TransControl::getTime(string& outTime){
  time_t rawTime;
  struct tm* myTime;
  stringstream ss1, ss2, ss3;


  time(&rawTime);
  myTime = localtime(&rawTime);

  ss2 << setfill('0') << setw(2);
  ss3 << setfill('0') << setw(2);

  ss1 << myTime->tm_year + 1900;
  ss2 << myTime->tm_mon + 1;
  ss3 << myTime->tm_mday;

  outTime = "";

  outTime += ss1.str();
  outTime += "/";
  outTime += ss2.str();
  outTime += "/";
  outTime += ss3.str();

}
