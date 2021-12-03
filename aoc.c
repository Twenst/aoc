#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "fonct.h"

//------Protoypes------//
//----Day One----//
int32_t increaseCompt(int32_t * tab, int32_t n);
int32_t increaseComptThreeMes(int32_t * tab, int32_t n);

//----Day Two----//
int32_t posMult(int32_t tab[][2], int32_t n);
int32_t posMultAim(int32_t tab[][2], int32_t n);

//----Day Three----//
long binCompt(long * bin, int32_t n, int32_t m);
int32_t binToInt(long l);

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

/* int32_t posMultAimStruct(subPos *tab, int32_t n){
    int32_t depth = 0; int32_t horizPos = 0; int32_t aim = 0;
    for (int32_t i = 0; i < n; i++){
        if (strcmp("forward",tab[i].dir)){
            horizPos += tab[i].val;
            depth += aim*tab[i].val;
        }
        else if (strcmp("up",tab[i].dir)){
            aim += -tab[i].val;
        }
        else{
            aim += tab[i].val;
        }
    }
    return depth*horizPos;
} */

//----Day Three----//
long binCompt(long * bin, int32_t n, int32_t m){//n nombre d'éléments dans le tableau, m longueur des binaires 
    long gammaRate = 0; long buffer = 0; long epsilonRate = 0;
    for (int k = m-1; k > -1; k--){
        buffer = 0;
        for (int i = 0; i < n; i++){
            buffer += (long) (bin[i]/(long)pow(10,k));
            bin[i] -= (long) (bin[i]/(long)pow(10,k) * (long)pow(10,k));
        }
        printf("%li, %li\n", buffer,(2*buffer/n) * (long)pow(10,k));
        gammaRate += (long)(2*buffer/n) * (long)pow(10,k);
        epsilonRate += (long) ((1-(buffer/(n/2)))) * (long)pow(10,k); 
    }
    return (binToInt(gammaRate) *binToInt(epsilonRate));
}

int32_t binToInt(long l){
    long res = 0; int32_t i = 0;
    while (l != 0){
        res += (long) ((l%10) * pow(2,i));
        l = (long) (l/10);
        i++;
    }
    return res;
}
