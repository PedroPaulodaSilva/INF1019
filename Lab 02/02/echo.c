#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
	int i;
	for(i=1;argv[i] != NULL; i++)
		printf("%s ",argv[i]);

	printf("\n");
}
