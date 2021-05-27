#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int pai2filho(){
    int p[2];
    char * line [] = {"linha1\n","linha2\n","linha3\n"};
    char buffer[64];
    int num_linhas = 3;
    int res;
    int status;
    int i= 0;


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
            res = 0;
            close(p[1]);
            while((res = read(p[0], buffer, 64))>0)
               printf("Leu %s\n ", res);
            
           
            close(p[0]);
            _exit(0);

        default :
            close(p[0]);
            
            for(int i= 0; i < num_linhas;++i){
                write(p[1], line[i], strlen(line[i]));
                printf("Pai escreveu %s\n",line[i]);
            }
           
            close(p[1]);
          
            wait(&status);
            
    }
    return 0;
}

int main(){
    pai2filho();
}