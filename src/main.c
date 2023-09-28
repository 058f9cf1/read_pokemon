#include <stdio.h>
 
#include "read_pk1.h"

int file_size(FILE* file)
{
	//Test that the argument given is a file
	if(file == NULL)
	{
		printf("File doesn't exist\n");
		return -1;
	}

	//Calculate the size of the file
	fseek(file, 0, SEEK_END); //Seek to the end of the file
	int size = ftell(file); //Get current file pointer
	fseek(file, 0, SEEK_SET); //Seek back to beginning of the file

	return size;
}

int main(int argc, char **argv)
{
	//Open file given as argument
	FILE* file = fopen(argv[1], "rb");
	//Determine the size of the file
	int size = file_size(file);
	
	switch(size)
	{
		case 69:	//.pk1
			read_pk1(file);
			break;

		case 74:	//.pk2
			break;
		
		//Gen 3+ Pokemon need to be decrypted

		//If file size does not match a known .pk format
		default:
			printf("Not a Pokemon file\n");
	}

	fclose(file);

	return 0;
}
