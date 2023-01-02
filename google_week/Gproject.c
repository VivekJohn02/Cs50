/*
Vivek John
AP CS50
Cmdr. Schenk
20 SEPT 9
Gproject
*/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// #include <conio.h>
// #include <iostream.h>
// #include "question.c"


int rand(void);
int main(int argc, string argv[]){
// basketball trivia game
//questions

string questions[] = {"1. Who invented Basketball?",


//Answer:  James Naismith.
 "2. When did he invent Basketball?",


//Answer: 1891.
 "3. Each Basketball team consists of how many players?",


//Answer:  Five.
"4. What is the full form of NBA?",


//Answer:  National Basketball Association.
"5. What is the diameter of a Basketball?",

// Answer:  24 cm.
"6. What was the color of the Basketball before it changed to Orange?",

// Answer:  Brown.
"7. When did Basketball become the official sport of the Olympics?",


// Answer:  1936.
"8. Who is the tallest Basketball player in NBA?",


// Answer:  Sun Mingming.
"9. Who was known as the first referee in NBA?",


// Answer:  Ken Mauer.
"10. The basketball court is made up of with which wood?",


// Answer:  Maple Planks.
"11. Who was the youngest NBA player in Basketball history?",


// Answer:  Andrew Bynum.
"12. Who is the richest Basketball Player in NBA History?",


// Answer:  Michael Jordan.
"13. What is the name of the Basketball team of New York?",


// Answer:  New York Knicks.
"14. What is the size of kids Basketball?",


// Answer:  Size 5.
"15. At what age did Kobe Bryant enter the NBA?",


// Answer:  Age of 17.
"16. What is the size of the Basketball court?",

// Answer:  94 x 50 Feet.
"17. What is the middle name of Michael Jordan?",


// Answer:  Jeffrey.
"18. What was the height of the Worlds shortest basketball player '“'Muggsy Bogues'”'?",

// Answer:  5 foot 3 inches.
"19. Which team has most of the NBA championships?",


// Answer:  Boston Celtics.
"20. The first NBA championship was owned by which team?",


// Answer:  Los Angeles Lakers.
"21. Which team has won most of the NBA titles?",

// Answer: Los Angeles Lakers.
"22. When did the first Basketball game take place?",

// Answer:  1882.

"23. On March 2, 1962, 100 points were scored by which NBA player?",

// Answer:  Wilt Chamberlain.
"24. What was the name of another basketball association which was joined to the NBA in 1949?",


// Answer:  BAA (Basketball Association of America).
"25. When did Muggsy Bogues and Manute Bol were played in the same team?",

// Answer:  1987-88.
"26. The creator of the Basketball (James Naismith) hated which team?",


// Answer:  Chicago Bulls.
"27. How many seasons have been played by Kareem Abdul Jabar?",

// Answer:  20.

"28. What is the total point of the all-time leading scorer of Kareem Abdul Jabar?",

// Answer:  38,387 Points.

"29. Which player has the most carrier rebounds?",

// Answer:  Wilt Chamberlain.

"30. The first three-point basket was scored by whom?"

// Answer:  Chris Ford.
};


// questions for trivia with image with randomizer to pick question from database
// printf("%c",questions[1]);
int i, j, k, n;
int arr_count [10] = {31, 31, 31, 31, 31, 31, 31, 31, 31, 31};
int point = 0;
//printf ("%c",questions[1]);
  for(i=0;i<10;i++)
  {
      n = rand()%10;
      //printf("%d",n);
      j = 0;
      while (j != n)
      {
         for (k=0; k<10; k++)
         {
            if (arr_count[k] == n)
            {
               j = j + 1;
            }
         }
         if (j < 1)
         {
            string display;
            display = get_string("%s\n",questions[n]);
            //printf("%s\n",display);
            //let user input answer and then proceed to switch case with answers
            string answer = display;
            //scanf("%s",answer);
            //printf ("%s",answer);
               //scanf("%s", &answer);
               //printf("%s\n",  ("answer: " + display));
               //printf ("%d", n);
               switch (n+1)
               {
                  //case "1. Who invented Basketball?" :
                  case '1' :
                     if (strcmp (answer, "James Naismith") == 0)
                     {
                        printf ("correct");
                        point = point + 1;
                     }
                     else{
                        printf("wrong");
                        }
                     break;
                  //case "2. When did he invent Basketball?":
                  case 2 :
                     if (strcmp (answer,"1891") == 0)
                     {
                        printf ("correct");
                        point = point + 1;
                     }
                     else{
                        printf("wrong");
                        }
                     break;
                  //case "3. Each Basketball team consists of how many players?":
                  case 3 :
                     if (strcmp (answer, "five") == 0)
                     {
                        printf ("correct");
                        point = point + 1;
                     }
                     else{
                        printf("wrong");
                        }
                     break;
                  //case "4. What is the full form of NBA?":
                  case 4 :
                  if (strcmp (answer, "National Basketball Association ") == 0)
                     {
                        printf ("correct");
                        point = point + 1;
                     }
                     else{
                        printf("wrong");
                        }
                  break;
                  //case "5. What is the diameter of a Basketball?":
                  case 5 :
                  if (strcmp (answer, "24cm") == 0)
                     {
                        printf ("correct");
                        point = point + 1;
                     }
                     else{
                        printf("wrong");
                        }
                  break;
                  //case "6. What was the color of the Basketball before it changed to Orange?":
                  case 6 :
                  if (strcmp (answer, "Brown") == 0)
                     {
                        printf ("correct");
                        point = point + 1;
                     }
                     else{
                        printf("wrong");
                        }
                  break;
                  //case "7. When did Basketball become the official sport of the Olympics?":
                  case 7 :
                  if (strcmp (answer, "1936") == 0)
                     {
                        printf ("correct");
                        point = point + 1;
                     }
                     else{
                        printf("wrong");
                        }
                  break;
                  //case "8. Who is the tallest Basketball player in NBA?":
                  case 8 :
                  if (strcmp(answer, "Sun Mingming  ") == 0)
                     {
                        printf ("correct");
                        point = point + 1;
                     }
                     else{
                        printf("wrong");
                        }
                  break;
                  //case "9. Who was known as the first referee in NBA?":
                  case 9:
                  if (strcmp(answer, "Ken Mauer") == 0)
                     {
                        printf ("correct");
                        point = point + 1;
                     }
                     else{
                        printf("wrong");
                        }
                  break;
                  //case "10. The basketball court is made up of with which wood?":
                  case 10 :
                  if (strcmp(answer, "Maple Planks") == 0)
                     {
                        printf ("correct");
                        point = point + 1;
                     }
                     else{
                        printf("wrong");
                        }
                  break;
                  //case "11. Who was the youngest NBA player in Basketball history?":
                  case 11 :
                  if (strcmp(answer, "Andrew Bynum") == 0)
                     {
                        printf ("correct");
                        point = point + 1;
                     }
                     else{
                        printf("wrong");
                        }
                  break;
                  //case "12. Who is the richest Basketball Player in NBA History?":
                  case 12 :
                  if (strcmp(answer,"Michael Jordan") == 0)
                     {
                        printf ("correct");
                        point = point + 1;
                     }
                     else{
                        printf("wrong");
                        }
                  break;
                  //case "13. What is the name of the Basketball team of New York?":
                  case 13 :
                  if (strcmp(answer,"New York Knicks ") == 0)
                     {
                        printf ("correct");
                        point = point + 1;
                     }
                     else{
                        printf("wrong");
                        }
                  break;
                  //case "14. What is the size of kids Basketball?":
                  case 14:
                  if (strcmp(answer, "Size 5") == 0)
                     {
                        printf ("correct");
                        point = point + 1;
                     }
                     else{
                        printf("wrong");
                        }
                  break;
                  //case "15.At what age did Kobe Bryant enter the NBA?":
                  case 15 :
                  if (strcmp(answer, "Age of 17") == 0)
                     {
                        printf ("correct");
                        point = point + 1;
                     }
                     else{
                        printf("wrong");
                        }
                  break;

               }


         }
         else
         {
            break;
         }
            j = j + 1;
            printf ("\n");
      }
      arr_count[i] = n;
  }


//score measure

//print final points
printf ("Total Points: %d \n", point);
if (point > 3)
{
   printf("You are too good.\n");
}
else
{
   printf("You can try again to see if you can score higher.\n");
}



}