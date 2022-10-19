#pragma once
#include"Snack.h"

class snackSlot
{
public:
	snackSlot(); // по умолчанию создаем слот на 10 батончиков
	snackSlot(unsigned short hCount);
	snackSlot(Snack *, unsigned short hCount);
	snackSlot(const snackSlot&);
	~snackSlot();

	void addSnack(Snack *); 
	void setSnack(const Snack&);
	void setPositionInSlot(unsigned short);
	void setCount(unsigned short);

	Snack getSnack();
	unsigned short getPositionInSlot() const;
	unsigned short getCount() const;
	void displaySlot() const;
	bool isEmpty() const;
	

private:
	
	void popBack(const Snack&);

	Snack *snack;
	unsigned short positionInSlot;
	unsigned short count;
};

