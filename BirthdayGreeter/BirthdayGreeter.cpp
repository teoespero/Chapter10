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
	int	month, day, year;
	struct Name {
		string lastname,
			firstname;

	};

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
	cin >> today.month;

	cout << "day.....";
	cin >> today.day;

	cout << "year.....";
	cin >> today.year;

	cout << endl << endl;

	// birthday
	cout << "Your birthdate:" << endl << endl;

	cout << "month.....";
	cin >> theDOB.month;

	cout << "day.....";
	cin >> theDOB.day;

	cout << "year.....";
	cin >> theDOB.year;

	mybirthdaytoday = today.isItYourBday(theDOB);
	today.greetFuncs(mybirthdaytoday, theDOB);
}

bool ProcessDates::isItYourBday(TheDate theDOB) {
	if (month == theDOB.month && day == theDOB.day)
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
		cout << "You are now " << year - theDOB.year << " yearls old..." << endl;
		cout << "************************************" << endl;
	}
	else {
		// not your birthday

		cout << endl << endl;
		cout << "Sorry. " << myname.firstname << ". " << endl;
		cout << "Today is not your birthday....." << endl;
		if (theDOB.month == month) {
			if (day < theDOB.day)
				waitdays = theDOB.day - day;
			else
				missedays = theDOB.day - theDOB.day;
		}
		else if (theDOB.month > month)
			waitmonths = theDOB.month - month;
		else
			waitmonths = 12 - (theDOB.month + month);
		if (waitmonths > 0)
			cout << "You need to wait " << waitmonths << " months "
			<< " and " << theDOB.day << " before your next birthday..." << endl;
		if (waitdays > 0)
			cout << "You need to wait " << waitdays << " days before your next birthday..." << endl;
		if (missedays > 0)
			cout << "You celebrated your birthday " << missedays << " days ago..." << endl;
	}
}