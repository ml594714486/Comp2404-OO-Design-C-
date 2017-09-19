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

#ifndef ACCTARRAY_H
#define ACCTARRAY_H

#include "defs.h"
#include "Account.h"

class AcctArray
{
  public:
    AcctArray();
    void add(Account*);
    Account* get(int);
    int getSize();
  private:
    Account* elements[MAX_ARR];
    int size;
};

#endif

