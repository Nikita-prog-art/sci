#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <unistd.h>

#include "config.h"
#include "str.h"

typedef struct _process{
    struct _process *next;
    int pid;
} process;

#ifdef DEBUG
char deffn[] = "init.sci";
#endif

void run(char *s){
    char *const a[] = {s, s, NULL};
    pid_t pid;
    pid = fork();
    if (pid < 0)
        exit(-2);
    if (pid == 0){
        execvp(s, a);
        _exit(-3);
    }
    return;
}

int main(int argc, char *argv[]){
    char *file_name;
    if (argc != 2){
        #ifndef DEBUG
        fprintf(stderr, "error: requred 1 argument, but given %d", argc - 1);
        exit(1);
        #else
        file_name = deffn;
        #endif
    }
    else
        file_name = argv[1];
    FILE *inp;
    if ((inp = fopen(file_name, "r")) == NULL){
        printf("can't open %s", file_name);
        exit(1);
    }
    char *str = malloc(1);
    Str s = {1, str};
    while (!eof) {
        s = inputString(inp, s);
        run(s.s);
    }
}