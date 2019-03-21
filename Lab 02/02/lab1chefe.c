#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	
	int PID;
	
	
	
	PID = fork();

	if(PID != 0){
		char* argv2[] = {"./alomundo", NULL};
		execvp(argv2[0], argv2);
		
		
	}
	else	{
		char* argv1[] = {"./echo","imprime","outra","coisa", NULL};
		execvp(argv1[0], argv1);
	}
	return 0;
}
