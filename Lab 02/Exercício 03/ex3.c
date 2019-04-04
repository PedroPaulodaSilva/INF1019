
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAXVECTOR 6

int main (int argc, char *argv[]) {
	int j, pid, id = 31;
	int *p;
	int v[] = {16, 31, 8, 2, 55, 40};
	int segmento = shmget (IPC_PRIVATE, sizeof (int), IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
	p = shmat (segmento, 0, 0); 


	for(j = 0; j < MAXVECTOR; j++){
		*(p+j) = v[j];
	}
	
	
	if ((pid = fork()) < 0) {
		puts ("Erro na criação do novo processo");
		exit (-2);
		}
	else if (pid == 0) {
	int i, flag = 0;
	for(i = 0; i<MAXVECTOR/2; i++){
			if(*(p+i) == id){
			printf("Achei no indice: %d \n", i);
			flag++;
			break;
		}
	}

	if (flag == 0)
		printf("Chave nao encontrada na primeira metade\n");

	}
	else {
	int i, flag = 0;
	int aux = MAXVECTOR/2;

	for(i = aux; i < MAXVECTOR; i++) {
		
		if(*(p+i) == id){
			printf("Achei no indice: %d \n", i);
			flag++;
			break;
		}
	}

	if (flag == 0)
		printf("Chave nao encontrada na segunda metade\n");
	
	
	}
	// libera a memória compartilhada do processo
	shmdt (p);
	// libera a memória compartilhada
	shmctl (segmento, IPC_RMID, 0);

	return 0;
}

