#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef FONCT_H
    #define FONCT_H
        extern void dayOne();
        extern int32_t inputJ1[2000];
        extern int32_t increaseCompt(int32_t tab[], int32_t n);
        extern int32_t increaseComptThreeMes(int32_t tab[], int32_t n);

        extern void dayTwo();
        extern int32_t inputJ2[1000][2];
        extern int32_t posMult(int32_t tab[][2], int32_t n);
        extern int32_t posMultAim(int32_t tab[][2], int32_t n);

#endif