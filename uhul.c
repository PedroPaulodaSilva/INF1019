#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int status;
	int cont = 0;
	pid_t PID;

	PID = fork();

	if(PID != 0){
		int i;
		
		for(i=0; i < 100; i++){
printf("%d\n",getpid());
			cont++;			
			printf("%d\n", cont);
		}
		waitpid(-1,&status,0);
	}
	else	{
		int j;
		for(j=0; j < 100; j++){
		printf("%d\n",getpid());
			cont = cont + 5;			
			printf("%d\n", cont);
		}
		//execve(command, parameters,0);
	}
}
