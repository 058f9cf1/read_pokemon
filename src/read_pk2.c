#include <stdio.h>

#include "tables.h"

int read_pk2(FILE* file)
{
	//Size of .pk2 files
	const int SIZE = 74;
	unsigned char buffer[SIZE];

	//Read file bytes to array
	fread(buffer, SIZE, 1, file);

	//Print file contents to the screen
	for(int i = 0; i < SIZE; i++)
	{
    		printf("%x ", buffer[i]);
	}
	printf("\n");

	//Print out Pokemon data
  return 0;
}
