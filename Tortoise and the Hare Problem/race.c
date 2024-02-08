//Import required libraries listed below
#include <stdio.h>
#include <stdlib.h>
#include "animals.h"

//Define constant finish_line with a value of 70.
#define finish_line 70

//Define variables
int tortoise = 0; 
int hare = 0; 
int winner = -1; // -1 means no winner yet
int seed; //Initalize seed variable
int time; //Initialize time variable
int movement; //Initialize movement variable

int main() {
    
    //Prompt user to enter a random number seed
    printf("Please enter a random number seed. \n");
    //Read seed entered and store
    scanf("%d", &seed);
    //Seed the random number gnereate with the provided seed
    srand(seed);

    int current_winner = 0;

    //Enter a while loop that continues until either the tortoise or hare crosses the finish line
    while (tortoise < finish_line && hare < finish_line) {
        hare = update_hare(hare);
        //Increment the time variable (listed in header file)
        //Call update_tortoise function to update the tortoise's position
        tortoise = update_tortoise(tortoise);
        //Call update_hare to update the hare's position
        time ++;
        //Call current_position function to print the current race status

            //Check if the tortoise has reached the finish line when the hare hasn't
            if (tortoise >= finish_line && hare <= finish_line) {
                printf("After %d seconds, the tortoise wins!!\n", time);
                //Declare winner as 0 for the tortoise
                winner = 0;
                    } 
            else if (tortoise < finish_line && hare >= finish_line) {
                //Check if the hare has reached the finish line when the tortoise hasn't
                printf("After %d seconds, the hare wins!!\n", time);
                //Declare winner as 1 for the hare
                winner = 1;
            }
             if (tortoise < hare && current_winner == 0) {
                    //If tortoise is less than hare, print "the hare (square (blank)) has passed the tortoise (square (blank)). "
                printf("At t = %d, the hare (square %d) has passed the tortoise (square %d).\n", time, hare, tortoise);
             } 
                else if (hare < tortoise && current_winner == 1){
                    //If tortoise is less than hare, print "the tortoise (square (blank)) has passed the hare (square (blank)). "
                printf("At t = %d, the tortoise (square %d) has passed the hare (square %d).\n", time, tortoise, hare);
             }
                if (tortoise > hare){
                    current_winner = 0;
             }
                else if (hare > tortoise){
                     current_winner = 1;
             }
           }
        }
