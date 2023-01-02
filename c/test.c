// #include <math.h>
// #include <stdio.h>
// #include <cs50.h>
// #include <string.h>
// #include <ctype.h>
// #include <stdbool.h>
// #define MAX_STRINGS 20
// #define MAX_STRING_LEN 200





// //Bubble Sort Function
// void Bubblesortcandy(string arrchoco[],int size){

//      // two elements were not swapped by the inner loop, then it should break out of the loop
//      int index,j,key;

//     for (index = 0; index < size - 1; index++)
//     {
//         // Last i elements are already in place
//         for (j = 0; j < size - index - 1; j++)
//         {

//              string temp = "";
//             if (strcmp(arrchoco[j], arrchoco[j+1]) > 0)
//             {
//                 temp = arrchoco[j];
//                 arrchoco[j] = arrchoco[j+1];
//                 arrchoco[j+1] = temp;
//                 //printf("here ");
//             }
//         }
//     }
// }

// // Insertion Sort Function
//  void Insertionsortcandy(string arrchoco[],int size){
//     string key;
//      int index,j;
//     for (index = 1; index < size; index++)
//     {
//         key = arrchoco[index];
//         j = index - 1;

//         //SWAPS ELEMENTS IF IT IS LESS ALPHANUMERICALLY
//         while (j >= 0 && strcmp(key, arrchoco[j]) < 0)
//         {
//              string temp = "";
//             if (strcmp(arrchoco[j], arrchoco[j+1]) > 0)
//             {
//                 temp = arrchoco[j];
//                 arrchoco[j] = arrchoco[j+1];
//                 arrchoco[j+1] = temp;
//             }
//             j = j - 1;
//         }
//     }
//  }

// // print Choco
// void PrintChoco(string arrchoco[],int size)
// {
//      int index;
//     for (index = 0; index < size; index++)
//     printf("%s\n",arrchoco[index]);
//        // printf("Sorted based on alphabetic order :%d ", );

// }

//  int main(void){
//         //string arrchoco[] = {"7","8","1","2","4","6","5","3"};
//         //string arrchoco[] = {"hi","hello","Vivek","vivek","here","He","is","goofy1"};
//         //string arrchoco[] = {"hi","hello","vivek1","vivek","here","he","is","goofy1"};
//         //string arrchoco[] = {"Hi","Hello","Vivek1","Vivek","Here","He","Is","Goofy1"};
//        string Ui =  get_string("What kinds of chocolate are you stocking up today name type and quantity:");
//        string Ui1 =  get_string("What kinds of chocolate are you stocking up today name type and quantity:");
//        string Ui2 =  get_string("What kinds of chocolate are you stocking up today name type and quantity:");
// //    int sum = 0, i, len;

// //         char Uilen = strlen(arrchoco);
// //     for (i = 0; i < Uilen; i++)
// //     {
// //         sum = sum + arrchoco[i];
// //         printf("%i", sum);

// //     }


//        string arrchoco[] = {Ui,Ui1,Ui2};
//      int size = sizeof(arrchoco)/ sizeof(arrchoco[0]);
//      //Insertionsortcandy(arrchoco, size);
//      Bubblesortcandy(arrchoco,size);
//      PrintChoco(arrchoco, size);

// }
// C program for implementation of selection sort
