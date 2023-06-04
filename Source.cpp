/*
Name: Srinivas Vardhan Dintakurthi

Class Name: CS-1337.503 Computer Programming-1

Due Date:11/13/2022

Description:This program will read in data from the file, find out number of unique accounts, and updates the balance 
based on the transaction type entered by the user.It creates an array of objects which belong to a class defined in .cpp and .h files attached.
It calls the getters to display account information and uses setters to update private variables.It also calls the friend function which 
]can directly access the variable of an object.It finally outputs a table displaying the portfolio of a bank.
*/


#include "Bank.h"
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

void displayAccountInfo(Bank &obj) {

    
       cout <<setw(12)<<obj.getAccountNo()
        << setw(10)<<fixed<<setprecision(2) << obj.getBalance()
        <<setw(30) << obj.getOwner()<<endl;

}

//Count Unique accounts
int countUniq(const char*, int);
int getNumberOfRecords(const char*);
int readFile(const char*, Bank*&);

int main() {


    const char file[100] = "bankInfo.txt";

    ifstream input;
    input.open(file);

    if (!input.is_open()) {
        cout << "Error opening file";
        return -1;
    }

    

    int size = getNumberOfRecords(file);
    size = size / 4;

    int usize = countUniq(file, size);

    Bank* portfolio;
    portfolio = new Bank[usize];



    bool inread = false;
    inread=readFile(file, portfolio);
    cout << endl;

    
    
    cout << setw(12) << "Account Number" << setw(10) << "Amount"
        << setw(30) << "Owner" << endl;

    int i = 0;
    while (i < usize) {

        displayAccountInfo(portfolio[i]);
        i++;
    }

   
    cout << endl;

    int j = 0;
    

    cout << setw(12) << "Account Number" << setw(10) << "Amount"
        << setw(30) << "Owner" << endl;

   while( j< usize) {

       accountInfo(portfolio[j]);
       j++;

   }

   portfolio->~Bank();
    if (portfolio != nullptr) {
       delete[] portfolio;
       portfolio = nullptr;
    }
    return 0;
}

//Used to find size of file
int getNumberOfRecords(const char* filename) {
    ifstream in;
    in.open(filename);
    if (!in.is_open()) {
        return -1;
    }
    int counter = 0;
    char buffer[1000];
    while (!in.eof()) {
        in.getline(buffer, 1000);
        counter++;
    }
    in.close();
    return counter;
}

//Find the number of unique student ids
int countUniq(const char* fn, int N) {

    //The worst case, all the records in the file are unique.
    //This is there are no repeated entries

   long long int* uniqueIDs = new long long int[N];

    ifstream in;
    in.open(fn);

    if (!in.is_open()) {
        return -1;
    }

    long long int anHelper;
    char onhelper[100];



    int uCounter = 0;
    bool found;

    while (!in.eof()&& uCounter<N) {

        //These are helpers, just to read the file content
        in >> anHelper;
        in.getline(onhelper,100);
        in.getline(onhelper, 100);
        in.getline(onhelper, 100);
        in.getline(onhelper, 100);

        //Set the found to false
        found = false;

        int i;

        //Go through all the current elementss in uniqueIDs
        for (i = 0; i < uCounter; i++) {

            //The value we are looking for is stored in anHelper.
            if (uniqueIDs[i] == anHelper) {
                found = true;
                break;
            }
        }

        //If the idHelper is not found, add it to the uniqeuIDs
        if (!found) {

            uniqueIDs[uCounter] = anHelper;

            //Now we have one more element in uniqueIDs array
            uCounter++;
        }
    }
    in.close();

    //release the memory allocated for uniqueIDs
    if(uniqueIDs!=nullptr)
    delete[] uniqueIDs;

    //Return the counter of unique ids.
    return uCounter;
}




//Reads and adds onlu unique accounts
int readFile(const char* fn, Bank*& data) {

    ifstream in;
    in.open(fn);

    if (!in.is_open()) {
        return -1;
    }

    long long int anHelper;
    int typeHelper;
    double amtHelper;
    char dummy[100];
    char waste[100];
    double a;

    int uCounter = 0;
    bool found;

   
    while (!in.eof()) {

        //Now we care about the type, id and grade
        in >> anHelper;
        in >> typeHelper;
        in >> amtHelper;
        in.getline(waste, 100);
        in.getline(dummy, 100);

        found = false;
        int i;

        //Find the if the id is already in the data array
        for (i = 0; i < uCounter; i++) {

            //The key is the id
            if (data[i].getAccountNo() == anHelper) {
                found = true;
                break;
            }
        }
        //If the id is not found
        if (!found) {

            
            //Add it to the data array
            data[uCounter].setAccountNo(anHelper);
            data[uCounter].setType(typeHelper);

            //Update the balance, depending on the typeHelper
            if (typeHelper == 0) {
                a = data[uCounter].deposit(amtHelper);
            }
            else if (typeHelper == 1) {
                a = data[uCounter].widthdraw(amtHelper);
            }

            data[uCounter].setBalance(a);

            data[uCounter].setOwner(dummy);
                
            //Increase the counter of unique eleement in data
            uCounter++;
        }
        else {
            //if the id was ffound, then update the grade
            if (typeHelper == 0)
                a = data[i].deposit(amtHelper);
            if (typeHelper == 1)
                a = data[i].widthdraw(amtHelper);

            data[i].setBalance(a);

        }
    }
    in.close();

   
    //this is just to make sure the function read all teh unique elements
    return uCounter;
}

