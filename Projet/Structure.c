struct elem{
	int longeur;
	int largeur;
	int sens;
	struct elem* suiv;
};
typedef struct elem* LISTE;

struct position{
	int x;
	int y;
};
typedef struct position POS;

struct pile{
	int coup;
	struct pile* prec;
};
typedef struct pile* PILE;

struct slider{
	int longeur;
	int largeur;
	POS joueur;
	LISTE murs;
	PILE coups;
};
typedef struct slider SLIDER;