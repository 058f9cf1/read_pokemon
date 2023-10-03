#include <stdio.h>

int read_rb_international(unsigned char* data)
{
	printf("Trainer Name: ");
	for(int i = 0x2598; i < 0x25A3; i++)
	{
		printf("%x ", data[i]);
	}
	printf("\n");


	printf("DEX O S\n-------\n");
	for(int i = 0; i < 152; i++)
	{
		printf("%03d %d %d\n", i+1, data[0x25A3 + (i >> 3)] >> (i & 7) & 1, data[0x25B6 + (i >> 3)] >> (i & 7) & 1);
	}


	printf("Item count: %d\n", data[0x25C9]);
	for(int i = 0x25CA; i < 0x25F2; i+=2)
	{
		printf("%-3d %d\n", data[i], data[i+1]);
	}


	int money = (data[0x25F3] >> 4)*100000 + (data[0x25F3] & 0b1111)*10000 + (data[0x25F4] >> 4)*1000 + (data[0x25F4] & 0b1111)*100 + (data[0x25F5] >> 4)*10 + (data[0x25F5] & 0b1111);
	printf("Money: %d\n", money);


	printf("Rival Name: ");
	for(int i = 0x25F6; i < 0x2601; i++)
	{
		printf("%x ", data[i]);
	}
	printf("\n");


	printf("Game Options: %08b\n", data[0x2601]);
	printf("Badges: %08b\n", data[0x2602]);




	unsigned char checksum = 0;
	for(int i = 0x2598; i < 0x3522; i++)
	{
		checksum += data[i];
	}
	checksum ^= 0xFF;
	printf("%d\n", checksum);
	printf("%d\n", data[0x3523]);

	return 0;
}
