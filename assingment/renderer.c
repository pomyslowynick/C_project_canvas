#include <stdio.h>
#include "renderer.h"
#include "common.h"

static void (*handler)(char *msg);

/*
 * Paints the given canvas buffer by echoing its contents to the console.
 */
void paint(char *canvas) {
    int i = 0, charCounter = 0;
    int lineLength = getWidth(canvas);

    //Common.c getWIdth implementation gives me the length of line for canvas
    while(*(canvas + i) != TERMINATOR ) {
        if(*(canvas + i) != 0) {
            putchar(*(canvas + i));
            charCounter++;
        }
        i++;

        //output newline if a whole line has been printed and there has been atleast one non zero character
        if(i%lineLength == 0 && charCounter > 0) {
            printf("\n");
        }
    }
    //after painting send meesage to handler in main
    handler(MSG_PRINTING_CANVAS);
}


void registerRendererCallback(void (*callback)(char *message)) {
    handler = callback;
}

