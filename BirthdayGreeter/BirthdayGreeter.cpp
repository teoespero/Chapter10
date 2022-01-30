//  BirthdayGreeter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  Teodulfo Espero
//  BS Cloud and Systems Administration
//  BS Software Development
//  Western Governors University

#include <iostream>

using namespace std;

// parent class
class TheDate {
public:

	// define the struc to
	// hold the dates
	struct Date {
		int	
			month, 
			day, 
			year;
	};
	
	// define the struc 
	// to hold the names
	struct Name {
		string 
			lastname,
			firstname;

	};

	Date myDate;
	Name myname;

	bool checkdate();
	bool isLeapyear();
};

// child class
class ProcessDates :public TheDate {
public:

	bool isItYourBday(TheDate theDOB);
	void greetFuncs(bool mybirthdaytoday, TheDate theDOB);
	void getname();
	void getdate();
};

int main() {
	ProcessDates today, theDOB;
	bool mybirthdaytoday = false;
	
	// user name
	today.getname();

	// current date
	do {
		cout << "Current date:" << endl;
		today.getdate();
	} while (!(today.checkdate()));
	
	
	// birthday
	do {
		cout << "Birthday:" << endl;
		theDOB.getdate();
	} while (!(theDOB.checkdate()));
	
	// check if today is the user's bday
	mybirthdaytoday = today.isItYourBday(theDOB);
	today.greetFuncs(mybirthdaytoday, theDOB);
}

bool TheDate::isLeapyear() {
	if ((myDate.year % 4) == 0)
		return true;
	else
		return false;
}

bool TheDate::checkdate() {
	// check if the date entered is valid
	// months 1-12
	if (
		myDate.month >= 1 
		&& myDate.month <= 12
		) {
		if (myDate.month == 2) {
			if (isLeapyear()) {
				if (
					myDate.day >= 1 
					&& myDate.day <=29
					) {
					return true;
				}
				else {
					cout << "\t**** invalid date." << endl;
					return false;
				}
			}
			else {
				if (
					myDate.day >= 1 
					&& myDate.day <= 28
					) {
					return true;
				}
				else {
					cout << "\t**** invalid date." << endl;
					return false;
				}
			}
		}

		// we are also validating if the number of days
		// corresponds to the month they entered
		else if (
			myDate.month == 1 
			|| myDate.month == 3 
			|| myDate.month == 5 
			|| myDate.month == 7 
			|| myDate.month == 8 
			|| myDate.month == 10 
			|| myDate.month == 12
			) {
			if (myDate.day >= 1 and myDate.day <= 31) {
				return true;
			}
			else {
				cout << "\t**** invalid date." << endl;
				return false;
			}
		}
		else if (
			myDate.month ==4 
			|| myDate.month == 6 
			|| myDate.month == 9 
			|| myDate.month == 11
			) {
			if (
				myDate.day >= 1 
				&& myDate.day <= 30
				) {
				return true;
			}
			else {
				cout << "\t**** invalid date." << endl;
				return false;
			}
		}
	}
	else {
		cout << "\t**** invalid date." << endl;
		return false;
	}
}

void ProcessDates::getdate() {
	// current date
	cout << "month.....";
	cin >> myDate.month;

	cout << "day.....";
	cin >> myDate.day;

	cout << "year.....";
	cin >> myDate.year;
}

void ProcessDates::getname() {
	// get name
	cout << "Names:" << endl;
	cout << "lastname...";
	cin >> myname.lastname;

	cout << "firstname...";
	cin >> myname.firstname;
}

bool ProcessDates::isItYourBday(TheDate theDOB) {
	if (
		myDate.month== theDOB.myDate.month 
		&& myDate.day == theDOB.myDate.day)
		return true;
	else
		return false;
}

void ProcessDates::greetFuncs(bool mybirthdaytoday, TheDate theDOB) {
	int 
		waitmonths = 0,
		waitdays = 0,
		missedays = 0;

	if (mybirthdaytoday) {
		// happy birthday

		cout << endl << endl;
		cout << "************************************" << endl;
		cout << "Happy birthday!!!!!" << myname.firstname << " " << myname.lastname << endl;
		cout << "You are now " << myDate.year- theDOB.myDate.year << " yearls old..." << endl;
		cout << "************************************" << endl;
	}
	else {
		// not your birthday

		cout << endl << endl;
		cout << "Sorry. " << myname.firstname << ". " << endl;
		cout << "Today is not your birthday....." << endl;

		// get the number of days you have to wait/missed
		// if the curr month is your bday
		if (theDOB.myDate.month == myDate.month) {
			if (myDate.day < theDOB.myDate.day)
				waitdays = theDOB.myDate.day - myDate.day;
			else
				missedays = myDate.day - theDOB.myDate.day;
		}

		// compute the number of months you have to wait
		// for your next bday
		else if (theDOB.myDate.month > myDate.month) {
			waitmonths = theDOB.myDate.month - myDate.month;
		}
		// if your birthday month has passed
		// you must wait for another year
		else {
			waitmonths = (12 - myDate.month) + theDOB.myDate.month;
		}
			

		// tell the user how long they
		// have to wait until their bday
		if (waitmonths > 0)
			cout << "You need to wait " << waitmonths << " months "
			<< " and " << theDOB.myDate.day << " before your next birthday..." << endl;
		if (waitdays > 0)
			cout << "You need to wait " << waitdays << " days before your next birthday..." << endl;
		if (missedays > 0)
			cout << "You celebrated your birthday " << missedays << " days ago..." << endl;
	}
}