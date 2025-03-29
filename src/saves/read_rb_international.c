#include <stdio.h>
#include "data/tables.h"
#include "data/pokemon_structs.h"

#include "pokemon/read_pk1.h"
#include "pokemon/print_pk1.h"


int calculate_checksum(unsigned char *data, int from, int to)
{
	unsigned char checksum = 0;
	for(int i = from; i < to; i++)
	{
		checksum += data[i];
	}
	return checksum ^= 0xFF;
}


void extract_pokemon(pk1 *p, unsigned char *data, int offset, int i, int data_size, int count, int box)
{
	unsigned char pk[69];
	for(int k = 0; k < data_size; k++)
	{
		pk[k + 0x03] = data[offset + (count + 2) + (i * data_size) + k];
	}
	if(box)
	{
		pk[0x24] = pk[6];
	}
	int names_offset = data_size * count + count + 2;
	for(int k = 0; k < 10; k++)
	{
		pk[k + 0x2F] = data[offset + names_offset + (i * 0xB) + k];
		pk[k + 0x3A] = data[offset + names_offset + (count + i) * 0xB + k];
	}
	read_pk1(p, pk);
}


int read_rb_international(unsigned char *data)
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
	printf("\nPlayer Name: ");
	for(int i = offset; i < offset + 0xB; i++)
	{
		printf("%c", gb_character_map(data[i]));
	}

	//Pokedex
	//NOTE: Entry #152 is a copy of #115, Kangaskhan
	offset = 0x25A3;
	int obtained, seen;
	char pokedex_display[] = {' ', '*'};
	printf("\n\nPokedex\n No.    Species O S\n-------------------\n");
	for(int i = 0; i < 151; i++)
	{
		obtained = data[offset + (i >> 3)] >> (i & 7) & 1;
		seen = data[offset + 0x13 + (i >> 3)] >> (i & 7) & 1;
		printf("#%03d %10s %c %c\n", i + 1, species(i + 1), pokedex_display[obtained], pokedex_display[seen]);
	}

	//Bag Items
	//TODO: Display item names
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

	//Last Map
	//offset = 0x2611;

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

	//Owned Hidden Coins
	//offset = 0x29AA;

	//Towns Visited
	//offset = 0x29B7;

	//Rival's Starter
	//offset = 0x29C1;

	//Player's Starter
	//offset = 0x29C3;

	//Flags 1
	//offset = 0x29D4;

	//Flags 2
	//offset = 0x29D8;

	//Flags 3
	//offset = 0x29D9;

	//Flags 4
	//offset = 0x29DA;

	//Flags 5
	//offset = 0x29DC;

	//Flags 6
	//offset = 0x29DE;

	//Flags 7
	//offset = 0x29DF;

	//Flags 8
	//offset = 0x29E2;

	//Completed In-Game Trades
	//offset = 0x29E3;

	//Lt. Surge Gym Locks
	//offset = 0x29EF;

	//Completed Game Events
	//offset = 0x29F3;

	//Time played
	//offset = 0x2CED;

	//Daycare
	//offset = 0x2CF5;

	//Party
	offset = 0x2F2C;
	printf("\nParty:\n");
	for(int i = 0; i < data[offset]; i++)
	{
		pk1 p;
		extract_pokemon(&p, data, offset, i, 0x2C, 6, 0);
		print_pk1(&p);
		printf("\n\n");
	}

	//Bank 1 Checksum
	offset = 0x2598;
	int checksum = calculate_checksum(data, offset, offset + 0xF8B);
	printf("\nBank 1 Calculated Checksum: %u\n", checksum);
	printf("Bank 1 Read Checksum:       %u\n", data[0x3523]);

	//*************
	//BANKS 2 and 3
	//*************

	//Boxes
	offset = 0x4000;
	for(int j = 1; j <= 12; j++)
	{
		printf("\nBox %d:", j);
		if(j == current_box)
		{
			printf(" <- Current Box");
		}
		printf("\n");

		//Loop through pokemon
		for(int i = 0; i < data[offset]; i++)
		{
			pk1 p;
			extract_pokemon(&p, data, offset, i, 0x21, 20, 1);
			print_main(&p);
		}

		offset += 0x462;
		if(j == 6)
		{
			offset = 0x6000;
		}
	}

	//Bank 2 and 3 Checksums

	return 0;
}
