#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid;

    if ((pid = fork()) == 0){
        pid_t fatherchild = getppid();
        pid_t pidchild = getpid();
        printf("O pai deste processo é %d e o pid deste processo é %d\n", (int)fatherchild,(int)pidchild);

    }else{
        pid_t father = getppid();
        pid_t fatherpid = getpid();
        pid_t fatherchildpid = pid;
        printf("Father pid : %d, Father father : %d, Child pid : %d\n", (int)fatherpid, (int) father, (int)fatherchildpid);

    }

    exit(0);

}