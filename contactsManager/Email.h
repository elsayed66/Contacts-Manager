#ifndef _EMAIL_H
#define _EMAIL_H
#include <string>
using namespace std;

class Email
{
private:
	string email;
	string type;
	string description;
public:
	Email();
	void setEmail(string );
	void setType(string );
	void setDescription(string );
	string getEmail();
	string getType();
	string getDescription();
};
#endif