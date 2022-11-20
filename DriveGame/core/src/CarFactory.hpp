#ifndef CAR_FACTORY_H
#define CAR_FACTORY_H

#include "cstdint"
#include "stdbool.h"
#include "CarBase.hpp"
#include "CarAutomatic.hpp"

class CarFactory {
private:
    CarFactory();

public:
    static CarFactory* carFactoryInstance_;
    static CarFactory* GetInstance ();

	CarBase* GetCar(void);
	void DeleteCar(void);
	void setGearType(uint8_t GearType);
	void setGear(uint8_t CurrentGear);
	void setSpeed(uint16_t CurrentSpeed);

	uint8_t getGear(void) const;
	uint16_t getSpeed(void) const;

private:
    CarBase *carInstance;
	mutable uint8_t CurrentGear_;
    uint16_t CurrentSpeed_;

	bool GearType_;
};

#endif  //CAR_FACTORY_H
