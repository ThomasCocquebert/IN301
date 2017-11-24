#include "liste.h"
#include "simul.h"
#define LARGEUR    800
#define HAUTEUR    800
#define COUL_FOND  noir





// ##########
// 4. Le main
// ##########

int main(){

  init_graphics(LARGEUR,HAUTEUR);
  affiche_auto_off();
  fill_screen(COUL_FOND);
  affiche_all();

  simulChaine();



  wait_escape();
  return 0;
}
