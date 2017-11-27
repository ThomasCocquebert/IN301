struct mur{ int longeur; int largeur; int sens};
typedef struct mur MUR;

struct position{int x; int y};
typedef struct position POS;

struct pile{int coup; struct pile* prec};
typedef struct pile* PILE;

struct slider{ int longeur; int largeur; POS joueur; POS sortie; int nombre_murs; MUR T[nombre_murs]; PILE coups};
typedef struct slider SLIDER;