#include <string>
#include <cstdlib>
using namespace std;

#include "TransArray.h"

TransArray::TransArray()
{
  size = 0;
}

int TransArray::getSize() { return size; }

Transaction* TransArray::get(int index)
{
  if (index < 0 || index >= size)
    exit(1);
  return elements[index];
}

void TransArray::add(Transaction* cust)
{
  if (size >= MAX_ARR)
    return;

  elements[size++] = cust;
}
