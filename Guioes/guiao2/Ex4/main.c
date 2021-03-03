#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    
    for (int i = 1; i < 11; i++){
        if(fork() == 0)
            _exit(i);
    }
    int exitstatus;
    while(wait(&exitstatus) != -1)
        printf("Exit status : %d\n", WEXITSTATUS(exitstatus));

    exit(0);
}