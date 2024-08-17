#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    pid_t pid, pid2;
    int estado;

    pid = fork(); /* Cria um PROCESSO */if (pid < 0) 
    {
        printf("Erro ao criar o processo\n");
        exit(-1);
    }
    else if (pid > 0) /* Código que só vai ser executado pelo Processo PAI */
    {
        printf("Eu sou o PAI\n");
		printf("Papai estah esperando vc...\n");
        pid2 = wait(&estado);
		printf("To pronto pai!\n");
        printf("O filho com o pid %d terminou\n", pid2);
    }
    else /* Código que só vai ser executado pelo Processo FILHO */
    {
        printf("Processo Filho\n");
    }

    printf("REPETIDO\n");

    return 0;
}
