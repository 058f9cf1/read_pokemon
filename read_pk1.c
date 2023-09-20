#include <stdio.h>

int main(int argc, char **argv)
{
	const int SIZE = 69;
	unsigned char buffer[SIZE];
	
	FILE *file = fopen(argv[1], "rb");
	
	if(file == NULL)
	{
		printf("Not a .pk1 file\n");
		return 1;
	}

	fread(buffer, SIZE, 1, file);
	
	for(int i = 0; i < SIZE; i++)
	{
    	printf("%x ", buffer[i]);
	}
	printf("\n");
    
	
	printf("%d\n", (buffer[4])<<8);

	printf("Species: %x\n", buffer[3]);
	printf("HP: %d\n", (buffer[4]<<8) | buffer[5]);
	printf("Level: %d\n", buffer[6]);
	printf("Status Condition: %d\n", buffer[7]);

	return 0;
}
