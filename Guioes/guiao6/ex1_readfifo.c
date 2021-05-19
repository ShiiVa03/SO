#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    char buffer[4096];
    int bytesread = 0;
    int fd = open("fifo",O_WRONLY);

    while((bytesread = read(0, buffer, 4096)>0))
        write(fd,buffer,bytesread);
    
    close(fd);
    return 0;
}