#include <stdio.h>
#include <stdlib.h>
#include "circonference.h"
#include "surface.h"

int main(){
	int rayon=5;
	printf("%f \n",circonference(rayon));
	printf("%f \n",surface(rayon));
}