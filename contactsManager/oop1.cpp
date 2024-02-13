// oop1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include "Contact.h"
using namespace std;

// main program object
Contact c1;


// functions prototypes
void welcomeIntro();
void mainScreen();
void outro();
void search();
void addContact();
void editContct();
void editPhones(int);
void editAddresses(int);
void editEmails(int);

int main()
{
	welcomeIntro();
	mainScreen();
	outro();

}


// this is welcome screen for User
void welcomeIntro() {

	// function output the header of the application
	cout << "\n\t\t\t\t";
	for (int i = 0; i < 16; i++) {
		cout << '=';
	}
	cout << endl << "\t\t\t\t";
	cout << " Contact Manager " << "\n\t\t\t\t";;
	for (int i = 0; i < 16; i++) {
		cout << '=';
	}
	cout << endl << "\n\n\n\n";
}





void mainScreen() {
	int dec = 6;
	// Main screen of application and its followed attributes based on switch 
	while (dec) {
		cout << "-------------------------------" << endl;
		cout << "[1] List Contacts" << endl
			<< "[2] Print Number of Contacts" << endl
			<< "[3] Search" << endl
			<< "[4] Add a contact" << endl
			<< "[5] Edit a Contact" << endl
			<< "[6] Delete all contacts " << endl
			<< "[0] Exit" << endl;
		cout << "-------------------------------\n\n";

		cout << "Please Choose a number to proceed : ";
		cin >> dec;
		cout << "\n--------------------------------\n";
		switch (dec) {
		case 1:
			c1.listContacts();
			break;
		case 2:
			cout << endl << "Number of contacts : " << c1.countUsers()<<endl;
			break;
		case 3:
			search();
			break;
		case 4:
			addContact();
			break;
		case 5:
			editContct();
			break;
		case 6:
			char dec;
			cout << "delete All contacts, Are you Sure??(Enter y for yes or n for no)";
			cin >> dec;
			cout << endl;
			if(tolower(dec)=='y')
			c1.deletAllContacts(true);
		}
	}
}

// out screen for the user
void outro() {
	cout << "\n\n\n\t\t\t Programmed by : Elsayed Ahmed Elsayed" << endl;
}


// function to search for users using name or phone number
void search() {
	string key;
	cout << endl
		<< "Enter a Key to search for: ";
	cin >> key;
	c1.search(key);
}


void addContact() {
	//void Contact::addContact(string fName, string lName, string gender, string phnNum, string addres, string email)

	// getting inputs from the user to fill inside a new user object
	string fName, lName, gender, phoneNum ,addres ,email;
	cout << "Enter User Informations:-\n";
	cout <<"\nEnter First Name : ";
	cin.ignore();
	getline(cin, fName);
	cout << "\nEnter Last Name : ";
	getline(cin, lName);
	cout << "\nEnter Gender: ";
	getline(cin, gender);
	cout << "\nEnter Phone number : ";
	getline(cin, phoneNum);
	cout << "\nEnter Address : ";
	getline(cin, addres);
	cout << "\nEnter E-mail : ";
	getline(cin, email);
	c1.addContact(fName, lName, gender, phoneNum, addres, email);
	cout << "\n\t\t\t\t New contact added successfully"<<endl;
}



