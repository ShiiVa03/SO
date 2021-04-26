#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){

    int input_fd = open("/etc/passwd", O_RDONLY);
    int out_fd = open("saida.txt",O_WRONLY | O_CREAT | O_TRUNC, 0666);
    int err_fd = open("erros.txt",O_WRONLY | O_CREAT | O_TRUNC, 0666);

    int stdin_fd = dup2(input_fd, 0);
    int stdout_fd = dup2(out_fd, 1);
    int stderr_fd = dup2(err_fd, 2);

    close(input_fd);
    close(out_fd);
    close(err_fd);

    execlp("wc","wc",NULL);    
       

    return 0;

}