#include "Customer.h"
#include "defs.h"
#include "Account.h"
using namespace std;
class CustArray
{
	public:
		CustArray();
		void add(Customer*);
		Customer* get(int);
                bool find(Account*);
		int getSize();
	private:
		Customer* elements[MAX_ARR];
		int size;
};
