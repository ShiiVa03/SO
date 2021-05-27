#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>


int main(){

    char *commands[4] = {"grep -v ˆ# /etc/passwd" ,"cut -f7 -d:" ,"uniq" ,"wc -l"};
  
    int num_pipes = 3;

    int arraypipes[num_pipes][2];

    for(int i = 0;i <= num_pipes; ++i){
        
        char * command, * buffer, *args[4];

        if(i == 0){ 
            pipe(arraypipes[i]);
            switch(fork()){
                case 0:
                    close(arraypipes[i][0]);
                
                    dup2(arraypipes[i][1],1);
                    close(arraypipes[i][1]);
                    
                    execlp("grep","grep", "-v", "^#", "/etc/passwd", NULL);
                default:                   
                    close(arraypipes[i][1]);
            }

        }else if(i == num_pipes){
            switch(fork()){
                case 0:
                    dup2(arraypipes[i-1][0],0); 
                    close(arraypipes[i-1][0]);                    
                                   
                    execlp("wc","wc","-l", NULL);

                default:      
                    close(arraypipes[i-1][0]);                    
            }

        }else{    
            pipe(arraypipes[i]);        
            switch(fork()){
                case 0:
                    buffer = strdup(commands[i]);                    
                    int j = 0;
                    while((args[j] = strsep(&buffer," ")) != NULL){
                        if(j == 0)
                            command = args[j];                                                      
                        
                        j++;    
                                         
                    }
                    args[j] = NULL;    

                    close(arraypipes[i][0]);              
                    
                    dup2(arraypipes[i-1][0],0);
                    close(arraypipes[i-1][0]);
                    dup2(arraypipes[i][1],1);
                    close(arraypipes[i][1]);    
                    
                    execvp(command,args);

                default :                                                      
                
                    close(arraypipes[i-1][0]);
                    close(arraypipes[i][1]);
                    
            }
        }
    }

    for(int i = 0;i< 4; i++)
        wait(NULL);
}