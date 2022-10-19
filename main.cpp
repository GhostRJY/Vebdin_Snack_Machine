#include<iostream>
#include<string>

#include"VendingMachine.h"
#include"Snack.h"
#include"snackSlot.h"

//#define DEBUG //�������� �� ������������

int main() {

	Snack* bounty = new Snack("Bounty");
	Snack* snickers = new Snack("Snickers");
	
	snackSlot* slot = new snackSlot(10/*���������� ����������, ������� ���������� � ����*/);
	
	
	slot->addSnack(bounty); //��������� �������� � ����
	slot->addSnack(snickers);

#ifdef DEBUG	//��������� ���� �� ������������
	
	snackSlot* slotSnik = new snackSlot(snickers, 5);
	snackSlot* slotBou = new snackSlot(7);

	for (int i = slot->getPositionInSlot(); i < slot->getCount(); i++) {
		slot->addSnack(bounty); 
	}

	for (int i = slotSnik->getPositionInSlot(); i < slotSnik->getCount(); i++) {
		slotSnik->addSnack(snickers); //��������� �������� � ����
	}

	for (int i = slotBou->getPositionInSlot(); i < slotBou->getCount(); i++) {
		slotBou->addSnack(bounty); //��������� �������� � ����
	}
	
	
#endif	

	VendingMachine* machine = new VendingMachine(3 /*���������� ������ ��� ������*/);
	machine->addSlot(slot); // �������� ���� ������� � �������

#ifdef DEBUG
	machine->addSlot(slotSnik);
	machine->addSlot(slotBou);
	machine->addSlot(slotBou);
#endif

	std::cout << "In machine "<<machine->getEmptySlotsCount()<<" empty slots"<< std::endl; // ������ �������� ���������� ������ ������ ��� ������
	
	slot->displaySlot();
	
	delete machine;

#ifdef DEBUG
	delete slotBou;
	delete slotSnik;
#endif

	delete slot;
	delete snickers;
	delete bounty;

	return 0;
}