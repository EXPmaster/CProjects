#include <stdio.h>
#include <stdlib.h>
#include "dice_roll.h"
#include <time.h>

int main() {
    int times,sides;
    int roll;
    int status;
    srand((unsigned int) time(0));
    printf("enter the number of sides, 0 to stop.\n");
    while(scanf("%d",&sides)==1 and sides>0)
    {
        printf("how many dice?\n");
        if ((status = scanf("%d",&times)) !=1)
        {
            if(status==EOF) break;
            else
            {
                printf("you should've entered an integer.");
                printf("start over\n");
                while(getchar() != '\n')
                    continue;
            }
        }
        roll=roll_n_dice(times,sides);
        printf("result=%d, total with use of %d times.\n",roll,times);
        printf("enter the number of sides, 0 to stop.\n");
    }
    printf("thank you.\n");
    return 0;
}