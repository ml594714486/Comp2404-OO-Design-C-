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

#ifndef VIEW_H
#define VIEW_H
#include "TransArray.h" 
#include <string>
using namespace std;
#include "Bank.h"

class View
{
  public:
    void mainMenu(int&);
    void adminMenu(int&);
    void custMenu(int&);
    void readCustId(int&);
    void readAcctType(AcctType&);
    void printAccounts(Bank&);
    void printTrans(TransArray&);
	void printCustomers(Bank&);
    void printBalance(double);
    void printError(string);
    void pause();

  private:
    int  readInt();
};

#endif
