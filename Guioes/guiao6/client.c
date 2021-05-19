#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>



int main(int argc, char *argv[]){
    int server = open("pip",O_WRONLY);

    if(server < 0){
        perror("Server offline");
    }
    for(int i = 1;i < argc;i++){
        write(server,argv[i],strlen(argv[i]));
    }

    close(server);

    return 0;
}