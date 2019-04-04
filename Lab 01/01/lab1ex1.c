#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	int status;
	

	if(fork() != 0){
		
		int i;
		
		for(i=0; i < 100; i++){
printf("PID pai: %d, PID: %d\n", getppid(), getpid());
			printf("%d\n", i);
			sleep(1);
		}
	printf("Processo pai vai finalizar!\n");
	waitpid(-1,&status,0);
		
	}
	else	{
		if(fork() != 0) {
			//FILHO
			int i;
			printf("Filho foi iniciado!\n");
			for(i = 100; i < 200; i++){
				printf("PID pai: %d, PID: %d\n", getppid(), getpid());
				printf("%d\n", i);
				sleep(2);
			}
			printf("Filho vai finalizar!\n");
			waitpid(-1,&status,0);
		}
	else{
		//NETO
		printf("O neto foi iniciado!\n");
		int i;
		for(i = 200; i < 300; i++){
			printf("PID pai: %d, PID: %d\n", getppid(), getpid());
			printf("%d\n",i);
			sleep(3);
		}
		printf("O neto vai finalizar!\n");
	}
}
}
