#ifndef _USER_H
#define _USER_H

#include "Address.h"
#include "Phone.h"
#include "Email.h"

#include<vector>

#include <string>
using namespace std;

class User
{
	static unsigned int countId;
	unsigned int id;
	string firstName;
	string lastName;
	string gender;
	string addedDate;

	int phonesCount;
	int addressesCount;
	int emailsCount;
	
	vector<Address> addressesVector;
	vector<Email> emailsVector;
	vector<Phone> phonesVector;

	Address* addressPointer;
	Phone* phonesPointer;
	Email* emailPointer;

	void setDate();

public:
	User();
	~User();
	int retCount();

	void showContact();
	void decrementId() { id--; }
	
	string getAddedDate() { return addedDate; }
	void setAddedDate(string date) { addedDate = date; }
	
	bool search(string);

	void setFName(string fN) { firstName = fN; }
	void setLName(string lN) { lastName = lN; }
	void setGender(string g) {gender=g;}

	void setPhone(int indx, string phn){ phonesVector[indx].setPhone(phn);}
	void setPhoneType(int indx, string phn){ phonesVector[indx].setType(phn);}
	void setPhoneDscrptn(int indx, string phn){ phonesVector[indx].setDescription(phn);}

	void setEmail(int indx, string email) { emailsVector[indx].setEmail(email);}
	void setEmailType(int indx, string email) { emailsVector[indx].setType(email);}
	void setEmailDscrptn(int indx, string email) { emailsVector[indx].setDescription(email);}

	void setAddress(int indx, string address){ addressesVector[indx].setPlace(address);}
	void setAddressType(int indx, string address){ addressesVector[indx].setType(address);}
	void setAddressDscrptn(int indx, string address){ addressesVector[indx].setDescription(address);}


	string getFName() { return firstName; }
	string getLName() { return lastName; }
	string getGender() { return gender; }
	string getPhoneNumber(int indx) {return phonesVector[indx].getPhone();}
	string getPhoneNumberDscrptn(int indx) {return phonesVector[indx].getDescription();}

	string getEmail(int indx) {return emailsVector[indx].getEmail();}
	string getEmailDscrptn(int indx) {return emailsVector[indx].getDescription();}

	string getAddress(int indx) {return  addressesVector[indx].getPlace();}
	string getAddressDscrptn(int indx) {return addressesVector[indx].getDescription();}

	int getMailsCount() { return emailsCount; }
	int getPhonesCount() { return phonesCount; }
	int getAddressesCount() { return addressesCount; }


	Phone getPhonesTyp(int indx) { return phonesVector[indx]; }
	Address getAddressesTyp(int indx) { return addressesVector[indx]; }
	Email getEmailsTyp(int indx) { return emailsVector[indx]; }




	
};
#endif