#include <iostream>

#include "snackSlot.h"

snackSlot::snackSlot() {

	positionInSlot = 0;
	count = 10;
	snack = new Snack[count];
}

snackSlot::snackSlot(unsigned short hCount) {
	
	positionInSlot = 0;
	count = hCount;
	snack = new Snack[count];
}

snackSlot::snackSlot(Snack* sSnack, unsigned short hCount) {

	positionInSlot = 0;
	count = hCount;
	snack = new Snack[count];
	snack[positionInSlot] = *sSnack;
	++positionInSlot;
}

snackSlot::snackSlot(const snackSlot& other) {
	
	delete[] snack;
	count = other.count;
	snack = new Snack[count];
	
	for (int i = 0; i < count; i++) {
		snack[i] = other.snack[i];
	}
		
}


snackSlot::~snackSlot() {

	delete[] snack;
}

void snackSlot::setSnack(const Snack& sSnack) {
	*snack = sSnack;
	
}

void snackSlot::setPositionInSlot(unsigned short pos) {

	positionInSlot = pos;
}

void snackSlot::setCount(unsigned short sCount) {

	count = sCount;
}

void snackSlot::addSnack(Snack * sSnack) {
	popBack(*sSnack);

} //сеттер

void snackSlot::popBack(const Snack& sSnack) {
	if (positionInSlot < count)
	{
		snack[positionInSlot] = sSnack;
		positionInSlot++;
	}
	else {
		std::cout << "Slot is full" << std::endl;
	}
}

unsigned short snackSlot::getPositionInSlot() const {
	
	return positionInSlot;
}

Snack snackSlot::getSnack() {
	
	return *snack;
}

unsigned short snackSlot::getCount() const {
	
	return count;
}

void snackSlot::displaySlot() const {
	if (this->isEmpty()) {
		std::cout << "Slot is empty" << std::endl;
	}
	else {
		std::cout << "Slot have: "<<positionInSlot<<" bars. And "<<count-positionInSlot<<" free cells" << std::endl;
	}
}

bool snackSlot::isEmpty() const{
	return positionInSlot == 0 ? true : false;
}