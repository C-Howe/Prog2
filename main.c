/*
Alexander Schnackenberg
aschnackenberg@albany.edu
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "prototypes.h"

int main(int argc, char *argv[]){
	FILE *input_file = NULL;
	FILE *output_file = NULL;

	if (argc == ARG_COUNT_1){
		//argv[FLAG] may either be -b or -t
		if(strcmp(argv[FLAG], "-b")==0){
			//open input and output files
			if ((input_file = fopen(argv[INFILE], "rb")) == NULL){
				fprintf(stderr, "Input file could not be opened \n");
				exit(1);
			}		
			if ((output_file = fopen(argv[OUTFILE], "w")) == NULL){
				fprintf(stderr, "Output file could not be opened \n");
				exit(1);
			}
			
			//convert binary file to text file
			binary_to_text(input_file, output_file);
		}
		else{ 
			if(strcmp(argv[FLAG], "-t")==0){
				//open input and output files
				if ((input_file = fopen(argv[INFILE], "r")) == NULL){
					fprintf(stderr, "Input file could not be opened \n");
					exit(1);
				}		
				if ((output_file = fopen(argv[OUTFILE], "wb")) == NULL){
					fprintf(stderr, "Output file could not be opened \n");
					exit(1);
				}
			
				//convert text file to binary file			
				text_to_binary(input_file, output_file);
			}
			else{
				fprintf(stderr, "Expect either -b or -t as flags. \n"); exit(1);		
			}
		}
	}	
	if (argc == ARG_COUNT_2){
		//argv[FLAG] must be -s
		if(strcmp(argv[FLAG], "-s")==0){
			if ((input_file = fopen(argv[INFILE], "rb")) == NULL){
				fprintf(stderr, "Input file could not be opened \n");
				exit(1);
			}
			
			//calculate statistics and print to stdout
			statistics(input_file);	
		}		
		else{
				fprintf(stderr, "Expect -s as the flag. \n"); exit(1);		
		}			
	}

	return 0;
}
