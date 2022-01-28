//  EmbeddedStructs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  Teodulfo Espero
//  BS Cloud and Systems Administration
//  BS Software Development
//  Western Governors University

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

// definition of a date
struct Dates{
	int month, day, year;
};

// defining a phone number
struct Phoneinfo{
	string areacode, phonenum, ext;
};

// defining an address
struct Address {
	int streetnum;
	string streetname, city, state, zip;
};

// defining a name
struct Name {
	string lastname, firstname;
};

// putting all the different structures
// together to form one record
// consisting of several types of data
struct Personnelrec {
	Name fullname;
	Dates birthday;
	Phoneinfo contactinfo;
	Address mailingaddress;
};


// print the data file
void printdata() {
	ifstream mydatafle;
	string linedata;
	
	mydatafle.open("mydatafile.txt");
	if (mydatafle.fail()) {
		cout << "File I/O error....." << endl;
		exit(1);
	}
	else
	{
		while (getline(mydatafle, linedata)) {
			cout << linedata << endl;
		}
	}
	mydatafle.close();
}

// save the user input into a data 
// file on disk
void writetofile(Personnelrec& rectowrite) {
	ofstream myFile;

	myFile.open("mydatafile.txt", ios::app);
	if (myFile.fail()) {
		cout << "\t***File I/O Error....." << endl;
		exit(1);
	}
	else {
		myFile << "---------------------------" << endl;
		myFile << "Name: " << rectowrite.fullname.firstname 
			<< " " << rectowrite.fullname.lastname 
			<< endl;

		myFile << "DOB: "
			<< rectowrite.birthday.month
			<< "." << rectowrite.birthday.day
			<< "." << rectowrite.birthday.year
			<< endl;

		myFile << "Mailing address: "
			<< rectowrite.mailingaddress.streetnum 
			<< " " << rectowrite.mailingaddress.streetname
			<< ", " << rectowrite.mailingaddress.city
			<< ", " << rectowrite.mailingaddress.state
			<< ", " << rectowrite.mailingaddress.zip
			<< endl;

		myFile << "Contact info:  "
			<< "(" << rectowrite.contactinfo.areacode << ")"
			<< " " << rectowrite.contactinfo.phonenum
			<< " ext " << rectowrite.contactinfo.ext
			<< endl;
	}
	myFile.close();
	cout << "\t(1) record saved" << endl;
}

// function to get input
// from the program user
void getinfofromuser(Personnelrec& newrecord) {
	
	cout << "first name.....";
	cin >> newrecord.fullname.firstname;

	cout << "last name.....";
	cin >> newrecord.fullname.lastname;

	cout << "birthday....." << endl;
	cout << "month.....";
	cin >> newrecord.birthday.month;

	cout << "day.....";
	cin >> newrecord.birthday.day;

	cout << "year.....";
	cin >> newrecord.birthday.year;

	cout << "mailing info....." << endl;
	cout << "Street number.....";
	cin >> newrecord.mailingaddress.streetnum;

	cin.ignore();
	cout << "Street name.....";
	getline(cin, newrecord.mailingaddress.streetname);

	cout << "Street city.....";
	getline(cin, newrecord.mailingaddress.city);

	cout << "state.....";
	cin >> newrecord.mailingaddress.state;

	cout << "zip.....";
	cin >> newrecord.mailingaddress.zip;

	cout << "phone info....." << endl;
	cout << "area code.....";
	cin >> newrecord.contactinfo.areacode;

	cout << "phone number.....";
	cin >> newrecord.contactinfo.phonenum;

	cin.ignore();
	cout << "ext.....";
	getline(cin, newrecord.contactinfo.ext);

}

int main(){
	Personnelrec newrec;
	char yesno = 'y';
	do {
		getinfofromuser(newrec);
		writetofile(newrec);
		cout << "add more [y/n]?.....";
		cin >> yesno;
	} while (yesno == 'y');

	system("CLS");
	printdata();
}

