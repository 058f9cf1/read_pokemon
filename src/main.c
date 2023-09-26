#include <stdio.h>
 
#include "read_pk1.h"

int file_size(FILE* file)
{
	if(file == NULL)
	{
		printf("File doesn't exist\n");
		return -1;
	}

	fseek(file, 0, SEEK_END);
	int size = ftell(file);
	fseek(file, 0, SEEK_SET);

	return size;
}

int main(int argc, char **argv)
{
	FILE* file = fopen(argv[1], "rb");
	int size = file_size(file);
	
	switch(size)
	{
		case 69:
			printf(".pk1\n");
			read_pk1(file);
			break;

		case 74:
			printf(".pk2\n");
			break;

		default:
			printf("Not a Pokemon file\n");
	}

	fclose(file);

	return 0;
}
