#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    printf("soy el PADRE, el proceso inicio: \n\n");
    if(fork()==0){
        printf("soy el hijo_1\n\n");
        if(fork()==0){
            printf("soy el hijo_4\n\n");
            exit(EXIT_SUCCESS);
        }else if(fork()==0){
            printf("soy el hijo_5\n\n");
            exit(EXIT_SUCCESS);
        }else{
            exit(EXIT_SUCCESS);
        }
    }

    if(fork()==0){
        printf("soy el hijo_2\n\n");
        if(fork()==0){
            printf("soy el hijo_6\n\n");
            exit(EXIT_SUCCESS);
        }else if(fork()==0){
            printf("soy el hijo_7\n\n");
            exit(EXIT_SUCCESS);
        }else{
            exit(EXIT_SUCCESS);
        }
    }

    if(fork()==0){
        printf("soy el hijo_3\n\n");
        exit(EXIT_SUCCESS);
    }
    wait(NULL); //
    printf("soy el PADRE, el proceso finalizo\n\n");
    return 0;
}