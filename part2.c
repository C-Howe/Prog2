/*
Alexander Schnackenberg
aschnackenberg@albany.edu
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "constants.h"

/*
Print the following statistics about the binary file to stdout:
(a) The length of a shortest string in the input file.
(b) The length of a longest string in the input file.
(c) The value of the maximum integer in the input file.
(d) The value of the minimum integer in the input file.
*/
void statistics(FILE *input_file){
	char array[MAX_LENGTH_OF_STRING+1];	//used to store string
	char length = '\0';	//used to receive length value
	int ilength = 0; //used to store length as an integer
	unsigned int u_integer; //used to store integer in line
	int len_shortest_string = MAX_LENGTH_OF_STRING;
	int len_longest_string = 0;
	unsigned int max_int = 0;
	unsigned int min_int = (unsigned int) MAX_UNSIGNED_INTEGER;
	
	while(fread ((void *) &length, sizeof(char), 1, input_file)){ //while not at the end of the file
		//read char length, string, and integer	
		ilength = (int) length;
		fread (array, sizeof(char), ilength, input_file);
		array[ilength] = '\0'; 			
		fread (&u_integer,sizeof(unsigned int), 1, input_file); 	

		if(u_integer < min_int){
			min_int = u_integer;
		}
		if(u_integer > max_int){
			max_int = u_integer;		
		}
		if(ilength < len_shortest_string){
			len_shortest_string = ilength;
		}
		if(ilength > len_longest_string){
			len_longest_string = ilength;
		} 
	}

	printf("(a) The length of a shortest string in the input file: %d\n(b) The length of a longest string in the input file: %d\n(c) The value of the maximum integer in the input file: %u\n(d) The value of the minimum integer in the input file: %u\n", len_shortest_string, len_longest_string, max_int, min_int);fflush(stdout);
}
