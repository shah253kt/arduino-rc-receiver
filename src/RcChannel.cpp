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
		pinMode(pin, INPUT);
		tolerance = 50;
}

void RcChannel::calibrate() {
	short reading = readRaw();

	if(reading < minVal) {
		minVal = reading;
	}

	if(reading > maxVal) {
		maxVal = reading;
	}

	midVal = ((maxVal - minVal) / 2) + minVal;
}

void RcChannel::calibrate(unsigned long duration) {
	unsigned long calibrateStart = millis();

	while (millis() - calibrateStart < duration) {
		calibrate();
	}
}

short RcChannel::readRaw() {
	return pulseIn(pin, HIGH);
}

short RcChannel::readPercentage() {
	short reading = constrain(readRaw(), minVal, maxVal);
	
	if(reading <= midVal + tolerance && reading >= midVal - tolerance) {
		return 0;
	}
	else {
		return map(reading, minVal, maxVal, -100, 100);
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

short RcChannel::getToleranceVal() {
	return tolerance;
}

short RcChannel::getMinVal() {
	return minVal;
}

short RcChannel::getMidVal() {
	return midVal;
}

short RcChannel::getMaxVal() {
	return maxVal;
}
