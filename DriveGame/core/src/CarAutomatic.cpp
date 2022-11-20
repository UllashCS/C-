#include "CarAutomatic.hpp"
#include <iostream>

CarAutomatic::CarAutomatic(uint8_t CurrentGear = 0, uint16_t CurrentSpeed = 0)
           : CarBase(CurrentGear, CurrentSpeed) {
    std::cout << "Automatic Car Created with Gear : " << CurrentGear_ << ", Speed : " << CurrentSpeed_ << std::endl;
}

uint8_t CarAutomatic::GearUp (void) {
	return CurrentGear_;
}

uint8_t CarAutomatic::GearDown (void) {
	return CurrentGear_;
}

uint16_t CarAutomatic::SpeedUp (void) {
	CurrentSpeed_ += AccelarationSteps_;
	
	if (CurrentSpeed_ > 240u) {
		CurrentSpeed_ = 240u;
	}
	
	if (CurrentSpeed_ > speedLimitGear[CurrentGear_].MaxSpeed_) {
		CurrentGear_++;
	}

	return CurrentSpeed_;
}

uint16_t CarAutomatic::SpeedDown (void) {
	CurrentSpeed_ -= AccelarationSteps_;

    if (CurrentSpeed_ > 240u) {
		CurrentSpeed_ = 0;
	}

	if (CurrentSpeed_ < speedLimitGear[CurrentGear_].MinSpeed_) {
		CurrentGear_--;
	}

	return CurrentSpeed_;
}

