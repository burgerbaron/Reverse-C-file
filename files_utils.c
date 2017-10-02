#include "files_utils.h" //* imports .h libraries that the program can use
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>






//* Potential error number
int errNum;

/*
 * Reads a file in order to set buffer to remember characters. 
 */
int read_file(char* filename, char** buffer){



	//* get's the size of the file 
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;



	//* opens file
	FILE *Input;
	Input = fopen(filename, "r");
	if (Input == NULL){
	errNum = errno;
	fprintf(stderr, "error value: %d/n", errno);
	fprintf(stderr, "File not opening");
	return 0;
	}


		
	//* creates new pointer to string
	char *newBuff;
	newBuff = malloc(size * sizeof(char));
	if (newBuff == NULL){
	fprintf(stderr, "memory allocation failed");
	}



	//* while loop for reading every character in file
	int a;
	int i=0;
	while((a = fgetc(Input)) != EOF){
		char toChar = (char) a;
		newBuff[i] = toChar;
		i++;
	}



	//* sets pointer for buffer to same value as newBuff
	*buffer = newBuff;


	
	//* frees memory space of Input file
	fclose( Input);

	return size;
}


/*
 * Writes to file from buffer based on length of the size of the read file.  
 */
int write_file(char *filename, char *buffer, int size){



	//* creates a pointer to the file output and lets us write in it
	FILE *Output;
	Output = fopen(filename, "w");
	if (Output == NULL){
	errNum = errno;
	fprintf(stderr, "error value: %d/n", errno);
	}



	//* moves through the size of the old file and places characters into
	//the new one
	for (int i = size-1; i >= 0; i--) {
		char *a = buffer + i;
		fprintf (Output, "%c", *a);
	}


	
	//* frees memory space of Output file
	fclose( Output);	

	return 0;
}	


