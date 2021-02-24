#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h> 
#include <string.h>
#include "readln.h"

int main(int argc, char *argv[]){
    int fd;
    char buffer [4096];

    fd = open(argv[1],O_RDONLY);

    if (fd == -1) return -1;

    ssize_t size = 0;

    int i = 1;
    while( (size = readln(fd, buffer, 4096))!= 0){
        char printed [4096], newline[2] ="\n";
        sprintf(printed,"%d ",i++);
        strcat(printed, buffer);
        write (STDOUT_FILENO, printed, size + 1);
        write(STDOUT_FILENO, newline,2);
        
    }
    return 0;


}

