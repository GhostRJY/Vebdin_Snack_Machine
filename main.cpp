#include<iostream>
#include<string>

#include"VendingMachine.h"
#include"Snack.h"
#include"snackSlot.h"

//#define DEBUG //ѕроверка на переполнение

int main() {

	Snack* bounty = new Snack("Bounty");
	Snack* snickers = new Snack("Snickers");
	
	snackSlot* slot = new snackSlot(10/*количество батончиков, которые помещаютс€ в слот*/);
	
	
	slot->addSnack(bounty); //ƒобавл€ем батончик в слот
	slot->addSnack(snickers);

#ifdef DEBUG	//небольшой тест на переполнение
	
	snackSlot* slotSnik = new snackSlot(snickers, 5);
	snackSlot* slotBou = new snackSlot(7);

	for (int i = slot->getPositionInSlot(); i < slot->getCount(); i++) {
		slot->addSnack(bounty); 
	}

	for (int i = slotSnik->getPositionInSlot(); i < slotSnik->getCount(); i++) {
		slotSnik->addSnack(snickers); //ƒобавл€ем батончик в слот
	}

	for (int i = slotBou->getPositionInSlot(); i < slotBou->getCount(); i++) {
		slotBou->addSnack(bounty); //ƒобавл€ем батончик в слот
	}
	
	
#endif	

	VendingMachine* machine = new VendingMachine(3 /* оличество слотов дл€ снеков*/);
	machine->addSlot(slot); // ѕомещаем слот обратно в аппарат

#ifdef DEBUG
	machine->addSlot(slotSnik);
	machine->addSlot(slotBou);
	machine->addSlot(slotBou);
#endif

	std::cout << "In machine "<<machine->getEmptySlotsCount()<<" empty slots"<< std::endl; // ƒолжно выводить количество пустых слотов дл€ снеков
	
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