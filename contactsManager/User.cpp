#include "User.h"
#include<iostream>
#include<ctime>

using namespace std;

unsigned int User::countId = 0;

void User::setDate()
{
	// this function get time as month day year
	int month, day, year;
	time_t tim;
	struct tm nowLocal;
	tim = time(NULL); // get os time
	nowLocal = *localtime(&tim);
	day = nowLocal.tm_mday;

	// year count since 1990
	year = 1900 + nowLocal.tm_year;
	month = nowLocal.tm_mon;
	switch (month)
	{
	case 0:
		addedDate = "Jan";
		break;
	case 1:
		addedDate = "Feb";
		break;
	case 2:
		addedDate = "Mar";
		break;
	case 3:
		addedDate = "Apr";
		break;
	case 4:
		addedDate = "May";
		break;
	case 5:
		addedDate = "Jun";
		break;
	case 6:
		addedDate = "Jul";
		break;
	case 7:
		addedDate = "Aug";
		break;
	case 8:
		addedDate = "Sep";
		break;
	case 9:
		addedDate = "Oct";
		break;
	case 10:
		addedDate = "Nov";
		break;
	case 11:
		addedDate = "Dec";
			
	default:
		break;
	}
	// concatinate month day and year to form the full date
	addedDate = addedDate + " " + to_string(day) +" " + to_string(year);
}

User::User():id(countId)
{
	// the constructor intialize variables of each user and increading id count 
	// in constructor each user can have multiple data such emails using pointer and vectors
	countId++;
	
	setDate();
	phonesCount = 3;
	emailsCount = 3;
	addressesCount = 3;
	
	for (int i = 0; i < phonesCount; i++)
	{
		phonesPointer = new Phone;
		phonesVector.push_back(*phonesPointer);
		delete phonesPointer;
	}
	for (int i = 0; i < emailsCount; i++)
	{
		emailPointer= new Email;
		emailsVector.push_back(*emailPointer);
		delete emailPointer;
	}
	for (int i = 0; i < addressesCount; i++)
	{
		addressPointer = new Address;
		addressesVector.push_back(*addressPointer);
		delete addressPointer;
	}
	
}


User::~User()
{

}
void User::showContact()
// funciton shows primary data of each contact
{
	/*
	  sayed  ahmed  male  01094123443  kafr-Saqr  el.20033116@gmail.com 
	  */
	
	cout << id << '\t' << firstName << "\t\t"<<lastName<< "\t\t"<<gender<<'\t';

	cout << phonesVector[0].getPhone()<< "\t\t" << addressesVector[0].getPlace() << '\t'<< emailsVector[0].getEmail() << "\t\t" << addedDate;
}

bool User::search(string key)
{
	// function to search on each user
	if (getFName().find(key) != string::npos || getLName().find(key) != string::npos || to_string(id) == key)
		return true;
	for (size_t i = 0; i < getPhonesCount(); i++)
	{
		if (getPhoneNumber(i).find(key) != string::npos || getPhoneNumber(i).find(key) != string::npos) {
			return true;
		}
	}
	return false;
}

int User::retCount()
{
	// return id count to be taken 
	return countId;
}