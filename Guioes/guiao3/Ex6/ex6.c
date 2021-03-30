#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int mysystem (char *command){
    char *args [100];
    char *buffer = strdup(command);
    char *aux;
    int i = 0;

    while((aux = strsep(&buffer," ")))
        args[i++] = strdup(aux);
    
    args[i] = NULL;

    if(!fork()){
        execvp(args[0],args);
    }else{
        wait(NULL);
        exit(1);
    }
    return 0;    

}

int main(){
    char *buffer;
    size_t n = 0;
    getline(&buffer,&n,stdin);
    strtok(buffer,"\n");
    mysystem(buffer);
    free(buffer);
    return 0;

}