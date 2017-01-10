default: cliser

cliser: client.c server.c
	gcc -o c client.c
	gcc -o s server.c

clean: rm *.o 
