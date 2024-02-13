#ifndef _CONTACT_H
#define _CONTACT_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "User.h"
using namespace std;

class Contact
{
	int countContacts;
	vector<User> usersVector;
	User* userPoint;

	// methods for reading and outputing files
	void readData();
	void writeData();

public:
	Contact();
	~Contact();
	int countUsers();
	void addContact(string fName, string lName, string gender, string phnNum, string addres, string email);
	void listContacts();
	void search(string);
	void deleteContact(int);
	void deletAllContacts(bool);
	void getContact(int);

	void setFName(int s, string name) { usersVector[s].setFName(name); };
	void setLName(int s, string name) { usersVector[s].setLName(name); };
	void setGender(int s, string name) { usersVector[s].setGender(name); };
	User getUser(int indx) { return usersVector[indx]; }
	void assignUser(int indx, User us1) { usersVector[indx] = us1; }

	void PrntHdrClms() {
		cout << "id\t" << "first Name\t" << "last Name\t" << "gender  \t" << "Phone\t\t" << "Address\t\t" << "E-Mail\t\t\t" << "added Date"
			<< "\n====================================================================================================================================\n";
	}
};
#endif
