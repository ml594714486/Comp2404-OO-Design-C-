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

#include <string>
#include <cstdlib>
using namespace std;

#include "AcctArray.h"

AcctArray::AcctArray()
{
  size = 0;
}

int AcctArray::getSize() { return size; }

Account* AcctArray::get(int index)
{
  if (index < 0 || index >= size)
    exit(1);
  return elements[index];
}

void AcctArray::add(Account* cust)
{
  if (size >= MAX_ARR)
    return;

  elements[size++] = cust;
}

