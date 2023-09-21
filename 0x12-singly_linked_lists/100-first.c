#include <stdio.h>

/**
 * myStartupFun - Function executed before main() using the constructor attribute.
 *                Prints two lines of text.
 */
void myStartupFun(void) __attribute__ ((constructor));

/**
 * myStartupFun - Implementation of myStartupFun.
 */
void myStartupFun(void)
{
    printf("You're beat! and yet, you must allow,\n");
    printf("I bore my house upon my back!\n");
}
