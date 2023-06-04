#include "Bank.h"



//Setters or Mutators
void Bank::setAccountNo(long long int an) {
	accountNumber = an;
};
void Bank::setType(int ti) {
	ttype = (TRANSACTION_TYPE)ti;
};
void Bank::setBalance(double bal) {
	balance = bal;
};
void Bank::setOwner(const char* oName) {

	//Release any memory
	if (owner != nullptr)
		delete[]owner;

	int i = 0;
	//Get length of oName
	while (oName[i] != '\0') {
		i++;
	}

	//Allocate memory for owner
	owner = new char[i + 1];

	//Create a copyof each element of oName into owner
	i = 0;

	while (oName[i] != '\0') {
		owner[i] = oName[i];
		i++;
	}

	owner[i] = '\0';

	

};

//Friend Function
void accountInfo(Bank &obj) {
	cout << setw(12) << obj.accountNumber
		<< setw(10) << fixed << setprecision(2) << obj.balance
		<< setw(30) << obj.owner << endl;
};

//Getters or Accessors
long long int Bank::getAccountNo() const {

	return accountNumber;
};
TRANSACTION_TYPE Bank::getType()const {

	return ttype;
};
double Bank::getBalance() const {

	return balance;
};
char* Bank::getOwner() const {

	return owner;
};

//Default Constructor
Bank::Bank() {

	accountNumber = 9999999999;
	balance = 500;
	owner = nullptr;

};

//Constructor with 2 param
Bank::Bank(long long int param1, double param2) {

	accountNumber = param1;
	balance = param2;
	owner = nullptr;
};

//Constructor with 3 param
Bank::Bank(long long int param1, double param2, char* param3) {
	accountNumber = param1;
	balance = param2;
	setOwner(param3);

};

//Withdraw 
double Bank::widthdraw(double param1) {

	if (balance >= param1) {
		balance -= param1;
	}
	else {
		cout << "Insufficient balance";
		balance -= balance;
	}

	return balance;
};

//Deposit
double Bank::deposit(double param1) {

	balance += param1;

	return balance;
};

//Destructor
Bank::~Bank() {

	if (owner != nullptr) {
		delete[] owner;
		owner = nullptr;
	}
};