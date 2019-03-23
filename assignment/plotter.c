#include <stdio.h>
#include "plotter.h"
#include "common.h"
/*
 * Erases the given canvas buffer, by filling its contents with the value 0.
 */
void erase(char *canvas) {
    int i = 0;
    while(*(canvas + i) != TERMINATOR) {
        *(canvas + i) = ERASE_VALUE;
        i++;
    }
}

/*
 * Fills the given canvas with the given char value.
 */
void fill(char *canvas, char c) {
    int i = 0;
    while(*(canvas + i) != TERMINATOR) {
        *(canvas + i) = c;
        i++;
    }
}

/*
 * Plots the given char value at coordinates x,y in the given canvas buffer.
 */
void plot(char *canvas, int x, int y, char c) {
    int lineLength = getWidth(canvas);
    if(lineLength == WIDTH_UNKNOWN) {
        ;
    }else {
        *(canvas + (y * lineLength) + x) = c;
    }
}

/*
 * Replaces all instances of char old with char new in the given canvas buffer.
 */
void replace(char *canvas, char old, char new) {
    int i = 0;
    while(*(canvas + i) != TERMINATOR) {
        if(*(canvas + i) == old) {
            *(canvas + i) = new;
        }
        i++;
    }
}