void editContct() {
	system("cls");// clearing console screen
	// Edit contact screen with its Attributes 
	int usId;
	int decs2 =10;
	string name;
	while (decs2 != 0) {


		cout << "\n\n\n";
		cout << "\t\t\t\tEditing Menu\n"
			<< "\t\t\t\t-------------" << endl;
		cout << "(1)-Change First Name " << endl
			<< "(2)-Change Last Name " << endl
			<< "(3)-Change gender " << endl
			<< "(4)-Edit Phones " << endl
			<< "(5)-Edit Addreses " << endl
			<< "(6)-Edit Emails " << endl
			<< "(7)-Delete Contact" << endl
			<< "(0)-Return to Main Menu" << endl;

		cout << endl << "Enter a User Id to Edit or Press( "<<c1.countUsers()+5<<" to exit) : ";
		// this loop check to get right id from user
		bool exit = true;
		while (exit)
		{
			cin.ignore();
			cin >> usId;
			if (usId == c1.countUsers() + 5) { exit = false; break; }
			if (usId < c1.countUsers()) 
				break;
			else {
				cout << "Please Enter a valid Id: ";
			}
		}
		if (!exit) {
			break;
		}
		c1.PrntHdrClms();
		c1.getContact(usId);

		cout << "\nNext choose one of Processes to do on your contact: ";
		cin >> decs2;
		cout << endl;
		switch (decs2)
		{
		case 1:
			cout << endl << "Please Enter a new First Name: ";
			cin.ignore();
			getline(cin, name);
			c1.setFName(usId, name);
			break;
		case 2:
			cout << endl << "Please Enter a new Last Name: ";
			cin.ignore();
			getline(cin, name);
			c1.setLName(usId, name);
			break;
		case 3:
			cout << endl << "Please Enter Gender: ";
			cin.ignore();
			getline(cin, name);
			c1.setGender(usId, name);
			break;
		case 4:
			editPhones(usId);
			break;
		case 5:
			editAddresses(usId);
			break;
		case 6:
			editEmails(usId);
			break;
		case 7:
			char dec;
			cout << "Are you Sure??(Enter y for yes or n for no) ";
			cin >> dec;
			cout << endl;
			if(tolower(dec) == 'y') {
				c1.deleteContact(usId);
				cout << "\t\t\t Contact with id " << usId << " Deleted Successfully ...:(\n" << endl;
			}
			break;
		}

	}
	system("cls");// clearing console screen

}

void editPhones(int id) {
	
	// Editing phones screen

	cout << "\n\n\n"
		<< "All phone Numbers : \n";
	cout << "Phone Number \t\t\t\t Type \t\t\t Description" << endl;

	// out put phones of the user and connected types and descriptions
	for (int i = 0; i < c1.getUser(id).getPhonesCount(); i++)
	{
		cout << '{' << i + 1 << "} " << c1.getUser(id).getPhoneNumber(i);
		(c1.getUser(id).getPhoneNumber(i).length() > 15) ? cout << " \t\t" : cout << "\t\t\t\t";
		cout<<c1.getUser(id).getPhonesTyp(i).getType() << " \t\t" << c1.getUser(id).getPhoneNumberDscrptn(i) << endl;
	}
	cout << "\n\n\n";

				cout << "\t\t\t\t Editing Phones Menu\n"
			<< "\t\t\t\t------------------------\n\n";
				int decs3 = -2;
		while (decs3 != 0) {

			cout << "<1> Change Phone Number \n"
				<< "<2> change phone Type \n"
				<< "<3> change phone Discribtion \n"
				<< "<4> Enter A new Id \n"
				<<"<0> Return To Edit Contact Menu\n\n"<<endl;

			cout << "Choose a process to proceed:";
			cin >> decs3;
			cout << endl;
			User* us1 = new User;
			*us1 = c1.getUser(id);

			int decs4;
			string str;
			switch (decs3)
			{
				case 1:
				{
					cout << '\n';
					

					cout << "Choose Phone Number to Edit : ";
					while (true) {
						cin >> decs4;
						if (decs4 <= us1->getPhonesCount() && decs4 >= 0) {
							break;
						}
						else { cout << "!!!!Please Enter a Valid Number"; }
					}
					cin.ignore();
					cout << "\nEnter the New Number :";
					getline(cin, str);

					us1->setPhone(decs4 - 1, str);
					c1.assignUser(id, *us1);
					cout << "\t\t\t\tPhone Number changed Successfully..." << endl;
				}
				break;

				case 2:
				{
					cout << "Choose Phone Number to Edit its type : ";
					cin.ignore();
					while (true) {
						cin >> decs4;
						if (decs4 <= us1->getPhonesCount() && decs4 >= 0) {
							break;
						}
						else { cout << "!!!!Please Enter a Valid Number"; }
					}
					cout << "\nEnter the New phone type :";
					cin.ignore();
					getline(cin, str);

					us1->setPhoneType(decs4 - 1, str);
					
					c1.assignUser(id, *us1);
					cout << "\t\t\t\tPhone Type changed Successfully..." << endl;
				}
				break;

				case 3:
				{
					cout << "Choose Phone Number to Edit its Description: ";
					while (true) {
						cin >> decs4;
						if (decs4 <= us1->getPhonesCount() && decs4 >= 0) {
							break;
						}
						else { cout << "!!!!Please Enter a Valid Number"; }
					}
					cout << "\nEnter the New Description :";
					cin.ignore();
					getline(cin, str);

					us1->setPhoneDscrptn(decs4 - 1, str);
					c1.assignUser(id, *us1);
					cout << "\t\t\t\tPhone Description changed Successfully..." << endl;
					}
				break;
				case 4:
					cout << endl
					      <<"Please enter New Id : ";
					while (true)
					{
						cin.ignore();
						cin >> id;
						if (id < c1.countUsers())
							break;
						else {
							cout << "Please Enter a valid Id: ";
						}
					}
					cout << "\n\n";
					break;
			default:
				break;
			}
			
			delete us1;
		}
		system("cls");// clearing console screen


}

