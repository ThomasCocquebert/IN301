#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uvsqgraphics.h"
#include "Structure.h"
#include "fct_jeu.h"
#include "graphisme_jeu.h"
#include "lecture_ecriture.h"
#include "editeur.h"

int main(int argc, char *argv[])
{
	init_graphics(700, 700);
	slider(argc, argv);
	wait_escape();
	exit(0);
}
