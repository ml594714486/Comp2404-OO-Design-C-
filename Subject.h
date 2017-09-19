#ifndef SUBJECT_H
#define SUBJECT_H

#include "defs.h"
#include "Observer.h"

class Subject
{
	public:
	  Subject();
	  void subscribe(Observer*);
	  void unsubscribe(Observer*);
	  void notify();
	Observer** getlist();
	private:
	  Observer* list[MAX_ARR];
	  int size;
};

#endif
