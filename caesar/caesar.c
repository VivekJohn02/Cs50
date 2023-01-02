#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int main(int argc, string argv[])
{
// step 1 - Make sure program was run with just one command-line argument

//make sure that two things are typed in ./caeser and whatever digit
if(argc !=2)
{
 printf("Usage: ./caesar key \n");
return 1;}

//step-2 make sure that the second part of the key array is greater than 0 and a positive number only

string key;
key = (argv[1]);






    //step-3 Make sure every character in argv[1] is a digit
{


    for(int i=0;i<strlen(key);i++){
        if(!isdigit(key[i])){
            printf("Usage: ./caesar key \n");

            return 1;
        }

}










    // Convert argv[1] from a string to an int
int k;
k = atoi(argv[1]);



    // Prompt user for plaintext
string plain_text = get_string("Plain text:");
  //step-3 preserve case of each character in the plain text: and print cipher text
    printf("cyphertext:");
    //finds length of string plain text and scrutinizes every char
     for(int i=0;i<strlen(plain_text);i++){
        // checks if it is an alphabet
        if(isalpha(plain_text[i])){
            //If plain_text  is capital letter than i which is each charcter
            // put here to be converted to cipher text capital letter by
             //the formula below it also rotaes back to the beggening of the alphabet if it goes above Z

            if(( plain_text[i]>='A'&&plain_text[i]<='Z')){
                printf("%c",((((plain_text[i] - 'A') + k) % 26) + 'A'));

        }

        //If plain_text  is smalleletter than i which is each charcter
            // put here to be converted to cipher text small letters by
            //the formula below it also rotaes back to the begening of the alphabet if it goes above z
        if(( plain_text[i]>='a'&&plain_text[i]<='z')){
                printf("%c",((((plain_text[i] - 'a') + k) % 26) + 'a'));

        }


        }
    else{
// if i of plain_text is not  and alphabet than it remains as is
        printf("%c",plain_text[i]);
    }


















}

printf("\n");
}


}

