#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "fonct.h"

//------Protoypes------//
//----Day One----//
int32_t increaseCompt(int32_t * tab, int32_t n);
int32_t increaseComptThreeMes(int32_t * tab, int32_t n);

//----Day Two----//
int32_t posMult(int32_t tab[][2], int32_t n);
int32_t posMultAim(int32_t tab[][2], int32_t n);


//------Fonctions------//
//----Day One----//
int32_t increaseCompt(int32_t * tab, int32_t n){
    int32_t compt = 0;
    for (int32_t i = 0; i < n; i++){
        if (tab[i] < tab[i+1]) compt ++;
    }
    return compt;
}

int32_t increaseComptThreeMes(int32_t * tab, int32_t n){
    int32_t compt = 0;
    for (int32_t i = 0; i < n-3; i++){
        if (tab[i] < tab[i+3]) compt++;
    }
    return compt;
}

//----Day Two----//
int32_t posMult(int32_t tab[][2], int32_t n){
    int32_t depth = 0; int32_t horizPos = 0;
    for (int32_t i = 0; i < n; i++){
        if (tab[i][0] == -1) horizPos += tab[i][1];
        else if (tab[i][0] == -2) depth += -tab[i][1];
        else depth += tab[i][1];
    }
    return depth*horizPos;
}

int32_t posMultAim(int32_t tab[][2], int32_t n){
//-1 = forward
//-2 = up
//-3 = down
    int32_t depth = 0; int32_t horizPos = 0; int32_t aim = 0;
    for (int32_t i = 0; i < n; i++){
        if (tab[i][0] == -1){
            horizPos += tab[i][1];
            depth += aim*tab[i][1];
        }
        else if (tab[i][0] == -2){
            aim += -tab[i][1];
        }
        else{
            aim += tab[i][1];
        }
    }
    return depth*horizPos;
}