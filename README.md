# Introduction
This library uses the built-in pulseIn function. The main purpose of this library is just for simplifying your codes when using RC receiver.
It does not provide any performance boost.

# How to Use It
Please take a look at the examples provided.

# Functions
## Constructors
```cpp
RcChannel(byte pin, short minVal = 1100, short midVal = 1500, short maxVal = 1900);

//You may initialize your code like the following if you want to use the default min, mid and max values:
RcChannel rc(4);

//If you want to supply your own set of values:
RcChannel rc(4, 1000, 1500, 2000);
```

## Calibrations
When doing calibration, you should move the sticks in both directions for each channel.
```cpp
//For when you have multiple channels to calibrate
RcChannel rc[] = {4, 5};

while(millis() < 5000) {
	rc[0].calibrate();
	rc[1].calibrate();
}

//For single channel
RcChannel rc(4);

rc.calibrate(5000); //This will calibrate this channel for 5 seconds. Note that this function is blocking.
```

## Readings
You have 2 options for reading the value of the channel; **RAW** or **PERCENTAGE**.
```cpp
//For reading raw data:
ch.readRaw();

//For reading percentage:
ch.readPercentage(); //This value returns value between -100 to 100. 0 being the middle value.
```

## Setters and Getters
### Tolerance
The tolerance allows the library to treat values within *-tolerance* and *+tolerance* as 0. This is to avoid value noise when the stick remain at the center. By default, the tolerance is set to **50**.
```cpp
//Setter
ch.setTolerance(100);

//Getter
ch.getTolerance();
```

### Min, Mid and Max Values
Min, Mid and Max values refers to the duration that the signal goes HIGH. Usually, for PPM signal, the value is around 1000 to 2000 microseconds. Some controllers may defer. That is the purpose of these functions.
```cpp
//Setter
ch.setMinVal(950);
ch.setMidVal(1550);
ch.setMaxVal(2000);

//Getter
ch.getMinVal();
ch.getMidVal();
ch.getMaxVal();
```
