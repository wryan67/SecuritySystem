sicurezza: main.cpp
	gcc -lpthread -lwiringPi -lwiringPiMCP23x17rpi -lNeoPixelRPi main.cpp -o sicurezza

clean:
	rm -f sicurezza

