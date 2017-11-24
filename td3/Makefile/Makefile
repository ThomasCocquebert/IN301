run: principal
	./principal

principal:	circonference.o surface.o principal.o
	gcc *.o -o principal

circonference.o:	circonference.c pi.h
	gcc -c circonference.c
	
surface.o:	surface.c pi.h
	gcc -c surface.c
	
principal.o: principal.c circonference.h surface.h
	gcc -c principal.c

clean:
	rm *.o
	rm principal