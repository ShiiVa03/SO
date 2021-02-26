#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h> 
#include <string.h>
#include "data.h"

int main (int argc, char *argv[]){
    int fd; 
    
    if (argc < 4){
        puts("Not all arguments were given to function");
        return -1;
    }
    Person person;

    switch (*(argv[1] + 1)){
        case 'i':

            fd = open("database", O_WRONLY | O_CREAT | O_APPEND, 0666);

            if (fd == -1){
                puts("Error during file opening");
                return -1;
            }

            strcpy(person.name,argv[2]);
            person.age = atoi(argv[3]);
            

            if (write(fd, &person, sizeof(struct person)) < 1){
                puts("Error writing to file");
                close(fd);
                return -1;

            }
            puts("Added info");
        break;

        case 'u':
            
            fd = open("database", O_RDWR);
            if ( fd == -1 ){
                puts("Error during file opening to update");
                return -1;
            }

            while (read(fd, &person, sizeof(struct person)) > 0){
                if (strcmp(person.name, argv[2]) == 0 ){
                    int num = atoi(argv[3]);
                    person.age = num;
                    lseek(fd,-sizeof(struct person),SEEK_CUR);
                    if (write(fd, &person, sizeof(struct person))<= 0){
                        puts("Error in file update");
                        return -1;
                    }else{           
                    puts("Updated");
                    break;
                    }
                }
            }
            break;
        default :
            puts("ERROR");
            return -1;
    }


    return 0;

}