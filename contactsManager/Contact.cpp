#include "Contact.h"

Contact::Contact() 
{
	// default constructor which start program by reading old contacts 's data file 
	countContacts = 0;
	readData();

}


Contact::~Contact()
{
	// after exiting the program normally the constructor will call the function to write contacts data to the data.txt file to save contacts.
	writeData();
}

void Contact::search(string key)
{
	// function search for contacts name or primary phone number or ID
	PrntHdrClms();
	bool contFound = false;
	for (int i = 0; i < this->countContacts; i++) {

		if (usersVector[i].search(key)) {
			contFound = true;
			usersVector[i].showContact();
			cout << endl;
		}
	}
	if (!contFound) {
		cout << "\t\t!!!Contact Not found\n"
			<< "--------------------------" << endl;
	}

}
void Contact::getContact(int x)
{
	// function output the contact if a right id is taken 
	if (usersVector.size() < x) {
		cout << "This is a wrong Id!!!!!";
	}
	else {
		usersVector[x].showContact();
	}
}
void Contact::addContact(string fName, string lName, string gender, string phnNum, string addres, string email)
{
	// adding a new contact to the contacts vector using pointer as a holder for the data 
	countContacts++;
	userPoint = new User;

	userPoint->setPhone(0, phnNum);
	userPoint->setEmail(0, email);
	userPoint->setAddress(0, addres);
	userPoint->setFName(fName);
	userPoint->setLName(lName);
	userPoint->setGender(gender);

	usersVector.push_back(*userPoint);
	delete userPoint;
}


void Contact::listContacts()
{
	// function loop for listing all contacts for the user
	PrntHdrClms();
	for (int i = 0; i < usersVector.size(); i++) {
		usersVector[i].showContact();
		cout << endl;
	}
}
void Contact::deleteContact(int f)
{
	// function to delete a contact and change id to fit the empty space
	usersVector.erase(usersVector.begin() + f);
	countContacts--;
	for (int j = f; j < usersVector.size(); j++) {
		usersVector[j].decrementId();
	}
}
int Contact::countUsers()
{
	return countContacts;
}

void Contact::deletAllContacts(bool dec) {
	// this function delete all contacts by clearing users vector
	if (dec) {
		countContacts = 0;
		usersVector.clear();
		cout << "All Contacts Deleted Successfully....:(" << endl;
	}
}




void Contact::readData()
{
	/*
	 private function to read data from text file this data pattern is as 

	 firstName lastName Gender addedDate phones phonesType phonesDescription addresses addressesTypes addresses Description emails emailsTypes emailsDescription

	 before and after each string of them there is a sign to take it as beginning and ending signal for each name 
	 example:
	 =firstName==lastName= and so on
	*/
	string line;
	ifstream inData;

	inData.open("data.txt");

	if (!inData.is_open()) {cerr << "Error Opening Data file";}
	else {
		//counter referrring to the index of users and nuber of line being read
		int lineCount = 0;
		while (!inData.eof()) {
			// create an empty user type data to make as prototype and push it to vector
			userPoint = new User;

			usersVector.push_back(*userPoint);


			getline(inData, line);

			// intialization of boolean to control the flow of data into variables
			bool phnCntEmpt = true, adrssCntEmpt = true, emlCntEmpt = true,
				fNameEmpt = true, lNameEmpt = true, genderEmpt = true,addedDateEmpt = true,
				phoneEmpt = true, phoneTypEmpt = true, phonDscEmp = true,
				addrsEmpt = true, addrsTypEmpt = true, addrsDscEmpt = true,
				emailEmpt = true, emalTypEmpt = true, emlDscEmpt = true;

			int phnsIndx = 0, phnsTypeIndx = 0, phnsDscIndx = 0;
			int AddrsIndx = 0, AddrsTypeIndx = 0, AddrsDscIndx = 0;
			int emlsIndx = 0, emlsTypeIndx = 0, emlsDscIndx = 0;

			// Dividing Each string into substrings and putting them into user's variables
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == '=') {
					for (int j = i + 1; j < line.length(); j++)
					{
						if (line[j] == '=') {

							if (fNameEmpt) {
								usersVector[lineCount].setFName(line.substr(i + 1, j - i - 1));
								fNameEmpt = false;
							}
							else if (lNameEmpt) {
								usersVector[lineCount].setLName(line.substr(i + 1, j - i - 1));
								lNameEmpt = false;
							}
							else if (genderEmpt) {
								usersVector[lineCount].setGender(line.substr(i + 1, j - i - 1));
								genderEmpt = false;
							}
							else if (addedDateEmpt) {
								usersVector[lineCount].setAddedDate(line.substr(i + 1, j - i - 1));
								addedDateEmpt = false;
							}

							// iterate to input multi user phones and multi description of each phone
							else if (phoneEmpt) {//&& phnsIndx == phnsTypeIndx && phnsIndx == phnsDscIndx ) {
								if (phnsIndx == usersVector[lineCount].getPhonesCount() - 1)
									phoneEmpt = false;

								usersVector[lineCount].setPhone(phnsIndx, line.substr(i + 1, j - i - 1));

								

								phnsIndx++;
							}
							else if (phoneTypEmpt){//&& phnsIndx > phnsDscIndx) {
								if (phnsTypeIndx == usersVector[lineCount].getPhonesCount() - 1)
									phoneTypEmpt = false;

								usersVector[lineCount].setPhoneType(phnsTypeIndx, line.substr(i + 1, j - i - 1));

								

								phnsTypeIndx++;
							}

							else if (phonDscEmp) {

								if (phnsDscIndx == usersVector[lineCount].getPhonesCount() - 1)
									phonDscEmp = false;

								usersVector[lineCount].setPhoneDscrptn(phnsDscIndx, line.substr(i + 1, j - i - 1));


								phnsDscIndx++;
							}


							// iterate to input multi user Addresser and multi description of each Address
							else if (addrsEmpt) {
								if (AddrsIndx == usersVector[lineCount].getAddressesCount() - 1)
									addrsEmpt = false;

								usersVector[lineCount].setAddress(AddrsIndx, line.substr(i + 1, j - i - 1));

								AddrsIndx++;
							}
							else if (addrsTypEmpt) {
								if (AddrsTypeIndx == usersVector[lineCount].getAddressesCount() - 1)
									addrsTypEmpt = false;

								usersVector[lineCount].setAddressType(AddrsTypeIndx, line.substr(i + 1, j - i - 1));

								

								AddrsTypeIndx++;
							}
							else if (addrsDscEmpt) {
								if (AddrsDscIndx == usersVector[lineCount].getAddressesCount() - 1)
									addrsDscEmpt = false;

								usersVector[lineCount].setAddressDscrptn(AddrsDscIndx, line.substr(i + 1, j - i - 1));

								AddrsDscIndx++;
							}


							// iterate to input multi user Emails and multi description of each Email
							else if (emailEmpt) {
								if (emlsIndx == usersVector[lineCount].getMailsCount() - 1)
									emailEmpt = false;

								usersVector[lineCount].setEmail(emlsIndx, line.substr(i + 1, j - i - 1));

								
								emlsIndx++;
							}
							else if (emlsTypeIndx) {
								if (emlsTypeIndx == usersVector[lineCount].getMailsCount() - 1)
									emalTypEmpt = false;

								usersVector[lineCount].setEmailType(emlsIndx, line.substr(i + 1, j - i - 1));

								emlsTypeIndx++;
							}
							else if (emlDscEmpt) {
								if (emlsDscIndx == usersVector[lineCount].getMailsCount() - 1)
									emlDscEmpt = false;

								usersVector[lineCount].setEmailDscrptn(emlsDscIndx, line.substr(i + 1, j - i - 1));

								emlsDscIndx++;
							}

							// to skip this word after putting it into variable
							i = j;
							break;
						}
					}

				}
			}

			delete userPoint;
			countContacts++;
			++lineCount;
		}
		inData.close();
	}

}

