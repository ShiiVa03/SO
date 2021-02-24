#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

int main (int argc, char *argv[]){
    int fdsource,ciclos = 0;

    if (argc < 3){
        puts("Não foram especificados todos os argumentos");
        return -2;
    
    }
    clock_t start_time = clock();

    fdsource = open(argv[1],O_RDONLY);

    if (fdsource == -1){
        puts("Erro na abertura do source");
        return -1;
    }

    int fddest = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC, 6666);

    char *buffer = malloc(100);
    ssize_t readbytes;

    while ((readbytes = read(fdsource,buffer,100))> 0){
        write (fddest, buffer, readbytes);
        ciclos++;
    }

    printf("Executou %d ciclos e demorou %f segundos\n", ciclos, (double)(clock()-start_time)/ CLOCKS_PER_SEC);

    return 0;



}