#include <stdio.h>

#include "data/tables.h"

int read_pk2(unsigned char *data)
{
	//Print file contents to the screen
	for(int i = 0; i < 74; i++)
	{
    		printf("%x ", data[i]);
	}
	printf("\n");

	//Print out Pokemon data

	return 0;
}