void editAddresses(int id) {
	// Editing Address screen

	//c1.PrntHdrClms();
	//c1.getContact(id);
	cout << "\n\n\n"
		<< "All Addresses : \n";
	cout << "Address \t\t\t\t Type \t\t\t Description" << endl;

	// output Address of the user and connected types and descriptions
	for (int i = 0; i < c1.getUser(id).getAddressesCount(); i++)
	{
		cout << '{' << i + 1 << "} " << c1.getUser(id).getAddressesTyp(i).getPlace();
		(c1.getUser(id).getAddressesTyp(i).getPlace().length() > 15) ? cout << " \t\t" : cout << "\t\t\t\t";
		cout << c1.getUser(id).getAddressesTyp(i).getType() << " \t\t" << c1.getUser(id).getAddressesTyp(i).getDescription() << endl;
	}
	cout << "\n\n\n";

	cout << "\t\t\t\t Editing Addresses Menu\n"
		<< "\t\t\t\t------------------------\n\n";
	int decs3 = -2;
	while (decs3 != 0) {

		cout << "<1> Change Address \n"
			<< "<2> change Address Type \n"
			<< "<3> change Address Discribtion \n"
			<< "<4> Enter A new Id \n"
			<< "<0> Return To Edit Contact Menu\n\n" << endl;

		cout << "Choose a process to proceed:";
		cin >> decs3;
		cout << endl;
		User* us1 = new User;
		*us1 = c1.getUser(id);

		int decs4;
		string str;
		switch (decs3)
		{
		case 1:
		{
			cout << '\n';


			cout << "Choose Address to Edit : ";
			while (true) {
				cin >> decs4;
				if (decs4 <= us1->getAddressesCount() && decs4 >= 0) {
					break;
				}
				else { cout << "!!!!Please Enter a Valid Number"; }
			}
			cin.ignore();
			cout << "\nEnter the New Address :";
			getline(cin, str);

			us1->setAddress(decs4 - 1, str);
			c1.assignUser(id, *us1);
			cout << "\t\t\t\tAddress changed Successfully..." << endl;
		}
		break;
		case 2:
		{
			cout << "Choose Address to Edit its type : ";
			cin.ignore();
			while (true) {
				cin >> decs4;
				if (decs4 <= us1->getAddressesCount() && decs4 >= 0) {
					break;
				}
				else { cout << "!!!!Please Enter a Valid Number"; }
			}
			cout << "\nEnter the New Address type :";
			cin.ignore();
			getline(cin, str);

			us1->setAddressType(decs4 - 1, str);

			c1.assignUser(id, *us1);
			cout << "\t\t\t\tAddress Type changed Successfully..." << endl;
		}
		break;

		case 3:
		{
			cout << "Choose Address to Edit its Description: ";
			while (true) {
				cin >> decs4;
				if (decs4 <= us1->getAddressesCount() && decs4 >= 0) {
					break;
				}
				else { cout << "!!!!Please Enter a Valid Number"; }
			}
			cout << "\nEnter the New Description :";
			cin.ignore();
			getline(cin, str);

			us1->setAddressDscrptn(decs4 - 1, str);
			c1.assignUser(id, *us1);
			cout << "\t\t\tAddress Description changed Successfully..." << endl;
		}
		break;
		case 4:
			cout << endl
				<< "Please enter New Id : ";
			while (true)
			{
				cin.ignore();
				cin >> id;
				if (id < c1.countUsers())
					break;
				else {
					cout << "Please Enter a valid Id: ";
				}
			}
			cout << "\n\n";
			break;
		default:
			break;
		}

		delete us1;
	}
	system("cls");// clearing console screen


}


