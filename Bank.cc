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


#include "Bank.h"
#include "iostream"
AcctArray& Bank::getAccounts() { return accounts; }

void Bank::addAcct(Account* acct)
{
    if(custArray.find(acct)){
    accounts.add(acct);
    }else{
    cout<<"No Suit Result For This ID"<<endl;
    }
}

CustArray& Bank::getCust(){ return custArray; }

void Bank::addCust(Customer* cust)
{
  custArray.add(cust);
}
