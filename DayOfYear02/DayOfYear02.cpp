//  DayOfYear02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  Teodulfo Espero
//  BS Cloud and Systems Administration
//  BS Software Development
//  Western Governors University

#include <iostream>

using namespace std;

class DayOfYear {
public:
	void getdate();
	void showdate();

	void set(int newmonth, int newday);
	int getmonth();
	int getday();
	bool birthdaytoday(int bdaymonth, int bdayday);

private:
	void checkdate();
	int month;
	int day;
};

int main(){
	int mymonth, myday;
	DayOfYear currentday, birthday;

	cout << "today's date....." << endl;
	cout << "month.....";
	cin >> mymonth;

	cout << "day.....";
	cin >> myday;

	currentday.set(mymonth, myday);	

	cout << "your birthdate....." << endl;
	cout << "month.....";
	cin >> mymonth;

	cout << "day.....";
	cin >> myday;

	birthday.set(mymonth, myday);

	if (currentday.birthdaytoday(birthday.getmonth(), birthday.getday())) {
		cout << "happy birthday!!!!" << endl;
	}
	else {
		cout << "not your birthday, but i hope you have a good day..." << endl;
	}

	

}

bool DayOfYear::birthdaytoday(int bdaymonth, int bdayday) {
	if (getday() == bdayday && getmonth() == bdaymonth) {
		return true;
	}
	else {
		return false;
	}
}

void DayOfYear::getdate() {
	cout << "month [1-12].....";
	cin >> month;

	cout << "day.....";
	cin >> day;
}

void DayOfYear::set(int newmonth, int newday) {
	month = newmonth;
	day = newday;
	checkdate();
}

void DayOfYear::checkdate(){
	if ((month < 1) || (month > 12) || (day < 1) || (day > 31)){
		cout << "Illegal date. Aborting program.\n";
		exit(1);
	}
}

int DayOfYear::getmonth() {
	return month;
}

int DayOfYear::getday(){
	return day;
}

void DayOfYear::showdate() {
	cout << "month: " << getmonth() << endl;
	cout << "day: " << getday() << endl;
}