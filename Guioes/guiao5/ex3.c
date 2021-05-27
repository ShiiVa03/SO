#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
    int p[2];
    int status;
    ssize_t res = 0;
    char buffer[4096];

    pipe(p);

    if(!fork()){
        close(p[1]);

        dup2(p[0],0);
        close(p[0]);

        execlp("wc","wc",NULL);
        _exit(1);
    }else{

        close(p[0]);

        while((res = read(0,buffer,4096))>0)
            write(p[1],buffer,res);

        close(p[1]);
        wait(&status);

        if(WIFEXITED(status))
            printf("[PAI]filho terminou com %d\n", WEXITSTATUS(status));
    } 

    return 0;
}