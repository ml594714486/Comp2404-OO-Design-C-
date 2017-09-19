#include "CustArray.h"
#include <cstdlib>
#include "defs.h"
#include <iostream>
using namespace std;
CustArray::CustArray()
{
	size=0;
}
void CustArray::add(Customer* cust)
{
	if(size>=MAX_ARR)
		return;
	elements[size++]=cust;
}
Customer* CustArray::get(int index)
{
	if(index<0||index>=size)
	        exit(1);
	return elements[index];
}

bool CustArray::find(Account* acct){
  for(int i=0;i<size;i++){
    if(acct->getCust()->getid() == get(i)->getid()){
      return true;
    }
  }
  return false;
}
int CustArray::getSize()
{
	return size;
}
