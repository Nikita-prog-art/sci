#pragma "once"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include "str.h"

bool eof = false;

Str inputString(FILE* fp, Str old){
    char *str = old.s;
    size_t size = old.size;
    int ch;
    size_t len = 0;
    if (!str) {
        fprintf(stderr, "memory error at inputString(1)");
        exit(-1);
    }
    while (EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if (len + 1 <= size){
            str = realloc(str, sizeof(*str)*(size+=16));
            if (!str) {
                fprintf(stderr, "memory error at inputString(2)");
                exit(-1);
            }
        }
    }
    if (ch == '\n')
        str[len++] = '\n';
    if (ch == EOF)
        eof = true;
    str[len++] = '\0';
    Str ret = {size, str};
    return ret;
}
