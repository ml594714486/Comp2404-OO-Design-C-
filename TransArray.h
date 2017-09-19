#ifndef TRANSARRAY_H
#define TRANSARRAY_H

#include "defs.h"
#include "Transaction.h"

class TransArray
{
  public:
    TransArray();
    void add(Transaction*);
    Transaction* get(int);
    int getSize();
  private:
    Transaction* elements[MAX_ARR];
    int size;
};

#endif
