/*
Vivek John

Cs50 ap
Cmdr. schenk
24 AUG 22
Mario
*/



#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //declare height, hastag, space, and row variable
    int h,_,pound,r;
    //prompts for user input for height of pyramid while height is between 1-8
    do{
        h = get_int ("Enter height of pyrmiad:\n");
    } while(h<1||h>8);

// sets row variable to 0 and if row is less then height thnad 1 to row each time it is less than height.
    for(r=0;r<h;r++){
        for(_=0;_<h-r-1;_++){//sets space to zero the says when space is less thn height - row - 1 add 1 to space variable and print space
            printf(" ");}

        for(pound=0;pound<=r;pound++){// when pound is zero and pound is less than or equal to row add one to pound variableand print a hashtag.
            printf("#");
        }

        printf("  ");//put space between first hashtag and the later set of hashtags mad belo

        for(pound=0;pound<=r;pound++){//reapetes top to make 2 sets/
            printf("#");


        }
            printf("\n");

        }
















    }// end of main










