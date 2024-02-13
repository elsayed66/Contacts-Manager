#ifndef _PHONE_H
#define _PHONE_H
#include <string>
using namespace std;

class Phone
{
private:
	string phone;
	string type;
	string description;
public:
	Phone();
	void setPhone(string);
	void setType(string);
	void setDescription(string);
	string getPhone();
	string getType();
	string getDescription();
	
};
#endif
