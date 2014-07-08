/*
Alexander Schnackenberg
aschnackenberg@albany.edu
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "constants.h"

void binary_to_text(FILE *input_file, FILE *output_file){
	char array[MAX_LENGTH_OF_STRING+1];	//used to store string
	char length = '\0';	//used to receive length value
	int ilength = 0; //used to store length as an integer
	unsigned int u_integer; //used to store integer in line
	
	while(fread ((void *) &length, sizeof(char), 1, input_file)){ //while not at the end of the file
		//read char length, string, and integer	
		ilength = (int) length;
		fread (array, sizeof(char), ilength, input_file);
		array[ilength] = '\0'; 			
		fread (&u_integer,sizeof(unsigned int), 1, input_file); 	
		fprintf(output_file, "%s%c%u\n", array, '\t', u_integer);
	}
}

void text_to_binary(FILE *input_file, FILE *output_file){
	//the length of each line in the output_file will be strlen + 5 (char and 4 for the unsigned int)	
	char string[MAX_LENGTH_OF_STRING];
	unsigned int u_integer;
	char length_of_string;
	int ilength; //used to store string length as an int

	while(fscanf(input_file, "%s", string) != EOF){
		fscanf(input_file, "%u", &u_integer);
		ilength = strlen(string);
		length_of_string = (char) ilength;
		fwrite(&length_of_string, sizeof(char), 1, output_file);		
		fwrite(string, ilength*sizeof(char), 1, output_file);
		fwrite(&u_integer, sizeof(unsigned int), 1, output_file);
	}	
	
}
