#include "CarFactory.hpp"

CarFactory* CarFactory::carFactoryInstance_ = nullptr;

CarFactory::CarFactory() {
    CurrentGear_ = 0u;
    CurrentSpeed_ = 0u;
	GearType_ = false;
	carInstance = nullptr;
}

CarFactory* CarFactory::GetInstance () {
    if(nullptr == carFactoryInstance_){
        carFactoryInstance_ = new CarFactory();
    }

    return carFactoryInstance_;
}

void CarFactory::setGearType(uint8_t GearType) {
	GearType_ = GearType;
}

void CarFactory::setGear(uint8_t CurrentGear) {
	CurrentGear_ = CurrentGear;
}

void CarFactory::setSpeed(uint16_t CurrentSpeed) {
	CurrentSpeed_ = CurrentSpeed;
}

uint8_t CarFactory::getGear(void) const {
	return CurrentGear_;
}

uint16_t CarFactory::getSpeed(void) const {
	return CurrentSpeed_;
}

CarBase *CarFactory::GetCar(void) {
	if (GearType_) {
		carInstance = new CarAutomatic(CurrentGear_, CurrentSpeed_);
	} else {
		carInstance = new CarBase(CurrentGear_, CurrentSpeed_);
	}

	return carInstance;
}

void CarFactory::DeleteCar(void){
	delete carInstance;
	carInstance = nullptr;
}
