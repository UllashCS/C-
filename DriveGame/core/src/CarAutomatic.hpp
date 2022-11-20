#ifndef CAR_AUTOMATIC_H
#define CAR_AUTOMATIC_H

#include "CarBase.hpp"
#include "cstdint"

class CarAutomatic : public CarBase {
public:
    CarAutomatic (uint8_t CurrentGear, uint16_t CurrentSpeed);
	virtual ~CarAutomatic() {}
	
	virtual uint8_t GearUp (void);
	virtual uint8_t GearDown (void);
	virtual uint16_t SpeedUp (void);
	virtual uint16_t SpeedDown (void);
};

#endif  //CAR_AUTOMATIC_H
