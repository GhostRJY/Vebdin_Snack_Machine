#pragma once
#include <string>

class Snack
{
public:
	
	Snack();
	Snack(std::string);
	Snack(std::string, unsigned short);
	Snack(const Snack&);
	

	Snack& operator= (const Snack&);

	std::string getSnackTM() const;
	unsigned short getSnackCal() const;
	void displaySnack() const;

	void setSnackTM(std::string);
	void setSnackCal(unsigned short cals);

private:
	std::string tm;
	unsigned short calories;
};

