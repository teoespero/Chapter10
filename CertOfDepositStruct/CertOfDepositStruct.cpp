//  CertOfDepositStruct.cpp : Illustrate the use of structs
//  Teodulfo Espero
//  BS Cloud and Systems Administration
//  BS Software Development
//  Western Governors University

#include <iostream>

using namespace std;

// define the CD account structure
struct CDAccount
{
	double
		mybalance,
		interestrate;

	int
		term;

};

// show the new balance after
// the account matures after term
void printnewbalance(CDAccount computedaccount) {
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "new balance after maturity...." << computedaccount.mybalance << endl;

}

// computes for the new balance
// upon maturity of the CD
void getbalanceafterterm(CDAccount& theaccount) {
	double interestindecimal = theaccount.interestrate / 100.00,
		interestamount = theaccount.mybalance * interestindecimal * (theaccount.term / 12.0);

	theaccount.mybalance += interestamount;

}

// get CD account data
// from the user
void defineCDaccount(CDAccount &newaccount) {
	cout << "balance.....";
	cin >> newaccount.mybalance;

	cout << "interest rate.....";
	cin >> newaccount.interestrate;

	cout << "term.....";
	cin >> newaccount.term;
}



int main() {
	CDAccount bankoneCD;

	defineCDaccount(bankoneCD);
	getbalanceafterterm(bankoneCD);
	printnewbalance(bankoneCD);
}