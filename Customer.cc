#include "defs.h"
#include "Customer.h"

Customer::Customer()
{
	id=0;
	name=" ";
}

Customer::Customer(int i, string n)
{
  id = i;
  name = n;
}

int Customer::getid(){ return id;}
string Customer::getname(){ return name;}



