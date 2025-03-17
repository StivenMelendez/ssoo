#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t hijo_1, hijo_2, hijo_3, hijo_4, hijo_5, hijo_6, hijo_7;

    // Crear hijo_1
    hijo_1 = fork();
    if (hijo_1 == 0) {
        printf("Soy el hijo_1\n");

        // Crear hijo_4
        hijo_4 = fork();
        if (hijo_4 == 0) {
            printf("Soy el hijo_4\n");
            exit(0); // Terminar hijo_4
        }

        // Crear hijo_5
        hijo_5 = fork();
        if (hijo_5 == 0) {
            printf("Soy el hijo_5\n");
            exit(0); // Terminar hijo_5
        }

        // Esperar a que hijo_4 e hijo_5 terminen
        wait(NULL);
        wait(NULL);
        exit(0); // Terminar hijo_1
    }

    // Crear hijo_2
    hijo_2 = fork();
    if (hijo_2 == 0) {
        printf("Soy el hijo_2\n");

        // Crear hijo_6
        hijo_6 = fork();
        if (hijo_6 == 0) {
            printf("Soy el hijo_6\n");
            exit(0); // Terminar hijo_6
        }

        // Crear hijo_7
        hijo_7 = fork();
        if (hijo_7 == 0) {
            printf("Soy el hijo_7\n");
            exit(0); // Terminar hijo_7
        }

        // Esperar a que hijo_6 e hijo_7 terminen
        wait(NULL);
        wait(NULL);
        exit(0); // Terminar hijo_2
    }

    // Crear hijo_3
    hijo_3 = fork();
    if (hijo_3 == 0) {
        printf("Soy el hijo_3\n");
        exit(0); // Terminar hijo_3
    }

    // Esperar a que todos los hijos terminen
    wait(NULL);
    wait(NULL);
    wait(NULL);

    printf("Soy el proceso padre, todos los hijos terminaron\n");
    return 0;
}