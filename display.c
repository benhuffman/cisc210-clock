#include <stdio.h>
#include <unistd.h>
#include "sense.h"
#include <stdbool.h>

#define GREEN 0x7E0
#define BLACK 0x0000
#define BLUE 0x1F




void assign_pixel(sense_fb_bitmap_t *bm, int time_amount, int x, int COLOR) { 
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

void display_hours(sense_fb_bitmap_t *bm, int hours) {

    int arr[] = {32, 16, 8, 4, 2, 1};

    bool looping = true;

    int i = 0;
    while(looping) {
        //Stop the loop when the amount of time has nothing left to divide.
        if (hours == 0) {
            looping = false;
            break;
        }
        printf("arr[i]=%d", arr[i]);
        if (arr[i] <= hours) { //If arr[i] fits into the amount of time, subtract arr[i] from hours
            assign_pixel(bm, arr[i], 6, BLUE); //Make blue pixels on column 6
            hours = hours - arr[i];
        } //Loop should restart at this point unless hours has hit 0.
     i++;
    }

}



int main(void) {
    pi_framebuffer_t *fb=getFrameBuffer();
    sense_fb_bitmap_t *bm=fb->bitmap;
    int input = 0;
    printf("Enter hours here:\n");
    scanf("%d",&input);
    display_hours(bm,input);
    sleep(1);

    freeFrameBuffer(fb);
    return 0;
}

