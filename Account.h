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

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "defs.h"
#include "Customer.h"
class Account
{
  public:
    Account(Customer*, AcctType);
    AcctType   getAcctType();
    int        getAcctNum();
    Customer*  getCust();
    double      getBalance();
	void deposit(double x);
	void withdraw(double x);
  protected:
    static int nextAcctNum;
    AcctType   acctType;
    int        acctNum;
    Customer*  cust;
    double      balance;
};

#endif
