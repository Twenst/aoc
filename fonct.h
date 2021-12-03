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
        typedef struct{
            char dir;
            int32_t val;
        }subPos;
        extern int32_t inputJ2[1000][2];
        //extern subPos inputJ2str[1000];
        extern int32_t posMult(int32_t tab[][2], int32_t n);
        extern int32_t posMultAim(int32_t tab[][2], int32_t n);
        int32_t posMultAimStruct(subPos * tab, int32_t n);

        extern void dayThree();
        extern long inputJ3[1000];
        extern long binCompt(long * bin, int32_t n, int32_t m);
        extern int32_t binToInt(long l);

#endif
