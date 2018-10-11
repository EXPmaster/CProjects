//
// Created by Leo on 2018/10/11.
//

#ifndef DICE_DICE_ROLL_H
#define DICE_DICE_ROLL_H

#endif //DICE_DICE_ROLL_H

#include <stdio.h>
#include <stdlib.h>
int roll_count=0;
int rool_n_dice(int times,int sides);
int rolldice(int sides);

int rolldice(int sides)
{
    int roll;
    roll=rand()%sides+1;
    ++roll_count;
    return roll;
}

int roll_n_dice(int times,int sides)
{
    int total=0;
    if(sides<2)
    {
        printf("need at least 2 sides\n");
        return -2;
    }
    if(times<1)
    {
        printf("need at least 1 time\n");
        return -1;
    }

    for (int i=0;i<times;i++) total += rolldice(sides);
    return total;
}

