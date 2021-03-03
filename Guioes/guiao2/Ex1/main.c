#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t process = getpid();
    pid_t father = getppid();
    char buffer[24],buffer2 [24];
    snprintf(buffer,24,"process %d\n",process);
    snprintf(buffer2,24,"father %d\n",father);

    write(1,buffer,sizeof(buffer));
    write(1, buffer2, sizeof(buffer2));

    exit(0);

}