struct elem{
	int L;
	int H;
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
	int L;
	int H;
	POS joueur;
	POS sortie;
	int nombre_murs;
	LISTE murs;
	PILE coups;
};
typedef struct slider SLIDER;