#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>



int main(int argc, char **argv){
   
    execv("../Ex3/a.out",argv);
    return 0;


}