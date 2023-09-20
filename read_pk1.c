#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	const int SIZE = 69;
	unsigned char buffer[SIZE];
	
	if(access(argv[1], R_OK) == 0)
	{
		FILE *file = fopen(argv[1],"rb");
		fread(buffer, SIZE, 1, file);
	}
	else
	{
		printf("Not a .pk1 file\n");
    	exit(0);
	}

	
	for(int i = 0; i < SIZE; i++)
    	printf("%x ", buffer[i]);
    printf("\n");
    
	
	printf("%d\n", (buffer[4])<<8);

	printf("Species: %x\n", buffer[3]);
	printf("HP: %d\n", (buffer[4]<<8) | buffer[5]);
	printf("Level: %d\n", buffer[6]);
	printf("Status Condition: %d\n", buffer[7]);
}

