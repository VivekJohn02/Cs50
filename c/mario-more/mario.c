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
    int height;
    do{
        height = get_int ("Enter height of pyrmiad:\n");
    } while(height<1||height>8);



    switch (height) {
        case 1:
        printf("# #\n");
        break;

        case 2:
        printf(" # #\n## ##\n");
        break;

        case 3:
        printf("  # #\n ## ##\n### ###\n");
        break;

        case 4:
        printf("   # #\n  ## ##\n ### ###\n#### ####\n");
        break;

        case 5:
        printf("    # #\n   ## ##\n  ### ###\n #### ####\n##### #####\n");
        break;

        case 6:
        printf("     # #\n    ## ##\n   ### ###\n  #### ####\n ##### #####\n###### ######\n");
        break;

        case 7:
        printf("      # #\n     ## ##\n    ### ###\n   #### ####\n  ##### #####\n ###### ######\n####### #######\n");
        break;

        case 8:
        printf("       # #\n      ## ##\n     ### ###\n    #### ####\n   ##### #####\n  ###### ######\n ####### #######\n######## ########\n");
        break;












    }










}