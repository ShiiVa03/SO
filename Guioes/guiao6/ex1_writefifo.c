#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd = open("fifo", O_RDONLY);
    char buffer[4096];    
    int bytesread = 0;

    while((bytesread = read(fd,buffer,4096)) > 0 )
        write(1,buffer,bytesread);

    close(fd);

    return 0;
}