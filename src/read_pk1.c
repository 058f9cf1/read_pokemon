#include <stdio.h>

int read_pk1(FILE* file)
{
	const int SIZE = 69;
	unsigned char buffer[SIZE];
	
	fread(buffer, SIZE, 1, file);
	
	for(int i = 0; i < SIZE; i++)
	{
    	printf("%x ", buffer[i]);
	}
	printf("\n");
    
	printf("Species: %x\n", buffer[3]);
	printf("HP: %d\n", (buffer[4]<<8) | buffer[5]);
	printf("Status Condition: %x\n", buffer[7]);
	printf("Type 1: %x\n", buffer[8]);
	printf("Type 2: %x\n", buffer[9]);
	printf("Catch Rate: %d\n", buffer[10]);
	printf("Move 1: %x\n", buffer[11]);
	printf("Move 2: %x\n", buffer[12]);
	printf("Move 3: %x\n", buffer[13]);
	printf("Move 4: %x\n", buffer[14]);
	printf("OT ID: %d\n", (buffer[15]<<8) | buffer[16]);
	printf("Exp Pointe: %d\n", (buffer[17]<<16) | (buffer[18]<<8) | buffer[19]);
	printf("HP EV: %d\n", (buffer[20]<<8) | buffer[21]);
	printf("Attack EV: %d\n", (buffer[22]<<8) | buffer[23]);
	printf("Defence EV: %d\n", (buffer[24]<<8) | buffer[25]);
	printf("Speed EV: %d\n", (buffer[26]<<8) | buffer[27]);
	printf("Special EV: %d\n", (buffer[28]<<8) | buffer[29]);
	printf("Attack IV: %d\n", buffer[30] >> 4);
	printf("Defence IV: %d\n", buffer[30] & 0b1111);
	printf("Speed IV: %d\n", buffer[31] >> 4);
	printf("Special IV: %d\n", buffer[31] & 0b1111);
	printf("Move 1 Current PP: %d\n", buffer[32] & 0b111111);
	printf("Move 1 PP Ups: %d\n", buffer[32] >> 6);
	printf("Move 2 Current PP: %d\n", buffer[33] & 0b111111);
	printf("Move 2 PP Ups: %d\n", buffer[33] >> 6);
	printf("Move 3 Current PP: %d\n", buffer[34] & 0b111111);
	printf("Move 3 PP Ups: %d\n", buffer[34] >> 6);
	printf("Move 4 Current PP: %d\n", buffer[35] & 0b111111);
	printf("Move 4 PP Ups: %d\n", buffer[35] >> 6);
	printf("Level: %d\n", buffer[36]);
	printf("HP Stat: %d\n", (buffer[37]<<8) | buffer[38]);
	printf("Attack Stat: %d\n", (buffer[39]<<8) | buffer[40]);
	printf("Defence Stat: %d\n", (buffer[41]<<8) | buffer[42]);
	printf("Speed Stat: %d\n", (buffer[43]<<8) | buffer[44]);
	printf("Special Stat: %d\n", (buffer[45]<<8) | buffer[46]);

	return 0;
}
