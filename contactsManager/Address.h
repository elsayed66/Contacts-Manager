#ifndef _ADDRESS_H
#define _ADRESS_H
#include <string>
using namespace std;

class Address{
private:
	string place;
	string type;
	string description;
public:
	Address();
	void setPlace(string);
	void setType(string);
	void setDescription(string);
	string getPlace(){	return place;}
	string getType() { return type; }
	string getDescription() { return description; }
};

#endif