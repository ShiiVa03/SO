#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
    int p[2];
    int status;

    pipe(p);

    if(!fork()){
        close(p[0]);

        dup2(p[1],1);
        close(p[1]);
        execlp("ls","ls","/etc",NULL);
        _exit(1);
    }else{
        close(p[1]);

        dup2(p[0],0);
        close(p[0]);
        
        execlp("wc","wc","-l",NULL);
    } 

    return 0;
}


/* versao 2

filho:
close(p[0]
dup2(p[1],1))
ls


pai :
close(p[1]);

fork)

filho2:
du2(p[0],0)
close(p[0])
exec wc
pai: close(p[0])

for(int w; w< 2;w++)
wait(&status[ws]);

