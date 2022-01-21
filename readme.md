Secuirty System
---------------

This security system is capable of supporting both “normally closed” and “normally open” devices, such as windows and doors.   It’s also able to support devices like smoke alarms and motion detectors, if they have open-drain capability on their output pins, and are normally open.

The Raspberry Pi is using an mcp23017 IC to read values supplied by the op-amps, which are setup in a window comparator type of circuit which then detmines if the voltage on the loop is in the specified range.  The light turns green when the value is in range and red when it is out of range.   


## Video

[YouTube Video Link](https://youtu.be/nNICbq8Yqfo)


## Photos

![photo1](https://raw.githubusercontent.com/wryan67/SecuritySystem/main/readme/014d91dbfe1941673540a70bb3e272a761816563d7.jpg)

![photo2](https://raw.githubusercontent.com/wryan67/SecuritySystem/main/readme/01bd47415adceec766baa4893ea106bea062a279ce.jpg)

## Circuit Diagram

![circuit diagram](https://raw.githubusercontent.com/wryan67/SecuritySystem/main/readme/circuit%20diagram.png)
