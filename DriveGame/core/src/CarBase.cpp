#include "CarBase.hpp"
#include <iostream>

const SpeedLimitPerGear_t speedLimitGear[Gear__COUNT] = {
	{0u, 0u},      //Gear__NEUTRAL
	{0u, 50u},     //Gear__1ST
	{30u, 90u},    //Gear__2ND
	{70u, 130u},   //Gear__3RD
	{110u, 170u},  //Gear__4TH
	{150u, 210u},  //Gear__5TH
	{190u, 240u},  //Gear__6TH
};

CarBase::CarBase(uint8_t CurrentGear = 0, uint16_t CurrentSpeed = 0)
           : CurrentGear_ (CurrentGear),
             CurrentSpeed_ (CurrentSpeed),
             AccelarationSteps_ (DEFAULT_ACCELARATION_STEPS) {
    std::cout << "Car Created with Gear : " << CurrentGear_ << ", Speed : " << CurrentSpeed_ << std::endl;
}

uint8_t CarBase::GearUp (void) {

	if (CurrentGear_+1 == Gear__COUNT) {
		//Don't do anything
	} else if ((CurrentSpeed_ >= speedLimitGear[CurrentGear_+1].MinSpeed_)) {
		CurrentGear_++;
	}

	return CurrentGear_;
}

uint8_t CarBase::GearDown (void) {
	    std::cout << "Gear : " << CurrentGear_ << std::endl;
	if (CurrentGear_ == 0u) {
		//Don't do anything
	} else if ((CurrentSpeed_ <= speedLimitGear[CurrentGear_-1].MaxSpeed_)) {
		CurrentGear_--;
	}

	return CurrentGear_;
}

uint16_t CarBase::SpeedUp (void) {
	CurrentSpeed_ += AccelarationSteps_;
	
	if (CurrentSpeed_ > speedLimitGear[CurrentGear_].MaxSpeed_) {
		CurrentSpeed_ = speedLimitGear[CurrentGear_].MaxSpeed_;
	}

	return CurrentSpeed_;
}

uint16_t CarBase::SpeedDown (void) {
	CurrentSpeed_ -= AccelarationSteps_;

	if (CurrentSpeed_ < speedLimitGear[CurrentGear_].MinSpeed_) {
		CurrentSpeed_ = speedLimitGear[CurrentGear_].MinSpeed_;
	} else if (CurrentSpeed_ > 240u) {
		CurrentSpeed_ = 0;
	}

	return CurrentSpeed_;
}

void CarBase::SetAccelarationStep(uint8_t AccelarationSteps) {
	AccelarationSteps_ = AccelarationSteps;
}

uint8_t CarBase::GetAccelarationStep(void) const  {
	return AccelarationSteps_;
}

uint8_t CarBase::GetGear (void) const {
	return CurrentGear_;
}
