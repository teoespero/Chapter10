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
};

// child class
class ProcessDates :public TheDate {
public:

	bool isItYourBday(TheDate theDOB);
	void greetFuncs(bool mybirthdaytoday, TheDate theDOB);
};

int main() {
	ProcessDates today, theDOB;
	bool mybirthdaytoday = false;
	
	// get name
	cout << "Names:" << endl;
	cout << "lastname...";
	cin >> today.myname.lastname;

	cout << "firstname...";
	cin >> today.myname.firstname;

	// current date
	cout << "Current date:" << endl << endl;

	cout << "month.....";
	cin >> today.myDate.month;

	cout << "day.....";
	cin >> today.myDate.day;

	cout << "year.....";
	cin >> today.myDate.year;

	cout << endl << endl;

	// birthday
	cout << "Your birthdate:" << endl << endl;

	cout << "month.....";
	cin >> theDOB.myDate.month;

	cout << "day.....";
	cin >> theDOB.myDate.day;

	cout << "year.....";
	cin >> theDOB.myDate.year;

	mybirthdaytoday = today.isItYourBday(theDOB);
	today.greetFuncs(mybirthdaytoday, theDOB);
}

bool ProcessDates::isItYourBday(TheDate theDOB) {
	if (myDate.month== theDOB.myDate.month && myDate.day == theDOB.myDate.day)
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
		else if (theDOB.myDate.month > myDate.month)
			waitmonths = theDOB.myDate.month - myDate.month;
		else
			waitmonths = 12 - (theDOB.myDate.month + myDate.month);

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