Secuirty System
---------------

This security system is capable of supporting both “normally closed” and “normally open” devices, such as windows and doors.   It’s also able to support devices like smoke alarms and motion detectors, if they have open-drain capability on their output pins, and are normally open.

The Raspberry Pi is using an mcp23017 to read values supplied by the LM393 voltage comparator.  The light turns green when the value is in range and red when it is out of range.   

So for example, if I open this normally closed switch, the alarm is tripped, and closing it resets the alarm.
Then, if I close this normally open switch, again, the alarm is trpped, and closing it to reset it.
Now if I wave my hand in front of the motion detector, the alarm is tripped.  This motion sensor is equipped with a variable timeout and will reset after about 10 seconds.


## Video

[YouTube Video Link](https://youtu.be/nNICbq8Yqfo)


## Photos

![photo1](https://raw.githubusercontent.com/wryan67/SecuritySystem/main/readme/014d91dbfe1941673540a70bb3e272a761816563d7.jpg)

![photo2](https://raw.githubusercontent.com/wryan67/SecuritySystem/main/readme/01bd47415adceec766baa4893ea106bea062a279ce.jpg)

## Circuit Diagram

![circuit diagram](https://raw.githubusercontent.com/wryan67/SecuritySystem/main/readme/circuit%20diagram.png)
