#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
using namespace std;


class Customer
{
 public:
  Customer();
  Customer(int,string);
  int getid();
  string getname();
 private:
  int id;
  string name;
};

#endif
