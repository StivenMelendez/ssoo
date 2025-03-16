#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> // Incluir para la función wait()

int nivel = 0; // Contador global para el nivel de creación de procesos

void crear_hijos(int nivel_actual, int n);
int cantidad_a_crear();

int main(void) {
    int n = cantidad_a_crear(); // Número de procesos a crear
    printf("||PADRE con PID %d|| **nivel %d**\n\n", getpid(), nivel); // Imprime el PID del proceso padre una sola vez
    crear_hijos(nivel, n);
    return EXIT_SUCCESS;
}

int cantidad_a_crear(){
    int n = 0;
    do{
        printf("Ingrese el número de procesos a crear: ");
        scanf("%d", &n);
    }while(n < 1);
}

void crear_hijos(int nivel_actual, int n) {
    int i;
    int m = 0;
    pid_t pid;
    char respuesta;

    for (i = 1; i < n+1; i++) { // Ciclo para crear n procesos
        pid = fork();
        if (pid == 0) { // Si el valor de retorno de fork es 0, entonces es el proceso hijo
            nivel_actual++;
            printf("||Soy el hijo %d|| {con PID %d} [mi padre tiene PID %d] **te encuentras en el nivel %d**\n\n", i, getpid(), getppid(), nivel_actual); // Imprime el PID del proceso hijo y el PID del proceso padre
            do{
                printf("¿||El hijo %d|| {con PID %d} también será padre? (y/n): \n\n", i, getpid());
                scanf(" %c", &respuesta);
                if(respuesta == 'y' || respuesta == 'Y'){
                    m = cantidad_a_crear();
                    crear_hijos(nivel_actual, m); // Llama a la función para crear más hijos
                    break;
                }
           }while (!(respuesta == 'y' || respuesta == 'Y' || respuesta == 'n' || respuesta == 'N'));
            break; // Termina el proceso hijo
        } else if (pid < 0) { // Si fork() falla
            perror("Error fork");
            exit(EXIT_FAILURE);
        } else { // Proceso padre
            wait(NULL); // Espera a que el hijo termine antes de continuar
        }
    }
}