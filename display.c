#include <stdio.h>
#include <unistd.h>
#include "sense.h"
#include <stdbool.h>
#include "display.h"

#define GREEN 0x7E0
#define BLACK 0x0000
#define BLUE 0x1F
#define RED 0xF800
#define WHITE 0xFFFF

void display_colons(pi_framebuffer_t *fb, sense_fb_bitmap_t *bm) {

        //top left square
        bm->pixel[5][1]=WHITE;
        bm->pixel[5][2]=WHITE;
        bm->pixel[4][1]=WHITE;
        bm->pixel[4][2]=WHITE;


        //top right square
        bm->pixel[2][1]=WHITE;
        bm->pixel[2][2]=WHITE;
        bm->pixel[1][1]=WHITE;
        bm->pixel[1][2]=WHITE;


        //bottom left square
        bm->pixel[5][4]=WHITE;
        bm->pixel[5][5]=WHITE;
        bm->pixel[4][4]=WHITE;
        bm->pixel[4][5]=WHITE;

        //bottom right square
        bm->pixel[2][4]=WHITE;
        bm->pixel[2][5]=WHITE;
        bm->pixel[1][4]=WHITE;
        bm->pixel[1][5]=WHITE;

}

void assign_pixel(pi_framebuffer_t *fb, sense_fb_bitmap_t *bm, int time_amount, int x, int COLOR) { 
    if (time_amount == 32) {
                bm->pixel[x][2]=COLOR;
            }
            else if (time_amount == 16) {
                bm->pixel[x][3]=COLOR;
            }

            else if (time_amount == 8) {
                bm->pixel[x][4]=COLOR;
            }

            else if (time_amount == 4) {
                bm->pixel[x][5]=COLOR;
            }

            else if (time_amount == 2) {
                bm->pixel[x][6]=COLOR;
            }

            else if (time_amount == 1) {
                bm->pixel[x][7]=COLOR;
            }
}



void display_minutes(pi_framebuffer_t *fb, sense_fb_bitmap_t *bm, int mins) {

    int arr[] = {32, 16, 8, 4, 2, 1};

    bool looping = true;

    int i = 0;
    while(looping) {
        //Stop the loop when the amount of time has nothing left to divide.
        if (mins == 0) {
            looping = false;
            break;
        }

        if (arr[i] <= mins) { //If arr[i] fits into the amount of time, subtract arr[i] from hours
            assign_pixel(fb, bm, arr[i], 3, GREEN); //Make blue pixels on column 6
            mins = mins - arr[i];
        } //Loop should restart at this point unless hours has hit 0.
     i++;
    }

}


void display_seconds(pi_framebuffer_t *fb, sense_fb_bitmap_t *bm, int secs) {

    int arr[7] = {32, 16, 8, 4, 2, 1};

    bool looping = true;

    int i = 0;
    while(looping) {
        //Stop the loop when the amount of time has nothing left to divide.
        if (secs == 0) {
            looping = false;
            break;
        }

        if (arr[i] <= secs) { //If arr[i] fits into the amount of time, subtract arr[i] from hours
            assign_pixel(fb, bm, arr[i], 0, RED); //Make blue pixels on column 6
            secs = secs - arr[i];
        } //Loop should restart at this point unless hours has hit 0.
     i++;
    }
}



void display_hours(pi_framebuffer_t *fb, sense_fb_bitmap_t *bm, int secs) {

    int arr[] = {32, 16, 8, 4, 2, 1};

    bool looping = true;

    int i = 0;
    while(looping) {
        //Stop the loop when the amount of time has nothing left to divide.
        if (secs == 0) {
            looping = false;
            break;
        }

        if (arr[i] <= secs) { //If arr[i] fits into the amount of time, subtract arr[i] from hours
            assign_pixel(fb, bm, arr[i], 6, BLUE); //Make blue pixels on column 6
            secs = secs - arr[i];
        } //Loop should restart at this point unless hours has hit 0.
     i++;
    }
}


void display_time(pi_framebuffer_t *fb, sense_fb_bitmap_t *bm, int hours, int minutes, int seconds) {
    display_colons(fb, bm);

    display_hours(fb, bm, hours);

    display_minutes(fb, bm, minutes);

    display_seconds(fb, bm, seconds);
}

int convert_input(char inputTime[]){
    int time;

             for (int i = 0; i < 2; i++) {

              if (i == 0) {
                  time = (inputTime[i] - '0')  * 10;
              }
              else {
                  time += (inputTime[i] - '0');
              }

         } //End of loop

     return time;
}

int open_display(void) {
    pi_framebuffer_t *fb=getFrameBuffer();
    sense_fb_bitmap_t *bm=fb->bitmap;

    bool looping = true;

    while (looping) {

    char inputHours[3];
    char inputMinutes[3];
    char inputSeconds[3];

    char input[9];

    scanf("%8s", input);
    sscanf(input, "%2s:%2s:%2s",inputHours, inputMinutes, inputSeconds);

    clearFrameBuffer(fb,BLACK);

/*
    if (userInput < 3) {
≈
       looping = false;
       break;
     }

*/

    int hours = 0;
    int minutes = 0;
    int seconds = 0;


    //Change strings to integers
    hours = convert_input(inputHours);
    minutes = convert_input(inputMinutes);
    seconds = convert_input(inputSeconds);
    display_time(fb,bm, hours, minutes, seconds);


    }//END OF WHILE LOOP

    sleep(1);
    freeFrameBuffer(fb);
    return 0;
}


