default: cliser

cliser:
	gcc -o client.out client_sender.c cryptage.c morse.c clean.c
	gcc -o server.out server.c cryptage.c morse.c
	gcc -o led.out    led_handler.c morse.c handleLED.c

clean: rm *.o 
