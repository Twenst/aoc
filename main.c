#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fonct.h"
// gcc -Wall main.c aoc.c puzzleInput.c -o aoc -lm

//----Bench----//
void dayOne(){
    printf("Par comparaison avec le terme suivant: %i\n", increaseCompt(inputJ1, 2000));
    printf("Par comparaison de la somme de 3mes: %i\n", increaseComptThreeMes(inputJ1, 2000));
}

void dayTwo(){
    printf("Déplacement: %i\n", posMult(inputJ2, 1000));
    printf("Déplacement (avec aim): %i\n", posMultAim(inputJ2, 1000));
}

void dayThree(){
    printf("%li\n", binCompt(inputJ3, 1000, 12));
}

//----Main----//
int main(){
    dayThree();
    return EXIT_SUCCESS;
}
