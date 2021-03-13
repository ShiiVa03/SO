#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[]){

    int rows = rand() % 10;
    int columns = rand() % 100;
    int matrix [rows] [columns];
    
    printf("ROWS : %d , COLUMS : %d\n",rows,columns);



    for (int i = 0; i < rows; ++i){
        for(int j = 0 ; j < columns; ++j){
            matrix[i][j] = rand() % 10;
            printf("%d ", matrix[i][j]);
            
        }
    puts("");
    }

    int i, j ;
    int num = 0;

    for (i = 0; i < rows; ++i){
        
        if (fork() == 0){
            for(j = 0; j < columns;j++){
               if(matrix[i][j] == atoi(argv[1]))_exit(1);
            }
            _exit(0);
        }else{
           int status;
           wait(&status);
           if(WEXITSTATUS(status) == 1)num++;
           printf("Status : %d\n", status);
        }
    
    }
    printf("Found: %d\n", num);
  
    exit(0);



}