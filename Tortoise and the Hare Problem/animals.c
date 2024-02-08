//Import required libraries listed below
#include <stdio.h>
#include <stdlib.h>
#include "animals.h"

int current_position(int time, int tortoise, int hare) {
    return 0;
}

int update_hare(int current_position) {
    int movement; //initialize movement variable

    //Generate a random float between 0 and 1 as val
    float val = ((float) rand() / (float) (RAND_MAX)); 

    //Sleep, no movement
    if (0 <= val && val < 0.2) {
        
    } 
         //Big hop
    else if (0.2 <= val && val < 0.4) {
        movement = 9; 
        //Add 9 spaces forward
       current_position = current_position + movement;
    } 
    else if (0.4 <= val && val < 0.5) {
        //Big slip, negative integer due to the placement moving backward
        movement = -12; 
        //Subtract 12 spaces backward
        current_position = current_position + movement;
    } 
    else if (0.5 <= val && val < 0.8) {
        //Small hop
        movement = 1; 
        //Add 1 space forward
       current_position = current_position + movement;
    } 
    else if (0.8 <= val){
        //Small slip, negative integer due to the placement moving backward
        movement = -2; 
       //Subtract 2 spaces backward
       current_position = current_position + movement;
    }
    if (current_position < 0){
        current_position = 0;
    }
    return current_position; 
}

int update_tortoise(int current_position) {
    int movement; //initialize movement variable

    //Generate a random float between 1 and 0
   float val = ((float) rand() / (float) (RAND_MAX));
    if (0 <= val && val < 0.5) {
        //Fast plod
        movement = 3; 
        //Add 3 spaces forward
        current_position = current_position + movement; 
    } 
    else if (0.5 <= val && val < 0.7) {
        //Slip
        movement = -6; 
        //Subtract 6 spaces backwards
        current_position = current_position + movement; 
    } 
    else if (0.7 <= val) {
        //Slow plod
        movement = 1; 
        //Add 1 space forward
        current_position = current_position + movement; 
    }
    if (current_position < 0){
        current_position = 0;
    }
    return current_position;
}