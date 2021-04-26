#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char * argv[]){

    int input_fd = -2;
    int output_fd = -2;

    if(strcmp(argv[1], "-i") == 0){
        input_fd = open(argv[2],O_RDONLY);
    }else if(strcmp(argv[1], "-o") == 0){
        output_fd = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC, 0666);
    }else{
        perror("nao suportavel");
        _exit(1);
    }  

    if(strcmp(argv[3], "-o") == 0){
        output_fd = open(argv[4],O_WRONLY | O_CREAT | O_TRUNC, 0666);
    }

    if(input_fd != -2 && output_fd != -2){
        dup2(input_fd,0);
        dup2(output_fd,1);

        close(input_fd);
        close(output_fd);
        argv[argc] = NULL;

        if(!fork()){
            execvp(argv[5],argv + 5);
            _exit(1);
        }
    
    }else if(input_fd != -2){
        dup2(input_fd,0);
        close(input_fd);

        if(!fork()){
            execvp(argv[3],argv + 3);
            _exit(1);
        }

    }else{
        dup2(output_fd,1);
        close(output_fd);

        if(!fork()){
            execvp(argv[3],argv + 3);
            _exit(1);
        }
    }

    wait(NULL);
    
    return 0;


}