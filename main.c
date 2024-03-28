#include "display.h"

int main(void) {
    pi_framebuffer_t *fb=getFrameBuffer();
    fprintf(stderr,"Going to print a sigma!\n");

  //  display_sigma(fb);
    sleep(5);
    fprintf(stderr,"Did it!\n");
    clearFrameBuffer(fb,0);
    sleep(1);
    freeFrameBuffer(fb);
    fprintf(stderr,"Exiting.\n");
    return 0;
}


//First use a scanf function to get a time in this format HH/MM/SS

//The time they entered in , then needs to be displayed on the HAT in binary format.
