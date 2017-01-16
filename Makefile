default: cliser

cliser: client.c server.c cryptage.c
	gcc -o sender client_sender.c cryptage.c
	gcc -o server server.c cryptage.c
	gcc -o led led_handler.c

clean: rm *.o 