void Contact::writeData()
{
	// this method write new data on the text file these data take place old Data
	ofstream outData;
	outData.open("data.txt");

	if (!outData.is_open()) {
		cerr << "Error opening Data File"<<endl;
	}
	else {
		// if the file opened correctly we can start output data inside it 

		for (int i = 0; i < usersVector.size(); i++)
		{
			userPoint = new User;
			*userPoint = getUser(i);
			//outData<<'='<<userPoint->getPhonesCount()<<'='<<'='<<userPoint->getAddressesCount()<<'='<<'='<<userPoint->getMailsCount()<<'='

			outData << '=' <<  userPoint->getFName() << '=' << '=' << userPoint->getLName() << '=' << '=' << userPoint->getGender() << '='<<'=' << userPoint->getAddedDate()<<'=';
			
			// output phones follwed by their description
			for (int j = 0; j < usersVector[i].getPhonesCount(); j++)
			{
				outData << '=' << userPoint->getPhonesTyp(j).getPhone() << '=';
			}
			for (int j = 0; j < usersVector[i].getPhonesCount(); j++)
			{
				outData << '=' << userPoint->getPhonesTyp(j).getType() << '=';
			}
			for (int j = 0; j < usersVector[i].getPhonesCount(); j++)
			{
				outData<< '=' << userPoint->getPhonesTyp(j).getDescription() << '=';
			}


			// output addresses follwed by their descriptions 
			for (int j = 0; j < usersVector[i].getAddressesCount(); j++)
			{
				outData << '=' << userPoint->getAddressesTyp(j).getPlace() << '=';
			}
			for (int j = 0; j < usersVector[i].getAddressesCount(); j++)
			{
				outData << '=' << userPoint->getAddressesTyp(j).getType() << '=';
			}
			for (int j = 0; j < usersVector[i].getAddressesCount(); j++)
			{
				outData << '=' << userPoint->getAddressesTyp(j).getDescription() <<'=';
			}


			// output Emails follwed by their descriptions 
			for (int j = 0; j < usersVector[i].getMailsCount(); j++)
			{
				outData << '=' << userPoint->getEmailsTyp(j).getEmail() << '=';
			}
			for (int j = 0; j < usersVector[i].getMailsCount(); j++)
			{
				outData << '=' << userPoint->getEmailsTyp(j).getType() << '=';
			}
			for (int j = 0; j < usersVector[i].getMailsCount(); j++)
			{
				outData << '=' << userPoint->getEmailsTyp(j).getDescription() << '=';			
			}

			// this allow next user to write on a new line and prevent cursor from moving to a new empty line 
			if(i != usersVector.size()-1)
			outData << endl;

			delete userPoint;
		}

		outData.close();

	}
}


