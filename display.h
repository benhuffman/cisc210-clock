#ifndef DISPLAY_H
#define DISPLAY_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sense.h"
#include "display.h"
//void display_sigma(pi_framebuffer_t *);

void display_colons(sense_fb_bitmap_t *bm);

void assign_pixel(sense_fb_bitmap_t *bm, int time_amount, int x, int COLOR);

void display_hours(sense_fb_bitmap_t *bm, int hours);

void display_minutes(sense_fb_bitmap_t *bm, int mins);

void display_seconds(sense_fb_bitmap_t *bm, int secs);

void display_time(sense_fb_bitmap_t *bm, int hours, int minutes, int seconds);

int open_display(void);

#endif
