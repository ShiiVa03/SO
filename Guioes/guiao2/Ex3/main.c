#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

    for (int i = 1; i < 11; ++i){

        if(fork() == 0){
            pid_t childPid = getpid();
            pid_t fatherPid = getppid();
            printf("Father : %d , PID : %d \n",(int)fatherPid,(int)childPid);
            _exit(i);            
        }
        int status;
        wait(&status);
        printf("Código de saída : %d\n", WEXITSTATUS(status));
    }
    exit(0);
}