#pragma once
#include "snackSlot.h"

class VendingMachine
{
public:
	VendingMachine() = default;
	VendingMachine(unsigned short);
	~VendingMachine();

	void addSlot(snackSlot*);
	unsigned short getEmptySlotsCount() const;

private:
	
	snackSlot *slot;
	unsigned short currentSlot;
	unsigned short slotNum;
};

