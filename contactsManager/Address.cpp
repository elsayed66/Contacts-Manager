#include "Address.h"

Address::Address()
{
	place = "No Address Associated";
	type = "Un-Known";
	description = "No Discription";
}
void Address::setPlace(string adrs)
{
	place = adrs;
}

void Address::setType(string typ)
{
	type = typ;
}

void Address::setDescription(string desc)
{
	description = desc;
}

