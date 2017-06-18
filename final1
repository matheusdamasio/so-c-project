#define _GNU_SOURCE
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>

#define sem 1;
#define FIBER_STACK 1024*64
int global = 0;
int result;

int UP(){
	sem+1;
	return sem;
}

int DOWN (){
	sem-1;
	return sem;
}

int thread1(void* argument){
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



int main(){
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
     return  0;
}
