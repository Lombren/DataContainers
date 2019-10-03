#include "Crime.h"


const std::string & Crime::get_place() const
{
	return this->place;
}

const std::string & Crime::get_crime() const
{
	return this->crime;
}

Crime::Crime(std::string place, std::string crime)
{
	this->place = place;
	this->crime = crime;
}

Crime::~Crime()
{
}
