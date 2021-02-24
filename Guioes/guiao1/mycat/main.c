#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main (int argc, char *argv[]){
    
    char buffer[4096];
    ssize_t readbytes = 0;


    while((readbytes = read(0,buffer,4096))> 0)
        write(STDOUT_FILENO,buffer,readbytes);
    
    return 0;


}