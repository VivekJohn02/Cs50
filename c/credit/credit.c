#include <cs50.h>
#include <stdio.h>


// main
int main(void)
{
    //declare variables to used
    int count = 0;
    long uI = 0;
    int x =0;

    do{
        uI = get_long("Insert your credit Number:");//propts user input while digts are from 0 to highest sixteen digit possible
        break;
    }while( uI <  0 || uI > (long)9999999999999999);

    long num = uI;// varable to hold number from user input

    while(uI!=0)//while uI not zero
    {
        uI=uI/10;//divide uIs held value by 10
        count++;// add to cout
    }

    int arrcc[count];//arraay credit card usin coun
    int i=0, numberlength = count;// numlenght is equal to count variables held value
    uI=num;

    while(num > 0) //do till num greater than  0
    {
        int mod = num % 10;  //split last digit from number
        //printf("%d\n",mod); //print the digit.
        arrcc[i] = mod;     //assigning digits to array
        i++;                //incrementing array index counter
        num = num / 10;    //divide num by 10. num /= 10 also a valid one
    }

    int firstsum = 0, secondsum=0;// declre sum variables
    i = 0;

    while(count > i) //do addition for algorithm
    {
        if (arrcc[i+1]*2 % 10 != 0)
        {
            firstsum = firstsum + ((arrcc[i+1]*2)%10) ;  //first addition
            firstsum = firstsum + ((arrcc[i+1])/10);  //first addition
        }
        else
        {
            firstsum = firstsum + arrcc[i+1]*2 ;  //first addition
        }
        //printf("%d\n",arrcc[i+1]);
        secondsum = secondsum + arrcc[i] ;  //second addition
        //count = count - 2;                //decrementing array index counter
        i = i + 2;
    }
    int totalsummod = ((firstsum) + secondsum) % 10;
//printf("%d",firstsum * 2);
    //credit card validity check
    if (totalsummod == 0)
    {
        //check type of card

        switch(numberlength) {// switch case determines what card type it is based on first digt of card num.
            case 13 :
                if(arrcc[12] == 4)
                {
                    printf("VISA\n" );

                }
                else{
                    printf("INVALID");
                }
                break;
            case 15 :
                if(arrcc[14] == 3 && (arrcc[13] == 4 || arrcc[13] == 7))
                {
                    printf("AMEX\n" );

                }
                else{
                    printf("INVALID");
                }
                break;
            case 16 :
                if(arrcc[15] == 5 && (arrcc[14] == 1 || arrcc[14] == 2 || arrcc[14] == 3 || arrcc[14] == 4 || arrcc[14] == 5))
                {
                    printf("MASTERCARD\n" );

                }
                else if (arrcc[15] == 4) {
                    printf("VISA\n" );

                }
                else{
                    printf("INVALID");
                }
                break;
            default :

                if((numberlength != 13)&&(numberlength != 15)&&(numberlength != 16)){
                    printf("INVALID\n" );
                }

        }
    }
    else
    {
       printf("INVALID\n");
    }
}
    //long check = uI;

    //return uI;
