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

#ifndef BANKCONTROL_H
#define BANKCONTROL_H
#include "Transaction.h"
#include "Bank.h"
#include "View.h"
#include "TransControl.h"
#include "Subject.h"
class BankControl : public Subject
{
  public:
    BankControl();
    ~BankControl();
    void launch();
    Transaction* getLast();
    virtual void subscribe(Observer*);
  private:
	Transaction* last;
    Bank bank;
	TransControl trans;
    View view;
    void init();
    void processAdmin();
    void processCust();
};
#endif
