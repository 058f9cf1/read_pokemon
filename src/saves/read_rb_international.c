#include <stdio.h>
#include "../pokemon/tables.h"

int read_rb_international(unsigned char* data)
{
	//Bank 0 - 0x0000 to 0x1FFF
	//Bank 1 - 0x2000 to 0x3FFF
	//Bank 2 - 0x4000 to 0x5FFF
	//Bank 3 - 0x6000 to 0x7FFF
	
	//******
	//Bank 0
	//******

	//TODO: Hall of Fame data
	int offset = 0x0;


	//******
	//Bank 1
	//******

	//Player Name
	offset = 0x2598;
	printf("Player Name: ");
	for(int i = offset; i < offset + 0xB; i++)
	{
		printf("%c", gb_character_map(data[i]));
	}

	//Pokedex
	//NOTE: Entry #152 is a copy of #115, Kangaskhan
	offset = 0x25A3;
	int obtained, seen;
	char pokedex_display[] = {' ', '*'};
	printf("\n\nDEX O S\n-------\n");
	for(int i = 0; i < 152; i++)
	{
		obtained = data[offset + (i >> 3)] >> (i & 7) & 1;
		seen = data[offset + 0x13 + (i >> 3)] >> (i & 7) & 1;
		printf("%03d %c %c\n", i + 1, pokedex_display[obtained], pokedex_display[seen]);
	}

	//Bag Items
	offset = 0x25C9;
	int item_count = data[offset];
	printf("\nBag\n------\n");
	for(int i = offset + 1; i < offset + item_count + 3; i += 2)
	{
		printf("%-3d %d\n", data[i], data[i + 0x1]);
	}

	//Money
	offset = 0x25F3;
	int money = (data[offset] >> 4) * 100000 + (data[offset] & 0b1111) * 10000 + (data[offset + 0x1] >> 4) * 1000 + (data[offset + 0x1] & 0b1111) * 100 + (data[offset + 0x2] >> 4) * 10 + (data[offset + 0x2] & 0b1111);
	printf("\nMoney: ₽%d\n", money);

	//Rival Name
	//TODO: Deal with suggested rival names
	offset = 0x25F6;
	printf("\nRival Name: ");
	for(int i = offset; i < offset + 0xB; i++)
	{
		printf("%c", gb_character_map(data[i]));
	}

	//Game Options
	//TODO: Convert bits to be human readable
	offset = 0x2601;
	printf("\n\nGame Options\n------------\n");
	printf("Battle Effects: %b\n", data[offset] & 0b100000000);
	printf("Battle Style: %b\n", data[offset] & 0b010000000);
	printf("Sound: %b\n", data[offset] & 0b001100000);
	printf("Text Speed: %b\n", data[offset] & 0b000000111);

	//Badges
	offset = 0x2602;
	printf("\nBadges: %08b\n", data[offset]);

	//Player ID
	offset = 0x2605;
	printf("\nPlayer ID: %05d\n", (data[offset] << 8) | data[offset + 0x1]);

	//Current Map
	//offset = 0x260A;

	//Player Coordinates
	//offset = 0x260D;

	//Pikachu Friendship
	//offset = 0x271C;

	//Box Items
	//offset = 0x27E6;

	//Current Box Number
	offset = 0x284C;
	int current_box = (data[offset] & 0x7F) + 1;

	//Hall of Fame Record Count
	//offset = 0x284E;

	//Slot Coins
	//offset = 0x2850;

	//Owned Hidden Items
	//offset = 0x299C;

	//Towns Visited
	//offset = 0x29B7;

	//
	//More bank 1 data to be read
	//



	//Party
	//TODO: Read pokemon using reading file and expand data read
	offset = 0x2F2C;
	printf("\nPokemon \n------------\nParty:\n");
	for(int i = offset + 0x1; i < offset + data[offset] + 1; i++)
	{
		int pokedex_number = gb_species_index(data[i]);
		printf("%s ", species(pokedex_number));
		printf("%c\n", gender(pokedex_number, data[0x2B * (i - offset) + i - 0x9] >> 4));
	}

	//Boxes
	for(int j = 0; j < 12; j++)
	{
		printf("\nBox %d:", j + 1);
		if(j + 1 == current_box)
		{
			offset = 0x30C0;
			printf(" <- Current Box\n");
		}
		else
		{
			offset = 0x4000 + (0x2000 * (j / 6)) + (0x462 * (j % 6));
			printf("\n");
		}
		for(int i = offset + 0x1; i < offset + data[offset] + 1; i++)
		{
			int pokedex_number = gb_species_index(data[i]);
			printf("%s ", species(pokedex_number));
			printf("%c\n", gender(pokedex_number, data[offset + 0x31 + (i - offset - 1) * 0x21] >> 4));
		}
	}


	//Checksum
	offset = 0x2598;
	unsigned char checksum = 0;
	for(int i = offset; i < offset + 0xF8B; i++)
	{
		checksum += data[i];
	}
	checksum ^= 0xFF;
	printf("\nCalculated Checksum: %d\n", checksum);
	printf("Read Checksum:       %d\n", data[0x3523]);

	return 0;
}