void editEmails(int id) {
	// Editing Mails screen

	cout << "\n\n\n"
		<< "All E-Mails : \n";
	cout << "E-Mail \t\t\t\t Type \t\t\t Description" << endl;

	// output Mails of the user and connected types and descriptions
	for (int i = 0; i < c1.getUser(id).getMailsCount(); i++)
	{
		cout << '{' << i + 1 << "} " << c1.getUser(id).getEmailsTyp(i).getEmail();
		(c1.getUser(id).getEmailsTyp(i).getEmail().length() > 15) ? cout << " \t\t" : cout << "\t\t\t\t";
		cout << c1.getUser(id).getEmailsTyp(i).getType() << " \t\t" << c1.getUser(id).getEmailsTyp(i).getDescription() << endl;
	}
	cout << "\n\n\n";

	cout << "\t\t\t\t Editing E-Mails Menu\n"
		<< "\t\t\t\t------------------------\n\n";
	int decs3 = -2;
	while (decs3 != 0) {

		cout << "<1> Change E-Mail \n"
			<< "<2> change E-Mail Type \n"
			<< "<3> change E-Mail Discribtion \n"
			<< "<4> Enter A new Id \n"
			<< "<0> Return To Edit Contact Menu\n\n" << endl;

		cout << "Choose a process to proceed:";
		cin >> decs3;
		cout << endl;
		User* us1 = new User;
		*us1 = c1.getUser(id);

		int decs4;
		string str;
		switch (decs3)
		{
		case 1:
		{
			cout << '\n';


			cout << "Choose E-Mail to Edit : ";
			while (true) {
				cin >> decs4;
				if (decs4 <= us1->getMailsCount() && decs4 >= 0) {
					break;
				}
				else { cout << "!!!!Please Enter a Valid Number"; }
			}
			cin.ignore();
			cout << "\nEnter the New E-Mail :";
			getline(cin, str);

			us1->setEmail(decs4 - 1, str);
			c1.assignUser(id, *us1);
			cout << "\t\t\t\tE-Mail changed Successfully..." << endl;
		}
		break;
		case 2:
		{
			cout << "Choose E-Mail to Edit its type : ";
			cin.ignore();
			while (true) {
				cin >> decs4;
				if (decs4 <= us1->getMailsCount() && decs4 >= 0) {
					break;
				}
				else { cout << "!!!!Please Enter a Valid Number"; }
			}
			cout << "\nEnter the New E-Mail type :";
			cin.ignore();
			getline(cin, str);

			us1->setEmailType(decs4 - 1, str);

			c1.assignUser(id, *us1);
			cout << "\t\t\t\tE-Mail Type changed Successfully..." << endl;
		}
		break;

		case 3:
		{
			cout << "Choose E-Mail to Edit its Description: ";
			while (true) {
				cin >> decs4;
				if (decs4 <= us1->getMailsCount() && decs4 >= 0) {
					break;
				}
				else { cout << "!!!!Please Enter a Valid Number"; }
			}
			cout << "\nEnter the New Description :";
			cin.ignore();
			getline(cin, str);

			us1->setEmailDscrptn(decs4 - 1, str);
			c1.assignUser(id, *us1);
			cout << "\t\t\tE-Mail Description changed Successfully..." << endl;
		}
		break;

		case 4:
			cout << endl
				<< "Please enter New Id : ";
			while (true)
			{
				cin.ignore();
				cin >> id;
				if (id < c1.countUsers())
					break;
				else {
					cout << "Please Enter a valid Id: ";
				}
			}
			cout << "\n\n";
			break;
		default:
			break;
		}

		delete us1;
	}
	system("cls");// clearing console screen

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu