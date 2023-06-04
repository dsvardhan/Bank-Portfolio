#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
#ifndef Bank_H
#define Bank_H


enum TRANSACTION_TYPE { DEPOSIT, WITHDRAWAL };

class Bank {

private:

	long long int accountNumber;
	TRANSACTION_TYPE ttype;
	double balance;
	char* owner;

	//Friend func
	friend void accountInfo(Bank&);

public:

	//Setters or Mutators
	void setAccountNo(long long int);
	void setType(int);
	void setBalance(double);
	void setOwner(const char*);

	//Getters or Accessors
	long long int getAccountNo() const;
	TRANSACTION_TYPE getType()const;
	double getBalance() const;
	char* getOwner() const;

	//Default Constructor
	Bank();

	//Constructor with 2 param
	Bank(long long int, double);

	//Constructor with 3 param
	Bank(long long int, double, char*);

	//Withdraw 
	double widthdraw(double);

	//Deposit
	double deposit(double);

	//Destructor
	~Bank();

};

#endif;

