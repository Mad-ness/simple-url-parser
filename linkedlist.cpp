#include <string.h>
#include <stdio.h>
#include "linkedlist.h"

void copystr( char *dest, const char *src )
{
    int size = strlen(src);
    // dest = new char[size+2];
//    dest = (char*)malloc(size * sizeof(src[0]) + 1);
    strcpy( dest, src );
//    printf("First letter: %c (%lu bytes), Old str [%s], new str [%s], src size %d\n", src[0], sizeof(src[0]), src, dest, size);
};



