#include <cs50.h>
#include <stdio.h>



int main(void)
{
    int count = 0;
    long uI = 0;
do{
    uI = get_long("Insert your credit Number:");


    }while( uI <  0 || uI > (long)1111111111111111);

    return uI;

    long check = uI;


    int uI1,uI2,uI3,uI4,uI5,uI6,uI7,uI8;
    uI1 = ((( uI1 % 100)/10)*2);
    uI2 = ((( uI1 % 10000)/1000)*2);
    uI3 = ((( uI1 % 1000000)/100000)*2);
    uI4 = ((( uI1 % 100000000)/10000000)*2);
    uI5 = ((( uI1 % 10000000000 )/1000000000)*2);
    uI6 = ((( uI1 % 1000000000000)/10000000000000)*2);
    uI7 = ((( uI1 % 100000000000000)/10000000000000)*2);
    uI8 = ((( uI1 % 10000000000000000)/1000000000000000)*2);



    uI1 = (uI1 % 100/10) + (uI1 % 10);
    uI2 = (uI2 % 100/10) + (uI2 % 10);
    uI3 = (uI3 % 100/10) + (uI3 % 10);
    uI4 = (uI4 % 100/10) + (uI4 % 10);
    uI5 = (uI5 % 100/10) + (uI5 % 10);
    uI6 = (uI6 % 100/10) + (uI6 % 10);
    uI7 = (uI7 % 100/10) + (uI7 % 10);
    uI8 = (uI8 % 100/10) + (uI8 % 10);

    int huns1 = uI1+uI2+uI3+uI4+uI5+uI6+uI7+uI8;

    int huns2notxed = (uI % 10) + ((uI % 1000)/100) + ((uI % 100000)/10000) + ((uI % 10000000)/1000000) +
    ((uI % 1000000000)/100000000) + ((uI % 100000000000)/10000000000) + ((uI % 10000000000000)/1000000000000) +
    ((uI % 1000000000000000)/100000000000000);

    int checksum = huns1+huns2notxed;

    if ((checksum % 10) != 0)
    {
        printf("Card num is invalid, please try again\n");
        return 0;
    }
    while (check > 0)
    {
        check = check / 10;
        count++;
    }
    if (count != 15 && count != 13 && count != 16)
    {
        printf("INVALID\n");
        return 1;
    }
    long MC = uI / 100000000000000;
    long AMEX = uI / 10000000000000;
    long Visa = uI  / 1000000000000000;
    if (count == 15)
    {
        if (AMEX != 34 && AMEX != 37)
        {
            printf("INVALID\n");
            return 1;
        }
        else
        {
            printf("AMEX\n");
            return 0;
        }
    }
 if (count == 13 && Visa == 4)
    {
        printf("VISA\n");
        return 0;
    }
    else if (count != 13 && Visa != 4)
    {
        printf("Invalid\n");
        return 1;
    }
    if (count == 16)
    {
        if (MC == 51 || MC == 52 || MC == 53 || MC == 54 || MC == 55)
        {
            printf("Mastercard\n");
            return 0;
        }
        else if (Visa == 4)
        {
            printf("VISA\n");
            return 0;
        }
        else if (MC != 51 && MC != 52 && MC != 53 && MC != 54 && MC != 55 && Visa == 4)
        {
            printf("INVALID\n");
            return 1;
        }
    }



}








