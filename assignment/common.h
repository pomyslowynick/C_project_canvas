#ifndef COMMON_H
#define COMMON_H

#define SUCCESS_VALUE 0
#define BUFFSIZE 1000
#define TERMINATOR -1
#define WIDTH_UNKNOWN -1
#define LENGTH_UNKNOWN -1

#define ERASE_VALUE 0
/*
 * Retuns the length of the given canvas buffer.
 */
int getLength(char *canvas);

/*
 * Retuns the width of the given canvas buffer.
 */
int getWidth(char *canvas);



#endif