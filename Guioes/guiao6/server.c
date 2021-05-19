#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>



int main()
{
    printf("Starting server...\n");
    mkfifo("pip", 0644);
    printf("Opening pipe\n");
    int input = open("pip", O_RDONLY);

    printf("Opening log\n");
    int log = open("log.txt", O_CREAT | O_WRONLY, 0644);

    printf("Reading\n");

    while (1) {
        char buf[1024];
        int n = read(input, buf, 1024);
        if (n > 0){
            write(log, buf, n);
            write(log, "\n",1);
        }
    }
  
    return 0;
}