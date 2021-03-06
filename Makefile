OBJ = main.o BankControl.o Bank.o Account.o View.o AcctArray.o Customer.o CustArray.o Transaction.o TransArray.o TransControl.o Observer.o Logger.o Subject.o
bsys:	$(OBJ)
	g++ -o bsys $(OBJ)

main.o:	main.cc 
	g++ -c main.cc

BankControl.o:	BankControl.cc BankControl.h Bank.h View.h Customer.h  TransControl.h Subject.h
	g++ -c BankControl.cc

View.o:	View.cc View.h Customer.h
	g++ -c View.cc

Bank.o:	Bank.cc Bank.h AcctArray.h CustArray.h
	g++ -c Bank.cc

Account.o:	Account.cc Account.h 
	g++ -c Account.cc

AcctArray.o:	AcctArray.cc AcctArray.h Account.h defs.h
	g++ -c AcctArray.cc

Customer.o:	Customer.cc Customer.h defs.h
	g++ -c Customer.cc

CustArray.o:	CustArray.cc CustArray.h Customer.h defs.h
	g++ -c CustArray.cc
Transaction.o:	Transaction.cc Transaction.h defs.h
	g++ -c Transaction.cc
TransArray.o:	Transaction.h TransArray.h TransArray.cc defs.h
	g++ -c TransArray.cc
TranControl.o:	TransControl.h TransControl.cc TransArray.h Transaction.h
	g++ -c TransControl.cc
Observer.o: Observer.h Observer.cc
	g++ -c Observer.cc
Logger.o: Logger.h Logger.cc TransArray.h BankControl.h
	g++ -c	Logger.cc
Subject.o: Subject.h Subject.cc Observer.h
	g++ -c Subject.cc
clean:
	rm -f $(OBJ) bsys
