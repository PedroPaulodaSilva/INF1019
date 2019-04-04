#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char *argv[]){
	char *peguei;
	peguei = shmat(1703959, 0, 0);

	if (peguei == (char*)-1) {
		printf("erro\n");
	}
	printf("%s \n", peguei);
	return 0;
}
