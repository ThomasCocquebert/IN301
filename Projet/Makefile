Structure.o:	Structure.c
	gcc -c Structure.c -Wall -g

fct_jeu.o:	fct_jeu.c Structure.h
	gcc -c fct_jeu.c -Wall -g

graphisme_jeu.o:	graphisme_jeu.c Structure.h fct_jeu.h
	gcc -c `sdl-config --cflags` -Wall -g graphisme_jeu.c
	
lecture_ecriture.o:	lecture_ecriture.c Structure.h fct_jeu.h graphisme_jeu.h editeur.h
	gcc -c `sdl-config --cflags` -Wall -g lecture_ecriture.c

editeur.o: editeur.c graphisme_jeu.h Structure.h fct_jeu.h
	gcc -c `sdl-config --cflags` -Wall -g editeur.c

main.o:	main.c Structure.h fct_jeu.h graphisme_jeu.h lecture_ecriture.h editeur.h
	gcc -c `sdl-config --cflags` -Wall -g main.c
	
slider:	Structure.o fct_jeu.o graphisme_jeu.o lecture_ecriture.o editeur.o main.o
	gcc *.o -o slider -g -Wall -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

run_slider:	slider
	./slider niv_1.slider

run_slider_mem:	slider
	valgrind ./slider niv_1.slider

run_slider_directory:	slider
	./slider dir_slider
clean:
	rm *.o