#include <stdio.h>
#include "common.h"
#include "canvas.h"
#define INITIAL_VALUE 0

static char bigBuffer[BUFFSIZE];
static void (*handler)(char *msg); 

//this variable holds the index of next available address in bigBuffer
static int index = INITIAL_VALUE; 
//this variable holds the index of the last created canvas
static int firstIndex = INITIAL_VALUE;



void registerCanvasCallback(void (*callback)(char *message)) {
    handler = callback;
}

char *getCanvas(int height) {
    int canvasSize = height * height; 

    if (index + canvasSize >= BUFFSIZE) {
         //print passed message using function passed by registerCanvasCallback
        handler(MSG_ERR_OUT_OF_MEMORY);
        return NULL; //NULL is defined in stdef.h file
    }

    // declares new vairable that points to first index of new Canvas
    char* newCanvas = &bigBuffer[index]; 
     //firstIndex keeps track of the starting address of most recent canvas
    firstIndex = index;
    
    index += canvasSize; //last index and size of new canvas
    bigBuffer[index] = TERMINATOR; // assigning -1 to the last index
    
    index++; //new index is now at next available position in buffer
    
    return newCanvas;
}


int freeCanvas(char* canvas) {
    //decrement index by 2 so it points to last non-terminator address of current canvas
    int i = firstIndex - 2;

    if(canvas != &(bigBuffer[firstIndex])) {
        handler(MSG_ERR_FREE_CANVAS_FAILURE);
        return 1;
    }

    index = firstIndex;
    for(;(bigBuffer[i]!=TERMINATOR) && i != INITIAL_VALUE; --i) { ; }

    firstIndex = i + 1;
    handler(MSG_INFO__CANVAS_FREED);
    return SUCCESS_VALUE;
}

int clone(char *srcCanvas, char* targetCanvas) {
    int i = 0, x = 0, y = 0;

    //those functions calculate the size of each canvas, so we are sure src will fit in target
    //I wrote getLength function because the code was being replicated 3 times.
    x = getLength(srcCanvas);
    y = getLength(targetCanvas);
    
    //clone only if target is bigger or equal to src, otherwise output error
    if(x <= y) {
        for(; srcCanvas[i] != TERMINATOR; i++) {
            *(targetCanvas + i) = *(srcCanvas + i);
        }
    }else {
        handler(MSG_ERR_CLONE_CANVAS_FAILURE);
    }
    
    return SUCCESS_VALUE;
}