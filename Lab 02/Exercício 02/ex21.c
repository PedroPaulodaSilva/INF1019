#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char *argv[]){
	int segmento, id = 8765;
	char *mensagem = "Bom dia";
	char *p;
	// aloca a memória compartilhada
	
	segmento = shmget (id, sizeof (int), IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
	p = shmat (1703959, 0, 0); // comparar o retorno com -1
	// associa a memória compartilhada ao processo
	printf("%d\n", segmento);

	strcpy(p, mensagem);
	printf("%s\n", p);
	return 0;
}
