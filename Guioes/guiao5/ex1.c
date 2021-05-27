#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


int pai2filho(){
    int p[2];
    char line [] = "linha1";
    char buffer[20];
    int res;
    int status;

    if(pipe(p) == -1){
        perror("pipe");
        return -1;
    }

    switch (fork()){
        case -1 : 
            perror("fork");
            return -1;
        case 0 : 
            //fechar descritor de escrita do filho
            close(p[1]);
            res = read(p[0], &buffer, sizeof(buffer));
            printf("Filho leu %s from pipe res %d\n", buffer, res);
            close(p[0]);
            _exit(0);

        default :
            close(p[0]);
            sleep(5);
            write(p[1],line, sizeof(line));
            close(p[1]);
            printf("Pai escreveu %s\n",line);
            wait(&status);
            
    }
    return 0;

}

int main(){
    pai2filho();
}