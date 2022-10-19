#include<iostream>

#include "Snack.h"

Snack::Snack() {
	tm = "empty";
	calories = 0;
}

Snack::Snack(std::string sTM) {
	tm = sTM;
	calories = 100;
}

Snack::Snack(std::string sTM, unsigned short cal) {
	if (cal < 65535 && cal >= 0) {
		tm = sTM;
		calories = cal;
	}
	else{
		tm = sTM;
		calories = 100;
	}
}

Snack::Snack(const Snack& other) {

	this->tm = other.tm;
	this->calories = other.calories;
}

Snack& Snack::operator= (const Snack& right) {

	tm = right.tm;
	calories = right.calories;
	return *this;
}

std::string Snack::getSnackTM() const {
	
	return tm;
}

unsigned short Snack::getSnackCal() const {

	return calories;
}

void Snack::setSnackTM(std::string sTM) {

	tm = sTM;
}

void Snack::setSnackCal(unsigned short cals) {

	calories = cals;
}

void Snack::displaySnack() const {

	std::cout << "Snack: " << tm << " have " << calories << " calories" << std::endl;
}