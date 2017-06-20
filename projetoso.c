#define _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>
#include <sys/ipc.h>

#define sem 1;
#define FIBER_STACK 1024*64
int global = 0;
int result;
int semid;

int UP(int semid){
	semid = sem;
	sem+1;
	return sem;
}

int DOWN (int semid){
	semid = sem;
	sem-1;
	return sem;
}

/*int thread1(void* argument){
	result = DOWN();
	if(result == 0){
	 global = 41;
	 printf("teste thread1 %d \n ",global);
	}
	UP();
}
int thread2(void* argument){
	result = DOWN();
	if(result == 0){
	 global = 41-100;
	 printf("teste thread1 %d \n ",global);
	}
	UP();
}
*/

int main(){/*
	 void* stack;
	 pid_t pid;
     //pid_t pid2;
     stack = malloc (FIBER_STACK);
     //printf("clonando a thread");
     pid = clone(&thread1, (char*) stack+FIBER_STACK, SIGCHLD | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_VM, 0);
     //printf("clonando a thread novamente");
     pid = clone(&thread2, (char*) stack+FIBER_STACK, SIGCHLD | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_VM, 0);
     //pid = waitpid(pid,0,0);
     //pid2 = waitpid(pid2, 0 ,0);
     printf("Retorno = %d\n",global);
     free(stack);
     printf("Retorno da thread filha e stack liberado.\n Resultado: %d\n",global);
     return  0;*/
	 int com_semaforo = 0;
	 int semid;
	 char *texto[8];
	 int i;
	 int pid, pid_father, pid_son;

	 pid_father = getpid();

	 texto[0] = "teste de semaforo parte 1";
	 texto[1] = "teste de semaforo parte 2";
	 texto[2] = "teste de semaforo parte 3";
	 texto[3] = "teste de semaforo parte 4";
	 texto[4] = "teste de semaforo parte 5";
	 texto[5] = "teste de semaforo parte 6";
	 texto[6] = "teste de semaforo parte 7";
	 texto[7] = "teste de semaforo parte 8";

pid_son = fork();
  pid = (pid_son)? pid_son : pid_father;

printf("Inicio de execucao do processo %d, semaforo %d\n", pid, semid);


    while(1)
  {
    if (com_semaforo)
      DOWN(semid); /*   entrada na Regiao Critica */
    for(i = 0; i < 8; i++)
    {
      printf("\n%d: %s", pid, texto[i]);
      //sleep(1);
    }
    printf("\n\n");
    if (com_semaforo)
      UP(semid); /*  saida da Regiao Critica */
   // sleep(2);
  }
	 
}
