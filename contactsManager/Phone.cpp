#include "Phone.h"

Phone::Phone()
{
	phone = "No Phone Number Associated";
	type = "Un-Known";
	description = "No Discription";

}

void Phone::setPhone(string phon)
{
	phone = phon;
}

void Phone::setType(string typ)
{
	type = typ;
}

void Phone::setDescription(string desc)
{
	description = desc;
}

string Phone::getPhone()
{
	return phone;
}

string Phone::getType()
{
	return type;
}

string Phone::getDescription()
{
	return description;
}
