Secuirty System
---------------

This security system is capable of supporting both “normally closed” and “normally open” devices, such as windows and doors.   It’s also able to support devices like smoke alarms and motion detectors, if they have open-drain capability on their output pins, and are normally open.

The Raspberry Pi is using an mcp23017 to read values supplied by the LM393 voltage comparator.  The light turns green when the value is in range and red when it is out of range.   

So for example, if I open this normally closed switch, the alarm is tripped, and closing it resets the alarm.
Then, if I close this normally open switch, again, the alarm is trpped, and closing it to reset it.
Now if I wave my hand in front of the motion detector, the alarm is tripped.  This motion sensor is equipped with a variable timeout and will reset after about 10 seconds.


## Video

<a href="https://youtu.be/W2xMPx8phms" target="_blank">![photo2](https://raw.githubusercontent.com/wryan67/SecuritySystem/main/readme/01f063e93a2838e34113a7dba107a2ded18657dd3e.jpg)</a>


## Photos

![photo1](https://raw.githubusercontent.com/wryan67/SecuritySystem/main/readme/0142ae436622752dbb6286ce74e409e4efab3f11c9.jpg)

![photo2](https://raw.githubusercontent.com/wryan67/SecuritySystem/main/readme/01f063e93a2838e34113a7dba107a2ded18657dd3e.jpg)

## Circuit Diagram

![circuit diagram](https://raw.githubusercontent.com/wryan67/SecuritySystem/main/readme/circuit%20diagram.png)
