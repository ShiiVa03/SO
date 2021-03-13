#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    
    int status;
    for (int i = 0; i < 11; ++i){
        pid_t father = getppid();
        pid_t pid  = getpid();

        printf("Father : %d , Process : %d\n", (int)father, (int) pid);

        if(fork()){
            int returned = wait(&status);
            printf("Processo wait : %d , exit code : %d\n", returned, status);
            _exit(i);
        }


    }

    return(0);
    
  
}
