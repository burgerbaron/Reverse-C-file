#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "files_utils.h"
//* initializes buffer and and size
char* buffer;	
int fSize;


int main(int argc, char**argv){

	//*sets size to file size with memory address of buffer and 
	//first argument as peramiters 
	if (argv[1] == NULL){
	fprintf( stderr, "No file");
	}
	fSize = read_file(argv[1], &buffer);
	
	//* writes file with taking in buffer, size, and second argument	
	write_file(argv[2], buffer, fSize);
	
	//* releases edited memory space for buffer
	free(buffer);

	return 0;
}


