#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    printf("soy el PADRE, el proceso inicio: \n\n");

    pid_t pid1, pid2, pid3;

    if((pid1 = fork()) == 0){
        printf("soy el hijo_1\n\n");
        pid_t pid4, pid5;
        if((pid4 = fork()) == 0){
            printf("soy el hijo_4\n\n");
            exit(EXIT_SUCCESS);
        }else if((pid5 = fork()) == 0){
            printf("soy el hijo_5\n\n");
            exit(EXIT_SUCCESS);
        }else{
            waitpid(pid4, NULL, 0);
            waitpid(pid5, NULL, 0);
            exit(EXIT_SUCCESS);
        }
    }

    if((pid2 = fork()) == 0){
        printf("soy el hijo_2\n\n");
        pid_t pid6, pid7;
        if((pid6 = fork()) == 0){
            printf("soy el hijo_6\n\n");
            exit(EXIT_SUCCESS);
        }else if((pid7 = fork()) == 0){
            printf("soy el hijo_7\n\n");
            exit(EXIT_SUCCESS);
        }else{
            waitpid(pid6, NULL, 0);
            waitpid(pid7, NULL, 0);
            exit(EXIT_SUCCESS);
        }
    }

    if((pid3 = fork()) == 0){
        printf("soy el hijo_3\n\n");
        exit(EXIT_SUCCESS);
    }

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    waitpid(pid3, NULL, 0);

    printf("soy el PADRE, el proceso finalizo\n\n");
    return 0;
}