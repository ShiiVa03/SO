#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h> 
#include <string.h>

ssize_t readln (int fd, char *line, size_t size){
    size_t i = 0;
    ssize_t readbytes = 0;

    while (i < size - 1){
        readbytes = read(fd, &line[i],1);
        if (readbytes < 1)break;
        if (line[i++]=='\n')break;
    }
    line[i] = '\0';

    return i;
}

ssize_t readln2 (int fd, char *line, size_t size){
    ssize_t readbytes = 0;

    readbytes = read(fd, line, size);

    if (readbytes <=0) return 0;

    size_t linelength = strcspn(line, "\n") + 1;
    if (readbytes < linelength) linelength = readbytes;
    line[linelength] = '\0'; 

    lseek(fd, linelength - readbytes, SEEK_CUR);

    return linelength;

}

