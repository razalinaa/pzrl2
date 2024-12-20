#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab2.h"

int main(int argc, char *argv[])
{
	if (argc < 4)
	{
		fprintf(stderr, "Usage: %s input.txt -r 'old text' 'new text'\n", argv[0]);
        	fprintf(stderr, "Usage: %s input.txt -d 'text to delete'\n", argv[0]);
        	fprintf(stderr, "Usage: %s input.txt -i -f 'insert text front'\n", argv[0]);
        	fprintf(stderr, "Usage: %s input.txt -i -b 'insert text back'\n", argv[0]);
        	return 1;
    	}

    	FILE *input = fopen(argv[1], "r");
    	if (input == NULL)
	{
        	perror("Error opening input file");
        	return 1;
    	}

    	if (strcmp(argv[2], "-d") == 0 && argc == 4)
	{
		const char *deletetext = argv[3];
        	FILE *output = fopen("output.txt", "w");
        	if (output == NULL)
		{
            		perror("Error opening output file");
            		fclose(input);
            		return 1;
        	}
        	deleteline(input, output, deletetext);
        	fclose(output);
	}
	else if (strcmp(argv[2], "-i") == 0 && argc == 5)
	{
        	const char *newinserttext = argv[4];
        	FILE *output = fopen("output.txt", "w");
        	if (output == NULL)
		{
            		perror("Error opening output file");
            		fclose(input);
            		return 1;
        	}
        	if (strcmp(argv[3], "-f") == 0)
		{
            		inserttext(input, output, newinserttext, 1);
        	}
		else if (strcmp(argv[3], "-b") == 0)
		{
            		inserttext(input, output, newinserttext, 0);
        	}
		else
		{
            		fprintf(stderr, "Mistake\n");
            		fclose(input);
            		fclose(output);
            		return 1;
        	}
		fclose(output);
	}
	else
	{
		fprintf(stderr, "Wrong arguments\n");
        	fclose(input);
        	return 1;
    	}
	fclose(input);
    	return 0;
}

