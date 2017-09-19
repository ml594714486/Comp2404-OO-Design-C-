#ifndef TRANSCONTROL_H
#define TRANSCONTROL_H
using namespace std;

#include "TransArray.h"


class TransControl
{
  public:
    TransControl();
    ~TransControl();
	void update(Transaction*);
	void retrieve(TransArray&);
	void getTime(string&);
	TransArray& getTransArray();
	
  private:
    TransArray trans;
    
};
#endif
