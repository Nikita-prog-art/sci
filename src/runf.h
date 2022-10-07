#pragma "once"

#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>

void runf(char *s){
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
