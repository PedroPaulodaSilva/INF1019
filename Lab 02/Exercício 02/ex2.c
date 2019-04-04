#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char *argv[])
{
	int segmento, *p, id, pid, status;
	// aloca a memória compartilhada
	segmento = shmget (IPC_PRIVATE, sizeof (int), IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
	// associa a memória compartilhada ao processo
	p = (int *) shmat (segmento, 0, 0); // comparar o retorno com -1
	*p = 8765;
	return 0;
}
