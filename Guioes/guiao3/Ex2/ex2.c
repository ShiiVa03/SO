#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>


int main(){

    if(!fork()){
        execlp("ls","ls","-l",NULL);   
    }
    int status;
    wait(&status);     
       
    return 0;
}