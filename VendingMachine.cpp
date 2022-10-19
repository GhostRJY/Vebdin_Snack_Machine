#include <iostream>
#include "VendingMachine.h"

VendingMachine::VendingMachine(unsigned short count) {
	currentSlot = 0;
	slotNum = count;
	slot = new snackSlot[slotNum];
}

VendingMachine::~VendingMachine() {
	delete[] slot;
}

void VendingMachine::addSlot(snackSlot* sSlot) {
	
	if (currentSlot < slotNum) {
		slot[currentSlot].setSnack(sSlot->getSnack());
		slot[currentSlot].setCount(sSlot->getCount());
		slot[currentSlot].setPositionInSlot(sSlot->getPositionInSlot());
		currentSlot++;
	}
	else {
		std::cout << "Machine is full of containers" << std::endl;
	}
}

unsigned short VendingMachine::getEmptySlotsCount() const {
	
	unsigned short count = 0;
	
	for (int i = 0; i < slotNum; i++) {
		if (slot[i].isEmpty()) {
			count++;
		}
	}

	return count;
}