#ifndef DRIVE_GAME_ADAPTER_H
#define DRIVE_GAME_ADAPTER_H

#include "stdbool.h"

extern "C" {

//Gear
unsigned char GearUp (void);
unsigned char GearDown (void);
unsigned char GetGear (void);
void GearType(bool bGear);

//Speed
unsigned short SpeedUp (void);
unsigned short SpeedDown (void);

}

#endif  //DRIVE_GAME_ADAPTER_H
