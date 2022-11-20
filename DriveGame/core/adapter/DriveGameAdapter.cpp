#include <iostream>
#include "DriveGameAdapter.hpp"
#include "../src/CarFactory.hpp"
#include "../src/CarBase.hpp"

extern "C" {

//Gear
unsigned char GearUp (void) {
	unsigned char ucGear = CarFactory::GetInstance()->getGear();
	CarBase *car = CarFactory::GetInstance()->GetCar();
	
	if (nullptr != car) {
	    ucGear = car->GearUp();
	    CarFactory::GetInstance()->setGear(ucGear);
	    CarFactory::GetInstance()->DeleteCar();
	}

	return ucGear;
}

unsigned char GearDown (void) {
	
	unsigned char ucGear = CarFactory::GetInstance()->getGear();
	CarBase *car = CarFactory::GetInstance()->GetCar();
	
	if (nullptr != car) {
	    ucGear = car->GearDown();
	    CarFactory::GetInstance()->setGear(ucGear);
	    CarFactory::GetInstance()->DeleteCar();
	}

	return ucGear;
}

unsigned char GetGear (void) {
	return CarFactory::GetInstance()->getGear();
}

void GearType(bool bGear) {
    std::cout << "Gear Type : " << bGear << std::endl;
	CarFactory::GetInstance()->setGearType(bGear);
}

//Speed
unsigned short SpeedUp (void) {
	
	unsigned short usSpeed = CarFactory::GetInstance()->getSpeed();
	CarBase *car = CarFactory::GetInstance()->GetCar();
	
	if (nullptr != car) {
	    usSpeed = car->SpeedUp();
	    CarFactory::GetInstance()->setSpeed(usSpeed);
	    CarFactory::GetInstance()->setGear(car->GetGear());
	    CarFactory::GetInstance()->DeleteCar();
	}

	return usSpeed;
}

unsigned short SpeedDown (void) {
	
	unsigned short usSpeed = CarFactory::GetInstance()->getSpeed();
	CarBase *car = CarFactory::GetInstance()->GetCar();

	if (nullptr != car) {
	    usSpeed = car->SpeedDown();
	    CarFactory::GetInstance()->setSpeed(usSpeed);
	    CarFactory::GetInstance()->setGear(car->GetGear());
	    CarFactory::GetInstance()->DeleteCar();
	}

	return usSpeed;
}

}
