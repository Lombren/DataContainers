#pragma once
#include<iostream>
class Crime
{
	std::string place;
	std::string crime;//нарушение
public:
	const std::string& get_place()const;
	const std::string& get_crime()const;
	Crime(std::string place,std::string crime);
	~Crime();
};

