#ifndef CAR_BASE_H
#define CAR_BASE_H

#include "cstdint"

#define DEFAULT_ACCELARATION_STEPS     5u

typedef enum {
    Gear__NEUTRAL = 0,	
    Gear__1ST,
    Gear__2ND,
    Gear__3RD,
    Gear__4TH,
    Gear__5TH,
    Gear__6TH,
    Gear__COUNT,
}Gear_t;

typedef struct {
    uint16_t MinSpeed_;
    uint16_t MaxSpeed_;
}SpeedLimitPerGear_t;

extern const SpeedLimitPerGear_t speedLimitGear[];

class CarBase {
public:
    CarBase (uint8_t CurrentGear, uint16_t CurrentSpeed);
	virtual ~CarBase() {}
	
	virtual uint8_t GearUp (void);
	virtual uint8_t GearDown (void);
	virtual uint16_t SpeedUp (void);
	virtual uint16_t SpeedDown (void);
	
	uint8_t GetGear (void) const;
	
	void SetAccelarationStep(uint8_t AccelarationSteps);
	uint8_t GetAccelarationStep(void) const;
protected:
    uint8_t CurrentGear_;
    uint16_t CurrentSpeed_;
    uint8_t AccelarationSteps_;
};

#endif  //CAR_BASE_H
