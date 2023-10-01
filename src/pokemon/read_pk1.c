#include <stdio.h>

#include "tables.h"

int read_pk1(unsigned char* data)
{
	//Print out Pokemon data
	printf("Species: %s\n", pk1_pk2_species(data[3]));
	printf("HP: %d\n", (data[4]<<8) | data[5]);
	printf("Status Condition: %s\n", status_condition(data[7]));
	printf("Type 1: %s\n", type(data[8]));
	printf("Type 2: %s\n", type(data[9]));
	printf("Catch Rate: %d\n", data[10]);
	printf("Move 1: %s\n", move(data[11]));
	printf("Move 2: %s\n", move(data[12]));
	printf("Move 3: %s\n", move(data[13]));
	printf("Move 4: %s\n", move(data[14]));
	printf("OT ID: %d\n", (data[15]<<8) | data[16]);
	printf("Exp Pointe: %d\n", (data[17]<<16) | (data[18]<<8) | data[19]);
	printf("HP EV: %d\n", (data[20]<<8) | data[21]);
	printf("Attack EV: %d\n", (data[22]<<8) | data[23]);
	printf("Defence EV: %d\n", (data[24]<<8) | data[25]);
	printf("Speed EV: %d\n", (data[26]<<8) | data[27]);
	printf("Special EV: %d\n", (data[28]<<8) | data[29]);
	printf("Attack IV: %d\n", data[30] >> 4);
	printf("Defence IV: %d\n", data[30] & 0b1111);
	printf("Speed IV: %d\n", data[31] >> 4);
	printf("Special IV: %d\n", data[31] & 0b1111);
	printf("Move 1 Current PP: %d\n", data[32] & 0b111111);
	printf("Move 1 PP Ups: %d\n", data[32] >> 6);
	printf("Move 2 Current PP: %d\n", data[33] & 0b111111);
	printf("Move 2 PP Ups: %d\n", data[33] >> 6);
	printf("Move 3 Current PP: %d\n", data[34] & 0b111111);
	printf("Move 3 PP Ups: %d\n", data[34] >> 6);
	printf("Move 4 Current PP: %d\n", data[35] & 0b111111);
	printf("Move 4 PP Ups: %d\n", data[35] >> 6);
	printf("Level: %d\n", data[36]);
	printf("HP Stat: %d\n", (data[37]<<8) | data[38]);
	printf("Attack Stat: %d\n", (data[39]<<8) | data[40]);
	printf("Defence Stat: %d\n", (data[41]<<8) | data[42]);
	printf("Speed Stat: %d\n", (data[43]<<8) | data[44]);
	printf("Special Stat: %d\n", (data[45]<<8) | data[46]);

	return 0;
}
