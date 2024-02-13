#include "Email.h"

Email::Email()
{
	email = "No Email Associated";
	type = "Un-Known";
	description = "No Discription";
}

void Email::setEmail(string eml)
{
	email = eml;
}

void Email::setType(string typ)
{
	type = typ;
}

void Email::setDescription(string desc)
{
	description = desc;
}

string Email::getEmail()
{
	return email;
}

string Email::getType()
{
	return type;
}

string Email::getDescription()
{
	return description;
}

