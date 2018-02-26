/*
Author: Ahmad Shahril
Date: 26/02/2018
Description: This library is made for using RC receiver with Arduino.
*/

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "RcChannel.h"

RcChannel::RcChannel(byte pin, short minVal, short midVal, short maxVal):
	pin(pin), minVal(minVal), midVal(midVal), maxVal(maxVal) {
		tolerance = 50;
}

void RcChannel::calibrate() {
}

short RcChannel::readRaw() {
	return pulseIn(pin, HIGH);
}

short RcChannel::readPercentage() {
	short reading = readRaw();

	if (reading < midVal - tolerance) {
		return map(reading, minVal, midVal - tolerance, -100, 0);
	}
	else if (reading > midVal + tolerance) {
		return map(reading, midVal + tolerance, maxVal, 0, 100);
	}
	else {
		return 0;
	}
}

void RcChannel::setTolerance(short toleranceVal){
	tolerance = toleranceVal;
}

void RcChannel::setMinVal(short val) {
	minVal = val;
}

void RcChannel::setMidVal(short val) {
	midVal = val;
}

void RcChannel::setMaxVal(short val) {
	maxVal = val;
}
