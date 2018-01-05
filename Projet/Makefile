Structure.o:	Structure.c
	gcc -c Structure.c -Wall

fct_jeu.o:	fct_jeu.c Structure.h
	gcc -c fct_jeu.c -Wall

graphisme_jeu.o:	graphisme_jeu.c Structure.h fct_jeu.h
	gcc -c `sdl-config --cflags` -Wall graphisme_jeu.c
	
main.o:	main.c Structure.h fct_jeu.h graphisme_jeu.h
	gcc -c `sdl-config --cflags` -Wall main.c
	
test:	Structure.o fct_jeu.o graphisme_jeu.o main.o
	gcc *.o -o test -Wall -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

run_test:	test
	./test

clean:	*.o
	rm *.o